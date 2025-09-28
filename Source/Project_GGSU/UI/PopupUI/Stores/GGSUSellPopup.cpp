// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PopupUI/Stores/GGSUSellPopup.h"

#include "Components/TileView.h"
#include "ResourceSystem/GGSUCurrencyDataAsset.h"
#include "ResourceSystem/GGSUResourceManager.h"

void UGGSUSellPopup::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	CachedResourceManager = GetGameInstance()->GetSubsystem<UGGSUResourceManager>();
}

void UGGSUSellPopup::LoadInventory()
{
	if (nullptr == CachedResourceManager) return;

	SellView->ClearListItems();
	
	for (auto ResourcePair : CachedResourceManager->ResourceAmount)
	{
		if (ResourcePair.Value > 0 && nullptr == Cast<UGGSUCurrencyDataAsset>(ResourcePair.Key))
		{
			SellView->AddItem(ResourcePair.Key);
		}
	}
}

void UGGSUSellPopup::Show_Implementation(float Duration)
{
	Super::Show_Implementation(Duration);
	LoadInventory();
}
