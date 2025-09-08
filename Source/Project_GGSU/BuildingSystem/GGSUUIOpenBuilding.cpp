#include "BuildingSystem/GGSUUIOpenBuilding.h"
#include "Kismet/GameplayStatics.h"
#include "UI/GGSUUIManager.h"
#include "UI/GGSUUserWidget.h"

void AGGSUUIOpenBuilding::OnClicked()
{
	Super::OnClicked();

	if (UIClass)
	{
		GetGameInstance()->GetSubsystem<UGGSUUIManager>()->ShowPopupUI(UIClass);

		UE_LOG(LogTemp, Log, TEXT("UI가 왜 안보이는데 신발"));
	}
}
