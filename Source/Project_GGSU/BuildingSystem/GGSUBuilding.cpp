// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUBuilding.h"

#include "Components/BoxComponent.h"

// Sets default values
AGGSUBuilding::AGGSUBuilding()
{
	PrimaryActorTick.bCanEverTick = true;

	// Component Setting...
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	Visual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual"));
	Visual->SetupAttachment(RootComponent);
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(RootComponent);
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Block);

	// Asset Load...
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshAsset.Succeeded())
	{
		Visual->SetStaticMesh(MeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void AGGSUBuilding::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGGSUBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGGSUBuilding::OnClicked()
{
	OpenBuildingEvent.Broadcast();
}

void AGGSUBuilding::OnHovered()
{
}

void AGGSUBuilding::OnUnhovered()
{
}

void AGGSUBuilding::OnUnlock()
{
	IsUnlocked = true;
}

void AGGSUBuilding::Disable()
{
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);

	if (BoxComponent)
	{
		BoxComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		BoxComponent->SetGenerateOverlapEvents(false);
		BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	}
}

void AGGSUBuilding::Enable()
{
	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);

	if (BoxComponent)
	{
		BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		BoxComponent->SetGenerateOverlapEvents(true);
		BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	}
}

