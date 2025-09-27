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

void UGGSUOpenAreaWidget::Setup(const int Price, AArea* Owner)
{
	OwnerArea = Owner;
	const FText PriceText = FText::Format(FText::FromString(TEXT("{0}")), FText::AsNumber(Price));
	Price_Txt->SetText(PriceText);
}

void UGGSUOpenAreaWidget::OnBuyBtnClick()
{
	OwnerArea->UnlockArea();
}
