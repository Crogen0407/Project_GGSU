// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "GGSUSellSlot.generated.h"

class UGGSUStoreProductsDataAsset;
class UGGSUCurrencyDataAsset;
class UGGSUResourceManager;
class UGGSUResourceDataAsset;
enum class EResourceGrade : uint8;
class UImage;
class UBorder;
class UTextBlock;
class UButton;

UCLASS()
class PROJECT_GGSU_API UGGSUSellSlot : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	void SetGrade(const EResourceGrade Grade) const;

private:
	UFUNCTION()
	void HandleSellTargetResource();

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> SellButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> CountText;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> IconImage;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UBorder> GradeIcon;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> GradeText;

protected:
	UPROPERTY(EditAnywhere, Category=SellSlot)
	TObjectPtr<UGGSUStoreProductsDataAsset> StoreProducts;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=SellSlot)
	TObjectPtr<UGGSUCurrencyDataAsset> TargetCurrency;
	
private:
	UPROPERTY(Transient)
	TObjectPtr<UGGSUResourceManager> CachedResourceManager;
	
	UPROPERTY(Transient)
	TObjectPtr<UGGSUResourceDataAsset> CachedTargetResource;

	int CachedCount;
};
