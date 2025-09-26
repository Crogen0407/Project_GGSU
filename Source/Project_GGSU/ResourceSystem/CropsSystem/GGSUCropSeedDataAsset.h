#pragma once

#include "CoreMinimal.h"
#include "GGSUCropDataAsset.h"
#include "GGSUCropSeedDataAsset.generated.h"

UCLASS()
class PROJECT_GGSU_API UGGSUCropSeedDataAsset : public UGGSUResourceDataAsset
{
	GENERATED_BODY()

public:
	virtual UGGSUCropDataAsset* GetCrop(const ECropGrade CropGrade) const
	{
		return Crops[CropGrade];
	}

	virtual float GetGrowthTime() const
	{
		return GrowthTime;	
	}

	virtual TArray<UStaticMesh*> GetStaticMeshes() const
	{
		return StaticMeshes;
	}
	
protected:
	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> StaticMeshes;

	UPROPERTY(EditAnywhere, meta = (Units = "min"))
	float GrowthTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<ECropGrade, UGGSUCropDataAsset*> Crops;
};
