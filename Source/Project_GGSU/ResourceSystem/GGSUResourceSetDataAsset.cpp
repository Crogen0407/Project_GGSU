#include "ResourceSystem/GGSUResourceSetDataAsset.h"
#include "CropsSystem/GGSUCropDataAsset.h"
#include "CropsSystem/GGSUCropSeedDataAsset.h"

UGGSUCropSeedDataAsset* UGGSUResourceSetDataAsset::GetCropSeedAsset(FName Name)
{
	for (auto CropsAsset : CropSeedAssets)
	{
		if (CropsAsset->GetName().IsEqual(Name))
		 	return CropsAsset;
	}

	return nullptr;
}

UGGSUCurrencyDataAsset* UGGSUResourceSetDataAsset::GetCurrencyAssets(FName Name)
{
	for (auto CurrencyAsset : CurrencyAssets)
	{
		if (CurrencyAsset->GetName().IsEqual(Name))
		 	return CurrencyAsset;
	}

	return nullptr;
}
