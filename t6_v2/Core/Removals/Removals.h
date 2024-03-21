#pragma once
#include "../Game/Game.h"

namespace t6
{
	class cRemovals
	{
	public:
		bool norecoil = true;
		bool nospread = true;
		void removeRecoil();
		void removeSpread(s_usercmd* usercmd, int server_time);
	}extern _removals;
}