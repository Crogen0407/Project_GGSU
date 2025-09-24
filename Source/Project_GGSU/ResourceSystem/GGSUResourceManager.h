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
class UGGSUResourceSetDataAsset;

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
	int GetResource(const UGGSUResourceDataAsset* Type) { return ResourceAmount[Type]; }
	void AddResource(const UGGSUResourceDataAsset* Type, int Value);
	void RemoveResource(const UGGSUResourceDataAsset* Type, int Value);
	bool TryRemoveResource(const UGGSUResourceDataAsset* Type, int Value);
	
public:
	UPROPERTY(EditAnywhere)
	TMap<UGGSUResourceDataAsset*, FResourceChangedEvent> ResourceChangedEvents;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGGSUResourceSetDataAsset> CropsSetDataAsset;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<UGGSUResourceDataAsset*, int> ResourceAmount;
};

