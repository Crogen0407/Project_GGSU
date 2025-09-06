// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUDateManager.generated.h"

UENUM(BlueprintType, Blueprintable)
enum ECountry
{
	Seoul = 9,
	Tokyo = 9,
	London = 0,
	Washington = -5,
	LandBerlin = 1,
};

UCLASS()
class PROJECT_GGSU_API UGGSUDateManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	
public:
	UFUNCTION(BlueprintPure, Category="Time")
	static FDateTime GetTime();

private:
	static TEnumAsByte<ECountry> CurrentCountry;
};
