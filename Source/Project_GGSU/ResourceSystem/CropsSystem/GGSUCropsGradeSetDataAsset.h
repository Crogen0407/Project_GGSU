#pragma once

#include "CoreMinimal.h"
#include "GGSUCropDataAsset.h"
#include "GGSUCropsGradeSetDataAsset.generated.h"

UCLASS()
class PROJECT_GGSU_API UGGSUCropsGradeSetDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UGGSUCropDataAsset* GetCrop(const EResourceGrade CropGrade)
	{
		return Crops[CropGrade];
	}
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<EResourceGrade, UGGSUCropDataAsset*> Crops;
};
