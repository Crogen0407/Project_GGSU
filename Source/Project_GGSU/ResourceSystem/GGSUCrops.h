// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGSUCropsAsset.h"
#include "GameFramework/Actor.h"
#include "GGSUCrops.generated.h"

UCLASS()
class PROJECT_GGSU_API AGGSUCrops : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGSUCrops();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	UGGSUCropsAsset* CropsDataAsset;
};
