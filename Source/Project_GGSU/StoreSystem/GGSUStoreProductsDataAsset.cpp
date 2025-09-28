// Fill out your copyright notice in the Description page of Project Settings.


#include "StoreSystem/GGSUStoreProductsDataAsset.h"

int UGGSUStoreProductsDataAsset::GetPrice(const UGGSUResourceDataAsset* TargetResource)
{
	// 미리 캐싱해두기
	if (ResourcePrices.IsEmpty())
		for (TPair<FString, FProductsGroup> Showcase : Showcases)
			for (auto ResourcePair : Showcase.Value.Items)
				ResourcePrices.Add(ResourcePair.Key, ResourcePair.Value);


	return ResourcePrices[TargetResource];
}
