// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GGSUCropsBuilding.generated.h"

class AGGSUCrop;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGGSUCropsBuilding : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECT_GGSU_API IGGSUCropsBuilding
{
	GENERATED_BODY()

public:
	virtual TArray<AGGSUCrop> GetCrops() = 0;
};
