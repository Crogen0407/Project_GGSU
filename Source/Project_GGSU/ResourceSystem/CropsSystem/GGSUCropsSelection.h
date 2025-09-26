
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUCropsSelection.generated.h"

class UGGSUCropSeedDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUCropsSelection : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void SetSelectedCropSeed(UGGSUCropSeedDataAsset* NewCropSeed);
	UGGSUCropSeedDataAsset* GetSelectedCropSeed() const;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UGGSUCropSeedDataAsset> SelectedCropSeed;
};
