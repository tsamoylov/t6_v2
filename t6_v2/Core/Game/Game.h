#pragma once

#include "../Utils/Utils.h"

#define moduleBase reinterpret_cast<uintptr_t>(GetModuleHandle(NULL))
namespace t6 
{
	enum boneIndex
	{
		j_helmet,
		j_head,
		j_neck,
		j_shoulder_ri,
		j_shoulder_le,
		j_elbow_le,
		j_elbow_ri,
		j_wrist_ri,
		j_wrist_le,
		j_spineupper,
		j_spinelower,
		j_hip_ri,
		j_hip_le,
		j_knee_le,
		j_knee_ri,
		j_ankle_ri,
		j_ankle_le,
		j_mainroot
	};
	struct s_playerstate
	{
		char _0x0[0x4];
		uint32_t pm_type;
		char _0x8[0x20];
		vec3 origin;
		char _0x34[0x64];
		vec3 viewangles;
		char _0xA4[0x5C];
		uint32_t eFlags2;

		char _0x104[0x9C];
		int ClientNum;
		char _1A4[0x14];
		int weapon;
		char _0x1BC[0x24];
		float weapon_pos_frac;
		char _0x1E4[0x3A4];
		float aimSpreadScale;
		char _0x58C[0x247C];
	};
	struct sclientInfo_t
	{
		uint32_t infoValid; //0x0000
		uint32_t nextValid; //0x0004
		uint32_t clientNum; //0x0008
		char name[32]; //0x000C
		uint32_t team; //0x002C
		uint32_t oldteam; //0x0030
		uint32_t ffaTeam; //0x0034
		char pad_0038[64]; //0x0038
		uint64_t xuid; //0x0078
		char pad_0080[1092]; //0x0080
		vec3 playerAngles; //0x04C4
		char pad_04D0[824]; //0x04D0
	}; //Size: 0x0808
	struct sbgs_t
	{
		char _0x0[0x98];

		sclientInfo_t clientInfo_t[18];

		char _0x9128[0x9EA8];
	};
	struct scpose_t
	{
		uint16_t lightingHandle; //0x0000
		uint16_t eType; //0x0002
		uint8_t localClientNum; //0x0004
		uint8_t isRagdoll; //0x0005
		char pad_0006[2]; //0x0006
		uint32_t ragdollHandle; //0x0008
		uint32_t physObjId; //0x000C
		uint32_t physUserBody; //0x0010
		uint32_t killcamRagdollHandle; //0x0014
		uint32_t physUserBodyProneFeet; //0x0018
		uint8_t destructiblePose; //0x001C
		char pad_001D[3]; //0x001D
		uint32_t startBurnTime; //0x0020
		uint32_t wetness; //0x0024
		uint32_t cullIn; //0x0028
		vec3 origin; //0x002C
		vec3 angles; //0x0038
		vec3 absmin; //0x0044
		vec3 absmax; //0x0050
		char pad_005C[260]; //0x005C
	}; //Size: 0x0160
	struct strajectory_t
	{
		uint32_t trType;
		uint32_t trTime;
		uint32_t trDuration;
		vec3 trBase;
		vec3 trDelta;

	};
	struct sLerpEntityState
	{
		DWORD eFlags;
		DWORD eFlags2;
		strajectory_t pos;
		strajectory_t apos;
		char _0x50[0x2C];
	};
	struct sentityState_s
	{
		int num;
		sLerpEntityState lerp;
		char _0x80[0x58];
		uint16_t eType;
		char _0xDA[0x1E];

	};
	struct scentity_t
	{
		scpose_t cpose_t;
		sLerpEntityState prevState;
		sentityState_s nextState;
		char _0x2D4[0x70];
		vec3 originError;
		char _0x338[0x28];
		int packed_bits[2];
	};
	struct ssnapshot_s
	{
		char _0x0[0x8];

		int serverTime;

		char _0xC[0x4];

		s_playerstate ps;
	};
	struct sCG_t 
	{
		uint32_t clientNum;

		uint32_t localClientNum;

		char _0x8[0x18];

		uint32_t snap;

		ssnapshot_s* nextSnap;

		char _0x28[0x48074];

		bool bThirdPerson;

