#include "ResourceSystem/ItemSystem/GGSUItemEffect.h"

#include "GGSUItemManager.h"

void UGGSUItemEffect::Setup_Implementation(UObject* Owner, UGGSUItemDataAsset* ItemDataAsset)
{
	CachedItemDataAsset = ItemDataAsset;
	if (UGGSUItemManager* ItemManager = GetWorld()->GetSubsystem<UGGSUItemManager>())
	{
		UE_LOG(LogTemp, Log, TEXT("Setup Effect"));
		ItemManager->Effects.Add(this);
	}
}

void UGGSUItemEffect::Tick_Implementation(float DeltaTime)
{
	
}

void UGGSUItemEffect::Release_Implementation()
{
	if (UGGSUItemManager* ItemManager = GetWorld()->GetSubsystem<UGGSUItemManager>())
	{
		UE_LOG(LogTemp, Log, TEXT("Release Effect"));
		ItemManager->Effects.Remove(this);
	}
}
