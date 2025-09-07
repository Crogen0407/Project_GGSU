#pragma once

#include "CoreMinimal.h"
#include "BuildingSystem/GGSUBuilding.h"
#include "GGSUUIOpenBuilding.generated.h"

class UGGSUUserWidget;
/**
 * 
 */
UCLASS()
class PROJECT_GGSU_API AGGSUUIOpenBuilding : public AGGSUBuilding
{
	GENERATED_BODY()

public:
	virtual void OnClicked() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	TSubclassOf<UGGSUUserWidget> UIClass;

private:
	UPROPERTY(Transient)
	TObjectPtr<UGGSUUserWidget> CachedUIInstance;
};
