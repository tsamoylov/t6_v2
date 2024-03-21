#include "pch.h"

namespace t6
{
	cRemovals _removals;
	void cRemovals::removeRecoil()
	{
		if (norecoil)
		{
			if (CG->kickAVel.x != 0.0f || CG->kickAVel.y != 0.0f || CG->kickAVel.z != 0.0f)
			{
				CG->kickAVel.x = 0.0f;
				CG->kickAVel.y = 0.0f;
				CG->kickAVel.z = 0.0f;
			}
		}
	}
	void cRemovals::removeSpread(s_usercmd* usercmd, int server_time)
	{
		if (nospread)
		{
			float minspread;
			float maxspread;
			float spread_mult = CG->spread_value / 255.0f;

			bg_getspread(&CG->pps, CG->pps.weapon, &minspread, &maxspread);
			unsigned int dw_time = server_time;
			unsigned int randSeed = ((unsigned __int8)dw_time << 24) ^ ((unsigned __int8)dw_time << 16) ^ dw_time ^ ((unsigned __int8)dw_time << 8);
			float fl_1 = rand_float(&randSeed) * (PI * 2.0f);
			changeSeed(&randSeed);
			float fl_2 = rand_float(&randSeed);

			float spread;

			if (CG->pps.weapon_pos_frac == 1.0f)
			{
				spread = ((maxspread - getweapondef(CG->pps.weapon)->ads_spread) * spread_mult) + getweapondef(CG->pps.weapon)->ads_spread;
			}
			else
			{
				spread = ((maxspread - minspread) * spread_mult) + minspread;
			}

			float x = cosf(fl_1) * fl_2 * spread;
			float y = sinf(fl_1) * fl_2 * spread;

			//s_clientactive->viewangles.x += y;
			//s_clientactive->viewangles.y += x;


			usercmd->viewangles[0] += AngleToShort(y);
			usercmd->viewangles[1] += AngleToShort(x);
		}
	}
}