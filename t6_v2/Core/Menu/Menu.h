#pragma once

#include "../Game/Game.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace t6 
{
	class cMenu
	{
	public:

		bool bInit;

		ID3D11Device* pDevice;
		ID3D11DeviceContext* pContext;
		DXGI_SWAP_CHAIN_DESC sd;
		HWND hwnd;

		ImDrawList* draw;

		ImGuiIO io;

		void present(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);

		ImVec4 active;

		ImVec4 inactive;

		ImVec4 hovered;

		ImVec4 frame_inactive;

		ImVec4 frame_hovered;

		ImVec4 frame_active;

		ImVec4 check_color;

		bool show;
		bool main_color_rgb;

		bool showcursor;
		
		bool aimbot;
		bool silent_aim = true;
		bool target_stick = true;
		bool autofire = true;

		bool thirdperson;
		float fov;

		void main_color_set(ImU32 base);

	}extern _menu;

}