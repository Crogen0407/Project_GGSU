// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSystem/AreaSystem/Area.h"
#include "Kismet/GameplayStatics.h"
#include "BuildingSystem/GGSUBuilding.h"
#include "Components/WidgetComponent.h"
#include "UI/Area/GGSUOpenAreaWidget.h"

AArea::AArea()
{
	PrimaryActorTick.bCanEverTick = true;

	OpenAreaWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("UIComponent"));
	OpenAreaWidgetComponent->SetupAttachment(GetRootComponent());
	OpenAreaWidgetComponent->SetRelativeLocation(FVector(0.0f , 0.0f , 90.0f));

	static ConstructorHelpers::FClassFinder<UUserWidget> OpenAreaWidgetRef(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Widget/Building/WBP_OpenArea.WBP_OpenArea_C'"));
	if (OpenAreaWidgetRef.Succeeded()) {
		OpenAreaWidgetComponent->SetWidgetClass(OpenAreaWidgetRef.Class);
		OpenAreaWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
		OpenAreaWidgetComponent->SetDrawSize(FVector2D(120.0f , 50.0f));
		OpenAreaWidgetComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}
void AArea::BeginPlay()
{
	Super::BeginPlay();
	
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	ResourceInstance = GameInstance->GetSubsystem<UGGSUResourceInstance>();
	ResourceInstance->AddResource(GoldItemData, 50);
	
	UGGSUOpenAreaWidget* OpenAreaWidget = Cast<UGGSUOpenAreaWidget>(OpenAreaWidgetComponent->GetUserWidgetObject());
	if (OpenAreaWidget) {
		OpenAreaWidget->SettingUI(UnlockCost, this);
	}
}

bool AArea::UnlockArea()
{
	if (ResourceInstance->TryRemoveResource(GoldItemData, UnlockCost))
	{
		// 이 구역에 속한 모든 땅 해금
		for (AGGSUBuilding* Building : Buildings)
		{
			if (Building)
			{
				Building->OnUnlock();
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("unlock area!"));
		return true;
	}
    
	UE_LOG(LogTemp, Warning, TEXT("not enough money"));
	return false;
}
