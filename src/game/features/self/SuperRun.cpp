#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/gta/Natives.hpp"
#include "src/types/pad/ControllerInputs.hpp"
#include "src/core/util/Math.hpp"

namespace YimMenu::Features
{
	class SuperRun : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (auto ped = Self::GetPed())
			{
				if (PED::IS_PED_RAGDOLL(ped.GetHandle()))
					return;

					float run_cap = 300.f;
					float run_speed     = 30.f;

					if (TASK::IS_PED_RUNNING(ped.GetHandle()) || TASK::IS_PED_SPRINTING(ped.GetHandle()))
					if (PAD::IS_CONTROL_PRESSED(0, (int)ControllerInputs::INPUT_SPRINT))
					{
						if (run_speed < run_cap)
							run_speed += .5f;

						Vector3 location = ENTITY::GET_ENTITY_COORDS(ped.GetHandle(), false /*Unused*/);

						Vector3 rot = ENTITY::GET_ENTITY_ROTATION(ped.GetHandle(), 2);
						float yaw   = Math::DegToRad(rot.z + 90);

						Vector3 offset;
						offset.x = location.x + (run_speed * cos(yaw));
						offset.y = location.y + (run_speed * sin(yaw));
						offset.z = location.z;

						float groundZ;
						MISC::GET_GROUND_Z_FOR_3D_COORD(offset.x, offset.y, 1000.f, &groundZ, false, false);
						if (groundZ < location.z)
							offset.z = groundZ;

						Vector3 vel = offset - location;

						ENTITY::SET_ENTITY_VELOCITY(ped.GetHandle(), vel.x, vel.y, vel.z);
					}
					else if (PAD::IS_CONTROL_JUST_RELEASED(0, (int)ControllerInputs::INPUT_SPRINT))
					{
						run_speed = 10.f;
					}
			}
		}
	};

	static SuperRun _Superrun{"superrun", "Super Run", "Run faster than normal"};
}
