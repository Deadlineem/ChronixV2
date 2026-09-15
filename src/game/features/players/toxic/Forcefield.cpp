#include "core/commands/LoopedCommand.hpp"
#include "core/commands/FloatCommand.hpp"
#include "game/backend/Players.hpp"
#include "game/gta/Entity.hpp"
#include "game/gta/Pools.hpp"
#include "game/gta/Natives.hpp"

namespace YimMenu::Features
{
	static FloatCommand m_Radius{
	    "forcefieldradius",
	    "Forcefield Radius",
	    "Radius around the target player where vehicles/peds are pushed away.",
	    0.0f,
	    1000.0f,
	    10.0f};

	static FloatCommand m_Magnitude{
	    "forcefieldmagnitude",
	    "Forcefield Magnitude",
	    "Strength of the push away from the target player.",
	    0.0f,
	    1000.0f,
	    10.0f};

	static void ApplyForcefield(Player player)
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
			    pos.x - targetCoords.x,
			    pos.y - targetCoords.y,
			    pos.z - targetCoords.z};

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
			    pos.x - targetCoords.x,
			    pos.y - targetCoords.y,
			    pos.z - targetCoords.z};

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

	class Forcefield : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Player target = Players::GetSelected();
			if (!target || !target.GetPed())
				return;

			ApplyForcefield(target);
		}
	};

	static Forcefield _Forcefield{
	    "forcefield",
	    "Forcefield",
	    "Pushes vehicles and peds away from the selected player"};
}
