// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUEasterEggPopup.generated.h"

struct FEasterEggData;
/**
 * 
 */
UCLASS(Blueprintable)
class PROJECT_GGSU_API UGGSUEasterEggPopup : public UGGSUUserWidget
{
	GENERATED_BODY()

public:
	void Setup(FEasterEggData EasterEggData);

	FString EasterEggName;
	FString EasterEggDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TObjectPtr<UTexture2D> EasterEggIcon;

public:
	UPROPERTY(meta=(BindWidget))
	class UImage* IconImage;
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TitleText;
	
	UPROPERTY(meta=(BindWidget))
	UTextBlock* DescriptionText;
};
