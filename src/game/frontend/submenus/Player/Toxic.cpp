#include "Toxic.hpp"
#include "game/frontend/items/Items.hpp"
#include "core/util/Joaat.hpp"

namespace YimMenu::Submenus
{
	std::shared_ptr<Category> BuildToxicMenu()
	{
		auto menu = std::make_shared<Category>("Toxic");

		auto damage = std::make_shared<Group>("Damage", 1);

		damage->AddItem(std::make_shared<PlayerCommandItem>("kill"_J));
		damage->AddItem(std::make_shared<PlayerCommandItem>("killexploit"_J));
		damage->AddItem(std::make_shared<PlayerCommandItem>("explode"_J));

		auto griefing = std::make_shared<Group>("Griefing");
		griefing->AddItem(std::make_shared<PlayerCommandItem>("ceokick"_J));

		auto force = std::make_shared<Group>("Magnet/Forcefield");
		force->AddItem(std::make_shared<BoolCommandItem>("magnet"_J));
		force->AddItem(std::make_shared<FloatCommandItem>("magnetradius"_J, std::nullopt, false));
		force->AddItem(std::make_shared<FloatCommandItem>("magnetmagnitude"_J, std::nullopt, false));
		force->AddItem(std::make_shared<BoolCommandItem>("forcefield"_J));
		force->AddItem(std::make_shared<FloatCommandItem>("forcefieldradius"_J, std::nullopt, false));
		force->AddItem(std::make_shared<FloatCommandItem>("forcefieldmagnitude"_J, std::nullopt, false));

		menu->AddItem(damage);
		menu->AddItem(griefing);
		menu->AddItem(force);

		return menu;
	}
}