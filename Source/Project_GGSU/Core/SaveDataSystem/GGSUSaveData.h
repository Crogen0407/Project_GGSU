// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DateSystem/GGSUDateManager.h"
#include "GameFramework/SaveGame.h"
#include "GGSUSaveData.generated.h"

UCLASS()
class PROJECT_GGSU_API UGGSUSaveData : public USaveGame
{
	GENERATED_BODY()
	
	UGGSUSaveData();
	
	// User
public:
	UPROPERTY(VisibleAnywhere, Category=SaveData)
	FString PlayerName;
	
	UPROPERTY(VisibleAnywhere, Category=SaveData)
	TEnumAsByte<ECountry> PlayerCountry;
};
