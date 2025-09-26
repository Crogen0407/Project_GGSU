// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUMessageBox.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUMessageBox : public UGGSUUserWidget
{
	GENERATED_BODY()

public:
	virtual void Setup(const FText& Text);
	void AddButton(const FText& Text, const TFunction<void()>& ClickCallback);

protected:
	UPROPERTY()
	int32 ButtonCount;
	
	TFunction<void()> FirstButtonClickCallback;
	TFunction<void()> SecondButtonClickCallback;

	UFUNCTION()
	virtual void OnFirstButtonClicked() { FirstButtonClickCallback(); }
	UFUNCTION()
	virtual void OnSecondButtonClicked() { SecondButtonClickCallback(); }
	
public:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TitleText;
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* FirstButtonText;
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* SecondButtonText;
	
	UPROPERTY(meta=(BindWidget))
	class UButton* FirstButton;
	
	UPROPERTY(meta=(BindWidget))
	class UButton* SecondButton;
};
