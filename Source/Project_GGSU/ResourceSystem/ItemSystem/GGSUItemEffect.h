#pragma once

#include "CoreMinimal.h"
#include "GGSUItemEffect.generated.h"

class UGGSUItemDataAsset;

UCLASS(Blueprintable)
class PROJECT_GGSU_API UGGSUItemEffect : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category=ItemEffect)
	void Setup(UObject* Owner, UGGSUItemDataAsset* ItemDataAsset);
	virtual void Setup_Implementation(UObject* Owner, UGGSUItemDataAsset* ItemDataAsset)
	{
		CachedItemDataAsset = ItemDataAsset;
	}

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category=ItemEffect)
	void Tick(float DeltaTime);
	virtual void Tick_Implementation(float DeltaTime) {}

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category=ItemEffect)
	void Release();
	virtual void Release_Implementation() {}

public:
	UPROPERTY(Transient)
	TObjectPtr<UGGSUItemDataAsset> CachedItemDataAsset;
};
 