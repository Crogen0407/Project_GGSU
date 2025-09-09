// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"
#include "GGSUCropDataAsset.generated.h"

UCLASS()
class PROJECT_GGSU_API UGGSUCropDataAsset : public UGGSUResourceDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> StaticMeshes;
	
	UPROPERTY(EditAnywhere)
	FText DisplayName;
	
	UPROPERTY(EditAnywhere)
	FText Description;
	
	UPROPERTY(EditAnywhere, meta = (Units = "min"))
	float GrowthTime;
	
	UPROPERTY(EditAnywhere)
	FVector2D Size;
};