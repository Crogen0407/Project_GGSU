// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUEasterEggPopup.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUEasterEggPopup : public UGGSUUserWidget
{
	GENERATED_BODY()

public:
	void Setup(FString Name, FString Description, TObjectPtr<UTexture2D> Icon);

public:
	FString EasterEggName;
	FString EasterEggDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TObjectPtr<UTexture2D> EasterEggIcon;
};
