#include "UI/PopupUI/Inventories/GGSUInventorySlot.h"
#include "GGSUInventoryPopup.h"
#include "Components/Border.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ResourceSystem/GradeSystem/GGSUGradeManager.h"

void UGGSUInventorySlot::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	if (const UGGSUInventoryElementObject* InventoryElementObject = Cast<UGGSUInventoryElementObject>(ListItemObject))
	{
		CountText->SetText(FText::FromString(FString::FromInt(InventoryElementObject->Count)));
		IconImage->SetBrushFromTexture(InventoryElementObject->IconTexture);

		if (InventoryElementObject->IsGradeResource)
		{
			SetGrade(InventoryElementObject->ResourceGrade);
		}
		else
			GradeIcon->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UGGSUInventorySlot::SetGrade(const EResourceGrade Grade) const
{
	if (const UGGSUGradeManager* GradeManager = GetGameInstance()->GetSubsystem<UGGSUGradeManager>())
	{
		const FColor Color = GradeManager->GetGradeColor(Grade);
		GradeIcon->SetBrushColor(Color);
		GradeIcon->SetVisibility(ESlateVisibility::Visible);
		GradeText->SetText(FText::FromString(StaticEnum<EResourceGrade>()->GetNameStringByValue(static_cast<int64>(Grade))));
	}
}
