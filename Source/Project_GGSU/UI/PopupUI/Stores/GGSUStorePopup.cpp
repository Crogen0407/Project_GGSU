#include "UI/PopupUI/Stores/GGSUStorePopup.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "StoreSystem/GGSUStoreProductsDataAsset.h"
#include "UI/PopupUI/Stores/GGSUStoreElement.h"
#include "UI/PopupUI/Stores/GGSUStoreCategoryButton.h"
#include "UI/PopupUI/Stores/GGSUStoreCategory.h"
#include "Components/HorizontalBoxSlot.h"
#include "DateSystem/GGSUDateManager.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"

void UGGSUStorePopup::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CachedCategoryIndex = 0;

	// 팝업 그룹 버튼-카테고리탭 일대일 매칭
	for (auto ProductsGroup : StoreProductsDataAsset->Showcases)
	{
		// 팝업 선택 버튼 생성
		if (const auto NewStoreCategoryButton = CreateWidget<UGGSUStoreCategoryButton>(this, StoreCategoryButtonClass))
		{
			int Index = CachedCategoryIndex;
			
			// 인덱스를 람다로 바인딩
			NewStoreCategoryButton->OnClicked.BindLambda([this, Index]()
			{
				StoreCategorySwitcher->SetActiveWidgetIndex(Index);
			});

			// 버튼과 대응되는 카테고리명 입력
			NewStoreCategoryButton->CategoryNameText->SetText(FText::FromString(ProductsGroup.Key));

			// 버튼 초기화
			NewStoreCategoryButton->Setup();

			// 버튼 HorizontalBox에 추가 및 사이즈 조절
			UHorizontalBoxSlot* ButtonSlot = StoreCategoryButtons->AddChildToHorizontalBox(NewStoreCategoryButton);
			ButtonSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
			NewStoreCategoryButton->SetPadding(FMargin(10.0f, 25.0f, 10.0f, 0.0f));
		}

		// 팝업 카테고리 생성
		if (auto NewStoreCategory = CreateWidget<UGGSUStoreCategory>(this, StoreCategoryClass))
		{
			// Switcher에 자식으로 추가
			StoreCategorySwitcher->AddChild(NewStoreCategory);
			NewStoreCategory->SetPadding(FMargin(10.0f));

			// 카테고리에 들어가는 상품들 요소 넣기
			for (const auto Item : ProductsGroup.Value.Items)
			{
				// 상점 요소 생성
				if (const auto NewStoreElement = CreateWidget<UGGSUStoreElement>(this, StoreElementClass))
				{
					// 초기화, Switcher에 자식으로 추가 및 사이즈 조절
					NewStoreElement->Setup(Item.Key, GetSellingPrice(Item.Key, Item.Value));
					NewStoreCategory->StoreElementList->AddChild(NewStoreElement);
					NewStoreElement->SetPadding(FMargin(50.0f));
				}
			}
		}

		// 버튼-카테고리탭 매칭 그룹 완성했으니 인덱스 증가
		CachedCategoryIndex++; 
	}
}

int UGGSUStorePopup::GetSellingPrice(UGGSUResourceDataAsset* ResourceDataAsset, int DefaultPrice)
{
	const FDateTime Time = UGGSUDateManager::GetTime();
		
	const int32 Day = Time.GetDay();
	const int32 Month = Time.GetMonth();
	const int32 Year = Time.GetYear();
	const int32 RandomSeed = Day + Month + Year + GetTypeHash(ResourceDataAsset->GetName()) + 123564356;
		
	const int RandomRange = GenerateAndPrintRandomNumbers(RandomSeed);
		
	return DefaultPrice + RandomRange;
}

int UGGSUStorePopup::GenerateAndPrintRandomNumbers(int Seed)
{
	RandomStream.Initialize(Seed);
	const int32 RandomInt = RandomStream.RandRange(-5, 5);

	return RandomInt;
}

