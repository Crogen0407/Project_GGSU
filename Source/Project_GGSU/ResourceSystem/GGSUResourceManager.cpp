#include "GGSUResourceManager.h"
#include "GGSUResourceSetDataAsset.h"
#include "CropsSystem/GGSUCropSeedDataAsset.h"

UGGSUResourceManager::UGGSUResourceManager()
{
	static ConstructorHelpers::FObjectFinder<UGGSUResourceSetDataAsset> CropsSetDataAssetObject(TEXT("/Game/DataAssets/Resources/DA_ResourceSet"));

	if (CropsSetDataAssetObject.Object == nullptr) return;
	
	ResourceSetDataAsset = CropsSetDataAssetObject.Object;	
}

UGGSUResourceManager::~UGGSUResourceManager()
{
}

void UGGSUResourceManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// 작물 에셋 초기화
	const TArray<UGGSUCropSeedDataAsset*> CropDataAssets = ResourceSetDataAsset->GetCropSeedAssets();
	for (UGGSUCropSeedDataAsset* CropDataAsset : CropDataAssets)
	{
		ResourceAmount.Add(Cast<UGGSUResourceDataAsset>(CropDataAsset), 0);
		ResourceChangedEvents.Add(Cast<UGGSUResourceDataAsset>(CropDataAsset), {});
	}

	// 재화 관련 초기화
	const TArray<UGGSUCurrencyDataAsset*> CurrencyDataAssets = ResourceSetDataAsset->GetCurrencyAssets();
	for (UGGSUCurrencyDataAsset* CurrencyDataAsset : CurrencyDataAssets)
	{
		ResourceAmount.Add(Cast<UGGSUResourceDataAsset>(CurrencyDataAsset), 0);
		ResourceChangedEvents.Add(Cast<UGGSUResourceDataAsset>(CurrencyDataAsset), {});
	}

	// 기타 관련 초기화(걍 잡다한 ResourceDataAsset들 다 여기에)
	const TArray<UGGSUResourceDataAsset*> OtherDataAssets = ResourceSetDataAsset->GetOtherAssets();
	for (UGGSUResourceDataAsset* OtherDataAsset : OtherDataAssets)
	{
		ResourceAmount.Add(OtherDataAsset, 0);
		ResourceChangedEvents.Add(OtherDataAsset, {});
	}
}

void UGGSUResourceManager::AddResource(const UGGSUResourceDataAsset* Type, const int Value)
{
	ResourceAmount[Type] += Value;
	ResourceChangedEvents[Type].Broadcast(ResourceAmount[Type]);
}

void UGGSUResourceManager::RemoveResource(const UGGSUResourceDataAsset* Type, const int Value)
{
	if (ResourceAmount[Type] >= Value)
	{
		ResourceAmount[Type] -= Value;
		ResourceChangedEvents[Type].Broadcast(ResourceAmount[Type]);
	}
}

bool UGGSUResourceManager::TryRemoveResource(const UGGSUResourceDataAsset* Type, const int Value)
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