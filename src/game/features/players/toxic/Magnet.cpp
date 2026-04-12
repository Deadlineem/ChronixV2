#include "core/commands/LoopedCommand.hpp"
#include "core/commands/FloatCommand.hpp"
#include "game/backend/Players.hpp"
#include "game/gta/Entity.hpp"
#include "game/gta/Pools.hpp"
#include "game/gta/Natives.hpp"

namespace YimMenu::Features
{
	static FloatCommand m_Radius{
	    "magnetradius",
	    "Magnet Radius",
	    "Radius around the target player where vehicles/peds are affected.",
	    0.0f,
	    1000.0f,
	    10.0f};

	static FloatCommand m_Magnitude{
	    "magnetmagnitude",
	    "Magnet Magnitude",
	    "Strength of the magnetic pull toward the target player.",
	    0.0f,
	    1000.0f,
	    10.0f};

	static void ApplyMagnet(Player player)
	{
		if (!player || !player.GetPed())
			return;

		Vector3 targetCoords = player.GetPed().GetPosition();
		float radius = m_Radius.GetState();
		float magnitude = m_Magnitude.GetState();
		float radiusSq = radius * radius;

		// Vehicles
		for (auto veh : Pools::GetVehicles())
		{
			if (!ENTITY::DOES_ENTITY_EXIST(veh.GetHandle()))
				continue;

			Vector3 pos = ENTITY::GET_ENTITY_COORDS(veh.GetHandle(), false);
			Vector3 delta{
			    targetCoords.x - pos.x,
			    targetCoords.y - pos.y,
			    targetCoords.z - pos.z};

			float distSq = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
			if (distSq > radiusSq)
				continue;

			veh.ForceControl();
			ENTITY::APPLY_FORCE_TO_ENTITY(
			    veh.GetHandle(),
			    2,
			    delta.x * magnitude,
			    delta.y * magnitude,
			    delta.z * magnitude,
			    0.f,
			    0.f,
			    0.f,
			    0,
			    false,
			    true,
			    true,
			    false,
			    false);
		}

		// Peds
		for (auto ped : Pools::GetPeds())
		{
			if (!ENTITY::DOES_ENTITY_EXIST(ped.GetHandle()))
				continue;

			Vector3 pos = ENTITY::GET_ENTITY_COORDS(ped.GetHandle(), false);
			Vector3 delta{
			    targetCoords.x - pos.x,
			    targetCoords.y - pos.y,
			    targetCoords.z - pos.z};

			float distSq = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
			if (distSq > radiusSq)
				continue;

			ped.ForceControl();
			ENTITY::APPLY_FORCE_TO_ENTITY(
			    ped.GetHandle(),
			    2,
			    delta.x * magnitude,
			    delta.y * magnitude,
			    delta.z * magnitude,
			    0.f,
			    0.f,
			    0.f,
			    0,
			    false,
			    true,
			    true,
			    false,
			    false);
		}
	}

	class Magnet : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Player target = Players::GetSelected();
			if (!target || !target.GetPed())
				return;

			ApplyMagnet(target);
		}
	};

	static Magnet _Magnet{
	    "magnet",
	    "Magnet",
	    "Pulls vehicles and peds toward the selected player"};
}
