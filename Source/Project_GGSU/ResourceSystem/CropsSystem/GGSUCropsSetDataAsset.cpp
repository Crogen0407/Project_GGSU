// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceSystem/CropsSystem/GGSUCropsSetDataAsset.h"

#include "GGSUCropDataAsset.h"

UGGSUCropDataAsset* UGGSUCropsSetDataAsset::GetCropsAsset(FName Name)
{
	for (auto CropsAsset : CropsAssets)
	{
		if (CropsAsset->Name.IsEqual(Name))
		 	return CropsAsset;
	}

	return nullptr;
}

TArray<UGGSUCropDataAsset*> UGGSUCropsSetDataAsset::GetCropAssets() const
{
	return CropsAssets;
}

UGGSUCurrencyDataAsset* UGGSUCropsSetDataAsset::GetCurrencyAssets(FName Name)
{
	for (auto CurrencyAsset : CurrencyAssets)
	{
		if (CurrencyAsset->Name.IsEqual(Name))
		 	return CurrencyAsset;
	}

	return nullptr;
}

TArray<UGGSUCurrencyDataAsset*> UGGSUCropsSetDataAsset::GetCurrencyAssets() const
{
	return CurrencyAssets;
}
