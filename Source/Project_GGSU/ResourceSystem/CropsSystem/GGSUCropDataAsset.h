// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DateSystem/GGSUDateManager.h"
#include "Engine/DataAsset.h"
#include "ResourceSystem/GGSUGradeResource.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"
#include "GGSUCropDataAsset.generated.h"

UCLASS()
class PROJECT_GGSU_API UGGSUCropDataAsset : public UGGSUResourceDataAsset, public IGGSUGradeResource
{
	GENERATED_BODY()

public:
	virtual int GetSellingPrice() override;

	UFUNCTION(BlueprintCallable, Category = "CropDataAsset")
	int GenerateAndPrintRandomNumbers(int Seed);
	
	UFUNCTION(BlueprintCallable)
	virtual EResourceGrade GetGrade() override
	{
		return CropGrade;
	}

protected:
	UPROPERTY(EditAnywhere)
	EResourceGrade CropGrade;
	
	UPROPERTY(Transient)
	FRandomStream RandomStream;
};