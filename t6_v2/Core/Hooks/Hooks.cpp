#include "pch.h"

namespace t6
{
	cHooks _hooks;
	void cHooks::call_hook(BYTE inst, BYTE* src, BYTE* dst)
	{
		DWORD old_protection;
		VirtualProtect(dst, 0x5, PAGE_EXECUTE_READWRITE, &old_protection);
		memcpy(&old_opcodes, dst, 0x5);
		*dst = inst;
		DWORD call_bytes = src - (dst + 0x5);

		*reinterpret_cast<DWORD*>(dst + 1) = call_bytes;
		VirtualProtect(dst, 0x5, old_protection, &old_protection);
	}
	void cHooks::call_unhook(BYTE inst, BYTE* src, BYTE* dst)
	{
		DWORD old_protection;
		VirtualProtect(dst, 0x5, PAGE_EXECUTE_READWRITE, &old_protection);
		memcpy(dst, &old_opcodes, 0x5);
		VirtualProtect(dst, 0x5, old_protection, &old_protection);
	}
	void cHooks::ret(BYTE* dst)
	{
		BYTE ret = 0xC3;
		DWORD old_protection;
		VirtualProtect(dst, 0x1, PAGE_EXECUTE_READWRITE, &old_protection);
		memcpy(dst, &ret, 0x1);
		VirtualProtect(dst, 0x1, old_protection, &old_protection);
	}
	void cHooks::bullethitevent(int local, int source, int hit, int weapon, vec3* sourcepos, vec3* position, vec3* normal, vec3* decal, int surftype, int event, uint8_t eventParam)
	{
		if ((source == CG->clientNum) && (hit < 18) && (CG->clientNum == CG->nextSnap->ps.ClientNum))
		{
			++_drawing.tracercount;
			if (_drawing.tracercount == 17)
			{
				_drawing.tracercount = 0;
			}
			_drawing.tracers[_drawing.tracercount].tracer_start3 = CG->bThirdPerson ? _targetList.TargetInfo[CG->clientNum].bones[j_head] : CG->lastViewOrg;
			_drawing.tracers[_drawing.tracercount].tracer_end3 = *(position);
			_drawing.tracers[_drawing.tracercount].tracer_alpha = 1.0f;
			if ((((centity_t(hit)->nextState.lerp.eFlags & 0x40000) == 0) && ((centity_t(hit)->packed_bits[0] & 2) != 0)))
			{
				_drawing.tracers[_drawing.tracercount].last_shot = false;
			}
			else
			{
				_drawing.tracers[_drawing.tracercount].last_shot = true;
			}
		}
	}
	void cHooks::CG_DrawActiveFrame(int localClientNum, int serverTime, int demoType, int cubemapShot, int cubemapSize, int renderScreen)
	{
		//if (CG->bThirdPerson != _menu.thirdperson)
		//{
		//	CG->bThirdPerson = _menu.thirdperson;
		//}
		_removals.removeRecoil();
		const char* mode = *(const char**)(Dvar_FindVarFromString("ui_gametype") + 0x18);
		for (int i = 0; i < 18; i++)
		{
			if (Com_GetClientDObj(centity_t(i)->nextState.num, 0) != nullptr)
			{
				if (!strcmp(mode, "dm"))
				{
					_targetList.TargetInfo[i].friendly = (clientinfo_t[CG->clientNum].team == clientinfo_t[i].ffaTeam);
				}
				else if (!strcmp(mode, "tdm"))
				{
					_targetList.TargetInfo[i].friendly = (clientinfo_t[CG->clientNum].team == clientinfo_t[i].team);
				}
				_targetList.TargetInfo[i].lifestate = (((centity_t(i)->nextState.lerp.eFlags & 0x40000) == 0) && ((centity_t(i)->packed_bits[0] & 2) != 0));
				_targetList.TargetInfo[i].origin = centity_t(i)->cpose_t.origin;
				_targetList.TargetInfo[i].team = clientinfo_t[i].team;
				bool result = false;
				if (w2s_wrap(&_targetList.TargetInfo[i].origin, &_targetList.TargetInfo[i].originOut))
				{
					result = true;
				}
				for (int boneIndex = 0; boneIndex < 18; boneIndex++)
				{
					CG_DObjGetWorldTagPos(&centity_t(i)->cpose_t,
						*(int*)((DWORD) &_targetList.boneNums.j_helmet + (0x4 * boneIndex)),
						Com_GetClientDObj(centity_t(i)->nextState.num, 0),
						&_targetList.TargetInfo[i].bones[boneIndex]);
					if (w2s_wrap(&_targetList.TargetInfo[i].bones[boneIndex], &_targetList.TargetInfo[i].bonesOut[boneIndex]))
					{
						result = true;
					}
				}
				_targetList.TargetInfo[i].w2s = result;
				_targetList.TargetInfo[i].valid = true;
				CG_LocationalTrace(&_targetList.entityTrace, 
					&_targetList.TargetInfo[CG->nextSnap->ps.ClientNum].bones[j_head],
					&_targetList.TargetInfo[i].bones[j_head],
					CG->clientNum, 0x280B001, false, nullptr);
				_targetList.TargetInfo[i].visible = (_targetList.entityTrace.hitId == i) && (*(__int16*)((DWORD) & _targetList.entityTrace + 0x28) != 20);
			}
			else
			{
				_targetList.TargetInfo[i].valid = false;
			}
		}
		if (_drawing.use_tracers)
		{
			for (int i = 0; i < 18; i++)
			{
				w2s_wrap(&_drawing.tracers[i].tracer_start3, &_drawing.tracers[i].tracer_start2);
				w2s_wrap(&_drawing.tracers[i].tracer_end3, &_drawing.tracers[i].tracer_end2);
				_drawing.tracers[i].tracer_alpha -= 0.005f;
			}
		}
		_aimbot.standard_aim();
	}
	void cHooks::predictplayerstate(int local_client_num)
	{
		static int angles[3];
		s_usercmd* old_cmd = usercmd_get(s_clientactive->cmd_num - 1);
		s_usercmd* cur_cmd = usercmd_get(s_clientactive->cmd_num);
		s_usercmd* new_cmd = usercmd_get(s_clientactive->cmd_num + 1);
		memcpy(new_cmd, cur_cmd, sizeof(s_usercmd));
		++s_clientactive->cmd_num;
		
		old_cmd->viewangles[0] = angles[0];
		old_cmd->viewangles[1] = angles[1];
		old_cmd->viewangles[2] = angles[2];
		
		angles[0] = cur_cmd->viewangles[0];
		angles[1] = cur_cmd->viewangles[1];
		angles[2] = cur_cmd->viewangles[2];
		++old_cmd->serverTime;
		--cur_cmd->serverTime;
		_aimbot.silent_aim(old_cmd);
		_aimbot.autofire(cur_cmd);
		_removals.removeSpread(old_cmd, cur_cmd->serverTime);
	}
	void cHooks::writepacket(int lcn)
	{
		//usercmd_get(s_clientactive->cmd_num)->viewangles[1] = AngleToShort(0.0f - CG->pps.viewangles.y);
		//_antiaim.usercmd_angles();
	}
	void cHooks::lerpentityorigin(int localClientNum, scentity_t* cent)
	{
		//_antiaim.centity_angles(cent);
	}
}