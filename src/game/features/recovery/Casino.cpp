#include "core/commands/LoopedCommand.hpp"
#include "core/commands/Command.hpp"
#include "core/commands/ListCommand.hpp"
#include "core/commands/IntCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/gta/Natives.hpp"
#include "game/gta/ScriptLocal.hpp"
#include "game/gta/ScriptGlobal.hpp"
#include "game/gta/Stats.hpp"
#include "game/backend/Tunables.hpp"
#include "core/backend/ScriptMgr.hpp"

#include <set>
#include <random>
#include <ctime>

namespace YimMenu::Features
{
	static std::vector<std::pair<int, const char*>> wheelPrizes = {
	    {0, "Clothing 1"},
	    {1, "2,500 RP"},
	    {2, "$20,000"},
	    {3, "10,000 Chips"},
	    {4, "Discount"},
	    {5, "5,000 RP"},
	    {6, "$30,000"},
	    {7, "15,000 Chips"},
	    {8, "Clothing 2"},
	    {9, "7,500 RP"},
	    {10, "20,000 Chips"},
	    {11, "Mystery Prize"},
	    {12, "Clothing 3"},
	    {13, "10,000 RP"},
	    {14, "$40,000"},
	    {15, "25,000 Chips"},
	    {17, "15,000 RP"},
	    {18, "Vehicle"},
	    {19, "$50,000"}};

	static ListCommand _CasinoWheelPrize{"casinowheelprize", "Lucky Wheel Prize", "Select prize for lucky wheel", wheelPrizes, 18};

	class CasinoSlotsWin : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int randomResultTable = 1374; 
			for (int i = 3; i <= 196; i++)
			{
				if (i != 67 && i != 132)
				{
					*ScriptLocal("casino_slots"_J, randomResultTable + i).As<int*>() = 6;
				}
			}
			LOG(INFO) << "Slots rigged to win!";
		}
	};

	class CasinoSlotsLose : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int randomResultTable = 1374; 
			for (int i = 3; i <= 196; i++)
			{
				if (i != 67 && i != 132)
				{
					*ScriptLocal("casino_slots"_J, randomResultTable + i).As<int*>() = 0;
				}
			}
			LOG(INFO) << "Slots forced to lose!";
		}
	};

	class CasinoGiveWheelPrize : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int prize = _CasinoWheelPrize.GetState();
			*ScriptLocal("casino_lucky_wheel"_J, 318).As<int*>() = prize;
			*ScriptLocal("casino_lucky_wheel"_J, 349).As<int*>() = 11; 
			LOG(INFO) << "Lucky wheel prize given: " << prize;
		}
	};

	class CasinoBypass : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Stats::SetInt("MPPLY_CASINO_CHIPS_WON_GD", 0);
			Stats::SetInt("MPPLY_CASINO_CHIPS_WONTIM", 0);
			Stats::SetInt("MPPLY_CASINO_GMBLNG_GD", 0);
			Stats::SetInt("MPPLY_CASINO_BAN_TIME", 0);
			Stats::SetInt("MPPLY_CASINO_CHIPS_PURTIM", 0);
			Stats::SetInt("MPPLY_CASINO_CHIPS_PUR_GD", 0);

			*ScriptGlobal(1972794).As<BOOL*>() = true;

			ScriptMgr::Yield(5000ms);
		}
	};

	static std::vector<std::pair<int, const char*>> chipLimits = {
	    {20000, "20,000 Chips (Standard)"},
	    {50000, "50,000 Chips (Penthouse)"}};

	static ListCommand _CasinoChipLimit{"casinochiplimit", "Chip Purchase Limit", "Select chip purchase limit", chipLimits, 0};

	class CasinoAcquireChips : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int limit = _CasinoChipLimit.GetState();
			int tunableHash = (limit == 20000) ? 0x7E4B8C1A : 0x7E4B8C1B;
			Tunable buyLimit(tunableHash);
			if (buyLimit.IsReady())
				buyLimit.Set(limit);
			LOG(INFO) << "Chip purchase limit set to: " << limit;
		}
	};

	class CasinoTradeChips : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			Tunable tradeLimit(0x2C9F4D8C);
			if (tradeLimit.IsReady())
				tradeLimit.Set(10000000);
			LOG(INFO) << "Chip trade limit set to 10,000,000";
		}
	};

	static CasinoSlotsWin _CasinoSlotsWin{"casinoslotswin", "Rig Slot Machines", "Forces slot machines to give jackpot"};
	static CasinoSlotsLose _CasinoSlotsLose{"casinoslotslose", "Lose Slot Machines", "Forces slot machines to lose"};
	static CasinoGiveWheelPrize _CasinoGiveWheelPrize{"casinogivewheelprize", "Give Lucky Wheel Prize", "Gives selected lucky wheel prize"};
	static CasinoBypass _CasinoBypass{"casinobypass", "Bypass Casino Limits", "Bypasses casino purchase and time limits"};
	static CasinoAcquireChips _CasinoAcquireChips{"casinoacquirechips", "Set Chip Purchase Limit", "Sets maximum chips you can buy"};
	static CasinoTradeChips _CasinoTradeChips{"casinotradechips", "Set Chip Trade Limit", "Sets maximum chips you can trade in"};
}
