// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"
#include "GGSUCropDataAsset.generated.h"

UENUM(BlueprintType)
enum class ECropGrade : uint8
{
	D = 0,
	C = 1,
	B = 2,
	A = 3,
};

UCLASS()
class PROJECT_GGSU_API UGGSUCropDataAsset : public UGGSUResourceDataAsset
{
	GENERATED_BODY()

public:
	virtual int GetSellingPrice() override
	{
		return (static_cast<int>(CropGrade) + 1) * SellingPrice;
	}

	UPROPERTY(EditAnywhere)
	ECropGrade CropGrade;
};