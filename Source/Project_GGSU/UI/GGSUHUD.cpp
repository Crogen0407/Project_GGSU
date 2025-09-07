#include "UI/GGSUHUD.h"
#include "Blueprint/UserWidget.h"

void AGGSUHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (HUDWidgetClass && PlayerOwner)
	{
		HUDWidgetInstance = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), HUDWidgetClass);

		if (HUDWidgetInstance)
			HUDWidgetInstance->AddToViewport();
	}
}
