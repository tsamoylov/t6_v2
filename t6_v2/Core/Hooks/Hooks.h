#pragma once

#include "../Game/Game.h"

namespace t6
{
	class cHooks
	{
	public:
		BYTE old_opcodes[5];
		int bullets_prev_fired;
		void call_hook(BYTE inst, BYTE* src, BYTE* dst);
		void call_unhook(BYTE inst, BYTE* src, BYTE* dst);
		void ret(BYTE* dst);
		void CG_DrawActiveFrame(int localClientNum, int serverTime, int demoType, int cubemapShot, int cubemapSize, int renderScreen);
		void predictplayerstate(int local_client_num);
		void writepacket(int lcn);
		void bullethitevent(int local, int source, int hit, int weapon, vec3* sourcepos, vec3* position, vec3* normal, vec3* decal, int surftype, int event, uint8_t eventParam);
		void lerpentityorigin(int localClientNum, scentity_t* cent);
	}extern _hooks;
}