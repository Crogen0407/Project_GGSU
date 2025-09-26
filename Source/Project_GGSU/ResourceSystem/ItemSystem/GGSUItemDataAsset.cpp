#include "ResourceSystem/ItemSystem/GGSUItemDataAsset.h"

#include "GGSUItemEffect.h"

UGGSUItemEffect* UGGSUItemDataAsset::GetEffect(UObject* Owner)
{
	UGGSUItemEffect* NewEffect = NewObject<UGGSUItemEffect>(Owner, ItemEffect);
	NewEffect->Setup(Owner, this);

	return NewEffect;
}