// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGSUSelectableObject.h"
#include "GameFramework/Actor.h"
#include "GGSUBuilding.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenBuildingEvent);

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

public:
	virtual void OnUnlock();
	virtual void Disable();
	virtual void Enable();

public:
	UPROPERTY(VisibleAnywhere, Category=Building)
	UStaticMeshComponent* Visual;

	UPROPERTY(VisibleAnywhere, Category=Building)
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category=Building)
	bool IsUnlocked = false;

	UPROPERTY(BlueprintAssignable, Category=Building)
	FOpenBuildingEvent OpenBuildingEvent;
};
