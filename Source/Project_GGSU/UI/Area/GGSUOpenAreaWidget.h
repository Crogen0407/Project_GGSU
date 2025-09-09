// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "GGSUOpenAreaWidget.generated.h"
class AArea;

UCLASS()
class PROJECT_GGSU_API UGGSUOpenAreaWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
public:
	UFUNCTION()
	void OnBuyBtnClick();
	
	void SettingUI(int price, AArea* owner);
protected:
	UPROPERTY(meta = (BindWidget))
	class UButton* BuyArea_Btn;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Price_Txt;
public:
	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	AArea* OwnerArea;
};
