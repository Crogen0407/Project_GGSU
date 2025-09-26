// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceSystem/ItemSystem/GGSUItemManager.h"

#include "GGSUItemEffect.h"

void UGGSUItemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (UGGSUItemEffect* Effect : Effects)
	{
		if (Effect)
			Effect->Tick(DeltaTime);
	}
}

ETickableTickType UGGSUItemManager::GetTickableTickType() const
{
	return ETickableTickType::Always;
}

TStatId UGGSUItemManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UMyWorldSubsystem, STATGROUP_Tickables);
}
