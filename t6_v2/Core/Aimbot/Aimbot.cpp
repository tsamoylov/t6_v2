#include "pch.h"

namespace t6
{
	cAimbot _aimbot;
	void cAimbot::standard_aim()
	{
		if (selected_type == aimbot_standard)
		{
			closest = findClosestValid();
			if (_menu.target_stick)
			{
				if (!_targetList.TargetInfo[bestEnt].lifestate || !_targetList.TargetInfo[bestEnt].visible)
				{
					bestEnt = closest;
				}

			}
			else
			{
				bestEnt = closest;
			}
			if (bestEnt != -1)
			{
				vec3 lookHere = _math.lookAt(
					{ centity_t(CG->clientNum)->cpose_t.origin.x,
					centity_t(CG->clientNum)->cpose_t.origin.y,
					centity_t(CG->clientNum)->cpose_t.origin.z + 60.0f },
					vec3{	_targetList.TargetInfo[bestEnt].bones[j_head].x + ((centity_t(bestEnt)->nextState.lerp.pos.trBase.x - centity_t(bestEnt)->prevState.pos.trBase.x)),
							_targetList.TargetInfo[bestEnt].bones[j_head].y + ((centity_t(bestEnt)->nextState.lerp.pos.trBase.y - centity_t(bestEnt)->prevState.pos.trBase.y)),
							_targetList.TargetInfo[bestEnt].bones[j_head].z + ((centity_t(bestEnt)->nextState.lerp.pos.trBase.z - centity_t(bestEnt)->prevState.pos.trBase.z)) });
				s_clientactive->viewangles.x -= _math.pitch_normalize(CG->refdefViewAngles.x + lookHere.x);
				s_clientactive->viewangles.y -= _math.yaw_normalize(CG->refdefViewAngles.y - lookHere.y);
			}
		}
	}
	void cAimbot::silent_aim(s_usercmd* cmd)
	{
		if (selected_type == aimbot_silent)
		{
			int closest_ent = findClosestValid();
			if (_menu.target_stick)
			{
				if (!_targetList.TargetInfo[bestEnt].lifestate || !_targetList.TargetInfo[bestEnt].visible || (bestEnt == CG->clientNum))
				{
					bestEnt = closest_ent;
				}

			}
			else
			{
				bestEnt = closest_ent;
			}

			if (bestEnt != -1)
			{
				vec3 lookHere = _math.lookAt(
					CG->lastViewOrg,
					vec3{	_targetList.TargetInfo[bestEnt].bones[j_head].x + ((centity_t(bestEnt)->nextState.lerp.pos.trBase.x - centity_t(bestEnt)->prevState.pos.trBase.x)),
							_targetList.TargetInfo[bestEnt].bones[j_head].y + ((centity_t(bestEnt)->nextState.lerp.pos.trBase.y - centity_t(bestEnt)->prevState.pos.trBase.y)),
							_targetList.TargetInfo[bestEnt].bones[j_head].z + ((centity_t(bestEnt)->nextState.lerp.pos.trBase.z - centity_t(bestEnt)->prevState.pos.trBase.z)) });
				float oldyaw = ShortToAngle(cmd->viewangles[1]);
				cmd->viewangles[0] -= AngleToShort(_math.pitch_normalize(CG->refdefViewAngles.x + lookHere.x));
				cmd->viewangles[1] -= AngleToShort(_math.yaw_normalize(CG->refdefViewAngles.y - lookHere.y));
				float yaw = ShortToAngle(cmd->viewangles[1]);
				_math.movement_fix(cmd, yaw, oldyaw, cmd->forwardmove, cmd->rightmove);
			}

		}
	}
	int cAimbot::findClosestValid()
	{
		int closestValid = -1;
		for (int i = 0; i < 18; i++)
		{
			if (i != CG->clientNum && _targetList.TargetInfo[i].valid)
			{
				if ((closestValid == -1) && _targetList.TargetInfo[i].lifestate && _targetList.TargetInfo[i].visible && !_targetList.TargetInfo[i].friendly)
				{
					closestValid = i;
				}
				else if ((_math.get3DDistance(centity_t(CG->clientNum)->cpose_t.origin, centity_t(closestValid)->cpose_t.origin) >
					_math.get3DDistance(centity_t(CG->clientNum)->cpose_t.origin, centity_t(i)->cpose_t.origin))
					&& _targetList.TargetInfo[i].lifestate && _targetList.TargetInfo[i].visible && !_targetList.TargetInfo[i].friendly && (closestValid != -1))
				{
					closestValid = i;
				}
			}
		}
		return closestValid;
	}
	void cAimbot::autofire(s_usercmd* cmd)
	{
		if (_removals.nospread && _menu.autofire)
		{
			char wbuffer1[1024];
			char wbuffer2[1024];
			getweaponname(playerState_t(CG->clientNum)->weapon, wbuffer1, 1024);
			getweaponname(CG->weaponLatestPrimary, wbuffer2, 1024);
			if ((bestEnt != -1) && (strcmp(wbuffer1, "riotshield_mp") != 0) && (strcmp(wbuffer2, "riotshield_mp") != 0))
			{
				cmd->buttons[0] |= 0x80000000;
				cmd->buttons[1] |= 0x20000000;
			}
		}
	}
}