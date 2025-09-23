// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUStorePopup.generated.h"

class UHorizontalBox;
class UGGSUItemDataAsset;
class UGGSUStoreProductsDataAsset;
class UGGSUStoreElement;

UCLASS()
class PROJECT_GGSU_API UGGSUStorePopup : public UGGSUUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UHorizontalBox> StoreElementList;
	
private:
	UPROPERTY(Transient)
	TMap<UGGSUItemDataAsset*, UGGSUStoreElement*> StoreElements;
	
public:
	UPROPERTY(EditAnywhere, Category="StorePopup")
	TSubclassOf<UGGSUUserWidget> StoreElementClass;  
	
	UPROPERTY(EditAnywhere, Category="StorePopup")
	TObjectPtr<UGGSUStoreProductsDataAsset> StoreProductsDataAsset;
};
