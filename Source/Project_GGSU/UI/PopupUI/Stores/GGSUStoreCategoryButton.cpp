// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PopupUI/Stores/GGSUStoreCategoryButton.h"

#include "Components/Button.h"

void UGGSUStoreCategoryButton::Setup()
{
	Button->OnClicked.AddDynamic(this, &UGGSUStoreCategoryButton::HandleClick);
}

void UGGSUStoreCategoryButton::HandleClick()
{
	OnClicked.Execute();
}
