// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResourceSystem/GGSUCurrencyDataAsset.h"
#include "GGSUCropsSetDataAsset.generated.h"

class AGGSUCrop;
class UGGSUCropDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUCropsSetDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	static UGGSUCropsSetDataAsset* GetInstance()
	{
		FStringAssetReference AssetRef(TEXT("/Script/Project_GGSU.GGSUCropsSetDataAsset'/Game/CropsDataAsset/ResourceSet.ResourceSet'"));
		Instance = Cast<UGGSUCropsSetDataAsset>(StaticLoadObject(UGGSUCropsSetDataAsset::StaticClass(), nullptr, *AssetRef.ToString()));
		return Instance;
	}

public:
	UGGSUCropDataAsset* GetCropsAsset(FName Name);
	TArray<UGGSUCropDataAsset*> GetCropAssets() const;
	UGGSUCurrencyDataAsset* GetCurrencyAssets(FName Name);
	TArray<UGGSUCurrencyDataAsset*> GetCurrencyAssets() const;
	
public:
	int GetCropsCount() const
	{
		return CropsAssets.Num();
	}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Crops")
	TArray<UGGSUCropDataAsset*> CropsAssets;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Crops")
	TArray<UGGSUCurrencyDataAsset*> CurrencyAssets;

private:
	static UGGSUCropsSetDataAsset* Instance;
};
