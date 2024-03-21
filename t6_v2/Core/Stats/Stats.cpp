#include "pch.h"

namespace t6
{
	c_stats _stats;
	void c_stats::hash_sign()
	{
		ecc_key* key = *(ecc_key**)0x0000000;
		unsigned __int8 in[8];
		int a = getvalfrombuffer("RANKXP", reinterpret_cast<uint8_t*>(dw_livestatsbuffer));
		int b = getvalfrombuffer("PLEVEL", reinterpret_cast<uint8_t*>(dw_livestatsbuffer));
		__int64 c = read_xuid((uint8_t*)(dw_livestatsbuffer));
		*(unsigned __int64*)in = a ^ b ^ c;
		int tiger_desc = 0xCC81B8;
		reghash(reinterpret_cast<DWORD*>(0x000000));
		unsigned int outlen = 24;
		int sprng_desc = 0x000000;
		unsigned __int8 out[24];
		hash_memory(find_hash((char*)"tiger"), in, 8u, out, &outlen);
		uint32_t hash_len = 0x32;
		ddlState_t search_state;
		lookupmoveto((ddlState_t*)dw_g_statsrootstate, "statsHash", &search_state);
		regprng(reinterpret_cast<DWORD*>(0x000000));
		signhash(out, 0x18, (uint8_t*)(dw_livestatsbuffer + ((search_state.absoluteOffset + 0x180) / 8)), &hash_len, NULL, findprng((LPCSTR)0x000000), key);
		ddlState_t hash_len_state;
		lookupmoveto((ddlState_t*)dw_g_statsrootstate, "hashLen", &hash_len_state);
		*(unsigned int*)(dw_livestatsbuffer + ((hash_len_state.absoluteOffset + 0x180) / 8)) = 0x32;
	}
	void c_stats::set_prestige(int prestige)
	{
		ddlState_t p_state;
		const char* ppath[3];
		ppath[0] = "PlayerStatsList";
		ppath[1] = "PLEVEL";
		ppath[2] = "StatValue";
		movetopath((ddlState_t*)dw_g_statsrootstate, &p_state, 3, ppath);
		*(unsigned int*)(dw_livestatsbuffer + ((p_state.absoluteOffset + 0x180) / 8)) = prestige;
		hash_sign();
	}
	void c_stats::set_rank(int rank)
	{
		if ((rank > 55) || (rank < 0))
		{
			return;
		}
		static unsigned int xp;
		for (unsigned int i = 0; i < 96; i++)
		{
			rankData_t* rankTable = reinterpret_cast<rankData_t*>(dw_rankxptable);
			if (rankTable->rankId[i] == (rank - 1))
			{
				xp = (rankTable->maxxp[i]) - 1;
				break;
			}
		}
		ddlState_t r_state;
		const char* rpath[3];
		rpath[0] = "PlayerStatsList";
		rpath[1] = "RANKXP";
		rpath[2] = "StatValue";
		movetopath((ddlState_t*)dw_g_statsrootstate, &r_state, 3, rpath);
		*(unsigned int*)(dw_livestatsbuffer + ((r_state.absoluteOffset + 0x180) / 8)) = xp;
		hash_sign();
	}
	void c_stats::unlockall()
	{
		for (int i = 0; i < 256; i++)
		{
			purchaseitem(0, i, 0);
			char buffer[50];
			snprintf(buffer, 50, "%d", i);
			const char* path[3];
			path[0] = "ItemStats";
			path[1] = buffer;
			path[2] = "maxxp";
			ddlState_t resultState;
			movetopath((ddlState_t*)dw_g_statsrootstate, &resultState, 3, path);
			static uint32_t xp = *(uint32_t*)(dw_livestatsbuffer + ((resultState.absoluteOffset + 0x180) / 8));
			path[0] = "ItemStats";
			path[1] = buffer;
			path[2] = "xp";
			movetopath((ddlState_t*)dw_g_statsrootstate, &resultState, 3, path);
			setint(&resultState, xp, (uint8_t*)dw_livestatsbuffer);
			path[0] = "ItemStats";
			path[1] = buffer;
			path[2] = "pLevel";
			movetopath((ddlState_t*)dw_g_statsrootstate, &resultState, 3, path);
			setint(&resultState, 2, (uint8_t*)dw_livestatsbuffer);
			const char* path1[5];
			path1[0] = "ItemStats";
			path1[1] = buffer;
			path1[2] = "stats";
			path1[3] = "challenges";
			path1[4] = "challengeValue";
			movetopath((ddlState_t*)dw_g_statsrootstate, &resultState, 5, path1);
			setint(&resultState, 0xFFFF, (uint8_t*)dw_livestatsbuffer);
			path1[0] = "ItemStats";
			path1[1] = buffer;
			path1[2] = "stats";
			path1[3] = "kills";
			path1[4] = "challengeValue";
			movetopath((ddlState_t*)dw_g_statsrootstate, &resultState, 5, path1);
			setint(&resultState, 0xFFFF, (uint8_t*)dw_livestatsbuffer);
			path1[0] = "ItemStats";
			path1[1] = buffer;
			path1[2] = "stats";
			path1[3] = "headshots";
			path1[4] = "challengeValue";
			movetopath((ddlState_t*)dw_g_statsrootstate, &resultState, 5, path1);
			setint(&resultState, 0xFFFF, (uint8_t*)dw_livestatsbuffer);
			for (int j = 1; j < 11; j++)
			{
				char buffer2[50];
				snprintf(buffer2, 50, "challenge%d", j);
				path1[0] = "ItemStats";
				path1[1] = buffer;
				path1[2] = "stats";
				path1[3] = buffer2;
				path1[4] = "challengeValue";
				movetopath((ddlState_t*)dw_g_statsrootstate, &resultState, 5, path1);
				setint(&resultState, 0xFFFF, (uint8_t*)dw_livestatsbuffer);
			}
		}
	}
}