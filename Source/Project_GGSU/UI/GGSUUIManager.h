// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUUIManager.generated.h"

class UGGSUUserWidget;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUUIManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UGGSUUserWidget* ShowPopupUI(TSubclassOf<UGGSUUserWidget> UserWidgetClass);
	
	UFUNCTION(BlueprintCallable)
	void HidePopupUI(TSubclassOf<UGGSUUserWidget> UserWidgetClass);
	
private:
	UPROPERTY(Transient)
	TMap<TSubclassOf<UGGSUUserWidget>, UGGSUUserWidget*> WidgetInstances;
};
