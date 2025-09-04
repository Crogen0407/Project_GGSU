// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GGSUCropsSetDataAsset.generated.h"

class AGGSUCrops;
class UGGSUCropsAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUCropsSetDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UGGSUCropsAsset* GetCropsAsset(FName Name);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Crops")
	TArray<UGGSUCropsAsset*> CropsAssets; 
};
