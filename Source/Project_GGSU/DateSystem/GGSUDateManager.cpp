#include "DateSystem/GGSUDateManager.h"

FDateTime UGGSUDateManager::GetTime()
{
	return FDateTime::UtcNow() + FTimespan::FromHours(CurrentCountry.GetIntValue());
}
