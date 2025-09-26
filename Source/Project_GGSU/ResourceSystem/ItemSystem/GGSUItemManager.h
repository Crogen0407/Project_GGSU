// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GGSUItemManager.generated.h"

class UGGSUItemDataAsset;
class UGGSUItemEffect;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUItemManager : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(Transient)
	TSet<UGGSUItemEffect*> Effects;
};
