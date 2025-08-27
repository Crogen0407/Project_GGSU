// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GGSUInputMapperComponent.generated.h"

class UInputComponent;
class UGGSUPlayerMovementComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECT_GGSU_API UGGSUInputMapperComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGGSUInputMapperComponent();

	// Pawn에서 호출할 입력 설정 함수
	void SetupPlayerInput(UInputComponent* PlayerInputComponent);

	// Pawn이 직접 MovementComponent를 설정해주는 함수
	void SetMovementComponent(UGGSUPlayerMovementComponent* InMovementComponent);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<UGGSUPlayerMovementComponent> CachedMovementComponent;

	void InitializeDefaultPawnInputBindings();
	void MoveForward(float Val);
	void MoveRight(float Val);
};
