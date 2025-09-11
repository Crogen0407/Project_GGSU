// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GGSUEasterEggPopup.h"

void UGGSUEasterEggPopup::Setup(FString Name, FString Description, TObjectPtr<UTexture2D> Icon)
{
	EasterEggName = Name;
	EasterEggDescription = Description;
	EasterEggIcon = Icon;
}
