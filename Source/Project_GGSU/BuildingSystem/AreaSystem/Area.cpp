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
	
	UGGSUOpenAreaWidget* OpenAreaWidget = Cast<UGGSUOpenAreaWidget>(OpenAreaWidgetComponent->GetUserWidgetObject());
	if (OpenAreaWidget) {
		OpenAreaWidget->SettingUI(UnlockCost, this);
	}


	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);
	
	for (AActor* Actor : AttachedActors)
	{
		if (AGGSUField* Field = Cast<AGGSUField>(Actor))
		{
			FieldBuildings.Add(Field);
		}
		else if (AGGSUBuilding* Building = Cast<AGGSUBuilding>(Actor))
		{
			FanceBuildings.Add(Building);
		}
	}
}

bool AArea::UnlockArea()
{
	if (ResourceInstance->TryRemoveResource(GoldItemData, UnlockCost))
	{
		// fance랑 fieldd해금
		for (AGGSUBuilding* Building : FanceBuildings)
		{
			if (Building)
			{
				Building->OnUnlock();
			}
		}
		for (AGGSUBuilding* Building : FieldBuildings)
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

void AArea::SetActiveUI(bool active)
{
	OpenAreaWidgetComponent->SetHiddenInGame(active); // 안보임
}

TArray<AGGSUField*> AArea::GetFields()
{
	return FieldBuildings;
}
