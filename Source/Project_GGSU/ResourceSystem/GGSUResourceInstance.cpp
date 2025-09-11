// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUResourceInstance.h"

#include "Engine/AssetManager.h"

void UGGSUResourceInstance::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UAssetManager& AssetManager = UAssetManager::Get();

	UGGSUCropsSetDataAsset* ResourceSetDataAsset = nullptr;
	
	//TArray<UGGSUCropDataAsset*> CropDataAssets = ResourceSetDataAsset->GetCropAssets();
	//for (UGGSUCropDataAsset* CropDataAsset : CropDataAssets)
	//{
	//	ResourceAmount.Add(Cast<UGGSUResourceDataAsset>(CropDataAsset), 0);
	//}
	//TArray<UGGSUCurrencyDataAsset*> CurrencyDataAssets = ResourceSetDataAsset->GetCurrencyAssets();
	//for (UGGSUCurrencyDataAsset* CurrencyDataAsset : CurrencyDataAssets)
	//{
	//	ResourceAmount.Add(Cast<UGGSUResourceDataAsset>(CurrencyDataAsset), 0);
	//}
}
