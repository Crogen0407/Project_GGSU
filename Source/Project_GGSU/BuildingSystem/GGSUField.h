// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingSystem/GGSUBuilding.h"
#include "GGSUField.generated.h"

class AGGSUCrop;
class UGGSUCropSeedDataAsset;

UCLASS()
class PROJECT_GGSU_API AGGSUField : public AGGSUBuilding
{
	GENERATED_BODY()
	
	virtual ~AGGSUField() override {}
	
public:
	virtual void OnClicked() override;
	virtual void OnUnlock() override;
	void SpawnCrop(UGGSUCropSeedDataAsset* CropSeed);
	
	bool HarvestCurrentCrops();
	
protected:
	UPROPERTY(Transient)
	TObjectPtr<AGGSUCrop> CurrentCrops;
};
