#include "BuildingSystem/GGSUUIOpenBuilding.h"
#include "Kismet/GameplayStatics.h"
#include "UI/GGSUUserWidget.h"

void AGGSUUIOpenBuilding::OnClicked()
{
	Super::OnClicked();

	if (CachedUIInstance)
	{
		
	}
	else
	{
		if (UIClass)
		{
			CachedUIInstance = CreateWidget<UGGSUUserWidget>(this, UIClass);

			if (CachedUIInstance)
			{
				AHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD();
				//HUD->Get
			}
		}
	}
}
