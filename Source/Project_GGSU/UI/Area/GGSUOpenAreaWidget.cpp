// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUOpenAreaWidget.h"

#include "BuildingSystem/AreaSystem/Area.h"

void UGGSUOpenAreaWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (BuyArea_Btn)
	{
		BuyArea_Btn->OnClicked.AddDynamic(this, &UGGSUOpenAreaWidget::OnBuyBtnClick);
	}
}

void UGGSUOpenAreaWidget::SettingUI(int price, AArea* owner)
{
	OwnerArea = owner;
	FText PriceText = FText::Format(FText::FromString(TEXT("{0}")), FText::AsNumber(price));
	Price_Txt->SetText(PriceText);
}

void UGGSUOpenAreaWidget::OnBuyBtnClick()
{
	OwnerArea->UnlockArea();
	//UE_LOG(LogTemp, Warning, TEXT("connect ui"));
}
