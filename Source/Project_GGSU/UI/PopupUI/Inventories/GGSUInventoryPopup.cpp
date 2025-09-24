#include "UI/PopupUI/Inventories/GGSUInventoryPopup.h"
#include "Components/TileView.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"
#include "ResourceSystem/GGSUResourceManager.h"

void UGGSUInventoryPopup::Show_Implementation(float Duration)
{
	Super::Show_Implementation(Duration);
	
	InventoryView->ClearListItems();
	
	if (const UGGSUResourceManager* ResourceManager = GetGameInstance()->GetSubsystem<UGGSUResourceManager>())
	{
		for (auto ResourcePair : ResourceManager->ResourceAmount)
		{
			if (ResourcePair.Key->IsInventoryElement)
				AddElement(ResourcePair.Key, ResourcePair.Value);
		}
	}
}

void UGGSUInventoryPopup::Hide(float Duration)
{
	Super::Hide(Duration);
}

void UGGSUInventoryPopup::AddElement(const UGGSUResourceDataAsset* TargetResource, const int Count)
{
	UGGSUInventoryElementObject* NewItem = NewObject<UGGSUInventoryElementObject>(this);
	NewItem->Name = TargetResource->Name.ToString();
	NewItem->Count = Count;
	NewItem->IconTexture = TargetResource->IconTexture;
	
	InventoryView->AddItem(NewItem);

	
}
