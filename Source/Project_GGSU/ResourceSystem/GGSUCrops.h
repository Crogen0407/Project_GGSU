// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGSUCrops.generated.h"

class UGGSUCropDataAsset;

UCLASS()
class PROJECT_GGSU_API AGGSUCrops : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGSUCrops();

public:
	virtual void Initialize(UGGSUCropDataAsset* CropsDataAsset);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UStaticMesh* GetCurrentStaticMesh() const;

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComp;
	int32 MeshCount;

public:
	float SpawnTime;
	float Age;

public:
	UPROPERTY(Transient)
	TObjectPtr<UGGSUCropDataAsset> CachedCropsDataAsset;
};
