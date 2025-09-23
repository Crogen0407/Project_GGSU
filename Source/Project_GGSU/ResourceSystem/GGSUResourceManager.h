// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGSUResourceDataAsset.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUResourceManager.generated.h"

UENUM()
enum EResourceType
{
	None = 0,
	Gold,
	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FResourceChangedEvent, int, CurrentResourceAmount);

class UGGSUResourceDataAsset;
class UGGSUCropsSetDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUResourceManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UGGSUResourceManager();

	virtual ~UGGSUResourceManager() override;
	
public:
	// 생성 시점에 호출됨
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:
	UFUNCTION(BlueprintCallable)
	int GetResource(const UGGSUResourceDataAsset* type) { return ResourceAmount[type]; }
	void AddResource(const UGGSUResourceDataAsset* type, int value);
	void RemoveResource(const UGGSUResourceDataAsset* type, int value);
	bool TryRemoveResource(const UGGSUResourceDataAsset* type, int value);
	
public:
	UPROPERTY(EditAnywhere)
	TMap<UGGSUResourceDataAsset*, FResourceChangedEvent> ResourceChangedEvents;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGGSUCropsSetDataAsset> CropsSetDataAsset;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<UGGSUResourceDataAsset*, int> ResourceAmount;
};

