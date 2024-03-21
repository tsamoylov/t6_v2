#include "pch.h"

namespace t6
{
	cTargetList _targetList;

	void cTargetList::initBones()
	{
		boneNums.j_helmet = SL_FindString("j_helmet");
		boneNums.j_head = SL_FindString("j_head");
		boneNums.j_neck = SL_FindString("j_neck");
		boneNums.j_shoulder_ri = SL_FindString("j_shoulder_ri");
		boneNums.j_shoulder_le = SL_FindString("j_shoulder_le");
		boneNums.j_elbow_le = SL_FindString("j_elbow_le");
		boneNums.j_elbow_ri = SL_FindString("j_elbow_ri");
		boneNums.j_wrist_ri = SL_FindString("j_wrist_ri");
		boneNums.j_wrist_le = SL_FindString("j_wrist_le");
		boneNums.j_spineupper = SL_FindString("j_spineupper");
		boneNums.j_spinelower = SL_FindString("j_spinelower");
		boneNums.j_hip_ri = SL_FindString("j_hip_ri");
		boneNums.j_hip_le = SL_FindString("j_hip_le");
		boneNums.j_knee_le = SL_FindString("j_knee_le");
		boneNums.j_knee_ri = SL_FindString("j_knee_ri");
		boneNums.j_ankle_ri = SL_FindString("j_ankle_ri");
		boneNums.j_ankle_le = SL_FindString("j_ankle_le");
		boneNums.j_mainroot = SL_FindString("j_mainroot");
	}
}