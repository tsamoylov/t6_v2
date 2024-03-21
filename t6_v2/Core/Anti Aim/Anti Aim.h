#pragma once
#include "../Game/Game.h"

namespace t6
{
	class c_antiaim
	{
	public:
		int aa_yselected_type;
		const char* aa_ytype[4]{"None", "Directional", "Spin", "Random"};
		float aa_ydir;
		float aa_ytotal;
		float aa_ychange;
		int aa_pselected_type;
		const char* aa_ptype[4]{ "None", "Directional", "Changing", "Random"};
		float aa_pdir;
		float aa_ptotal;
		float aa_pchange;
		void usercmd_angles();
		void centity_angles(scentity_t* cent);
	}extern _antiaim;
}