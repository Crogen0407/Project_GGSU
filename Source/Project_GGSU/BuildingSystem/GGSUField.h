// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingSystem/GGSUBuilding.h"
#include "GGSUField.generated.h"

class UGGSUCropDataAsset;
class AGGSUCrop;

UCLASS()
class PROJECT_GGSU_API AGGSUField : public AGGSUBuilding
{
	GENERATED_BODY()

	
	virtual ~AGGSUField() override {}
	
public:
	virtual void OnClicked() override;
	void SpawnCrop(UGGSUCropDataAsset* CropDataAsset);
	void HarvestCurrentCrops();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CropLocations")
	TArray<TObjectPtr<USceneComponent>> CropSpawnLocations;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AGGSUCrop>> CurrentCrops;
};
