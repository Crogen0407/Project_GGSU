// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUCropsSubSystem.generated.h"

class AGGSUCrops;
class UGGSUCropsAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUCropsSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	AGGSUCrops* SpawnCrop(const UGGSUCropsAsset* CropsAsset, const FVector& Location) const;
};
