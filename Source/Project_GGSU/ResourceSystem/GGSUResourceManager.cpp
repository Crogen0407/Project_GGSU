// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUResourceManager.h"
#include "CropsSystem/GGSUCropsSetDataAsset.h"
#include "CropsSystem/GGSUCropDataAsset.h"
#include "UI/GGSUResourceElement.h"

UGGSUResourceManager::UGGSUResourceManager()
{
	static ConstructorHelpers::FObjectFinder<UGGSUCropsSetDataAsset> CropsSetDataAssetObject(TEXT("/Game/DataAssets/Resources/DA_ResourceSet"));

	if (CropsSetDataAssetObject.Object == nullptr) return;
	
	CropsSetDataAsset = CropsSetDataAssetObject.Object;	
}

UGGSUResourceManager::~UGGSUResourceManager()
{
}

void UGGSUResourceManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TArray<UGGSUCropDataAsset*> CropDataAssets = CropsSetDataAsset->GetCropAssets();
	for (UGGSUCropDataAsset* CropDataAsset : CropDataAssets)
	{
		ResourceAmount.Add(Cast<UGGSUResourceDataAsset>(CropDataAsset), 0);
		ResourceChangedEvents.Add(Cast<UGGSUResourceDataAsset>(CropDataAsset), {});
	}
	
	TArray<UGGSUCurrencyDataAsset*> CurrencyDataAssets = CropsSetDataAsset->GetCurrencyAssets();
	for (UGGSUCurrencyDataAsset* CurrencyDataAsset : CurrencyDataAssets)
	{
		ResourceAmount.Add(Cast<UGGSUResourceDataAsset>(CurrencyDataAsset), 0);
		ResourceChangedEvents.Add(Cast<UGGSUResourceDataAsset>(CurrencyDataAsset), {});
	}
}

void UGGSUResourceManager::AddResource(const UGGSUResourceDataAsset* type, int value)
{
	ResourceAmount[type] += value;
	ResourceChangedEvents[type].Broadcast(ResourceAmount[type]);
}

void UGGSUResourceManager::RemoveResource(const UGGSUResourceDataAsset* type, int value)
{
	if (ResourceAmount[type] >= value)
	{
		ResourceAmount[type] -= value;
		ResourceChangedEvents[type].Broadcast(ResourceAmount[type]);
	}
}

bool UGGSUResourceManager::TryRemoveResource(const UGGSUResourceDataAsset* type, int value)
{
	if (ResourceAmount.Contains(type) == false)
	{
		return false;
	}
		
	if (ResourceAmount[type] >= value)
	{
		ResourceAmount[type] -= value;
		ResourceChangedEvents[type].Broadcast(ResourceAmount[type]);
		return true;
	}
	return false;
}