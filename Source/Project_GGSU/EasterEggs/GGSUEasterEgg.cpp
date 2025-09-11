#include "GGSUEasterEgg.h"
#include "UI/GGSUUIManager.h"
#include "UI/GGSUEasterEggPopup.h"

// Sets default values
AGGSUEasterEgg::AGGSUEasterEgg()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	StaticMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGGSUEasterEgg::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGGSUEasterEgg::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGGSUEasterEgg::OnClicked()
{
	if (EasterEggPopupClass != nullptr)
	{
		UGGSUEasterEggPopup* EasterEggPopup
			= Cast<UGGSUEasterEggPopup>(GetGameInstance()->GetSubsystem<UGGSUUIManager>()->ShowPopupUI(EasterEggPopupClass));
		EasterEggPopup->Setup(EasterEggName, EasterEggDescription, EasterEggIcon);
	}
}

void AGGSUEasterEgg::OnHovered()
{
	
}

void AGGSUEasterEgg::OnUnhovered()
{
	
}

