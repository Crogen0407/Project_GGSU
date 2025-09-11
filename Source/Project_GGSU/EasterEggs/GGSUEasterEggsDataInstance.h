// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUEasterEgg.h"
#include "GGSUEasterEggsDataInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUEasterEggsDataInstance : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void CollectEasterEgg(const FEasterEggData& EasterEggData);
	bool IsCollected(const FString& Name) const;
	FEasterEggData GetEasterEgg(const FString& Name) const;
	bool TryGetEasterEgg(const FString& Name, FEasterEggData& EasterEggData);
public:
	TMap<FString, FEasterEggData> FoundEasterEggs;
};
