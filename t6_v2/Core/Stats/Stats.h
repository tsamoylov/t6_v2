#pragma once

#include "../Game/Game.h"

namespace t6
{
	class c_stats
	{
	public:
		void hash_sign();
		void set_prestige(int prestige);
		void set_rank(int rank);
		void unlockall();
	}extern _stats;
}