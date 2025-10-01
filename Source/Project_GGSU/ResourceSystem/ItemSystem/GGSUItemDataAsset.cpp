#include "ResourceSystem/ItemSystem/GGSUItemDataAsset.h"

#include "GGSUItemEffect.h"
#include "BuildingSystem/GGSUBuilding.h"
#include "BuildingSystem/Utils/GGSUItemUseableBuilding.h"

UGGSUItemEffect* UGGSUItemDataAsset::GetEffect(UObject* Owner)
{
	UGGSUItemEffect* NewEffect = NewObject<UGGSUItemEffect>(Owner, ItemEffect);
	NewEffect->Setup(Owner, this);

	return NewEffect;
}

bool UGGSUItemDataAsset::IsCanUse_Implementation(AGGSUBuilding* Owner)
{
	const bool IsItemBuilding = Owner->Implements<IGGSUItemUseableBuilding>(); 
	return Owner != nullptr && IsItemBuilding;
}
