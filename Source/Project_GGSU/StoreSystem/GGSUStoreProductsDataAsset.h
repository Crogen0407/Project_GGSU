// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GGSUStoreProductsDataAsset.generated.h"

class UGGSUResourceDataAsset;

USTRUCT()
struct FProductsGroup
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TMap<UGGSUResourceDataAsset*, int> Items;
};

UCLASS()
class PROJECT_GGSU_API UGGSUStoreProductsDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	int GetPrice(const UGGSUResourceDataAsset* TargetResource);
	
public:
	UPROPERTY(EditAnywhere)
	TMap<FString, FProductsGroup> Showcases;

protected:
	UPROPERTY(Transient)
	TMap<UGGSUResourceDataAsset*, int> ResourcePrices;
};
