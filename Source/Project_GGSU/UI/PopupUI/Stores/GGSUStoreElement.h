// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUStoreElement.generated.h"

class UGGSUStoreProductsDataAsset;
class UGGSUCurrencyDataAsset;
class UGGSUResourceDataAsset;
class UGGSUStoreBuyMessageBox;
class UImage;
class UTextBlock;
class UButton;

UCLASS()
class PROJECT_GGSU_API UGGSUStoreElement : public UGGSUUserWidget
{
	GENERATED_BODY()

public:
	void Setup(UGGSUResourceDataAsset* TargetResourceDataAsset, int Price);
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
	UPROPERTY(EditAnywhere, Category=StoreElement)
	TSubclassOf<UGGSUStoreBuyMessageBox> StoreBuyMessageBoxClass;

	UPROPERTY(EditAnywhere, Category=StoreElement)
	TObjectPtr<UGGSUStoreProductsDataAsset> StoreProducts;
	
	UPROPERTY(EditAnywhere, Category=StoreElement)
	TObjectPtr<UGGSUCurrencyDataAsset> TargetCurrency;
	
public:
	UPROPERTY(Transient)
	UGGSUResourceDataAsset* CachedTargetItemDataAsset;
	
	int CachedPrice;
};
