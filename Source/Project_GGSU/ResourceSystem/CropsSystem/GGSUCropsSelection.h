
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUCropsSelection.generated.h"

class UGGSUCropDataAsset;

UCLASS()
class PROJECT_GGSU_API UGGSUCropsSelection : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void SetSelectedCrop(UGGSUCropDataAsset* NewCropDataAsset);
	UGGSUCropDataAsset* GetSelectedCrop() const;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UGGSUCropDataAsset> SelectedCropDataAsset;
};
