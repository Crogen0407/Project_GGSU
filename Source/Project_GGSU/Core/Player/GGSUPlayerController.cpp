// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUPlayerController.h"
#include "BuildingSystem/GGSUBuilding.h"
#include "BuildingSystem/GGSUSelectSubSystem.h"
#include "BuildingSystem/GGSUSelectableObject.h"

AGGSUPlayerController::AGGSUPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// 커서 표시
	bShowMouseCursor = true;

	// 커서 모양 변경
	static ConstructorHelpers::FObjectFinder<UTexture2D> CursorTexture(TEXT("/Game/UI/MyCursor.MyCursor"));
	if (CursorTexture.Succeeded())
	{
		CurrentMouseCursor = EMouseCursor::Custom;
	}
}

void AGGSUPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Click", EInputEvent::IE_Pressed, this, &AGGSUPlayerController::HandlePressed);
	InputComponent->BindAction("Click", EInputEvent::IE_Released, this, &AGGSUPlayerController::HandleReleased);
}

void AGGSUPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (IsSelecting)
	{
		Select();
	}
	
}

void AGGSUPlayerController::HandlePressed()
{
	IsSelecting = true;
}

void AGGSUPlayerController::HandleReleased()
{
	IsSelecting = false;
}

FRotator AGGSUPlayerController::GetControlRotation() const
{
	return FRotator(0, -45.f, 0);
}

void AGGSUPlayerController::Select() const
{
	FVector WorldLocation, WorldDirection;
   
	// 마우스 커서의 2D 화면 위치를 3D 월드 공간의 위치와 방향으로 변환합니다.
	if (DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
	{
		FHitResult HitResult;
		FVector StartLocation = WorldLocation;
		FVector EndLocation = StartLocation + (WorldDirection * TraceDistance);
   
		// 충돌 쿼리 파라미터를 설정합니다. (예: 플레이어 자신은 무시)
		FCollisionQueryParams CollisionParams;
		if (GetPawn())
		{
			CollisionParams.AddIgnoredActor(GetPawn());
		}
   
		// 월드에 라인 트레이스(레이캐스트)를 실행합니다.
		bool bHit = GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECC_Visibility, // Visibility 채널에 있는 오브젝트만 감지
			CollisionParams
		);
   
		// 무언가에 부딪혔고, 해당 액터가 유효하다면
		if (bHit && HitResult.GetActor())
		{
			AActor* HitActor = HitResult.GetActor();

			// 부딪힌 액터가 InteractableInterface를 구현하고 있는지 확인합니다.
			if (HitActor->GetClass()->ImplementsInterface(UGGSUSelectableObject::StaticClass()))
			{
				// 인터페이스 함수를 실행합니다.
				if (IGGSUSelectableObject* Interactable = Cast<IGGSUSelectableObject>(HitActor))
				{
					Interactable->OnClicked();

					if (AGGSUBuilding* Building = Cast<AGGSUBuilding>(Interactable))
					{
						BuildingSelect(Building);
					}
				}
			}
		}
	}
}

void AGGSUPlayerController::Deselect()
{
}

void AGGSUPlayerController::BuildingSelect(AGGSUBuilding* Building) const
{
	UGGSUSelectSubSystem* BuildingSubSystem = GetGameInstance()->GetSubsystem<UGGSUSelectSubSystem>(); 
	BuildingSubSystem->SetSelectedObject(Building);
}
