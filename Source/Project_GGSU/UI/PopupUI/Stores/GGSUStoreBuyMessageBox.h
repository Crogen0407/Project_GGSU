#pragma once
#include "CoreMinimal.h"
#include "UI/Others/GGSUMessageBox.h"
#include "GGSUStoreBuyMessageBox.generated.h"

class UGGSUResourceDataAsset;
class UGGSUItemDataAsset;
class UImage;

UCLASS()
class PROJECT_GGSU_API UGGSUStoreBuyMessageBox : public UGGSUMessageBox
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

public:
	virtual void Setup(const FText Text) override;
	
public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> IconImage;

	// 여기에 +, -, Min, Max 버튼 받아와서 바인딩하기
	// 버튼마다 함수 각각 만들어서 바인딩하는 게 빠르더라. 억지로 람다쓰려고 하다가 시간 더 오래 걸림.
	// 바인딩 자체는 NativeOnInitialized()에서 하면 됨.
	// ItemCount로 조정하고 버튼 클릭할 때마다 수량 텍스트 변동하면 될 듯
	// ItemCount UPROPERTY()로 해둔 이유는 블루프린트에서 쓸 수도 있을 것 같아서 빼둠. C++에서 할꺼라면 지워도 됨.
	
public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGGSUResourceDataAsset> GoldResource;
	
	UPROPERTY(Transient)
	TObjectPtr<UGGSUResourceDataAsset> TargetResource;

	UPROPERTY(EditAnywhere)
	int ItemCount;
	
	int ItemPrice;
};
