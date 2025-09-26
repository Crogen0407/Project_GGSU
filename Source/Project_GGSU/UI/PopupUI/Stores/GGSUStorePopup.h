// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUStorePopup.generated.h"

class UGGSUStoreCategory;
class UGGSUStoreCategoryButton;
class UWidgetSwitcher;
class UHorizontalBox;
class UGGSUItemDataAsset;
class UGGSUStoreProductsDataAsset;
class UGGSUStoreElement;

UCLASS(Blueprintable)
class PROJECT_GGSU_API UGGSUStorePopup : public UGGSUUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UHorizontalBox> StoreCategoryButtons;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UWidgetSwitcher> StoreCategorySwitcher;
	
public:
	UPROPERTY(EditAnywhere, Category="StorePopup")
	TSubclassOf<UGGSUUserWidget> StoreElementClass;  

	UPROPERTY(EditAnywhere, Category="StorePopup")
	TSubclassOf<UGGSUStoreCategory> StoreCategoryClass;
	
	UPROPERTY(EditAnywhere, Category="StorePopup")
	TSubclassOf<UGGSUStoreCategoryButton> StoreCategoryButtonClass;
	
public:
	UPROPERTY(EditAnywhere, Category="StorePopup")
	TObjectPtr<UGGSUStoreProductsDataAsset> StoreProductsDataAsset;

private:
	int CachedCategoryIndex;
};
