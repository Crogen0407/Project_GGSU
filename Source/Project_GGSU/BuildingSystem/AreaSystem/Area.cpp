// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSystem/AreaSystem/Area.h"
#include "Kismet/GameplayStatics.h"
#include "Widget/GGSUOpenAreaWidget.h"


AArea::AArea()
{
	PrimaryActorTick.bCanEverTick = true;
	
	AreaWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("AreaWidgetComponent"));
	SetRootComponent(AreaWidgetComponent);
	AreaWidgetComponent->SetWidgetSpace(EWidgetSpace::World); // 3D 월드 공간에 표시
	AreaWidgetComponent->SetDrawSize(FVector2D(500.0f, 150.0f)); // UI 크기 설정
}
void AArea::BeginPlay()
{
	Super::BeginPlay();
	
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	ResourceInstance = GameInstance->GetSubsystem<UGGSUResourceInstance>();

	if (OpenAreaWidgetClass)
	{
		AreaWidgetComponent->SetWidgetClass(OpenAreaWidgetClass);

		// 생성된 위젯 인스턴스에 접근하여 함수 호출
		// GetWidget()은 UWidget*을 반환하므로, 캐스팅이 필요합니다.
		UGGSUOpenAreaWidget* AreaWidget = Cast<UGGSUOpenAreaWidget>(AreaWidgetComponent->GetWidget());
		if (AreaWidget)
		{
			// 예시: 위젯 클래스에 정의된 함수 호출
			AreaWidget->SettingUI(100);
		}
	}
}

bool AArea::UnlockArea()
{
	if (ResourceInstance->TryRemoveResource(EResourceType::Gold, UnlockCost))
	{
		// 이 구역에 속한 모든 땅 해금
		for (AGroundTile* Tile : GroundTiles)
		{
			if (Tile)
			{
				Tile->SetUnlocked(true);
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("unlock area!"));
		return true;
	}
    
	UE_LOG(LogTemp, Warning, TEXT("not enough money"));
	return false;
}