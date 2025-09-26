// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResourceSystem/GGSUCurrencyDataAsset.h"
#include "GGSUResourceSetDataAsset.generated.h"

class UGGSUItemDataAsset;
class AGGSUCrop;
class UGGSUResourceDataAsset;
class UGGSUCropSeedDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUResourceSetDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UGGSUCropSeedDataAsset* GetCropSeedAsset(FName Name);
	UGGSUCurrencyDataAsset* GetCurrencyAssets(FName Name);
	TArray<UGGSUCropSeedDataAsset*> GetCropSeedAssets() const
	{
		return CropSeedAssets;
	}
	TArray<UGGSUCurrencyDataAsset*> GetCurrencyAssets() const
	{
		return CurrencyAssets;
	}
	TArray<UGGSUResourceDataAsset*> GetOtherAssets() const
	{
		return OtherAssets;
	}

	TArray<UGGSUItemDataAsset*> GetItemsAssets() const
	{
		return ItemAssets;
	}
	
public:
	int GetCropsCount() const
	{
		return CropSeedAssets.Num();
	}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Resource")
	TArray<UGGSUCropSeedDataAsset*> CropSeedAssets;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Resource")
	TArray<UGGSUCurrencyDataAsset*> CurrencyAssets;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Resource")
	TArray<UGGSUResourceDataAsset*> OtherAssets;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Resource")
	TArray<UGGSUItemDataAsset*> ItemAssets;
};
