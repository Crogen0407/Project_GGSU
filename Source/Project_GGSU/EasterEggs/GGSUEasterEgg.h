// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingSystem/GGSUSelectableObject.h"
#include "GameFramework/Actor.h"
#include "GGSUEasterEgg.generated.h"

class UGGSUEasterEggPopup;
class UGGSUEasterEggsDataInstance;

USTRUCT(BlueprintType)
struct FEasterEggData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString EasterEggName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString EasterEggDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> EasterEggIcon;
};

UCLASS()
class PROJECT_GGSU_API AGGSUEasterEgg : public AActor, public IGGSUSelectableObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGSUEasterEgg();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void OnClicked() override;
	virtual void OnHovered() override;
	virtual void OnUnhovered() override;

private:
	UPROPERTY()
	TObjectPtr<UGGSUEasterEggsDataInstance> EasterEggsDataInstance;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	FEasterEggData EasterEggData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TSubclassOf<UGGSUEasterEggPopup> EasterEggPopupClass;
};
