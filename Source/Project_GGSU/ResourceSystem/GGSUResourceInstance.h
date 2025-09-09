// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUResourceInstance.generated.h"

UENUM()
enum EResourceType
{
	None = 0,
	Gold,
	
};

/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUResourceInstance : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:
	uint32 GetResource(EResourceType type) { return ResourceAmount[type]; }
	void AddResource(EResourceType type, uint32 value) { ResourceAmount[type] += value; }
	void RemoveResource(EResourceType type, uint32 value)
	{
		if (ResourceAmount[type] >= value)
			ResourceAmount[type] -= value;
	}
	bool TryRemoveResource(EResourceType type, uint32 value)
	{
		if (ResourceAmount[type] >= value)
		{
			ResourceAmount[type] -= value;
			return true;
		}
		return false;
	}
	
private:
	TMap<EResourceType, uint32> ResourceAmount;
};

