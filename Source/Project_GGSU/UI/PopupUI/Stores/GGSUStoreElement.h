// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUStoreElement.generated.h"

class UImage;
class UTextBlock;
class UButton;
class UGGSUItemDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUStoreElement : public UGGSUUserWidget
{
	GENERATED_BODY()

public:
	void Setup(UGGSUItemDataAsset* TargetItemDataAsset, int Price);
	UFUNCTION()
	void HandleBuyItem();
	
public:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* TitleText;
	
	UPROPERTY(meta=(BindWidget))
	UButton* BuyButton;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* PriceText;
	
	UPROPERTY(meta=(BindWidget))
	UImage* IconImage;
	
public:
	UPROPERTY(Transient)
	UGGSUItemDataAsset* CachedTargetItemDataAsset;
};
