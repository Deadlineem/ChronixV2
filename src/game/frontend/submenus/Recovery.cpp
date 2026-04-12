#include "Recovery.hpp"
#include "Recovery/HeistModifier.hpp"
#include "Recovery/StatEditor.hpp"
#include "Recovery/Transactions.hpp"
#include "Recovery/DailyActivities.hpp"
#include "game/frontend/items/Items.hpp"

namespace YimMenu::Submenus
{
	Recovery::Recovery() :
		#define ICON_FA_SACK_DOLLAR "\xef\x93\x80"
	    Submenu::Submenu("Recovery", ICON_FA_SACK_DOLLAR)
	{
		auto main = std::make_shared<Category>("Main");
		auto businesses = std::make_shared<Category>("Businesses");
		auto casino = std::make_shared<Category>("Casino");

		auto generalGroup = std::make_shared<Group>("General");
		auto businessGroup = std::make_shared<Group>("General");
		auto casinoSlots = std::make_shared<Group>("Slot Machines");
		//auto casinoWheel = std::make_shared<Group>("Lucky Wheel");
		//auto casinoBlackJack = std::make_shared<Group>("Blackjack");
		//auto casinoRoulette = std::make_shared<Group>("Roulette");
		auto safeLoopGroup = std::make_shared<Group>("Safe Loops");

		auto hangarGroup = std::make_shared<Group>("Hangar");
		auto warehouseGroup = std::make_shared<Group>("Warehouse");
		auto mcBusinessGroup = std::make_shared<Group>("MC Businesses");
		auto specialBusinessGroup = std::make_shared<Group>("Special Businesses");
		auto servicesGroup = std::make_shared<Group>("Services");

		generalGroup->AddItem(std::make_shared<BoolCommandItem>("playallmissionssolo"_J));
		generalGroup->AddItem(std::make_shared<BoolCommandItem>("unlockgtaplus"_J));
		generalGroup->AddItem(std::make_shared<BoolCommandItem>("overriderpmultiplier"_J));
		generalGroup->AddItem(std::make_shared<ConditionalItem>("overriderpmultiplier"_J, std::make_shared<FloatCommandItem>("rpmultiplierinput"_J)));
		generalGroup->AddItem(std::make_shared<CommandItem>("maxskills"_J));
		generalGroup->AddItem(std::make_shared<IntCommandItem>("rpslider"_J, "Character Level"));
		generalGroup->AddItem(std::make_shared<CommandItem>("applyrp"_J));
		generalGroup->AddItem(std::make_shared<BoolCommandItem>("freechangeappearance"_J));
		generalGroup->AddItem(std::make_shared<BoolCommandItem>("nochangeappearancecooldown"_J));
		generalGroup->AddItem(std::make_shared<BoolCommandItem>("allowgenderchange"_J));

		businessGroup->AddItem(std::make_shared<ListCommandItem>("businesssafe"_J));
		businessGroup->AddItem(std::make_shared<CommandItem>("claimsafeearnings"_J));

		safeLoopGroup->AddItem(std::make_shared<BoolCommandItem>("nightclubsafeloop"_J));
		safeLoopGroup->AddItem(std::make_shared<BoolCommandItem>("agencysafeloop"_J));

		hangarGroup->AddItem(std::make_shared<ListCommandItem>("hangargoodtype"_J));
		hangarGroup->AddItem(std::make_shared<CommandItem>("hangarrestock"_J));

		warehouseGroup->AddItem(std::make_shared<ListCommandItem>("warehousegoodtype"_J));
		warehouseGroup->AddItem(std::make_shared<CommandItem>("warehouserestock"_J));

		mcBusinessGroup->AddItem(std::make_shared<CommandItem>("mcbusinesssupplies"_J));
		mcBusinessGroup->AddItem(std::make_shared<CommandItem>("methrestock"_J));
		mcBusinessGroup->AddItem(std::make_shared<CommandItem>("weedrestock"_J));
		mcBusinessGroup->AddItem(std::make_shared<CommandItem>("cokerestock"_J));
		mcBusinessGroup->AddItem(std::make_shared<CommandItem>("cashrestock"_J));
		mcBusinessGroup->AddItem(std::make_shared<CommandItem>("documentsrestock"_J));

		specialBusinessGroup->AddItem(std::make_shared<CommandItem>("bunkerrestock"_J));
		specialBusinessGroup->AddItem(std::make_shared<CommandItem>("acidlabrestock"_J));
		specialBusinessGroup->AddItem(std::make_shared<CommandItem>("nightclubrestock"_J));

		servicesGroup->AddItem(std::make_shared<CommandItem>("salvageyardpopularity"_J));
		servicesGroup->AddItem(std::make_shared<CommandItem>("moneyfrontsheat"_J));

		casinoSlots->AddItem(std::make_shared<BoolCommandItem>("casinomanipulaterigslotmachines"_J));

		main->AddItem(generalGroup);
		businesses->AddItem(businessGroup);
		businesses->AddItem(safeLoopGroup);
		businesses->AddItem(hangarGroup);
		businesses->AddItem(warehouseGroup);
		businesses->AddItem(mcBusinessGroup);
		businesses->AddItem(specialBusinessGroup);
		businesses->AddItem(servicesGroup);
		casino->AddItem(casinoSlots);

		AddCategory(std::move(main));
		AddCategory(std::move(businesses));
		AddCategory(std::move(casino));
		AddCategory(BuildStatEditorMenu());
		AddCategory(BuildTransactionsMenu());
		AddCategory(BuildHeistModifierMenu());
		AddCategory(BuildDailyActivitiesMenu());

		auto unlockerCategory = std::make_shared<Category>("Unlocker");
		auto unlockGroup = std::make_shared<Group>("Unlock Categories");

		unlockGroup->AddItem(std::make_shared<CommandItem>("unlockallitems"_J));
		unlockGroup->AddItem(std::make_shared<CommandItem>("unlockallclothes"_J));
		unlockGroup->AddItem(std::make_shared<CommandItem>("unlockallvehicles"_J));
		unlockGroup->AddItem(std::make_shared<CommandItem>("unlockallweapons"_J));
		unlockGroup->AddItem(std::make_shared<CommandItem>("unlockallcollectables"_J));
		unlockGroup->AddItem(std::make_shared<CommandItem>("unlockallheists"_J));
		unlockGroup->AddItem(std::make_shared<CommandItem>("unlockallawards"_J));
		unlockGroup->AddItem(std::make_shared<CommandItem>("unlockallproperties"_J));

		unlockerCategory->AddItem(unlockGroup);
		AddCategory(std::move(unlockerCategory));
	}
}
