// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "ResourceSystem/GGSUGradeResource.h"
#include "GGSUInventorySlot.generated.h"

class UBorder;
class UImage;
class UTextBlock;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API UGGSUInventorySlot : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	void SetGrade(const EResourceGrade Grade) const;

public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> CountText;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> IconImage;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UBorder> GradeIcon;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> GradeText;
};
