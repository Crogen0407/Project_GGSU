// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUEasterEggsManager.h"

void UGGSUEasterEggsManager::CollectEasterEgg(const FEasterEggData& EasterEggData)
{
	FoundEasterEggs.Add(EasterEggData.EasterEggName, EasterEggData);
}

bool UGGSUEasterEggsManager::IsCollected(const FString& Name) const
{
	return FoundEasterEggs.Contains(Name);
}

FEasterEggData UGGSUEasterEggsManager::GetEasterEgg(const FString& Name) const
{
	if (IsCollected(Name))
		return FoundEasterEggs[Name];
	else
		return {};
}

bool UGGSUEasterEggsManager::TryGetEasterEgg(const FString& Name, FEasterEggData& EasterEggData)
{
	if (IsCollected(Name))
	{
		EasterEggData = FoundEasterEggs[Name];
		return true;
	}
	else
	{
		EasterEggData = {};
		return false;
	}
}
