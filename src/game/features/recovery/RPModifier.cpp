#include "core/commands/ListCommand.hpp"
#include "core/commands/Command.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/gta/ScriptGlobal.hpp"
#include "game/gta/Stats.hpp"
#include "core/backend/ScriptMgr.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/backend/tunables.hpp"
#include "types/script/globals/GPBD_FM.hpp"
#include "types/script/globals/GPBD_FM_2.hpp"

namespace YimMenu::Features
{
	enum class eAppVinewoodMenuSafe
	{
		NIGHTCLUB,
		ARCADE,
		AGENCY,
		SALVAGE_YARD,
		BAIL_OFFICE,
		GARMENT_FACTORY,
		HANDS_ON_CAR_WASH
	};

	static std::vector<std::pair<int, const char*>> businessNames = {
	    {static_cast<int>(eAppVinewoodMenuSafe::NIGHTCLUB), "Nightclub"},
	    {static_cast<int>(eAppVinewoodMenuSafe::ARCADE), "Arcade"},
	    {static_cast<int>(eAppVinewoodMenuSafe::AGENCY), "Agency"},
	    {static_cast<int>(eAppVinewoodMenuSafe::SALVAGE_YARD), "Salvage Yard"},
	    {static_cast<int>(eAppVinewoodMenuSafe::BAIL_OFFICE), "Bail Office"},
	    {static_cast<int>(eAppVinewoodMenuSafe::GARMENT_FACTORY), "Garment Factory"},
	    {static_cast<int>(eAppVinewoodMenuSafe::HANDS_ON_CAR_WASH), "Hands on Car Wash"}};

	static ListCommand _SelectedBusiness{"businesssafe", "Business", "Business to claim earning from.", businessNames, 0};

	class ClaimSafeEarnings : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (!*Pointers.IsSessionStarted)
				return;

