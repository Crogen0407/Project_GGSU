// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GGSUPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API AGGSUPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGGSUPlayerController();

	virtual FRotator GetControlRotation() const override;
};
