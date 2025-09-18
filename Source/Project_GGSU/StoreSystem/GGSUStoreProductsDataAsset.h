// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GGSUStoreProductsDataAsset.generated.h"

class UGGSUItemDataAsset;

USTRUCT()
struct FProductsGroup
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TArray<UGGSUItemDataAsset*> Items;
};

UCLASS()
class PROJECT_GGSU_API UGGSUStoreProductsDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TMap<FString, FProductsGroup> Showcases;
};
