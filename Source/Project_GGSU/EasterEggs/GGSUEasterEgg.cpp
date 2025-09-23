#include "GGSUEasterEgg.h"

#include "GGSUEasterEggsDataInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UI/GGSUUIManager.h"
#include "UI/PopupUI/EasterEggs/GGSUEasterEggPopup.h"

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
	
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	EasterEggsDataInstance = GameInstance->GetSubsystem<UGGSUEasterEggsDataInstance>();
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
		EasterEggPopup->Setup(EasterEggData);
	}

	EasterEggsDataInstance->CollectEasterEgg(EasterEggData);
	Destroy();
}

void AGGSUEasterEgg::OnHovered()
{
	
}

void AGGSUEasterEgg::OnUnhovered()
{
	
}

