// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"
#include "GGSUItemDataAsset.generated.h"

class UGGSUItemEffect;

UCLASS()
class PROJECT_GGSU_API UGGSUItemDataAsset : public UGGSUResourceDataAsset
{
	GENERATED_BODY()

public:
	UGGSUItemEffect* GetEffect(UObject* Owner);
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGGSUItemEffect> ItemEffect;
	
};
