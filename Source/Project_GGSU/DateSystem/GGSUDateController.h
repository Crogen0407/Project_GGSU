// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGSUDateController.generated.h"

class UDirectionalLightComponent;

UCLASS()
class PROJECT_GGSU_API AGGSUDateController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGSUDateController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintPure, Category="Time")
	static float GetTime()
	{
		return Time;
	}

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Time")
	float TimeSpeed = 10.f;
	
private:
	static float Time;
	
private:
	UPROPERTY(VisibleAnywhere, Category="Components")
	UDirectionalLightComponent* DirectionalLightComponent;
};
