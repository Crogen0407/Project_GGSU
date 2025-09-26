#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GGSUResourceDataAsset.generated.h"

UCLASS()
class PROJECT_GGSU_API UGGSUResourceDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual int GetSellingPrice() { return SellingPrice; }
	virtual TObjectPtr<UTexture2D> GetIconTexture() { return IconTexture; }
	virtual FName GetName() { return Name; }
	virtual FString GetDescription() { return Description; }
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> IconTexture;
	
	UPROPERTY(EditAnywhere)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SellingPrice;
};
