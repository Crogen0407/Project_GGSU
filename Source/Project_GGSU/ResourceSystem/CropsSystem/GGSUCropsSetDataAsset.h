// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GGSUCropsSetDataAsset.generated.h"

class AGGSUCrop;
class UGGSUCropDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUCropsSetDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UGGSUCropDataAsset* GetCropsAsset(FName Name);
	TArray<UGGSUCropDataAsset*> GetCropAssets() const;
	
public:
	int GetDropsCount() const
	{
		return CropsAssets.Num();
	}
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Crops")
	TArray<UGGSUCropDataAsset*> CropsAssets;
};
