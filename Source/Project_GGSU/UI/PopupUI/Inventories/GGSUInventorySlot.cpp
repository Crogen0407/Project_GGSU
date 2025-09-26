#include "UI/PopupUI/Inventories/GGSUInventorySlot.h"
#include "GGSUInventoryPopup.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UGGSUInventorySlot::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	if (UGGSUInventoryElementObject* InventoryElementObject = Cast<UGGSUInventoryElementObject>(ListItemObject))
	{
		CountText->SetText(FText::FromString(FString::FromInt(InventoryElementObject->Count)));
		IconImage->SetBrushFromTexture(InventoryElementObject->IconTexture);
	}
}
