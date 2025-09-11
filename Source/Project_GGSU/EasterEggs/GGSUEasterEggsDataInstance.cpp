// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUEasterEggsDataInstance.h"

void UGGSUEasterEggsDataInstance::CollectEasterEgg(const FEasterEggData& EasterEggData)
{
	FoundEasterEggs.Add(EasterEggData.EasterEggName, EasterEggData);
}

bool UGGSUEasterEggsDataInstance::IsCollected(const FString& Name) const
{
	return FoundEasterEggs.Contains(Name);
}

FEasterEggData UGGSUEasterEggsDataInstance::GetEasterEgg(const FString& Name) const
{
	if (IsCollected(Name))
		return FoundEasterEggs[Name];
	else
		return {};
}

bool UGGSUEasterEggsDataInstance::TryGetEasterEgg(const FString& Name, FEasterEggData& EasterEggData)
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
