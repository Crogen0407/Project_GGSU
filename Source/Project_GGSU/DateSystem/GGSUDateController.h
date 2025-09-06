// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGSUDateController.generated.h"

class UDirectionalLightComponent;

UENUM(BlueprintType, Blueprintable)
enum ECountry
{
	Seoul = 9,
	Tokyo = 9,
	London = 0,
	Washington = -5,
	LandBerlin = 1,
};


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
	static FDateTime GetTime()
	{
		return Time;
	}

private:
	static FDateTime Time;

public:
	UPROPERTY(EditAnywhere, Category="Country")
	TEnumAsByte<ECountry> CurrentCountry;
	
private:
	UPROPERTY(VisibleAnywhere, Category="Lights")
	USceneComponent* LightSceneComponent;	
	
	UPROPERTY(VisibleAnywhere, Category="Lights")
	UDirectionalLightComponent* SunDirectionalLightComponent;

	UPROPERTY(VisibleAnywhere, Category="Lights")
	UDirectionalLightComponent* MoonDirectionalLightComponent;
};
