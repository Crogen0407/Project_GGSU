// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"
#include "GGSUCropsGradeSetDataAsset.generated.h"

class UGGSUCropDataAsset;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUCropsGradeSetDataAsset : public UGGSUResourceDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<UGGSUCropDataAsset*, float> CropsList;
	
};
