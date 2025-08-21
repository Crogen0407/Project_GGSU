// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DateController.generated.h"

class UDirectionalLightComponent;

UCLASS()
class PROJECT_GGSU_API ADateController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADateController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Time")
	float Time;
	
private:
	UPROPERTY(VisibleAnywhere, Category="Components")
	UDirectionalLightComponent* DirectionalLightComponent;
};