		char _0x4809D[0xB];

		s_playerstate pps;

		char _0x4AAB0[0x19E40];

		vec3 refdefViewAngles;

		char _0x648FC[0x4EC0];

		vec3 kickAVel;

		char _0x697C8[0x160];

		uint32_t inKillCam;

		char _0x6992C[0x8];

		uint32_t killCamEntity;

		char _0x69938[0x4];

		uint32_t killCamEntityType;

		uint32_t killCamLastEntityNum;

		char _0x69944[0x84];

		sbgs_t bgs_t;

		char _0x7C998[0x41C4];

		float spread_value;
	};
	struct s_cg_t
	{
		uint32_t clientNum; //0x0000
		uint32_t localClientNum; //0x0004
		char pad_0008[24]; //0x0008
		uint32_t snap; //0x0020
		ssnapshot_s* nextSnap; //0x0024
		char pad_0028[88]; //0x0028
		uint8_t N00002A3A[294912]; //0x0080
		char pad_48080[28]; //0x48080
		bool bThirdPerson; //0x4809C
		char pad_4809D[11]; //0x4809D
		s_playerstate pps; //0x480A8
		char pad_4AAB0[4]; //0x4AAB0
		scentity_t predictedPlayerEntity; //0x4AAB4
		char pad_4AE34[68]; //0x4AE34
		uint8_t N00002A59[10760]; //0x4AE78
		char pad_4D880[16]; //0x4D880
		uint8_t pad_4D890[0x34]; //0x4D890
		vec3 vieworg; //0x4D8C4
		uint8_t N00002A5E[94240];//4D8D0
		vec3 refdefViewAngles; //0x648F0
		vec3 lastViewOrg; //0x648FC
		uint8_t N00002A61[288]; //0x64908
		char pad_64A28[52]; //0x64A28
		vec3 recoilAngles; //0x64A5C
		vec3 recoilSpeed; //0x64A68
		vec3 damageKickAngles; //0x64A74
		char pad_64A80[44]; //0x64A80
		vec3 radiantCameraOrigin; //0x64AAC
		vec3 radiantCameraAngles; //0x64AB8
		uint32_t radiantCamInUse; //0x64AC4
		char N00002A80[1792][4]; //0x64AC8
		char N00002A81[1792][4]; //0x666C8
		char pad_682C8[4]; //0x682C8
		uint8_t isLoading; //0x682CC
		uint8_t N00003762[1024]; //0x682CD
		char pad_686CD[1]; //0x686CD
		uint8_t N00002A84; //0x686CE
		uint8_t N0000378A; //0x686CF
		char pad_686D0[4016]; //0x686D0
		uint32_t weaponLatestPrimary; //0x69680
		char pad_69684[312]; //0x69684
		vec3 kickAVel; //0x697BC
		vec3 kickAngles; //0x697C8
		vec3 offsetAngles; //0x697D4
		char pad_697E0[244]; //0x697E0
		uint32_t radarType; //0x698D4
		char pad_698D8[80]; //0x698D8
		uint32_t inKillCam; //0x69928
		char pad_6992C[156]; //0x6992C
		sbgs_t bgs_t; //0x699C8
		scpose_t viewModelPose; //0x7C998
		uint8_t N00002F3D[3840]; //0x7CAF8
		uint8_t N00002F3E[512]; //0x7D9F8
		uint8_t N00002F3F[3840]; //0x7DBF8
		uint8_t N00002F40[3840]; //0x7EAF8
		uint8_t N00002F41[3840]; //0x7F9F8
		char pad_808F8[612]; //0x808F8
		float spread_value; //0x80B5C
		char pad_80B60[212]; //0x80B60
		char N0000504C[256][4]; //0x80C34
		char pad_81034[1048]; //0x81034
		char N00005153[512][4]; //0x8144C
		char pad_81C4C[476]; //0x81C4C
		vec3 extraCamOrigin; //0x81E28
		char pad_81E34[488]; //0x81E34
		uint8_t N00005246[9216]; //0x8201C
		uint8_t N00005247[13028]; //0x8441C
	}; //Size: 0x87700
	struct sgentity_t
	{
		char _0x0[0x158];
		char _0x15C[0x4C];
		uint32_t health;
	};
	struct s_usercmd
	{
		int serverTime;
		int buttons[2];
		int viewangles[3];
		char _0x18[0xC];
		BYTE forwardmove;
		BYTE rightmove;
		char _0x26[0x16];
	};
	struct clientActive_t
	{
		char _0x0[0x2C8C];
		vec3 viewangles;
		char _0x2C98[0x40010];
		s_usercmd cmds[128];
		int cmd_num;
	};
	struct trace_t
	{
		float fraction;
		vec3 normal;
		char _0x10[0xC];
		int hitType;
		uint16_t hitId;
		char _0x22[0x1E];

	};
	struct s_weapondef
	{
		char _0x0[0x7E0];
		float ads_spread;
	};
	struct ddlDef_t
	{
		uint32_t version; //0x0000
		uint32_t size; //0x0004
		uint32_t structList; //0x0008
		uint32_t structCount; //0x000C
		uint32_t enumList; //0x0010
		uint32_t enumCount; //0x0014
		uint32_t next; //0x0018
	}; //Size: 0x001C
	struct ddlMemberDef_t
	{
		uint32_t name; //0x0000
		uint32_t size; //0x0004
		uint32_t offset; //0x0008
		uint32_t type; //0x000C
		uint32_t externalIndex; //0x0010
		uint32_t rangeLimit; //0x0014
		uint32_t serverDelta; //0x0018
		uint32_t clientDelta; //0x001C
		uint32_t arraySize; //0x0020
		uint32_t enumIndex; //0x0024
		uint32_t permission; //0x0028
	}; //Size: 0x002C
	struct ddlState_t
	{
		uint32_t absoluteOffset; //0x0000
		uint32_t arrayIndex; //0x0004
		ddlMemberDef_t* member; //0x0008
		ddlDef_t* ddl; //0x000C
		uint32_t returnCode; //0x0010
	};
	struct ecc_point
	{
		uint32_t x; //0x0000
		uint32_t y; //0x0004
		uint32_t z; //0x0008
	};
	struct ecc_key
	{
		uint32_t type; //0x0000
		uint32_t idx; //0x0004
		uint32_t dp; //0x0008
		ecc_point pubkey; //0x000C
		uint32_t k; //0x0018

	};
	struct rankData_t
	{
		uint32_t minxp[96]; //0x0000
		uint32_t maxxp[96]; //0x0180
		uint32_t rankId[96]; //0x0300
		uint8_t unlocks[1920]; //0x0480
		uint32_t topRow; //0x0C00
		uint8_t isValid; //0x0C04
		char pad_0C05[3]; //0x0C05
	}; //Size: 0x0C08
	struct unlockMapping_t
	{
		char* name; //0x0000
		char* stringRef; //0x0004
	}; //Size: 0x0008
	struct unlockableItemsDataShared
	{
		unlockMapping_t unlockMappings[20]; //0x0000
		uint32_t itemGroupToUnlock[20]; //0x00A0
		uint32_t itemGroupCount[20]; //0x00F0
	}; //Size: 0x0140
	struct netadr_t
	{
		union //0x0000
		{
			uint8_t _ip[4]; //0x0000
			uint32_t inaddr; //0x0000
		};
		uint8_t port; //0x0004
		char pad_0005[3]; //0x0005
		uint32_t type; //0x0008
		uint32_t localNetID; //0x000C
		uint32_t serverID; //0x0010
	}; //Size: 0x0014
	struct PartyMember
	{
		uint8_t status; //0x0000
		char pad_0001[3]; //0x0001
		uint32_t ackedMembers; //0x0004
		uint32_t lastPacketTime; //0x0008
		uint32_t lastHeartbeatTime; //0x000C
		uint32_t lastPartyStateAck; //0x0010
		uint32_t lastDemoHeartbeatTime; //0x0014
		uint32_t challenge; //0x0018
		uint32_t subpartyIndex; //0x001C
		uint32_t reportedConnState; //0x0020
		uint8_t invited; //0x0024
		uint8_t headsetPresent; //0x0025
		uint8_t inLivePartyVoice; //0x0026
		uint8_t inLivePartyTalking; //0x0027
		uint8_t finishedLoadingDemo; //0x0028
		uint8_t isReady; //0x0029
		uint8_t isGuest; //0x002A
		uint8_t isSplitscreenClient; //0x002B
		uint32_t connectionType; //0x002C
		uint32_t natType; //0x0030
		char pad_0034[4]; //0x0034
		uint64_t player; //0x0038
		char gamertag[32]; //0x0040
		uint32_t localControllerIndex; //0x0060
		uint32_t playerEmblem; //0x0064
		char pad_0068[36]; //0x0068
		char clanAbbrev[5]; //0x008C
		uint8_t clanAbbrev_IsEliteValidated; //0x0091
		char pad_0092[2]; //0x0092
		uint32_t codPoints; //0x0094
		uint32_t affinityBits; //0x0098
		char pad_009C[60]; //0x009C
		uint32_t availableMapPackFlags; //0x00D8
		char pad_00DC[16]; //0x00DC
		uint32_t deaths; //0x00EC
		uint32_t skillRating; //0x00F0
		uint32_t skillVariance; //0x00F4
		char pad_00F8[16]; //0x00F8
		uint32_t score; //0x0108
		char pad_010C[60]; //0x010C
	}; //Size: 0x0148
	struct PartyData_s
	{
		uint32_t session; //0x0000
		uint32_t presenceSession; //0x0004
		char pad_0008[512]; //0x0008
		PartyMember partyMembers[19]; //0x0208
		char pad_1A60[39032]; //0x1A60
	}; //Size: 0xB2D8
	struct BulletFireParams
	{
		uint32_t weaponEntIndex; //0x0000
		uint32_t ignoreEntIndex; //0x0004
		float damageMultiplier; //0x0008
		uint32_t methodOfDeath; //0x000C
		vec3 origStart; //0x0010
		vec3 start; //0x001C
		vec3 end; //0x0028
		vec3 dir; //0x0034
	}; //Size: 0x0040
	static DWORD dwCG_t = 0x0000000;
	static DWORD dwcentity_t = 0x0000000;
	static DWORD dwWorldPosToScreenPos = 0x0000000;
	static DWORD dwCG_DrawActiveFrame = 0x0000000;
	static DWORD dwgentity_t = 0x0000000;
	static DWORD dwplayerState_t = 0x0000000;
	static DWORD dwCG_CalcPlayerHealth = 0x0000000;
	static DWORD dwCom_GetClientDObj = 0x0000000;
	static DWORD dwCG_DObjGetWorldTagPos = 0x0000000;
	static DWORD dwCL_LocalClientIsInGame = 0x0000000;
	static DWORD dwSL_FindString = 0x0000000;
	static DWORD dwIN_MouseMove = 0x0000000;
	static DWORD dwDvar_FindVarFromString = 0x0000000;
	static DWORD dwDvar_SetFloat = 0x0000000;
	static DWORD dwDvar_SetLatchedValue = 0x0000000;
	static DWORD dwDvar_SetVariant = 0x0000000;
	static DWORD dwCG_UpdateFOV = 0x0000000;
	static DWORD dwDvar_FindVar = 0x0000000;
	static DWORD dwClientActive_t = 0x0000000;
	static DWORD dwCG_LocationalTrace = 0x0000000;
	static DWORD dwCL_WritePacket = 0x0000000;
	static DWORD dwusercmd_base = 0x0000000;
	static DWORD dw_predictplayerstate = 0x0000000;
	static DWORD dw_getspreadforweapon = 0x0000000;
	static DWORD dw_getweapondef = 0x0000000;
	static DWORD dw_angle_vectors = 0x0000000;
	static DWORD dw_bullethitevent = 0x0000000;
	static DWORD dw_lerpentityorigin = 0x0000000;
	static DWORD dw_setclantag = 0x0000000;
	static DWORD dw_setstatfromint = 0x0000000;
	static DWORD dw_writestats = 0x0000000;
	static DWORD dw_g_statsrootstate = 0x0000000;
	static DWORD dw_livestatsbuffer = 0x0000000;
	static DWORD dw_movetopath = 0x0000000;
	static DWORD dw_setint = 0x0000000;
	static DWORD dw_moveto = 0x0000000;
	static DWORD dw_addtext = 0x0000000;
	static DWORD dw_relcmd = 0x0000000;
	static DWORD dw_getxuid = 0x0000000;
	static DWORD dw_deathmessage = 0x0000000;
	static DWORD dw_lookup_move_to = 0x0000000;
	static DWORD dw_setchecksumfromserver = 0x0000000;
	static DWORD dw_find_hash = 0x0000000;
	static DWORD dw_hash_memory = 0x0000000;
	static DWORD dw_readxuid = 0x0000000;
	static DWORD dw_getvalfrombuffer = 0x0000000;
	static DWORD dw_regprng = 0x0000000;
	static DWORD dw_findprng = 0x0000000;
	static DWORD dw_signhash = 0x0000000;
	static DWORD dw_registerhash = 0x0000000;
	static DWORD dw_setstatswriteneeded = 0x0000000;
	static DWORD dw_thirdperson_offsetangles = 0x0000000;
	static DWORD dw_rankxptable = 0x0000000;
	static DWORD dw_unlocktable = 0x0000000;
	static DWORD dw_playername = 0x0000000;
	static DWORD dw_something = 0x0000000;
	static DWORD dw_setvalforkey = 0x0000000;
	static DWORD dw_getnetaddr = 0x0000000;
	static DWORD dw_lobbydata = 0x0000000;
	static DWORD dw_sbf_internal = 0x0000000;
	static DWORD dw_extra_w2s = 0x0000000;
	static DWORD dw_obituary = 0x0000000;
	static DWORD dw_event = 0x0000000;
	static DWORD dw_getweaponname = 0x0000000;
	static DWORD dw_indexfromname = 0x0000000;
	static DWORD dw_purchaseitem = 0x0000000;
	static DWORD dw_tokens = 0x0000000;
	static DWORD dw_weaponstatpath = 0x0000000;
	static DWORD dw_setfov = 0x0000000;
	static DWORD dw_baseweapon = 0x0000000;
#define CG reinterpret_cast<s_cg_t*>(*reinterpret_cast<s_cg_t**>(dwCG_t))
#define clientinfo_t CG->bgs_t.clientInfo_t
#define s_clientactive reinterpret_cast<clientActive_t*>(*reinterpret_cast<clientActive_t**>(dwClientActive_t))
#define lobby_data reinterpret_cast<PartyData_s*>(dw_lobbydata)
	FORCEINLINE float rand_float(unsigned int* seed)
	{
		unsigned int temp = 0x343FD * *seed + 0x269EC3;
		*seed = temp;
		return (temp >> 17) * 0.000030517578f;
	}
	FORCEINLINE unsigned int* changeSeed(unsigned int* seed)
	{
		unsigned int* result = seed;
		*seed = 214013 * (214013 * (214013 * (214013 * *seed + 2531011) + 2531011) + 2531011) + 2531011;
		return result;
	}
	FORCEINLINE s_playerstate* playerState_t(int entNum) {
		return reinterpret_cast<s_playerstate*>(dwplayerState_t + (entNum * 0x57F8));
	}
	FORCEINLINE scentity_t* centity_t(int entNum)
	{
		return reinterpret_cast<scentity_t*>(*reinterpret_cast<DWORD*>(dwcentity_t) + (entNum * 0x380));
	}
	FORCEINLINE sgentity_t* gentity_t(int entNum)
	{
		return reinterpret_cast<sgentity_t*>(dwgentity_t + (entNum * 0x31C));
	}
	FORCEINLINE s_usercmd* usercmd_get(int cmdNum)
	{
		return (&s_clientactive->cmds[cmdNum & 0x7F]);
	}
	FORCEINLINE bool WorldPosToScreenPos(int localClientNum, vec3* worldPos, vec2* outScreenPos)
	{
		return CallFuncPtr<bool>(dwWorldPosToScreenPos, localClientNum, worldPos, outScreenPos);
	}
	FORCEINLINE double CG_CalcPlayerHealth(s_playerstate* ps)
	{
		return CallFuncPtr<double>(dwCG_CalcPlayerHealth, ps);
	}
	FORCEINLINE LPVOID Com_GetClientDObj(int handle, int localClientNum)
	{
		return CallFuncPtr<LPVOID>(dwCom_GetClientDObj, handle, localClientNum);
	}
	FORCEINLINE bool CL_LocalClientIsInGame(int localClientNum)
	{
		return CallFuncPtr<bool>(dwCL_LocalClientIsInGame, localClientNum);
	}
	FORCEINLINE unsigned int SL_FindString(const char* str)
	{
		return CallFuncPtr<unsigned int>(dwSL_FindString, str);
	}
	FORCEINLINE LPVOID CG_DObjGetWorldTagPos(scpose_t* pose, WORD tagName, LPVOID objEA, vec3* pos)
	{
		return CallFuncPtr<LPVOID>(dwCG_DObjGetWorldTagPos, pose, objEA, tagName, pos);
	}
	FORCEINLINE BYTE* Dvar_FindVarFromString(const char* string)
	{
		return CallFuncPtr<BYTE*>(dwDvar_FindVarFromString, string);
	}
	FORCEINLINE void Dvar_SetFloat(LPVOID dvar, float value)
	{
		return CallFuncPtr<void>(dwDvar_SetFloat, dvar, value);
	}
	FORCEINLINE void CG_UpdateFOV(float value)
	{
		return CallFuncPtr<void>(dwCG_UpdateFOV, value);
	}
	FORCEINLINE void Dvar_SetVariant(LPVOID dvar, float value, int source)
	{
		return CallFuncPtr<void>(dwDvar_SetVariant, dvar, value, source);
	}
	FORCEINLINE LPVOID Dvar_FindVar(int dvarHash)
	{
		return CallFuncPtr<LPVOID>(dwDvar_FindVar, dvarHash);
	}
	FORCEINLINE void CG_LocationalTrace(trace_t* results, vec3* start, vec3* end, int passEntityNum, int contentMask, bool checkRopes, int* context)
	{
		return CallFuncPtr<void>(dwCG_LocationalTrace, results, start, end, passEntityNum, contentMask, checkRopes, context);
	}
	FORCEINLINE void bg_getspread(s_playerstate* ps, int weapon, float* minspread, float* max_spread)
	{
		return CallFuncPtr<void>(dw_getspreadforweapon, ps, weapon, minspread, max_spread);
	}
	FORCEINLINE s_weapondef* getweapondef(std::uint8_t weapon)
	{
		return CallFuncPtr<s_weapondef*>(dw_getweapondef, weapon);
	}
	FORCEINLINE void angle_vectors(vec3* angles, vec3* forward, vec3* right, vec3* up)
	{
		return CallFuncPtr<void>(dw_angle_vectors, angles, forward, right, up);
	}
	FORCEINLINE char setclantag(int index, const char* tag)
	{
		return CallFuncPtr<char>(dw_setclantag, index, tag);
	}
	FORCEINLINE bool setstatfromint(int index, const char* string, int value)
	{
		return CallFuncPtr<bool>(dw_setstatfromint, index, string, value);
	}
	FORCEINLINE int writestats(int index)
	{
		return CallFuncPtr<int>(dw_writestats, index);
	}
	FORCEINLINE int movetopath(ddlState_t* searchState, ddlState_t* resultState, int depth, const char** ddlPath)
	{
		return CallFuncPtr<int>(dw_movetopath, searchState, resultState, depth, ddlPath);
	}
	FORCEINLINE int setint(ddlState_t* searchState, int value, uint8_t* buffer)
	{
		return CallFuncPtr<int>(dw_setint, searchState, value, buffer);
	}
	FORCEINLINE int moveto(ddlState_t* searchState, ddlState_t* resultState, int numArgs)
	{
		return CallFuncPtr<int>(dw_moveto, searchState, resultState, numArgs);
	}
	FORCEINLINE void addtext(int lcm, const char* text)
	{
		return CallFuncPtr<void>(dw_addtext, lcm, text);
	}
	FORCEINLINE void relcmd(int lcm, const char* text)
	{
		return CallFuncPtr<void>(dw_relcmd, lcm, text);
	}
	FORCEINLINE uint64_t getxuid(const char* username)
	{
		return CallFuncPtr<uint64_t>(dw_getxuid, username);
	}
	FORCEINLINE char deathmessage(int lcn, int channel, char* text, int duration, int pixel_width, int flags)
	{
		return CallFuncPtr<char>(dw_deathmessage, lcn, channel, text, duration, pixel_width, flags);
	}
	FORCEINLINE int lookupmoveto(ddlState_t* searchState, const char* name, ddlState_t* resultState)
	{
		return CallFuncPtr<int>(dw_lookup_move_to, searchState, name, resultState);
	}
	FORCEINLINE int find_hash(const char* type)
	{
		return CallFuncPtr<int>(dw_find_hash, type);
	}
	FORCEINLINE int hash_memory(int hash, uint8_t* in, uint32_t inlen, uint8_t* out, uint32_t* outlen)
	{
		return CallFuncPtr<int>(dw_hash_memory, hash, in, inlen, out, outlen);
	}
	FORCEINLINE uint64_t read_xuid(uint8_t* buffer)
	{
		return CallFuncPtr<uint64_t>(dw_readxuid, buffer);
	}
	FORCEINLINE uint32_t getvalfrombuffer(const char* statName, uint8_t* buffer)
	{
		return CallFuncPtr<uint32_t>(dw_getvalfrombuffer, statName, buffer);
	}
	FORCEINLINE int regprng(DWORD* desc)
	{
		return CallFuncPtr<int>(dw_regprng, desc);
	}
	FORCEINLINE int findprng(const char* name)
	{
		return CallFuncPtr<int>(dw_findprng, name);
	}
	FORCEINLINE int signhash(uint8_t* in, uint32_t len, uint8_t* out, uint32_t* outlen, LPVOID useless, int wprng, ecc_key* key)
	{
		return CallFuncPtr<int>(dw_signhash, in, len, out, outlen, useless, wprng, key);
	}
	FORCEINLINE int reghash(DWORD* desc)
	{
		return CallFuncPtr<int>(dw_registerhash, desc);
	}
	FORCEINLINE bool setstatswriteneeded(int controller_index, bool is_write_needed, int stats_location)
	{
		return CallFuncPtr<bool>(dw_setstatswriteneeded, controller_index, is_write_needed, stats_location);
	}
	FORCEINLINE void offsetthirdperson(int lcn)
	{
		return CallFuncPtr<void>(dw_thirdperson_offsetangles, lcn);
	}
	FORCEINLINE char* playername(int localClientNum)
	{
		return CallFuncPtr<char*>(localClientNum);
	}
	FORCEINLINE void setvalueforkey(char* s, const char* key, const char* value)
	{
		return CallFuncPtr<void>(dw_setvalforkey, s, key, value);
	}
	FORCEINLINE netadr_t* getnetadr(netadr_t* result, DWORD* session, int clientNum)
	{
		return CallFuncPtr<netadr_t*>(dw_getnetaddr, result, session, clientNum);
	}
	FORCEINLINE bool extracam_w2s(int localClientNum, vec3* worldPos, vec2* outScreenPos)
	{
		return CallFuncPtr<bool>(dw_extra_w2s, localClientNum, worldPos, outScreenPos);
	}
	FORCEINLINE int getweaponname(int Weapon, char* output, int len)
	{
		return CallFuncPtr<int>(dw_getweaponname, Weapon, output, len);
	}
	FORCEINLINE int indexfromname(const char* item_name)
	{
		return CallFuncPtr<int>(dw_indexfromname, item_name);
	}
	FORCEINLINE bool purchaseitem(int controller, int item_index, int cost)
	{
		return CallFuncPtr<bool>(dw_purchaseitem, controller, item_index, cost);
	}
	FORCEINLINE int tokens(int controller, int index, int cost)
	{
		return CallFuncPtr<int>(dw_tokens, controller, index, cost);
	}
	FORCEINLINE int weaponstatpath(ddlState_t* resultState, int itemIndex, const char* statName, const char* statType)
	{
		return CallFuncPtr<int>(dw_weaponstatpath, resultState, itemIndex, statName, statType);
	}
	FORCEINLINE void set_fov(float fov)
	{
		return CallFuncPtr<void>(dw_setfov, fov);
	}
	FORCEINLINE int baseweapon(int weapon)
	{
		return CallFuncPtr<int>(dw_baseweapon, weapon);
	}
}