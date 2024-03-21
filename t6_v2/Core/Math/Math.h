#pragma once

#include "../Game/Game.h"
#define AngleToShort(a) ((int)((a)*(65535/360.0f))&65535)
#define ShortToAngle(a) ((float)((a)*(360.0f/65535)))
#define PI 3.1415926535897932f
#define DEG2RAD(d) ((d)*(PI/180.000000f))
#define RAD2DEG(x) (x * (180.000000f/PI))

namespace t6
{
	class cMath
	{
	public:
		float get3DDistance(vec3 src, vec3 dst);
		vec3 lookAt(vec3 src, vec3 dst);
		float yaw_normalize(float in);
		float pitch_normalize(float in);
		char clamp(char in);
		void movement_fix(s_usercmd* cmd, float yaw, float oldyaw, float forward, float right);
	}extern _math;

}