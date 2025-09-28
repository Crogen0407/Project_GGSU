#include "BuildingSystem/GGSUField.h"

#include "ResourceSystem/GGSUResourceManager.h"
#include "ResourceSystem/CropsSystem/GGSUCropsGenerator.h"
#include "ResourceSystem/CropsSystem/GGSUCropsSelection.h"
#include "ResourceSystem/CropsSystem/GGSUCrop.h"
#include "ResourceSystem/CropsSystem/GGSUCropSeedDataAsset.h"

void AGGSUField::BeginPlay()
{
	Super::BeginPlay();
	
	CachedCropsSelection = GetGameInstance()->GetSubsystem<UGGSUCropsSelection>();
	CachedResourceManager = GetGameInstance()->GetSubsystem<UGGSUResourceManager>();
}

void AGGSUField::OnClicked()
{
	Super::OnClicked();

	// 이미 심어져 있는 작물이 있는지 판별
	if (CurrentCrops != nullptr)
	{
		HarvestCurrentCrops();
		
		return;
	}

	// Crop spawn.
	if (CachedCropsSelection == nullptr) return;
	if (CachedResourceManager == nullptr) return;
	
	if (UGGSUCropSeedDataAsset* CropSeed = CachedCropsSelection->GetSelectedCropSeed())
	{
		if (CachedResourceManager->GetResource(CropSeed) > 0)
		{
			SpawnCrop(CropSeed);
			CachedResourceManager->RemoveResource(CropSeed, 1);
		}
	}
	
}

void AGGSUField::OnUnlock()
{
	Enable();
	Super::OnUnlock();
}

void AGGSUField::SpawnCrop(UGGSUCropSeedDataAsset* CropSeed)
{
	if (const UGGSUCropsGenerator* CropsGenerator = GetGameInstance()->GetSubsystem<UGGSUCropsGenerator>())
	{
		CurrentCrops = CropsGenerator->SpawnCrop(CropSeed, GetActorLocation());
		TargetCropSeed = CropSeed;
	}
}

bool AGGSUField::HarvestCurrentCrops()
{
	if (CurrentCrops == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("HarvestCurrentCrops: CurrentCrops is nullptr"));
		return false;
	}

	if (!CurrentCrops->IsCropFullyGrown())
	{
		UE_LOG(LogTemp, Log, TEXT("HarvestCurrentCrops: Crop is not fully grown yet"));
		return false;
	}
	
	CachedCropsSelection->SetSelectedCropSeed(nullptr);
	UGGSUResourceManager* ResourceManager = GetGameInstance()->GetSubsystem<UGGSUResourceManager>();
	if (ResourceManager && TargetCropSeed)
	{
		if (UGGSUCropDataAsset* CropResource = TargetCropSeed->GetCrop(EResourceGrade::D))
		{
			ResourceManager->AddResource(CropResource, 1);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("HarvestCurrentCrops: TargetCropSeed->GetCrop returned nullptr"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HarvestCurrentCrops: ResourceManager or TargetCropSeed is nullptr"));
	}

	if (UWorld* World = GetWorld())
	{
		World->DestroyActor(CurrentCrops);
	}

	CurrentCrops = nullptr;
	TargetCropSeed = nullptr;

	return true;
}