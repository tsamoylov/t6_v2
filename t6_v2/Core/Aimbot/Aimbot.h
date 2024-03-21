#pragma once

#include "../Game/Game.h"

namespace t6
{
	class cAimbot
	{
	public:
		enum aimbot_type
		{
			aimbot_none,
			aimbot_standard,
			aimbot_silent
		};
		int bestEnt;
		int closest;
		float aa_temp;
		void standard_aim();
		void silent_aim(s_usercmd* cmd);
		void autofire(s_usercmd* cmd);
		int findClosestValid();
		int selected_type = 2;
		const char* types[3] = {"None", "Standard", "Silent"};
	}extern _aimbot;
}