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

	if (IsUnlocked)
		Visual->SetScalarParameterValueOnMaterials(FName(""), 1.f);
}

// Called every frame
void AGGSUBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGGSUBuilding::OnClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClicked"));
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
	
	Visual->SetScalarParameterValueOnMaterials(FName("IsLocked"), 0.f);
}

