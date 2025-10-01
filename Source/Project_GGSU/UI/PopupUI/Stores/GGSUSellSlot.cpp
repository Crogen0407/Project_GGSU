// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PopupUI/Stores/GGSUSellSlot.h"

#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"
#include "ResourceSystem/GGSUResourceManager.h"
#include "ResourceSystem/GradeSystem/GGSUGradeManager.h"
#include  "ResourceSystem/GGSUCurrencyDataAsset.h"
#include "StoreSystem/GGSUStoreProductsDataAsset.h"

void UGGSUSellSlot::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	CachedResourceManager = GetGameInstance()->GetSubsystem<UGGSUResourceManager>();

	SellButton->OnClicked.AddDynamic(this, &UGGSUSellSlot::HandleSellTargetResource);
}

void UGGSUSellSlot::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	if (UGGSUResourceDataAsset* ElementObject = Cast<UGGSUResourceDataAsset>(ListItemObject))
	{
		// 내부 데이터
		CachedTargetResource = ElementObject;

		// 갯수 검색
		if (nullptr == CachedResourceManager) return;
		CachedCount = CachedResourceManager->GetResource(ElementObject);
		
		// UI 셋팅
		CountText->SetText(FText::FromString(FString::FromInt(CachedCount)));
		IconImage->SetBrushFromTexture(ElementObject->GetIconTexture());

		if (IGGSUGradeResource* GradeResource = Cast<IGGSUGradeResource>(ElementObject))
			SetGrade(GradeResource->GetGrade());
		else
			GradeIcon->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UGGSUSellSlot::SetGrade(const EResourceGrade Grade) const
{
	if (const UGGSUGradeManager* GradeManager = GetGameInstance()->GetSubsystem<UGGSUGradeManager>())
	{
		const FColor Color = GradeManager->GetGradeColor(Grade);
		GradeIcon->SetBrushColor(Color);
		GradeIcon->SetVisibility(ESlateVisibility::Visible);
		GradeText->SetText(FText::FromString(StaticEnum<EResourceGrade>()->GetNameStringByValue(static_cast<int64>(Grade))));
	}
}

void UGGSUSellSlot::HandleSellTargetResource()
{
	if (nullptr == CachedResourceManager || nullptr == StoreProducts) return;

	if (CachedResourceManager->TryRemoveResource(CachedTargetResource, 1))
	{
		const int ResourceCount = CachedResourceManager->GetResource(CachedTargetResource);

		// 리소스를 전부 팔았다면 이 UI를 파괴하기
		if (ResourceCount <= 0)
		{
			// TODO : UI 파괴
		}
		else
		{
			const int SellCost = CachedTargetResource->GetSellingPrice();
			CachedResourceManager->AddResource(TargetCurrency, SellCost);
			CountText->SetText(FText::FromString(FString::FromInt(ResourceCount)));	
		}
	}
	else
	{
		// TODO : 메시지 띄우면 좋을 듯
	}
}
