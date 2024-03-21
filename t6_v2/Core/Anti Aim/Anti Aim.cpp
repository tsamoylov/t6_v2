#include "pch.h"

namespace t6
{
	c_antiaim _antiaim;
	void c_antiaim::usercmd_angles()
	{
        //switch (_antiaim.aa_yselected_type)
        //{
        //case 0:
        //    break;
        //case 3:
        //    break;
        //case 1:
        //    aa_ytotal = CG->refdefViewAngles.y - _antiaim.aa_ydir;
        //    usercmd_get(s_clientactive->cmd_num)->viewangles[1] = AngleToShort(aa_ytotal);
        //    break;
        //case 2:
        //    aa_ytotal += aa_ychange;
        //    usercmd_get(s_clientactive->cmd_num)->viewangles[1] = AngleToShort(aa_ytotal);
        //    break;
        //}
        //switch (_antiaim.aa_pselected_type)
        //{
        //case 1:
        //    usercmd_get(s_clientactive->cmd_num)->viewangles[0] = AngleToShort(_antiaim.aa_pdir);
        //    break;
        //case 2:
        //    usercmd_get(s_clientactive->cmd_num)->viewangles[0] = AngleToShort(remainderf(_antiaim.aa_ptotal, 85.0f));
        //    break;
        //}
	}
    void c_antiaim::centity_angles(scentity_t* cent)
    {
        //if ((cent->nextState.num == CG->clientNum) && CG->bThirdPerson)
        //{
        //
        //    switch (_antiaim.aa_yselected_type)
        //    {
        //    case 0:
        //        break;
        //    case 3:
        //        break;
        //
        //    case 1:
        //        cent->cpose_t.angles.y = (aa_ytotal);
        //        break;
        //    case 2:
        //        cent->cpose_t.angles.y = (CG->refdefViewAngles.y + _antiaim.aa_ytotal);
        //        break;
        //    }
        //    switch (_antiaim.aa_pselected_type)
        //    {
        //    case 1:
        //        clientinfo_t[CG->clientNum].playerAngles.x = _antiaim.aa_pdir;
        //        break;
        //    case 2:
        //        clientinfo_t[CG->clientNum].playerAngles.x = _antiaim.aa_ptotal;
        //        break;
        //    }
        //}
    }
}