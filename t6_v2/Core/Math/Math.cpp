#include "pch.h"

namespace t6
{
	cMath _math;
	float cMath::get3DDistance(vec3 src, vec3 dst)
	{
		return sqrtf(powf((src.x - dst.x), 2) + powf((src.y - dst.y), 2) + powf((src.z - dst.z), 2));
	}
	vec3 cMath::lookAt(vec3 src, vec3 dst)
	{
		float dx = dst.x - src.x;
		float dy = dst.y - src.y;
		float dz = dst.z - src.z;
		float hdist = sqrtf(powf(dx, 2) + powf(dy, 2));
		float rv = RAD2DEG(atanf(dz/hdist));
		float rh = RAD2DEG(atan2f(dy, dx));

		return vec3{ rv , rh , 0.0f};
	}
	float cMath::yaw_normalize(float in)
	{
		while (in > 180.f) in -= 360.f;
		while (in < -180.f) in += 360.f;
		return in;
	}
	float cMath::pitch_normalize(float in)
	{
		while (in > 90.f) in -= 360.f;
		while (in < -90.f) in += 360.f;
		return in;
	}
	char cMath::clamp(char in)
	{
		if (in > 127)
		{
			return 127;
		}
		if (in < -128)
		{
			return -128;
		}
		return in;

	}
	void cMath::movement_fix(s_usercmd* cmd, float yaw, float oldyaw, float forward, float right)
	{
		float delta = DEG2RAD(yaw - oldyaw);

		cmd->forwardmove = clamp((char)(cosf(delta) * forward - sinf(delta) * right));
		cmd->rightmove = clamp((char)(sinf(delta) * forward - cosf(delta) * right));
	}
}