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
	}
}

bool AGGSUField::HarvestCurrentCrops() const
{
	// TODO : 다 자랐는지 확인
	if (CurrentCrops->IsCropFullyGrown())
	{
		// TODO : 등급 반영
		GetGameInstance()->GetSubsystem<UGGSUResourceManager>()->AddResource(TargetCropSeed->GetCrop(EResourceGrade::D), 1);

		// 오브젝트 없애기
		if (UWorld* World = GetWorld())
			World->DestroyActor(CurrentCrops);
		
		return true; 
	}

	return false;		
}
