// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GGSUUserWidget.h"
#include "GGSUInventoryPopup.generated.h"

class UGGSUResourceDataAsset;

UCLASS(BlueprintType)
class PROJECT_GGSU_API UGGSUInventoryElementObject : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* IconTexture;
};

class UTileView;

UCLASS()
class PROJECT_GGSU_API UGGSUInventoryPopup : public UGGSUUserWidget
{
	GENERATED_BODY()

public:
	virtual void Show_Implementation(float Duration) override;
	virtual void Hide(float Duration) override;

	void AddElement(UGGSUResourceDataAsset* TargetResource, int Count);
	
public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTileView> InventoryView;
	
};
