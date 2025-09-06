// Fill out your copyright notice in the Description page of Project Settings.


#include "DateSystem/GGSUDateManager.h"

TEnumAsByte<ECountry> UGGSUDateManager::CurrentCountry = Seoul;

FDateTime UGGSUDateManager::GetTime()
{
	return FDateTime::UtcNow() + FTimespan::FromHours(CurrentCountry.GetIntValue());
}
