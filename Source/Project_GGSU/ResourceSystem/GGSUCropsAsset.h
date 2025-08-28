// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GGSUCropsAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUCropsAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UStaticMesh* StaticMesh;
	
	UPROPERTY(EditAnywhere)
	FName Name;
	
	UPROPERTY(EditAnywhere)
	FText DisplayName;
	
	UPROPERTY(EditAnywhere)
	FText Description;
	
	UPROPERTY(EditAnywhere)
	float GrowthTime;
};
