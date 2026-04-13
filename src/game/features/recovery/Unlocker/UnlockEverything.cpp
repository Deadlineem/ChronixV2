#include "UnlockEverything.hpp"
#include "core/commands/Command.hpp"
#include "game/gta/Stats.hpp"
#include "game/gta/ScriptGlobal.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	static bool IsPlayerMale()
	{
		auto genderStat = ScriptGlobal(1574927);
		if (auto ptr = genderStat.As<int*>())
			return *ptr == 0;
		return true; 
	}

	class UnlockAllItemsCommand : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			// Nightclub Trophies
			for (int i = 15552; i <= 15560; i++)
				Stats::SetPackedBool(i, true);

			// Arcade Machines
			for (int i = 0; i <= 11; i++)
				Stats::SetInt(("MPX_ARCADE_MAC_" + std::to_string(i)).c_str(), 1);

			// Office/Clubhouse Decorations
			Stats::SetPackedInt(7666, 25);
			Stats::SetPackedInt(9357, 4);
			Stats::SetPackedInt(7671, 100);

			// Business Battle Items
			Stats::SetPackedInt(22051, 50);
			Stats::SetPackedInt(22052, 100);
			Stats::SetPackedInt(22053, 20);
			Stats::SetPackedInt(22054, 80);
			Stats::SetPackedInt(22055, 60);
			Stats::SetPackedInt(22056, 40);
			Stats::SetPackedInt(22057, 10);
			Stats::SetPackedInt(22058, 20);

			// Special Items
			Stats::SetPackedBool(25002, true);
			Stats::SetPackedBool(25004, true);
			Stats::SetPackedBool(25005, true);
			Stats::SetPackedBool(25006, true);
			Stats::SetPackedBool(25516, true);
			Stats::SetPackedBool(25520, true);
			Stats::SetPackedBool(25521, true);
			Stats::SetPackedBool(25406, true);
			Stats::SetPackedBool(42148, true);
			Stats::SetPackedBool(42149, true);
			Stats::SetPackedBool(51189, true);
			Stats::SetPackedBool(51196, true);
			Stats::SetPackedBool(51197, true);
			Stats::SetPackedBool(27247, true);

			// LD Organics
			for (int i = 34262; i <= 34361; i++)
				Stats::SetPackedBool(i, true);

			// Casino Items
			Stats::SetInt("MPX_CASINO_DECORATION_GIFT_1", -1);
			Stats::SetInt("MPX_CH_ARC_CAB_CLAW_TROPHY", -1);
			Stats::SetInt("MPX_CH_ARC_CAB_LOVE_TROPHY", -1);

			LOG(INFO) << "Unlock All Items completed!";
		}
	};

	class UnlockAllClothesCommand : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			bool is_player_male = IsPlayerMale();

			// Clothing ranges
			for (int i = 110; i <= 113; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 3593; i <= 3599; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 3608; i <= 3609; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 3615; i <= 3616; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(3750, true);
			for (int i = 3770; i <= 3781; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 3783; i <= 3802; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 4247; i <= 4269; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 4300; i <= 4327; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 4333; i <= 4335; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 7467; i <= 7495; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 7515; i <= 7528; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(7551, true);
			for (int i = 7595; i <= 7601; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 9362; i <= 9385; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 9426; i <= 9440; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(9443, true);
			for (int i = 9461; i <= 9481; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 15388; i <= 15423; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 18121; i <= 18125; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 18134; i <= 18137; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 22124; i <= 22132; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 22147; i <= 22178; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 25018; i <= 25099; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 26968; i <= 27088; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 27147; i <= 27182; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 27184; i <= 27213; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 28171; i <= 28191; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 28197; i <= 28223; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 28224; i <= 28227; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 28229; i <= 28249; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 28254; i <= 28255; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 28319; i <= 28321; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 30254; i <= 30295; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 30524; i <= 30557; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 30563; i <= 30693; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 30699; i <= 30704; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 31708; i <= 31714; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(31736, true);
			for (int i = 31760; i <= 31764; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 31766; i <= 31777; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 31779; i <= 31796; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 31805; i <= 31808; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 31826; i <= 31978; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 31980; i <= 32074; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 32084; i <= 32273; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 32275; i <= 32291; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 32295; i <= 32311; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 32314; i <= 32316; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 32407; i <= 32408; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(32409, true);
			for (int i = 34372; i <= 34411; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 34415; i <= 34510; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 34703; i <= 34705; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 34730; i <= 34737; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(34761, true);
			for (int i = 36699; i <= 36770; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 36774; i <= 36788; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(36809, true);
			Stats::SetPackedBool(36825, true);
			Stats::SetPackedBool(41593, true);
			Stats::SetPackedBool(41674, true);
			Stats::SetPackedBool(41675, true);
			for (int i = 41806; i <= 41810; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 41884; i <= 41980; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 41994; i <= 41996; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 42052; i <= 42058; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(42062, true);
			Stats::SetPackedBool(42063, true);
			Stats::SetPackedBool(42068, true);
			Stats::SetPackedBool(42069, true);
			Stats::SetPackedBool(42111, true);
			for (int i = 42119; i <= 42123; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 42128; i <= 42146; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 42152; i <= 42190; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 42191; i <= 42216; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(42249, true);
			for (int i = 42286; i <= 42289; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 42294; i <= 42297; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 51215; i <= 51258; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(54569, true);
			Stats::SetPackedBool(54570, true);
			for (int i = 54572; i <= 54579; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 54594; i <= 54611; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 54614; i <= 54634; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(54635, true);
			Stats::SetPackedBool(54651, true);
			for (int i = 54682; i <= 54707; i++)
				Stats::SetPackedBool(i, true);

			// Gender-specific clothing
			if (is_player_male)
			{
				for (int i = 3483; i <= 3492; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 6082; i <= 6083; i++)
					Stats::SetPackedBool(i, true);
				Stats::SetPackedBool(6097, true);
				Stats::SetPackedBool(6169, true);
				for (int i = 6303; i <= 6304; i++)
					Stats::SetPackedBool(i, true);
				Stats::SetPackedBool(15708, true);
				Stats::SetPackedBool(15710, true);
				Stats::SetPackedBool(15717, true);
				Stats::SetPackedBool(15720, true);
				Stats::SetPackedBool(15724, true);
				Stats::SetPackedBool(15728, true);
				Stats::SetPackedBool(15730, true);
				Stats::SetPackedBool(15732, true);
				for (int i = 28393; i <= 28416; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 28447; i <= 28451; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 28452; i <= 28478; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 30355; i <= 30361; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 30407; i <= 30410; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 30418; i <= 30422; i++)
					Stats::SetPackedBool(i, true);
			}
			else
			{
				for (int i = 3496; i <= 3505; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 6091; i <= 6092; i++)
					Stats::SetPackedBool(i, true);
				Stats::SetPackedBool(6106, true);
				Stats::SetPackedBool(6181, true);
				for (int i = 6316; i <= 6317; i++)
					Stats::SetPackedBool(i, true);
				Stats::SetPackedBool(15719, true);
				Stats::SetPackedBool(15721, true);
				Stats::SetPackedBool(15728, true);
				Stats::SetPackedBool(15731, true);
				Stats::SetPackedBool(15735, true);
				Stats::SetPackedBool(15739, true);
				Stats::SetPackedBool(15741, true);
				Stats::SetPackedBool(15743, true);
				for (int i = 28404; i <= 28427; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 28458; i <= 28462; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 30418; i <= 30421; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 28463; i <= 28478; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 30355; i <= 30372; i++)
					Stats::SetPackedBool(i, true);
				for (int i = 30429; i <= 30433; i++)
					Stats::SetPackedBool(i, true);
			}

			// Shirt Unlocks
			Stats::SetBool("MPX_FILM4SHIRTUNLOCK", true);
			Stats::SetBool("MPX_FILM5SHIRTUNLOCK", true);
			Stats::SetBool("MPX_FILM6SHIRTUNLOCK", true);
			Stats::SetBool("MPX_FILM7SHIRTUNLOCK", true);
			Stats::SetBool("MPX_FILM8SHIRTUNLOCK", true);
			Stats::SetBool("MPX_FILM9SHIRTUNLOCK", true);
			Stats::SetBool("ACCOUNTANTSHIRTUNLOCK", true);
			Stats::SetBool("BAHAMAMAMASHIRTUNLOCK", true);
			Stats::SetBool("DRONESHIRTUNLOCK", true);
			Stats::SetBool("GROTTISHIRTUNLOCK", true);
			Stats::SetBool("GOLFSHIRTUNLOCK", true);
			Stats::SetBool("MAISONETTESHIRTUNLOCK", true);
			Stats::SetBool("MANOPAUSESHIRTUNLOCK", true);
			Stats::SetBool("MELTDOWNSHIRTUNLOCK", true);
			Stats::SetBool("PACIFICBLUFFSSHIRTUNLOCK", true);
			Stats::SetBool("PROLAPSSHIRTUNLOCK", true);
			Stats::SetBool("TENNISSHIRTUNLOCK", true);
			Stats::SetBool("TOESHOESSHIRTUNLOCK", true);
			Stats::SetBool("VANILLAUNICORNSHIRTUNLOCK", true);
			Stats::SetBool("MARLOWESHIRTUNLOCK", true);
			Stats::SetBool("CRESTSHIRTUNLOCK", true);

			// Hair Unlocks
			for (int i = 1; i <= 17; i++)
				Stats::SetInt(("MPX_CHAR_HAIR_UNLCK" + std::to_string(i)).c_str(), -1);

			// Tattoo Unlocks
			for (int i = 0; i <= 53; i++)
				Stats::SetInt(("MPX_TATTOO_FM_UNLOCKS_" + std::to_string(i)).c_str(), -1);

			LOG(INFO) << "Unlock All Clothes completed!";
		}
	};

	class UnlockAllVehiclesCommand : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			// Special Vehicles
			Stats::SetPackedBool(115, true);
			Stats::SetPackedBool(124, true);
			Stats::SetPackedBool(129, true);
			Stats::SetPackedBool(135, true);
			Stats::SetPackedBool(136, true);
			Stats::SetPackedBool(137, true);
			Stats::SetPackedBool(3604, true);
			Stats::SetPackedBool(3605, true);
			Stats::SetPackedBool(15381, true);
			Stats::SetPackedBool(15382, true);
			Stats::SetPackedBool(18099, true);

			// Arena War vehicles
			for (int i = 24963; i <= 25000; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 25101; i <= 25109; i++)
				Stats::SetPackedBool(i, true);

			// Tuner Cars
			for (int i = 31810; i <= 31824; i++)
				Stats::SetPackedBool(i, true);

			// Trade Prices
			Stats::SetPackedInt(22050, 5);
			Stats::SetPackedInt(22063, 20);
			Stats::SetPackedInt(24946, 100);
			Stats::SetPackedInt(24947, 100);
			Stats::SetPackedInt(24948, 100);
			Stats::SetPackedInt(3032, 100);

			// Police Vehicle Trade Prices
			Stats::SetPackedBool(28272, true);
			for (int i = 32319; i <= 32323; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(32366, true);
			for (int i = 41656; i <= 41659; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(41671, true);
			Stats::SetPackedBool(42016, true);
			Stats::SetPackedBool(42125, true);
			Stats::SetPackedBool(42233, true);
			Stats::SetPackedBool(42234, true);
			for (int i = 42239; i <= 42242; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 42244; i <= 42247; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 42280; i <= 42284; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(51283, true);
			Stats::SetPackedBool(51285, true);
			Stats::SetPackedBool(54637, true);
			Stats::SetPackedBool(54638, true);

			// Vehicle Upgrade Parts
			Stats::SetPackedInt(18982, 3);
			Stats::SetPackedInt(18983, 3);
			Stats::SetPackedInt(18984, 3);
			Stats::SetPackedInt(18985, 3);
			Stats::SetPackedInt(18986, 3);

			// HSW Liveries
			for (int i = 34138; i <= 34151; i++)
				Stats::SetPackedBool(i, true);

			// Christmas Liveries
			for (int i = 0; i <= 20; i++)
				Stats::SetInt(("MPPLY_XMASLIVERIES" + std::to_string(i)).c_str(), -1);

			// Chameleon Colors
			Stats::SetInt("MPPLY_XMAS22CPAINT0", -1);
			Stats::SetInt("MPPLY_XMAS22CPAINT1", -1);
			Stats::SetInt("MPPLY_SUM23WHEELCPAINT0", -1);
			Stats::SetInt("MPPLY_SUM23WHEELCPAINT1", -1);

			// Vehicle Stats
			Stats::SetInt("MPX_LFETIME_HANGAR_BUY_COMPLET", 100);
			Stats::SetInt("MPX_DCTL_WINS", 500);
			Stats::SetInt("MPX_DCTL_PLAY_COUNT", 750);
			Stats::SetInt("MPX_COUNT_HOTRING_RACE", 20);
			Stats::SetInt("MPX_FINISHED_SASS_RACE_TOP_3", 20);
			Stats::SetInt("MPX_AWD_CARS_EXPORTED", 50);
			Stats::SetBool("MPX_AWD_PRO_CAR_EXPORT", true);

			LOG(INFO) << "Unlock All Vehicles completed!";
		}
	};

	class UnlockAllWeaponsCommand : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			// Weapon Unlocks
			Stats::SetInt("MPX_CHAR_WEAP_UNLOCKED", -1);
			Stats::SetInt("MPX_CHAR_WEAP_UNLOCKED2", -1);
			Stats::SetInt("MPX_CHAR_FM_WEAP_UNLOCKED", -1);
			Stats::SetInt("MPX_CHAR_FM_WEAP_UNLOCKED2", -1);
			Stats::SetInt("MPX_CHAR_FM_WEAP_UNLOCKED3", -1);
			Stats::SetInt("MPX_CHAR_FM_WEAP_UNLOCKED4", -1);
			Stats::SetInt("MPX_CHAR_FM_WEAP_UNLOCKED5", -1);
			Stats::SetInt("MPX_CHAR_FM_WEAP_UNLOCKED6", -1);

			// Weapon Add-ons
			for (int i = 1; i <= 20; i++)
				Stats::SetInt(("MPX_CHAR_FM_WEAP_ADDON_" + std::to_string(i) + "_UNLCK").c_str(), -1);

			// Weapon Tints
			Stats::SetInt("MPX_PISTOL_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_CMBTPISTOL_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_APPISTOL_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_MICROSMG_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_SMG_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_ASLTSMG_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_CRBNRIFLE_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_ADVRIFLE_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_MG_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_PUMP_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_SAWNOFF_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_HVYSNIPER_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_GRNLAUNCH_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_MINIGUNS_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_ASLTSHTGN_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_ASLTRIFLE_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_SNIPERRFL_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_CMBTMG_ENEMY_KILLS", 600);
			Stats::SetInt("MPX_RPG_ENEMY_KILLS", 600);

			// Special Weapons
			Stats::SetPackedInt(7315, 6);
			Stats::SetPackedInt(18981, 4);
			Stats::SetBool("MPPLY_NAVYREVOLVERCOMPLETED", true);
			Stats::SetInt("MPX_REV_NV_KILLS", 50);

			// Shooting Range
			Stats::SetInt("MPX_SR_WEAPON_BIT_SET", 262143);
			Stats::SetBool("MPX_SR_TIER_1_REWARD", true);
			Stats::SetBool("MPX_SR_INCREASE_THROW_CAP", true);
			Stats::SetBool("MPX_SR_TIER_3_REWARD", true);

			// Mk II Ammo Types
			for (int i = 15456; i <= 15460; i++)
				Stats::SetPackedBool(i, true);

			// Gun Locker Fix
			Stats::SetInt("MPX_CHAR_WEAP_FM_PURCHASE3", -872415233);
			Stats::SetInt("MPX_CHAR_WEAP_FM_PURCHASE4", 126);

			LOG(INFO) << "Unlock All Weapons completed!";
		}
	};

	class UnlockAllCollectablesCommand : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			// Action Figures & Playing Cards
			for (int i = 26811; i <= 26964; i++)
				Stats::SetPackedBool(i, true);

			// Signal Jammers
			for (int i = 28099; i <= 28148; i++)
				Stats::SetPackedBool(i, true);

			// Movie Props
			for (int i = 30230; i <= 30251; i++)
				Stats::SetPackedBool(i, true);

			// Snowman
			for (int i = 36630; i <= 36654; i++)
				Stats::SetPackedBool(i, true);

			// Yuanbao Treasures
			for (int i = 51302; i <= 51337; i++)
				Stats::SetPackedBool(i, true);

			// Ghosts Exposed
			for (int i = 41316; i <= 41325; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 42257; i <= 42268; i++)
				Stats::SetPackedBool(i, true);
			Stats::SetPackedBool(54664, true);

			// Bronze Idol, Ornamental Egg, Tiki Statue
			Stats::SetPackedBool(51273, true);
			Stats::SetPackedBool(51274, true);
			Stats::SetPackedBool(51275, true);

			LOG(INFO) << "Unlock All Collectables completed!";
		}
	};

	class UnlockAllHeistsCommand : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			// Apartment Heists
			for (int i = 3765; i <= 3769; i++)
				Stats::SetPackedBool(i, true);

			Stats::SetInt("MPX_HEIST_SAVED_STRAND_0", 0);
			Stats::SetInt("MPX_HEIST_SAVED_STRAND_0_L", 5);
			Stats::SetInt("MPX_HEIST_SAVED_STRAND_1", 0);
			Stats::SetInt("MPX_HEIST_SAVED_STRAND_1_L", 5);
			Stats::SetInt("MPX_HEIST_SAVED_STRAND_2", 0);
			Stats::SetInt("MPX_HEIST_SAVED_STRAND_2_L", 5);
			Stats::SetInt("MPX_HEIST_SAVED_STRAND_3", 0);
			Stats::SetInt("MPX_HEIST_SAVED_STRAND_3_L", 5);
			Stats::SetInt("MPX_HEIST_SAVED_STRAND_4", 0);
			Stats::SetInt("MPX_HEIST_SAVED_STRAND_4_L", 5);

			Stats::SetInt("MPPLY_CREW_NO_HEISTS_0", 2);
			Stats::SetInt("MPPLY_CREW_NO_HEISTS_1", 5);
			Stats::SetInt("MPPLY_CREW_NO_HEISTS_2", 5);
			Stats::SetInt("MPPLY_CREW_NO_HEISTS_3", 5);
			Stats::SetInt("MPPLY_CREW_NO_HEISTS_4", 5);

			// Doomsday Heist
			for (int i = 18116; i <= 18118; i++)
				Stats::SetPackedBool(i, true);

			Stats::SetInt("MPPLY_GANGOPS_LOYALTY2", -1);
			Stats::SetInt("MPPLY_GANGOPS_LOYALTY3", -1);
			Stats::SetInt("MPPLY_GANGOPS_CRIMMASMD2", -1);
			Stats::SetInt("MPPLY_GANGOPS_CRIMMASMD3", -1);
			Stats::SetInt("MPPLY_GANGOPS_SUPPORT", -1);
			Stats::SetInt("MPPLY_GANGOPS_ALLINORDER", -1);
			Stats::SetInt("MPPLY_GANGOPS_LOYALTY", -1);
			Stats::SetInt("MPPLY_GANGOPS_CRIMMASMD", -1);

			// Diamond Casino Heist
			for (int i = 28194; i <= 28196; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 28224; i <= 28227; i++)
				Stats::SetPackedBool(i, true);
			for (int i = 28229; i <= 28249; i++)
				Stats::SetPackedBool(i, true);

			Stats::SetInt("MPX_H3_VEHICLESUSED", -1);

			// Cayo Perico Heist
			Stats::SetInt("MPX_H4_H4_DJ_MISSIONS", 127);
			Stats::SetInt("MPX_H4_PROGRESS", -1);
			Stats::SetBool("MPX_COMPLETE_H4_F_USING_VETIR", true);
			Stats::SetBool("MPX_COMPLETE_H4_F_USING_LONGFIN", true);
			Stats::SetBool("MPX_COMPLETE_H4_F_USING_ANNIH", true);
			Stats::SetBool("MPX_COMPLETE_H4_F_USING_ALKONOS", true);
			Stats::SetBool("MPX_COMPLETE_H4_F_USING_PATROLB", true);

			// Auto Shop Heists
			Stats::SetInt("MPX_TUNER_GEN_BS", 12543);
			Stats::SetInt("MPX_TUNER_COMP_BS", 255);
			Stats::SetInt("MPX_AWD_AUTO_SHOP", 5);

			// Agency Heists/Contracts
			Stats::SetInt("MPX_FIXER_STORY_BS", 4095);
			Stats::SetInt("MPX_FIXER_COMPLETED_BS", -1);
			Stats::SetInt("MPX_FIXER_GENERAL_BS", -1);

			LOG(INFO) << "Unlock All Heists completed!";
		}
	};

	class UnlockAllAwardsCommand : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			// General Awards
			Stats::SetInt("MPX_AWD_FM_DM_WINS", 50);
			Stats::SetInt("MPX_AWD_FM_TDM_WINS", 50);
			Stats::SetInt("MPX_AWD_FM_TDM_MVP", 50);
			Stats::SetInt("MPX_AWD_RACES_WON", 50);
			Stats::SetInt("MPX_AWD_FMWINAIRRACE", 25);
			Stats::SetInt("MPX_AWD_FMWINSEARACE", 25);
			Stats::SetInt("MPX_AWD_FM_GTA_RACES_WON", 50);
			Stats::SetBool("MPX_AWD_FMKILL3ANDWINGTARACE", true);
			Stats::SetInt("MPX_AWD_FMRALLYWONDRIVE", 25);
			Stats::SetInt("MPX_AWD_FMRALLYWONNAV", 25);
			Stats::SetInt("MPX_AWD_FMWINRACETOPOINTS", 25);
			Stats::SetBool("MPX_AWD_FMWINCUSTOMRACE", true);
			Stats::SetInt("MPX_AWD_FM_RACE_LAST_FIRST", 25);
			Stats::SetBool("MPX_AWD_FMRACEWORLDRECHOLDER", true);
			Stats::SetInt("MPX_AWD_FM_RACES_FASTEST_LAP", 50);
			Stats::SetBool("MPX_AWD_FMWINALLRACEMODES", true);
			Stats::SetInt("MPX_AWD_FMHORDWAVESSURVIVE", 10);

			// Sports Awards
			Stats::SetInt("MPX_MOST_ARM_WRESTLING_WINS", 25);
			Stats::SetInt("MPX_AWD_WIN_AT_DARTS", 25);
			Stats::SetInt("MPX_AWD_FM_GOLF_WON", 25);
			Stats::SetInt("MPX_AWD_FM_TENNIS_WON", 25);
			Stats::SetBool("MPX_AWD_FM_TENNIS_5_SET_WINS", true);
			Stats::SetBool("MPX_AWD_FM_TENNIS_STASETWIN", true);
			Stats::SetInt("MPX_AWD_FM_GOLF_BIRDIES", 25);
			Stats::SetBool("MPX_AWD_FM_GOLF_HOLE_IN_1", true);
			Stats::SetInt("MPX_AWD_FM_TENNIS_ACE", 25);

			// Shooting Range Awards
			Stats::SetInt("MPX_AWD_FM_SHOOTRANG_TG_WON", 25);
			Stats::SetInt("MPX_AWD_FM_SHOOTRANG_CT_WON", 25);
			Stats::SetBool("MPX_AWD_FM_SHOOTRANG_GRAN_WON", true);
			Stats::SetInt("MPX_AWD_FM_SHOOTRANG_RT_WON", 25);

			// Heist Awards
			Stats::SetBool("MPPLY_AWD_FLEECA_FIN", true);
			Stats::SetBool("MPPLY_AWD_PRISON_FIN", true);
			Stats::SetBool("MPPLY_AWD_HUMANE_FIN", true);
			Stats::SetBool("MPPLY_AWD_SERIESA_FIN", true);
			Stats::SetBool("MPPLY_AWD_PACIFIC_FIN", true);
			Stats::SetBool("MPPLY_AWD_HST_ORDER", true);
			Stats::SetBool("MPPLY_AWD_HST_SAME_TEAM", true);
			Stats::SetBool("MPPLY_AWD_HST_ULT_CHAL", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_IAA", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_SUBMARINE", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_MISSILE", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_ALLINORDER", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_LOYALTY", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_LOYALTY2", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_LOYALTY3", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_CRIMMASMD", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_CRIMMASMD2", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_CRIMMASMD3", true);
			Stats::SetBool("MPPLY_AWD_GANGOPS_SUPPORT", true);

			// Casino Heist Awards
			Stats::SetBool("MPX_AWD_SCOPEOUT", true);
			Stats::SetInt("MPX_AWD_PREPARATION", 40);
			Stats::SetBool("MPX_AWD_CREWEDUP", true);
			Stats::SetBool("MPX_AWD_GUNMAN", true);
			Stats::SetBool("MPX_AWD_SMASHNGRAB", true);
			Stats::SetBool("MPX_AWD_INPLAINSI", true);
			Stats::SetBool("MPX_AWD_UNDETECTED", true);
			Stats::SetBool("MPX_AWD_ALLROUND", true);
			Stats::SetBool("MPX_AWD_ELITETHEIF", true);

			// Nightclub Awards
			Stats::SetInt("MPX_AWD_CLUB_DRUNK", 200);
			Stats::SetInt("MPX_DANCEPERFECTOWNCLUB", 100);
			Stats::SetInt("MPX_NIGHTCLUB_PLAYER_APPEAR", 500);
			Stats::SetInt("MPX_AWD_DANCE_TO_SOLOMUN", 100);
			Stats::SetInt("MPX_AWD_DANCE_TO_TALEOFUS", 100);
			Stats::SetInt("MPX_AWD_DANCE_TO_DIXON", 100);
			Stats::SetInt("MPX_AWD_DANCE_TO_BLKMAD", 100);
			Stats::SetInt("MPX_DANCETODIFFDJS", 4);

			// Arena War Awards
			Stats::SetInt("MPX_AWD_ARENA_WAGEWORKER", 20000000);
			Stats::SetInt("MPX_AWD_WEVE_GOT_ONE", 50);
			Stats::SetInt("MPX_AWD_YOURE_OUTTA_HERE", 200);
			Stats::SetInt("MPX_AWD_MASSIVE_SHUNT", 50);
			Stats::SetInt("MPX_AWD_KILL_OR_BE_KILLED", 50);
			Stats::SetInt("MPX_AWD_CROWDPARTICIPATION", 50);
			Stats::SetInt("MPX_AWD_SITTING_DUCK", 50);
			Stats::SetInt("MPX_AWD_YOUMEANBOOBYTRAPS", 50);
			Stats::SetInt("MPX_AWD_MASTER_BANDITO", 50);
			Stats::SetInt("MPX_AWD_SPINNER", 50);
			Stats::SetInt("MPX_AWD_THROUGH_A_LENS", 50);
			Stats::SetInt("MPX_AWD_READY_FOR_WAR", 50);
			Stats::SetBool("MPX_AWD_UNSTOPPABLE", true);
			Stats::SetBool("MPX_AWD_CONTACT_SPORT", true);
			Stats::SetInt("MPX_AWD_TOWER_OFFENSE", 50);
			Stats::SetInt("MPX_AWD_WATCH_YOUR_STEP", 50);
			Stats::SetBool("MPX_AWD_PEGASUS", true);

			// Cayo Perico Awards
			Stats::SetBool("MPX_AWD_INTELGATHER", true);
			Stats::SetBool("MPX_AWD_COMPOUNDINFILT", true);
			Stats::SetInt("MPX_AWD_WELL_PREPARED", 50);
			Stats::SetBool("MPX_AWD_LOOT_FINDER", true);
			Stats::SetBool("MPX_AWD_MAX_DISRUPT", true);
			Stats::SetBool("MPX_AWD_THE_ISLAND_HEIST", true);
			Stats::SetBool("MPX_AWD_GOING_ALONE", true);
			Stats::SetBool("MPX_AWD_TEAM_WORK", true);
			Stats::SetBool("MPX_AWD_MIXING_UP", true);
			Stats::SetBool("MPX_AWD_PRO_THIEF", true);
			Stats::SetBool("MPX_AWD_CAT_BURGLAR", true);
			Stats::SetInt("MPX_AWD_FILL_YOUR_BAGS", 20000000);
			Stats::SetBool("MPX_AWD_GOLDEN_GUN", true);
			Stats::SetBool("MPX_AWD_ELITE_THIEF", true);

			// LS Car Meet Awards
			Stats::SetInt("MPX_AWD_CAR_CLUB_MEM", 1000);
			Stats::SetInt("MPX_AWD_SPRINTRACER", 50);
			Stats::SetInt("MPX_AWD_STREETRACER", 50);
			Stats::SetInt("MPX_AWD_PURSUITRACER", 50);
			Stats::SetInt("MPX_AWD_TEST_CAR", 1800000);

			LOG(INFO) << "Unlock All Awards completed!";
		}
	};

	class UnlockAllPropertiesCommand : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			// Agency
			Stats::SetInt("MPX_FIXER_HQ_OWNED", 1);
			Stats::SetBool("MPX_BS_IMANI_D_APP_SETUP", true);
			Stats::SetBool("MPX_BS_IMANI_D_APP_STRAND", true);
			Stats::SetBool("MPX_BS_IMANI_D_APP_PARTY", true);
			Stats::SetBool("MPX_BS_IMANI_D_APP_BILL", true);
			Stats::SetBool("MPX_BS_IMANI_D_APP_HOOD", true);

			// Nightclub
			Stats::SetPackedBool(22067, true);
			Stats::SetPackedBool(22068, true);
			Stats::SetPackedBool(15533, true);
			Stats::SetPackedBool(22082, true);
			Stats::SetPackedBool(22083, true);
			Stats::SetPackedBool(36944, true);
			Stats::SetInt("MPX_NIGHTCLUB_VIP_APPEAR", 25);
			Stats::SetInt("MPX_NIGHTCLUB_JOBS_DONE", 25);

			// Acid Lab
			Stats::SetPackedBool(42037, true);
			Stats::SetPackedBool(42038, true);
			Stats::SetPackedBool(42041, true);
			Stats::SetPackedBool(42042, true);

			// Hangar
			Stats::SetPackedBool(15966, true);
			Stats::SetPackedBool(41676, true);
			Stats::SetInt("MPX_LFETIME_HANGAR_SEL_COMPLET", 1);

			// Bunker
			Stats::SetInt("MPX_FACTORYSETUP5", 1);
			Stats::SetPackedInt(9359, 25);

			// Vehicle Warehouse
			Stats::SetInt("MPX_OWNED_IE_WAREHOUSE", 1);
			Stats::SetInt("MPX_LFETIME_IE_EXPORT_COMPLETED", 25);

			// Arcade
			Stats::SetPackedBool(28270, true);

			// Facility
			Stats::SetPackedBool(18139, true);
			Stats::SetPackedBool(36861, true);

			// Kosatka
			Stats::SetPackedBool(30522, true);
			Stats::SetInt("MPX_CR_SUBMARINE", 1);

			// Auto Shop
			Stats::SetPackedBool(31753, true);
			Stats::SetInt("MPX_TUNER_COUNT", 25);

			// Salvage Yard
			Stats::SetInt("MPX_SALVAGE_YARD_OWNED", 1);
			for (int i = 42044; i <= 42051; i++)
				Stats::SetPackedBool(i, true);

			// Bail Office
			Stats::SetInt("MPX_BAIL_OFFICE_OWNED", 1);
			Stats::SetPackedBool(9537, true);
			Stats::SetPackedBool(7639, true);

			// Garment Factory
			Stats::SetInt("MPX_HACKER_DEN_OWNED", 1);
			Stats::SetPackedBool(9539, true);

			// Other Properties
			Stats::SetInt("MPX_SB_CAR_WASH_OWNED", 1);
			Stats::SetInt("MPX_SB_HELI_TOURS_OWNED", 1);
			Stats::SetInt("MPX_SB_WEED_SHOP_OWNED", 1);
			for (int i = 28313; i <= 28318; i++)
				Stats::SetPackedBool(i, true);

			// CEO Office
			for (int i = 7553; i <= 7592; i++)
				Stats::SetPackedBool(i, true);

			// Biker Clubhouse
			Stats::SetInt("MPX_LIFETIME_BKR_SELL_COMPLETBC", 1);
			Stats::SetInt("MPX_BAR_RESUPPLY_CR", 10);

			// High-end Apartment
			Stats::SetPackedBool(36867, true);
			Stats::SetPackedBool(36868, true);

			LOG(INFO) << "Unlock All Properties completed!";
		}
	};

	static UnlockAllItemsCommand _UnlockAllItemsCommand{"unlockallitems", "Unlock All Items", "Unlocks all trophies, decorations, arcade machines, and business battle items"};
	static UnlockAllClothesCommand _UnlockAllClothesCommand{"unlockallclothes", "Unlock All Clothes", "Unlocks all clothing, outfits, masks, hats, and accessories"};
	static UnlockAllVehiclesCommand _UnlockAllVehiclesCommand{"unlockallvehicles", "Unlock All Vehicles", "Unlocks all special vehicles, trade prices, liveries, and upgrades"};
	static UnlockAllWeaponsCommand _UnlockAllWeaponsCommand{"unlockallweapons", "Unlock All Weapons", "Unlocks all weapons, MKII upgrades, tints, and attachments"};
	static UnlockAllCollectablesCommand _UnlockAllCollectablesCommand{"unlockallcollectables", "Unlock All Collectables", "Unlocks all action figures, playing cards, signal jammers, and movie props"};
	static UnlockAllHeistsCommand _UnlockAllHeistsCommand{"unlockallheists", "Unlock All Heists", "Unlocks all heists including Apartment, Doomsday, Casino, and Cayo Perico"};
	static UnlockAllAwardsCommand _UnlockAllAwardsCommand{"unlockallawards", "Unlock All Awards", "Unlocks all awards, achievements, and accolades"};
	static UnlockAllPropertiesCommand _UnlockAllPropertiesCommand{"unlockallproperties", "Unlock All Properties", "Unlocks all properties, businesses, and safehouses"};
}