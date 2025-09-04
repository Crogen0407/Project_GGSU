// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ResourceSystem/GGSUResourceInstance.h"
#include "Area.generated.h"

class AGGSUBuilding;

UCLASS()
class PROJECT_GGSU_API AArea : public AActor
{
	GENERATED_BODY()
	
public:	
	AArea();

protected:
	virtual void BeginPlay() override;

public:
	// 구역 해금
	bool UnlockArea();

protected:
	// 구역 해금 비용
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Area")
	int32 UnlockCost;

	// 구역의 모든 땅
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Area")
	TArray<AGGSUBuilding*> Buildings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Area")
	UGGSUResourceInstance* ResourceInstance;
};
