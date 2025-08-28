// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingSystem/Interactable.h"
#include "GroundTile.generated.h"

UCLASS()
class PROJECT_GGSU_API AGroundTile : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	AGroundTile();

protected:
	virtual void BeginPlay() override;

public:
	// IInteractable 인터페이스 구현
	virtual void OnClicked_Implementation() override;
	virtual void OnHovered_Implementation() override;
	virtual void OnUnhovered_Implementation() override;
	virtual bool IsUnlocked_Implementation() const override;

	// 해재 상태 설정
	void SetUnlocked(bool bNewState);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GroundTile")
	bool isUnlocked = false;
};