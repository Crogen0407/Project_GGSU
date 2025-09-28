// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"
#include "GGSUItemDataAsset.generated.h"

class AGGSUBuilding;
class UGGSUItemEffect;

UCLASS()
class PROJECT_GGSU_API UGGSUItemDataAsset : public UGGSUResourceDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category=ItemDataAsset)
	UGGSUItemEffect* GetEffect(UObject* Owner);

	UFUNCTION(BlueprintNativeEvent, Category=ItemDataAsset)
	bool IsCanUse(AGGSUBuilding* Owner);
	virtual bool IsCanUse_Implementation(AGGSUBuilding* Owner);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ItemDataAsset)
	TSubclassOf<UGGSUItemEffect> ItemEffect;
};
