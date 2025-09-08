// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGSUSelectableObject.h"
#include "GameFramework/Actor.h"
#include "GGSUBuilding.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class PROJECT_GGSU_API AGGSUBuilding : public AActor, public IGGSUSelectableObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGSUBuilding();

	virtual ~AGGSUBuilding() override {}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:	
	virtual void OnClicked() override;
	virtual void OnHovered() override;
	virtual void OnUnhovered() override;
	void OnUnlock();

public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Visual;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere)
	bool IsUnlocked = false;
};
