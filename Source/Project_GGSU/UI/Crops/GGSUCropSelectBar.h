// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GGSUCropSelectBar.generated.h"

class UGGSUResourceDataAsset;
class UGGSUResourceManager;
class UGGSUResourceSetDataAsset;
class UGGSUCropIcon;
class UHorizontalBox;

UCLASS()
class PROJECT_GGSU_API UGGSUCropSelectBar : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	void CreateCropElements();
	
	UFUNCTION()
	void HandleChangeCropSeedCount(UGGSUResourceDataAsset* Type, int Value);

public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UHorizontalBox> CropIcons;

public:	
	// 에디터에서 생성할 자식 위젯의 WBP 클래스를 지정할 수 있습니다.
	UPROPERTY(EditDefaultsOnly, Category = "CropSelectBar")
	TSubclassOf<UGGSUCropIcon> ItemWidgetClass;

	UPROPERTY(EditAnywhere, Category = "CropSelectBar")
	UGGSUResourceSetDataAsset* ResourceSetDataAsset;

	UPROPERTY(Transient)
	UGGSUResourceManager* CachedResourceManager;

	UPROPERTY(Transient)
	TMap<UGGSUResourceDataAsset*, UGGSUCropIcon*> CropIconMap;
};
