// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UObject/ScriptInterface.h" // Required for TScriptInterface
#include "GGSUSelectSubSystem.generated.h"

class IGGSUSelectableObject;
/**
 * 
 */

DECLARE_MULTICAST_DELEGATE_OneParam(FSelectedObjectChangedDelegate, IGGSUSelectableObject* SelectableObject);

UCLASS()
class PROJECT_GGSU_API UGGSUSelectSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	void SetSelectedObject(IGGSUSelectableObject* SelectableObject);

public:
	FSelectedObjectChangedDelegate OnSelectedObjectChanged;
	
private:
	UPROPERTY(Transient)
	TScriptInterface<IGGSUSelectableObject> SelectedObject;
};
