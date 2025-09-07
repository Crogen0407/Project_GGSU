#include "BuildingSystem/GGSUUIOpenBuilding.h"
#include "Kismet/GameplayStatics.h"
#include "UI/GGSUUIManager.h"
#include "UI/GGSUUserWidget.h"

void AGGSUUIOpenBuilding::OnClicked()
{
	Super::OnClicked();

	if (UIClass)
	{
		if (CachedUIInstance == nullptr)
		{
			CachedUIInstance = GetGameInstance()->GetSubsystem<UGGSUUIManager>()->ShowPopupUI(UIClass);
		}
	}
}
