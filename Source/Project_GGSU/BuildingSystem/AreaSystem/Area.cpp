#include "BuildingSystem/AreaSystem/Area.h"

#include "Kismet/GameplayStatics.h"
#include "BuildingSystem/GGSUBuilding.h"
#include "Components/WidgetComponent.h"
#include "UI/GGSUUIManager.h"
#include "UI/Others/GGSUMessageBox.h"
#include "UI/Area/GGSUOpenAreaWidget.h"
#include "BuildingSystem/GGSUBuilding.h"

AArea::AArea()
{
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootSceneComponent);
	
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
	ResourceInstance = GameInstance->GetSubsystem<UGGSUResourceManager>();

	if (UGGSUOpenAreaWidget* OpenAreaWidget = Cast<UGGSUOpenAreaWidget>(OpenAreaWidgetComponent->GetUserWidgetObject())) {
		OpenAreaWidget->Setup(UnlockCost, this);
	}

	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);
	
	for (AActor* Actor : AttachedActors)
	{
		if (AGGSUField* Field = Cast<AGGSUField>(Actor))
			FieldBuildings.Add(Field);
		else if (AGGSUBuilding* Building = Cast<AGGSUBuilding>(Actor))
			FanceBuildings.Add(Building);
	}
	
	if (IsUnlockArea)
	{
		UnlockCost = 0;
		SetActiveUI(false);
	}
	else
	{
		for (AGGSUBuilding* Building : FieldBuildings)
		{
			if (Building)
				Building->Disable();
		}
	}
}

bool AArea::UnlockArea()
{
	if (UGGSUUIManager* UIManager = GetGameInstance()->GetSubsystem<UGGSUUIManager>())
	{
		if (UGGSUMessageBox* MessageBox = Cast<UGGSUMessageBox>(UIManager->ShowPopupUI(MessageBoxClass)))
		{
			if (ResourceInstance->GetResource(GoldItemData) >= UnlockCost)
			{
				FText MessageText = FText::FromString(
					FString::Printf(TEXT("%d원을 지불하여 해당 매물을 구매하시겠습니까?"), UnlockCost)
				);
				FText FirstButtonText = FText::FromString(TEXT("음... 좀 더 생각해볼께요"));
				FText SecondButtonText =  FText::FromString(TEXT("네!"));

				MessageBox->Setup(MessageText);
				MessageBox->AddButton(FirstButtonText, [this, UIManager]
				{
					UIManager->HidePopupUI(MessageBoxClass);
				});
				MessageBox->AddButton(SecondButtonText, [this, UIManager]
				{
					for (AGGSUBuilding* Building : FieldBuildings)
					{
						if (Building) Building->OnUnlock();
					}
					ResourceInstance->RemoveResource(GoldItemData, UnlockCost);
					SetActiveUI(false);
					UIManager->HidePopupUI(MessageBoxClass);
					IsUnlockArea = true;
				});

				return true;
			}
			else
			{
				FText MessageText = FText::FromString(TEXT("계약금이 부족합니다"));
				FText FirstButtonText = FText::FromString(TEXT("다음에 다시 와보도록 하자"));
		
				MessageBox->Setup(MessageText);
				MessageBox->AddButton(FirstButtonText, [this, UIManager]
				{
					UIManager->HidePopupUI(MessageBoxClass);
				});
				
				return false;
			}
		}
	}
	
	return false;
}

void AArea::SetActiveUI(bool Active)
{
	OpenAreaWidgetComponent->SetHiddenInGame(!Active); // 안보임
}

TArray<AGGSUField*> AArea::GetFields()
{
	return FieldBuildings;
}
