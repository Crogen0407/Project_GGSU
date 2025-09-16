// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GGSUUserWidget.generated.h"

class UGGSUPresenterBase;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GGSUUserWidget")
	void Show(float Duration);

	void Show_Implementation(float Duration);
	
	UFUNCTION(BlueprintCallable)
	virtual void Hide(float Duration);

private:
	bool IsFade = false;
	float FadeDuration = 0.f;
	float TargetOpacity = 0.f;
	float OpacityTimer = 0.f;
};
