#include "ResourceSystem/GGSUResourceSetDataAsset.h"
#include "CropsSystem/GGSUCropDataAsset.h"

UGGSUCropDataAsset* UGGSUResourceSetDataAsset::GetCropsAsset(FName Name)
{
	for (auto CropsAsset : CropsAssets)
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

TArray<UGGSUCropDataAsset*> UGGSUResourceSetDataAsset::GetCropAssets() const
{
	return CropsAssets;
}

TArray<UGGSUCurrencyDataAsset*> UGGSUResourceSetDataAsset::GetCurrencyAssets() const
{
	return CurrencyAssets;
}

TArray<UGGSUResourceDataAsset*> UGGSUResourceSetDataAsset::GetOtherAssets() const
{
	return OtherAssets;
}
