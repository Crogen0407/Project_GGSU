#include "DateSystem/GGSUDateManager.h"

TEnumAsByte<ECountry> UGGSUDateManager::CurrentCountry = ECountry::Seoul;

FDateTime UGGSUDateManager::GetTime()
{
	return FDateTime::UtcNow() + FTimespan::FromHours(CurrentCountry.GetIntValue());
}
