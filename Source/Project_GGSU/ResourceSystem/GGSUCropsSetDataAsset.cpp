// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceSystem/GGSUCropsSetDataAsset.h"

#include "GGSUCropsAsset.h"

UGGSUCropsAsset* UGGSUCropsSetDataAsset::GetCropsAsset(FName Name)
{
	for (auto CropsAsset : CropsAssets)
	{
		if (CropsAsset->Name.IsEqual(Name))
			return CropsAsset;
	}

	return nullptr;
}
