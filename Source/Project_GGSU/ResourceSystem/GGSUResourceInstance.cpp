// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUResourceInstance.h"
#include "CropsSystem/GGSUCropsSetDataAsset.h"
#include "CropsSystem/GGSUCropDataAsset.h"

UGGSUResourceInstance::UGGSUResourceInstance()
{
	static ConstructorHelpers::FObjectFinder<UGGSUCropsSetDataAsset> CropsSetDataAssetObject(TEXT("/Game/CropsDataAsset/Resources/DA_ResourceSet"));

	if (CropsSetDataAssetObject.Object == nullptr) return;
	
	CropsSetDataAsset = CropsSetDataAssetObject.Object;	
}

UGGSUResourceInstance::~UGGSUResourceInstance()
{
}

void UGGSUResourceInstance::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TArray<UGGSUCropDataAsset*> CropDataAssets = CropsSetDataAsset->GetCropAssets();
	for (UGGSUCropDataAsset* CropDataAsset : CropDataAssets)
	{
		ResourceAmount.Add(Cast<UGGSUResourceDataAsset>(CropDataAsset), 0);
	}
	TArray<UGGSUCurrencyDataAsset*> CurrencyDataAssets = CropsSetDataAsset->GetCurrencyAssets();
	for (UGGSUCurrencyDataAsset* CurrencyDataAsset : CurrencyDataAssets)
	{
		ResourceAmount.Add(Cast<UGGSUResourceDataAsset>(CurrencyDataAsset), 0);
	}
}