			switch (static_cast<eAppVinewoodMenuSafe>(_SelectedBusiness.GetState()))
			{
			case eAppVinewoodMenuSafe::NIGHTCLUB:
			{
				if (GPBD_FM::Get()->Entries[Self::GetPlayer().GetId()].PropertyData.NightclubData.SafeCashValue > 0)
					*ScriptGlobal(2708832).As<BOOL*>() = TRUE;
				break;
			}
			case eAppVinewoodMenuSafe::ARCADE:
			{
				if (GPBD_FM::Get()->Entries[Self::GetPlayer().GetId()].PropertyData.ArcadeData.SafeCashValue > 0)
					*ScriptGlobal(2708841).As<BOOL*>() = TRUE;
				break;
			}
			case eAppVinewoodMenuSafe::AGENCY:
			{
				if (GPBD_FM::Get()->Entries[Self::GetPlayer().GetId()].PropertyData.FixerHQData.SafeCashValue > 0)
					*ScriptGlobal(2708850).As<BOOL*>() = TRUE;
				break;
			}
			case eAppVinewoodMenuSafe::SALVAGE_YARD:
			{
				if (GPBD_FM::Get()->Entries[Self::GetPlayer().GetId()].PropertyData.SalvageYardData.TotalEarnings > 0)
					*ScriptGlobal(2708859).As<BOOL*>() = TRUE;
				break;
			}
			case eAppVinewoodMenuSafe::BAIL_OFFICE:
			{
				if (GPBD_FM::Get()->Entries[Self::GetPlayer().GetId()].PropertyData.BailShopData.SafeCashValue > 0)
					*ScriptGlobal(2708868).As<BOOL*>() = TRUE;
				break;
			}
			case eAppVinewoodMenuSafe::GARMENT_FACTORY:
			{
				if (GPBD_FM::Get()->Entries[Self::GetPlayer().GetId()].PropertyData.HackerDenData.SafeCashValue > 0)
					*ScriptGlobal(2708883).As<BOOL*>() = TRUE;
				break;
			}
			case eAppVinewoodMenuSafe::HANDS_ON_CAR_WASH:
			{
				if (GPBD_FM_2::Get()->Entries[Self::GetPlayer().GetId()].SYVehSaleData.HOWCData.SafeCashValue > 0)
					*ScriptGlobal(2708890).As<BOOL*>() = TRUE;
				break;
			}
			}
		}
	};

	static ClaimSafeEarnings _ClaimSafeEarnings{"claimsafeearnings", "Claim Safe Earnings", "Claims your safe earnings from the selected business."};

	class NightclubSafeLoop : public LoopedCommand
	{
	public:
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Stats::SetInt("mpx_club_popularity", 1000);
			Stats::SetInt("mpx_club_pay_time_left", -1);

			if (GPBD_FM::Get()->Entries[Self::GetPlayer().GetId()].PropertyData.NightclubData.SafeCashValue > 0)
			{
				*ScriptGlobal(2708832).As<BOOL*>() = TRUE;
			}
		}
	};

	class AgencySafeLoop : public LoopedCommand
	{
	public:
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Stats::SetInt("mpx_FIXER_COUNT", 500);
			Stats::SetInt("mpx_FIXER_PASSIVE_PAY_TIME_LEFT", -1);

			if (GPBD_FM::Get()->Entries[Self::GetPlayer().GetId()].PropertyData.FixerHQData.SafeCashValue > 0)
			{
				*ScriptGlobal(2708850).As<BOOL*>() = TRUE;
			}
		}
	};

	static NightclubSafeLoop _NightclubSafeLoop{"nightclubsafeloop", "Nightclub Safe Loop", "50K Loop"};
	static AgencySafeLoop _AgencySafeLoop{"agencysafeloop", "Agency Safe Loop", "20K Loop"};

	enum class eHangarGoodType
	{
		ANIMAL_MATERIALS = 0,
		ART_AND_ANTIQUES = 1,
		CHEMICALS = 2,
		COUNTERFEIT_GOODS = 3,
		JEWELRY_AND_GEMSTONES = 4,
		MEDICAL_SUPPLIES = 5,
		NARCOTICS = 6,
		TOBACCO_AND_ALCOHOL = 7
	};

	enum class eWarehouseGoodType
	{
		MEDICAL_SUPPLIES = 0,
		TOBACCO_AND_ALCOHOL = 1,
		ART_AND_ANTIQUES = 2,
		ELECTRONIC_GOODS = 3,
		WEAPONS_AND_AMMO = 4,
		NARCOTICS = 5,
		GEMSTONES = 6,
		ANIMAL_MATERIALS = 7,
		COUNTERFEIT_GOODS = 8,
		JEWELRY = 9,
		BULLION = 10
	};

	static std::vector<std::pair<int, const char*>> hangarGoodTypes = {
	    {0, "Animal Materials"},
	    {1, "Art & Antiques"},
	    {2, "Chemicals"},
	    {3, "Counterfeit Goods"},
	    {4, "Jewelry & Gemstones"},
	    {5, "Medical Supplies"},
	    {6, "Narcotics"},
	    {7, "Tobacco & Alcohol"}};

	static std::vector<std::pair<int, const char*>> warehouseGoodTypes = {
	    {0, "Medical Supplies"},
	    {1, "Tobacco & Alcohol"},
	    {2, "Art & Antiques"},
	    {3, "Electronic Goods"},
	    {4, "Weapons & Ammo"},
	    {5, "Narcotics"},
	    {6, "Gemstones"},
	    {7, "Animal Materials"},
	    {8, "Counterfeit Goods"},
	    {9, "Jewelry"},
	    {10, "Bullion"}};

	static ListCommand _HangarGoodType{"hangargoodtype", "Hangar Good Type", "Select goods type for Hangar", hangarGoodTypes, 6};
	static ListCommand _WarehouseGoodType{"warehousegoodtype", "Warehouse Good Type", "Select goods type for Warehouse", warehouseGoodTypes, 5};

	static auto SetTunable = [](int hash, int value) {
		Tunable tunable(hash);
		if (tunable.IsReady())
			tunable.Set(value);
	};

	class HangarRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int hangarprop = 1845299 + 1 + 260 + 304;

			if (*ScriptGlobal(hangarprop).As<int*>() >= 1)
			{
				if (*ScriptGlobal(hangarprop + 3).As<int*>() <= 49)
				{
					*ScriptGlobal(1882707 + 8).As<int*>() = _HangarGoodType.GetState();
					*ScriptGlobal(1882707 + 7).As<int*>() = 50;
					Stats::SetPackedBool(36828, true);
					LOG(INFO) << "Hangar goods replenished!";
				}
				else
				{
					LOG(WARNING) << "Hangar is at max capacity!";
				}
			}
			else
			{
				LOG(WARNING) << "You don't own a Hangar!";
			}
		}
	};

	class WarehouseRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int whprop = 1845299 + 1 + 260 + 128;

			if (*ScriptGlobal(whprop + 1).As<int*>() >= 1)
			{
				for (int c = 0; c < 5; c++)
				{
					if (*ScriptGlobal(whprop + 1).At(c, 3).As<int*>() <= 110)
					{
						*ScriptGlobal(1882682 + 16).As<int*>() = _WarehouseGoodType.GetState();
						*ScriptGlobal(1882682 + 13).As<int*>() = 111;
						for (int wh = 32359; wh <= 32363; wh++)
						{
							Stats::SetPackedBool(wh, true);
						}
						LOG(INFO) << "Warehouse goods replenished!";
					}
				}
			}
			else
			{
				LOG(WARNING) << "You don't own a Warehouse!";
			}
		}
	};

	class MCBusinessSupplies : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int bbizprop = 1845299 + 1 + 260 + 205;

			for (int b = 0; b < 8; b++)
			{
				if (*ScriptGlobal(bbizprop).At(b, 13).As<int*>() >= 1)
				{
					for (int bsup = 1; bsup <= 7; bsup++)
					{
						*ScriptGlobal(1673814 + bsup).As<int*>() = 1;
					}
					LOG(INFO) << "MC Business supplies replenished!";
					return;
				}
			}
			LOG(WARNING) << "You don't own any MC Business!";
		}
	};

	class MethRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int bbizprop = 1845299 + 1 + 260 + 205;
			bool found = false;

			for (int slot = 0; slot < 5; slot++)
			{
				int bizId = *ScriptGlobal(bbizprop).At(slot, 13).As<int*>();
				if (bizId <= 0)
					continue;

				int currentStock = *ScriptGlobal(bbizprop + 1).At(slot, 13).As<int*>();

				if ((bizId == 1 || bizId == 6 || bizId == 11 || bizId == 16) && currentStock <= 19)
				{
					SetTunable(1370024930, 1);
					SetTunable(1944848251, 1);
					SetTunable(1577999189, 1);
					SetTunable(1678460062, 1);
					SetTunable(-730135062, 1);
					SetTunable(-660914094, 1);
					LOG(INFO) << "Meth Business restock ready!";
					found = true;
					break;
				}
			}
			if (!found)
				LOG(WARNING) << "Meth Lab not found or at max capacity!";
		}
	};

	class WeedRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int bbizprop = 1845299 + 1 + 260 + 205;
			bool found = false;

			for (int slot = 0; slot < 5; slot++)
			{
				int bizId = *ScriptGlobal(bbizprop).At(slot, 13).As<int*>();
				if (bizId <= 0)
					continue;

				int currentStock = *ScriptGlobal(bbizprop + 1).At(slot, 13).As<int*>();

				if ((bizId == 2 || bizId == 7 || bizId == 12 || bizId == 17) && currentStock <= 79)
				{
					SetTunable(-635596193, 1);
					SetTunable(-1694873660, 1);
					SetTunable(1575359233, 1);
					SetTunable(102029883, 1);
					SetTunable(-373027461, 1);
					SetTunable(1195564032, 1);
					LOG(INFO) << "Weed Business restock ready!";
					found = true;
					break;
				}
			}
			if (!found)
				LOG(WARNING) << "Weed Farm not found or at max capacity!";
		}
	};

	class CokeRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int bbizprop = 1845299 + 1 + 260 + 205;
			bool found = false;

			for (int slot = 0; slot < 5; slot++)
			{
				int bizId = *ScriptGlobal(bbizprop).At(slot, 13).As<int*>();
				if (bizId <= 0)
					continue;

				int currentStock = *ScriptGlobal(bbizprop + 1).At(slot, 13).As<int*>();

				if ((bizId == 3 || bizId == 8 || bizId == 13 || bizId == 18) && currentStock <= 9)
				{
					SetTunable(702413484, 1);
					SetTunable(2070857577, 1);
					SetTunable(-1539796661, 1);
					SetTunable(396217128, 1);
					SetTunable(-161187879, 1);
					SetTunable(1500658261, 1);
					LOG(INFO) << "Cocaine Business restock ready!";
					found = true;
					break;
				}
			}
			if (!found)
				LOG(WARNING) << "Coke Lockup not found or at max capacity!";
		}
	};

	class CashRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int bbizprop = 1845299 + 1 + 260 + 205;
			bool found = false;

			for (int slot = 0; slot < 5; slot++)
			{
				int bizId = *ScriptGlobal(bbizprop).At(slot, 13).As<int*>();
				if (bizId <= 0)
					continue;

				int currentStock = *ScriptGlobal(bbizprop + 1).At(slot, 13).As<int*>();

				if ((bizId == 4 || bizId == 9 || bizId == 14 || bizId == 19) && currentStock <= 39)
				{
					SetTunable(1310272402, 1);
					SetTunable(1690071006, 1);
					SetTunable(-1454958662, 1);
					SetTunable(-1913260493, 1);
					SetTunable(631857857, 1);
					SetTunable(-891680742, 1);
					LOG(INFO) << "Cash Business restock ready!";
					found = true;
					break;
				}
			}
			if (!found)
				LOG(WARNING) << "Cash Factory not found or at max capacity!";
		}
	};

	class DocumentsRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int bbizprop = 1845299 + 1 + 260 + 205;
			bool found = false;

			for (int slot = 0; slot < 5; slot++)
			{
				int bizId = *ScriptGlobal(bbizprop).At(slot, 13).As<int*>();
				if (bizId <= 0)
					continue;

				int currentStock = *ScriptGlobal(bbizprop + 1).At(slot, 13).As<int*>();

				if ((bizId == 5 || bizId == 10 || bizId == 15 || bizId == 20) && currentStock <= 59)
				{
					SetTunable(-959721585, 1);
					SetTunable(1672482518, 1);
					SetTunable(-518264160, 1);
					SetTunable(489023341, 1);
					SetTunable(-1839004359, 1);
					SetTunable(-192060672, 1);
					LOG(INFO) << "Documents Business restock ready!";
					found = true;
					break;
				}
			}
			if (!found)
				LOG(WARNING) << "Document Forgery not found or at max capacity!";
		}
	};

	class BunkerRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int bbizprop = 1845299 + 1 + 260 + 205;
			bool found = false;

			for (int slot = 0; slot < 5; slot++)
			{
				int bizId = *ScriptGlobal(bbizprop).At(slot, 13).As<int*>();
				if (bizId >= 21 && bizId <= 31)
				{
					int currentStock = *ScriptGlobal(bbizprop + 1).At(slot, 13).As<int*>();
					if (currentStock <= 99)
					{
						SetTunable(215868155, 1);
						SetTunable(631477612, 1);
						SetTunable(818645907, 1);
						SetTunable(-1652502760, 1);
						SetTunable(1647327744, 1);
						LOG(INFO) << "Bunker restock ready!";
						found = true;
					}
					break;
				}
			}
			if (!found)
				LOG(WARNING) << "Bunker not found or at max capacity!";
		}
	};

	class AcidLabRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int bbizprop = 1845299 + 1 + 260 + 205;

			if (*ScriptGlobal(bbizprop).At(6, 13).As<int*>() >= 1)
			{
				int currentStock = *ScriptGlobal(bbizprop + 1).At(6, 13).As<int*>();
				if (currentStock <= 159)
				{
					SetTunable(-672998848, 1);
					SetTunable(494316332, 1);
					SetTunable(-40235252, 1);
					SetTunable(-1506354854, 1);
					SetTunable(-993236072, 1);
					LOG(INFO) << "Acid Lab restock ready!";
				}
				else
				{
					LOG(WARNING) << "Acid Lab is at max capacity!";
				}
			}
			else
			{
				LOG(WARNING) << "You don't own an Acid Lab!";
			}
		}
	};

	class NightclubRestock : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int ncprop = 1845299 + 1 + 260 + 364;

			if (*ScriptGlobal(ncprop).As<int*>() >= 1)
			{
				Stats::SetInt("MPX_CLUB_POPULARITY", 1000);

				SetTunable(-147565853, 1);
				SetTunable(-1390027611, 1);
				SetTunable(-1292210552, 1);
				SetTunable(1007184806, 1);
				SetTunable(18969287, 1);
				SetTunable(-863328938, 1);
				SetTunable(1607981264, 1);
				LOG(INFO) << "Nightclub restock ready! Re-assign your technicians.";
			}
			else
			{
				LOG(WARNING) << "You don't own a Nightclub!";
			}
		}
	};

	class SalvageYardPopularity : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int syprop = 1845299 + 1 + 260 + 504;

			if (*ScriptGlobal(syprop).As<int*>() >= 1)
			{
				Stats::SetPackedInt(51051, 100);
				LOG(INFO) << "Salvage Yard popularity maxed out!";
			}
			else
			{
				LOG(WARNING) << "You don't own a Salvage Yard!";
			}
		}
	};

	class MoneyFrontsHeatRemoval : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int cwprop = 1882717 + 1 + 158 + 27;

			if (*ScriptGlobal(cwprop + 1).As<int*>() >= 1 && *ScriptGlobal(cwprop + 13).As<int*>() >= 0)
			{
				Stats::SetPackedInt(24924, 0);
				Stats::SetPackedInt(24925, 0);
				Stats::SetPackedInt(24926, 0);
				LOG(INFO) << "Money Fronts Businesses Heat Removed!";
			}
			else
			{
				LOG(WARNING) << "You don't own Hands on Car Wash!";
			}
		}
	};

	static HangarRestock _HangarRestock{"hangarrestock", "Restock Hangar", "Restocks Hangar with selected goods type"};
	static WarehouseRestock _WarehouseRestock{"warehouserestock", "Restock Warehouse", "Restocks all Warehouses with selected goods type"};
	static MCBusinessSupplies _MCBusinessSupplies{"mcbusinesssupplies", "MC Business Supplies", "Resupplies all MC Businesses"};
	static MethRestock _MethRestock{"methrestock", "Restock Meth Lab", "Restocks Methamphetamine Lab"};
	static WeedRestock _WeedRestock{"weedrestock", "Restock Weed Farm", "Restocks Weed Farm"};
	static CokeRestock _CokeRestock{"cokerestock", "Restock Coke Lockup", "Restocks Cocaine Lockup"};
	static CashRestock _CashRestock{"cashrestock", "Restock Cash Factory", "Restocks Counterfeit Cash Factory"};
	static DocumentsRestock _DocumentsRestock{"documentsrestock", "Restock Document Forgery", "Restocks Document Forgery Office"};
	static BunkerRestock _BunkerRestock{"bunkerrestock", "Restock Bunker", "Restocks Bunker"};
	static AcidLabRestock _AcidLabRestock{"acidlabrestock", "Restock Acid Lab", "Restocks Acid Lab"};
	static NightclubRestock _NightclubRestock{"nightclubrestock", "Restock Nightclub", "Restocks Nightclub goods and maxes popularity"};
	static SalvageYardPopularity _SalvageYardPopularity{"salvageyardpopularity", "Max Salvage Yard Popularity", "Maxes out Salvage Yard popularity"};
	static MoneyFrontsHeatRemoval _MoneyFrontsHeatRemoval{"moneyfrontsheat", "Remove Money Fronts Heat", "Removes heat from all Money Fronts businesses"};
}
