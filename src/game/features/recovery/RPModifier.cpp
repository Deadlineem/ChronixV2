#include "core/commands/IntCommand.hpp"
#include "core/commands/Command.hpp"
#include "game/gta/Stats.hpp"
#include "game/gta/Network.hpp"
#include <algorithm>
#include <limits>

namespace YimMenu::Features
{
		static IntCommand RPSlider{"rpslider", "RP Slider", "Character level selection", 1, 8000, 1};

		static void InitRPModifier()
	    {
		    int currentLevel = Stats::GetInt("MPX_CHAR_RANK_FM");
		    if (currentLevel >= 1 && currentLevel <= 8000)
			    RPSlider.SetState(currentLevel);
	    }

		static constexpr int kLevelToRp_1_97[] = {
		    0,       // 1
		    800,     // 2
		    2100,    // 3
		    3800,    // 4
		    6100,    // 5
		    9500,    // 6
		    12500,   // 7
		    16000,   // 8
		    19800,   // 9
		    24000,   // 10
		    28500,   // 11
		    33400,   // 12
		    38700,   // 13
		    44200,   // 14
		    50200,   // 15
		    56400,   // 16
		    63000,   // 17
		    69900,   // 18
		    77100,   // 19
		    84700,   // 20
		    92500,   // 21
		    100700,  // 22
		    109200,  // 23
		    118000,  // 24
		    127100,  // 25
		    136500,  // 26
		    146200,  // 27
		    156200,  // 28
		    166500,  // 29
		    177100,  // 30
		    188000,  // 31
		    199200,  // 32
		    210700,  // 33
		    222400,  // 34
		    234500,  // 35
		    246800,  // 36
		    259400,  // 37
		    272300,  // 38
		    285500,  // 39
		    299000,  // 40
		    312700,  // 41
		    326800,  // 42
		    341000,  // 43
		    355600,  // 44
		    370500,  // 45
		    385600,  // 46
		    401000,  // 47
		    416600,  // 48
		    432600,  // 49
		    448800,  // 50
		    465200,  // 51
		    482000,  // 52
		    499000,  // 53
		    516300,  // 54
		    533800,  // 55
		    551600,  // 56
		    569600,  // 57
		    588000,  // 58
		    606500,  // 59
		    625400,  // 60
		    644500,  // 61
		    663800,  // 62
		    683400,  // 63
		    703300,  // 64
		    723400,  // 65
		    743800,  // 66
		    764500,  // 67
		    785400,  // 68
		    806500,  // 69
		    827900,  // 70
		    849600,  // 71
		    871500,  // 72
		    893600,  // 73
		    916000,  // 74
		    938700,  // 75
		    961600,  // 76
		    984700,  // 77
		    1008100, // 78
		    1031800, // 79
		    1055700, // 80
		    1079800, // 81
		    1104200, // 82
		    1128800, // 83
		    1153700, // 84
		    1178800, // 85
		    1204200, // 86
		    1229800, // 87
		    1255600, // 88
		    1281700, // 89
		    1308100, // 90
		    1334600, // 91
		    1361400, // 92
		    1388500, // 93
		    1415800, // 94
		    1443300, // 95
		    1471100, // 96
		    1499100  // 97
		};

		static int LevelToRP(int level)
		{
			if (level <= 1)
				return 0;
			if (level <= 97)
				return kLevelToRp_1_97[level - 1];

			long long L = level;
			long long total = 25 * L * L + 23575 * L - 1023150;
			if (total > std::numeric_limits<int>::max())
				total = std::numeric_limits<int>::max();
			return static_cast<int>(total);
		}

		class ApplyRP : public Command
		{
			using Command::Command;

			void OnCall() override
			{
				int level = std::clamp(RPSlider.GetState(), 1, 8000);
				int rp = LevelToRP(level);

				Stats::SetInt("MPX_CHAR_SET_RP_GIFT_ADMIN", rp);

				Network::LaunchJoinType(static_cast<Network::JoinType>(Network::JoinType::SOLO));
			}
		};

		static ApplyRP _ApplyRP{"applyrp", "Set Character Level", "Sets your wanted level to the desired level set in the slider."};
}
