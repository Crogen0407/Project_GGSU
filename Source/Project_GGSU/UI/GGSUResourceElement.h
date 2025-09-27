// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUResourceElement.generated.h"

class UImage;
class UTextBlock;
class UGGSUResourceDataAsset;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUResourceElement : public UGGSUUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	
private:
	UFUNCTION()
	void HandleChangeAmountText(UGGSUResourceDataAsset* ResourceDataAsset, int CurrentAmount);
	
public:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* AmountText;

	UPROPERTY(meta=(BindWidget))
	UImage* Icon;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UGGSUResourceDataAsset> TargetResource;

};
