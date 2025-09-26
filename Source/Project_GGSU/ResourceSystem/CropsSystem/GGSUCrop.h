// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGSUCrop.generated.h"

class UGGSUCropSeedDataAsset;

UCLASS()
class PROJECT_GGSU_API AGGSUCrop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGSUCrop();

public:
	virtual void Initialize(UGGSUCropSeedDataAsset* CropSeed);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UStaticMesh* GetCurrentStaticMesh() const;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	uint32 MeshCount;
	
public:
	FDateTime SpawnTime;
	FTimespan Age;

public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGGSUCropSeedDataAsset> CachedCropSeed;
};
