// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GGSUColorPalette.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUColorPalette : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<FColor> Colors;
};
