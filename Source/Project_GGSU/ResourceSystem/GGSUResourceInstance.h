// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGSUResourceDataAsset.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUResourceInstance.generated.h"

UENUM()
enum EResourceType
{
	None = 0,
	Gold,
	
};

class UGGSUResourceDataAsset;
class UGGSUCropsSetDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUResourceInstance : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UGGSUResourceInstance();

	virtual ~UGGSUResourceInstance() override;
	
public:
	// 생성 시점에 호출됨
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:
	UFUNCTION(BlueprintCallable)
	int GetResource(const UGGSUResourceDataAsset* type) { return ResourceAmount[type]; }
	void AddResource(const UGGSUResourceDataAsset* type, int value) { ResourceAmount[type] += value; }
	void RemoveResource(const UGGSUResourceDataAsset* type, int value)
	{
		if (ResourceAmount[type] >= value)
			ResourceAmount[type] -= value;
	}
	bool TryRemoveResource(const UGGSUResourceDataAsset* type, int value)
	{
		if (ResourceAmount.Contains(type) == false)
		{
			return false;
		}
		
		if (ResourceAmount[type] >= value)
		{
			ResourceAmount[type] -= value;
			return true;
		}
		return false;
	}
	
public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGGSUCropsSetDataAsset> CropsSetDataAsset;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<UGGSUResourceDataAsset*, int> ResourceAmount;
};

