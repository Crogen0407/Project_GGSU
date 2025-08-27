// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GGSUPlayerPawn.generated.h"

class UGGSUInputMapperComponent;
class USpringArmComponent;
class UCameraComponent;
class UGGSUPlayerMovementComponent;

UCLASS()
class PROJECT_GGSU_API AGGSUPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	AGGSUPlayerPawn();

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	USpringArmComponent* CameraBoomComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Movement)
	UGGSUPlayerMovementComponent* MovementComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	UGGSUInputMapperComponent* InputMapperComponent;
};
