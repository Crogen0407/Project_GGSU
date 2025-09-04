// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GGSUUserWidget.generated.h"

class UGGSUPresenterBase;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUUserWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;
};
