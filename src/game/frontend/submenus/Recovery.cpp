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
		auto missions   = std::make_shared<Category>("Missions");
		auto businesses = std::make_shared<Category>("Businesses");
		auto casino     = std::make_shared<Category>("Casino");

		auto generalGroup  = std::make_shared<Group>("General");
		auto businessGroup = std::make_shared<Group>("General");
		auto casinoGroup   = std::make_shared<Group>("Slot Machines");

		generalGroup->AddItem(std::make_shared<BoolCommandItem>("playallmissionssolo"_J));
		generalGroup->AddItem(std::make_shared<CommandItem>("forcelaunchheist"_J));
		generalGroup->AddItem(std::make_shared<BoolCommandItem>("unlockgtaplus"_J));
		generalGroup->AddItem(std::make_shared<BoolCommandItem>("overriderpmultiplier"_J));
		generalGroup->AddItem(std::make_shared<ConditionalItem>("overriderpmultiplier"_J, std::make_shared<FloatCommandItem>("rpmultiplierinput"_J)));

		businessGroup->AddItem(std::make_shared<ListCommandItem>("businesssafe"_J));
		businessGroup->AddItem(std::make_shared<CommandItem>("claimsafeearnings"_J));

		casinoGroup->AddItem(std::make_shared<BoolCommandItem>("casinomanipulaterigslotmachines"_J));

		missions->AddItem(generalGroup);
		businesses->AddItem(businessGroup);
		casino->AddItem(casinoGroup);

		AddCategory(std::move(missions));
		AddCategory(std::move(businesses));
		AddCategory(std::move(casino));
		AddCategory(BuildStatEditorMenu());
		AddCategory(BuildTransactionsMenu());
		AddCategory(BuildHeistModifierMenu());
	}
}