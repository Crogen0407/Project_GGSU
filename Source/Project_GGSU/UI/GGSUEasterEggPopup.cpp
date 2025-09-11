// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GGSUEasterEggPopup.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"

void UGGSUEasterEggPopup::Setup(FString Name, FString Description, TObjectPtr<UTexture2D> Icon)
{
	EasterEggName = Name;
	EasterEggDescription = Description;
	EasterEggIcon = Icon;
}

void UGGSUEasterEggPopup::Show(float Duration)
{
	Super::Show(Duration);

	TitleText->SetText(FText::FromString(EasterEggName));
	DescriptionText->SetText(FText::FromString(EasterEggDescription));
	IconImage->SetBrushFromTexture(EasterEggIcon);
}
