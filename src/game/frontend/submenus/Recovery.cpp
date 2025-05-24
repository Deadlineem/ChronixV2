#include "Recovery.hpp"
#include "game/frontend/items/Items.hpp"
#include "Recovery/StatEditor.hpp"
#include "Recovery/Transactions.hpp"
#include "Recovery/HeistModifier.hpp"

namespace YimMenu::Submenus
{
	Recovery::Recovery() :
		#define ICON_FA_SACK_DOLLAR "\xef\x93\x80"
		Submenu::Submenu("Recovery", ICON_FA_SACK_DOLLAR)
	{
		auto missions = std::make_shared<Category>("Missions");
		auto vehiclesGroup = std::make_shared<Group>("Vehicles");
		auto generalGroup = std::make_shared<Group>("General");

		generalGroup->AddItem(std::make_shared<BoolCommandItem>("playallmissionssolo"_J));
		generalGroup->AddItem(std::make_shared<CommandItem>("forcelaunchheist"_J));

		missions->AddItem(generalGroup);
		AddCategory(std::move(missions));
		AddCategory(BuildStatEditorMenu());
		AddCategory(BuildTransactionsMenu());
		AddCategory(BuildHeistModifierMenu());
	}
}