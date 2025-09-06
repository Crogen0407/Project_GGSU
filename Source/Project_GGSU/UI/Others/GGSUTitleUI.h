// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUTitleUI.generated.h"

class UCanvasPanel;
class UBackgroundBlur;

UCLASS()
class PROJECT_GGSU_API UGGSUTitleUI : public UGGSUUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

public:
	UFUNCTION(BlueprintNativeEvent, Category="Handle")
	void HandleGameStart();
	
	void HandleGameStart_Implementation();
	
public:
	UPROPERTY(meta=(BindWidget), BlueprintReadOnly)
	UBackgroundBlur* BackgroundBlur;

	UPROPERTY(meta=(BindWidget), BlueprintReadOnly)
	UCanvasPanel* TitleGroup;
};
