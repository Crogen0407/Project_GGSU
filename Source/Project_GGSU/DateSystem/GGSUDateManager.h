// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUDateManager.generated.h"

class AGGSUDateController;

UENUM(BlueprintType, Blueprintable)
enum ECountry
{
	Seoul = 9,
	Tokyo = 9,
	London = 0,
	Washington = -5,
	LandBerlin = 1,
};

UENUM(BlueprintType)
enum class EDay : uint8
{
	Day,
	Night,
};

UCLASS()
class PROJECT_GGSU_API UGGSUDateManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	friend AGGSUDateController;
	
public:
	UFUNCTION(BlueprintPure, Category="Time")
	static FDateTime GetTime();

	UFUNCTION(BlueprintPure, Category="Time")
	static EDay GetCurrentDay();
	
	static TEnumAsByte<ECountry> CurrentCountry;

protected:
	static EDay CurrentDay;
};
