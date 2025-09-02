// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "GGSUBuilding.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class PROJECT_GGSU_API AGGSUBuilding : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGSUBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnClicked() override;
	virtual void OnHovered() override;
	virtual void OnUnhovered() override;
	virtual bool IsUnlocked() const override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Visual;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;
};
