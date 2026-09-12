#include "core/commands/Command.hpp"
#include "game/gta/Stats.hpp"
#include "game/gta/Network.hpp"

namespace YimMenu::Features
{
	class MaxSkills : public Command
	{
		using Command::Command;

		void OnCall() override
		{
			int maxAmount = 1000;

			Stats::SetInt("MPX_SCRIPT_INCREASE_DRIV", maxAmount);
			Stats::SetInt("MPX_SCRIPT_INCREASE_FLY", maxAmount);
			Stats::SetInt("MPX_SCRIPT_INCREASE_LUNG", maxAmount);
			Stats::SetInt("MPX_SCRIPT_INCREASE_SHO", maxAmount);
			Stats::SetInt("MPX_SCRIPT_INCREASE_STAM", maxAmount);
			Stats::SetInt("MPX_SCRIPT_INCREASE_STL", maxAmount);
			Stats::SetInt("MPX_SCRIPT_INCREASE_STRN", maxAmount);

			//Network::LaunchJoinType(static_cast<Network::JoinType>(Network::JoinType::SOLO));
		}
	};

	static MaxSkills _MaxSkills{"maxskills", "Max All Skills", "Sets your cheracter skills (Stamina, driving, flying, etc.) to max."};
}