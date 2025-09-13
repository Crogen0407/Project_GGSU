#include "DateSystem/GGSUDateManager.h"

TEnumAsByte<ECountry> UGGSUDateManager::CurrentCountry = ECountry::Seoul;
EDay UGGSUDateManager::CurrentDay = EDay::Day;

FDateTime UGGSUDateManager::GetTime()
{
	return FDateTime::UtcNow() + FTimespan::FromHours(CurrentCountry.GetIntValue());
}

EDay UGGSUDateManager::GetCurrentDay()
{
	return CurrentDay;
}
