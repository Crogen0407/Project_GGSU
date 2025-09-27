// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUCropIcon.generated.h"

class UTextBlock;
class UButton;
class UImage;
class UGGSUCropSeedDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUCropIcon : public UGGSUUserWidget
{
	GENERATED_BODY()

public:
	void SetTargetCropSeed(UGGSUCropSeedDataAsset* InCropSeed);

	UFUNCTION()
	void HandleSelectTargetCrop();

	void SetCount(int Count);
	
public:
	UPROPERTY(Transient, BlueprintReadOnly)
	TObjectPtr<UGGSUCropSeedDataAsset> TargetCrop;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UImage* IconImage;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UButton* Button;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* CountText;
};
