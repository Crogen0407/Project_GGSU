#include "BuildingSystem/GGSUSelectSubSystem.h"

void UGGSUSelectSubSystem::SetSelectedObject(IGGSUSelectableObject* SelectableObject)
{
	SelectedObject.SetInterface(SelectableObject);
	OnSelectedObjectChanged.Broadcast(SelectableObject);
}
