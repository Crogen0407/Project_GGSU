// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUSellPopup.generated.h"

enum class EResourceGrade : uint8;
class UGGSUResourceManager;
class UGGSUResourceDataAsset;
class UTileView;
class UButton;

UCLASS()
class PROJECT_GGSU_API UGGSUSellPopup : public UGGSUUserWidget
{
	GENERATED_BODY()

public:
	virtual void Show_Implementation(float Duration) override;
	
protected:
	virtual void NativeOnInitialized() override;

private:
	void LoadInventory();
	
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTileView> SellView;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UGGSUResourceManager> CachedResourceManager;
};
