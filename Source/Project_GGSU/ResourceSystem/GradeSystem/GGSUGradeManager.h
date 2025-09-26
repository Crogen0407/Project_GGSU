// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ResourceSystem/GGSUGradeResource.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUGradeManager.generated.h"

class UGGSUColorPalette;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUGradeManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UGGSUGradeManager();
	virtual  ~UGGSUGradeManager() override;
	
public:
	FColor GetGradeColor(EResourceGrade Grade) const;
	
private:
	UPROPERTY(Transient)
	TObjectPtr<UGGSUColorPalette> CachedGradeColorPalette;
};
