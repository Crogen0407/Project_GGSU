// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GGSUPlayerMovementComponent.generated.h"

class AGGSUPlayerPawn;

UCLASS()
class PROJECT_GGSU_API UGGSUPlayerMovementComponent : public UFloatingPawnMovement
{
	GENERATED_BODY()

public:
	void MoveRight(float Val);
	void MoveForward(float Val);

private:
	void AddMovementInput(FVector WorldDirection, float ScaleValue = 1.0f, bool bForce = false);
	
protected:
	UPROPERTY(Transient)
	TObjectPtr<AGGSUPlayerPawn> PlayerPawnOwner;
};
