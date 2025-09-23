// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GGSUStoreCategory.generated.h"

class UHorizontalBox;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUStoreCategory : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UHorizontalBox> StoreElementList;
};
