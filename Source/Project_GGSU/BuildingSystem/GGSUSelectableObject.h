// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GGSUSelectableObject.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGGSUSelectableObject : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECT_GGSU_API IGGSUSelectableObject
{
	GENERATED_BODY()

public:
	virtual void OnClicked() = 0;

	virtual void OnHovered() = 0;

	virtual void OnUnhovered() = 0;
};
