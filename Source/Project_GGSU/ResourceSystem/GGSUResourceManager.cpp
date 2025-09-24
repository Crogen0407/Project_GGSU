// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUResourceManager.h"
#include "CropsSystem/GGSUResourceSetDataAsset.h"
#include "CropsSystem/GGSUCropDataAsset.h"
#include "UI/GGSUResourceElement.h"

UGGSUResourceManager::UGGSUResourceManager()
{
	static ConstructorHelpers::FObjectFinder<UGGSUResourceSetDataAsset> CropsSetDataAssetObject(TEXT("/Game/DataAssets/Resources/DA_ResourceSet"));

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

	TArray<UGGSUResourceDataAsset*> OtherDataAssets = CropsSetDataAsset->GetOtherAssets();
	for (UGGSUResourceDataAsset* OtherDataAsset : OtherDataAssets)
	{
		ResourceAmount.Add(OtherDataAsset, 0);
		ResourceChangedEvents.Add(OtherDataAsset, {});
	}
}

void UGGSUResourceManager::AddResource(const UGGSUResourceDataAsset* Type, int Value)
{
	ResourceAmount[Type] += Value;
	ResourceChangedEvents[Type].Broadcast(ResourceAmount[Type]);
}

void UGGSUResourceManager::RemoveResource(const UGGSUResourceDataAsset* Type, int Value)
{
	if (ResourceAmount[Type] >= Value)
	{
		ResourceAmount[Type] -= Value;
		ResourceChangedEvents[Type].Broadcast(ResourceAmount[Type]);
	}
}

bool UGGSUResourceManager::TryRemoveResource(const UGGSUResourceDataAsset* Type, int Value)
{
	if (ResourceAmount.Contains(Type) == false)
	{
		return false;
	}
		
	if (ResourceAmount[Type] >= Value)
	{
		ResourceAmount[Type] -= Value;
		ResourceChangedEvents[Type].Broadcast(ResourceAmount[Type]);
		return true;
	}
	return false;
}