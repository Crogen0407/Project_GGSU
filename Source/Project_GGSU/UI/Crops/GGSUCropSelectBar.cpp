#include "UI/Crops/GGSUCropSelectBar.h"
#include "UI/Crops/GGSUCropIcon.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "ResourceSystem/GGSUResourceManager.h"
#include "ResourceSystem/GGSUResourceSetDataAsset.h"
#include "ResourceSystem/CropsSystem/GGSUCropSeedDataAsset.h"

void UGGSUCropSelectBar::NativeConstruct()
{
	UE_LOG(LogTemp, Log, TEXT("NativeConstruct"));
	
	Super::NativeConstruct();

	CachedResourceManager = GetGameInstance()->GetSubsystem<UGGSUResourceManager>(); 
	if (nullptr == CachedResourceManager) return;
	
	// 초기 UI 셋팅
	CreateCropElements();

	for (UGGSUCropSeedDataAsset* CropSeedAsset : ResourceSetDataAsset->GetCropSeedAssets())
	{
		CachedResourceManager->ResourceChangedEvents[CropSeedAsset].AddDynamic(this, &UGGSUCropSelectBar::HandleChangeCropSeedCount);
	}
}

void UGGSUCropSelectBar::CreateCropElements()
{
	if (CropIcons == nullptr || ItemWidgetClass == nullptr) return;
	
	for (UGGSUCropSeedDataAsset* CropSeedAsset : ResourceSetDataAsset->GetCropSeedAssets())
	{
		UGGSUCropIcon* CreatedItemWidget = CreateWidget<UGGSUCropIcon>(this, ItemWidgetClass);
		CropIconMap.Add(CropSeedAsset, CreatedItemWidget);
		
		if (CreatedItemWidget)
		{
			// UI 셋팅
			if (UHorizontalBoxSlot* NewSlot = CropIcons->AddChildToHorizontalBox(CreatedItemWidget))
			{
				FSlateChildSize ChildSize;
				ChildSize.SizeRule = ESlateSizeRule::Fill;
				ChildSize.Value = 1.0f;
				
				NewSlot->SetSize(ChildSize);
				NewSlot->SetVerticalAlignment(VAlign_Center);
				NewSlot->SetHorizontalAlignment(HAlign_Center);
				NewSlot->SetPadding(FMargin(5.f));

				const int SeedCount = CachedResourceManager->GetResource(CropSeedAsset); 
				
				if (SeedCount <= 0)
				{
					CropIconMap[CropSeedAsset]->SetVisibility(ESlateVisibility::Collapsed);;
				}
				
				// 초기화
				CreatedItemWidget->SetTargetCropSeed(CropSeedAsset);
				CreatedItemWidget->SetCount(SeedCount);
			}
			
		}
	}
}

void UGGSUCropSelectBar::HandleChangeCropSeedCount(UGGSUResourceDataAsset* Type, int Value)
{
	if (CropIconMap.Contains(Type))
	{
		CropIconMap[Type]->SetVisibility(ESlateVisibility::Visible);
		CropIconMap[Type]->SetCount(Value);
	}
}
