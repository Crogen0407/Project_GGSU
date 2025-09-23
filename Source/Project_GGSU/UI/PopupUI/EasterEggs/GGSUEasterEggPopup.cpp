#include "UI/PopupUI/EasterEggs/GGSUEasterEggPopup.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "EasterEggs/GGSUEasterEgg.h"

void UGGSUEasterEggPopup::Setup(FEasterEggData EasterEggData)
{
	EasterEggName = EasterEggData.EasterEggName;
	EasterEggDescription = EasterEggData.EasterEggDescription;
	EasterEggIcon = EasterEggData.EasterEggIcon;

	TitleText->SetText(FText::FromString(EasterEggName));
	DescriptionText->SetText(FText::FromString(EasterEggDescription));
	IconImage->SetBrushFromTexture(EasterEggIcon);
}