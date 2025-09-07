// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUCropIcon.generated.h"

class UButton;
class UImage;
class UGGSUCropDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUCropIcon : public UGGSUUserWidget
{
	GENERATED_BODY()

public:
	void SetTargetCrop(UGGSUCropDataAsset* InCrop);

	UFUNCTION()
	void HandleSelectTargetCrop(); 
	
public:
	UPROPERTY(Transient, BlueprintReadOnly)
	TObjectPtr<UGGSUCropDataAsset> TargetCrop;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UImage* IconImage;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UButton* Button;
};
