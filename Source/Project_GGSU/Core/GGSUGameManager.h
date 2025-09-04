// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUGameManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameStartEvent);

UCLASS()
class PROJECT_GGSU_API UGGSUGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void GameStart();
	
public:
	FGameStartEvent* GameStartEvent;
};
