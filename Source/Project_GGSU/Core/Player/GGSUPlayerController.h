// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GGSUPlayerController.generated.h"

/**
 * 
 */

class AGGSUBuilding;

UCLASS()
class PROJECT_GGSU_API AGGSUPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGGSUPlayerController();

protected:
	virtual void SetupInputComponent() override;

public:
	virtual void Tick(float DeltaSeconds) override;

public:
	void HandlePressed();
	void HandleReleased();
	
	virtual FRotator GetControlRotation() const override;
	void Select() const;
	void Deselect();
	void BuildingSelect(AGGSUBuilding* Building) const;
	
private:
	// 레이의 최대 사정거리
	float TraceDistance = 10000.0f;
	bool IsSelecting = false;
};
