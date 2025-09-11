// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GGSUEasterEggPopup.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "EasterEggs/GGSUEasterEgg.h"

void UGGSUEasterEggPopup::Setup(FEasterEggData EasterEggData)
{
	EasterEggName = EasterEggData.EasterEggName;
	EasterEggDescription = EasterEggData.EasterEggDescription;
	EasterEggIcon = EasterEggData.EasterEggIcon;
}

void UGGSUEasterEggPopup::Show(float Duration)
{
	Super::Show(Duration);

	TitleText->SetText(FText::FromString(EasterEggName));
	DescriptionText->SetText(FText::FromString(EasterEggDescription));
	IconImage->SetBrushFromTexture(EasterEggIcon);
}
