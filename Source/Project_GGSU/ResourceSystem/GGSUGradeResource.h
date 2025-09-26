// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GGSUGradeResource.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGGSUGradeResource : public UInterface
{
	GENERATED_BODY()
};

UENUM(BlueprintType)
enum class EResourceGrade : uint8
{
	D = 0,
	C = 1,
	B = 2,
	A = 3,
};

class PROJECT_GGSU_API IGGSUGradeResource
{
	GENERATED_BODY()

public:
	virtual EResourceGrade GetGrade() = 0;
};
