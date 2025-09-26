// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUCropsGenerator.generated.h"

class AGGSUCrop;
class UGGSUCropSeedDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUCropsGenerator : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	AGGSUCrop* SpawnCrop(UGGSUCropSeedDataAsset* CropSeed, const FVector& Location) const;
};
