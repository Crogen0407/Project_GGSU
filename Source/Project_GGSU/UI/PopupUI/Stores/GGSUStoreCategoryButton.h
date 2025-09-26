// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GGSUStoreCategoryButton.generated.h"

class UButton;
class UTextBlock;

DECLARE_DELEGATE(FClickedEvent)

UCLASS()
class PROJECT_GGSU_API UGGSUStoreCategoryButton : public UUserWidget
{
	GENERATED_BODY()

public:
	void Setup();
	
private:
	UFUNCTION()
	void HandleClick();

public:
	FClickedEvent OnClicked;
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> CategoryNameText;
};
