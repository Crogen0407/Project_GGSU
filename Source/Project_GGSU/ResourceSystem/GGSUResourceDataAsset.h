// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GGSUResourceDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUResourceDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> IconTexture;
	
	UPROPERTY(EditAnywhere)
	FName Name;
};
