#pragma once

#include "../Game/Game.h"

namespace t6
{
	class cTargetList
	{
	public:
		void initBones();
		struct sBoneNums
		{
			int j_helmet;
			int j_head;
			int j_neck;
			int j_shoulder_ri;
			int j_shoulder_le;
			int j_elbow_le;
			int j_elbow_ri;
			int j_wrist_ri;
			int j_wrist_le;
			int j_spineupper;
			int j_spinelower;
			int j_hip_ri;
			int j_hip_le;
			int j_knee_le;
			int j_knee_ri;
			int j_ankle_ri;
			int j_ankle_le;
			int j_mainroot;

		}boneNums;
		trace_t entityTrace;
		struct sTargetInfo
		{
			int playernum;
			int team;
			vec3 origin;
			vec2 originOut;
			vec3 bones[18];
			vec2 bonesOut[18];
			bool valid;
			bool w2s;
			bool visible;
			bool lifestate;
			bool aimTarget;
			bool friendly;
		}TargetInfo[18];
	}extern _targetList;
}