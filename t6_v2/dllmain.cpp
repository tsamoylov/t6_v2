#include "pch.h"

using namespace t6;

#define attachHook(original, hook) (DetourTransactionBegin(), DetourUpdateThread(GetCurrentThread()), DetourAttach((LPVOID*)&original, (LPVOID)hook), DetourTransactionCommit())
#define detachHook(original, hook) (DetourTransactionBegin(), DetourUpdateThread(GetCurrentThread()), DetourDetach((LPVOID*)&original, (LPVOID)hook), DetourTransactionCommit())

#define presentAddy ((DWORD_PTR)GetModuleHandle(L"dxgi.dll") + 0x00000)

#define ByteToFloat(a) ((float)(a)/255.0f)

HRESULT WINAPI hPresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);
typedef HRESULT(WINAPI* tPresent)(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);
tPresent oPresent = reinterpret_cast<tPresent>presentAddy;

int __cdecl hCG_DrawActiveFrame(int localClientNum, int serverTime, int demoType, int cubemapShot, int cubemapSize, int renderScreen);
typedef int(__cdecl* tCG_DrawActiveFrame)(int localClientNum, int serverTime, int demoType, int cubemapShot, int cubemapSize, int renderScreen);
tCG_DrawActiveFrame oCG_DrawActiveFrame = reinterpret_cast<tCG_DrawActiveFrame>(dwCG_DrawActiveFrame);

HWND __cdecl hIN_MouseMove();
typedef HWND(__cdecl* tIN_MouseMove)();
tIN_MouseMove oIN_MouseMove = reinterpret_cast<tIN_MouseMove>(dwIN_MouseMove);

void __cdecl hCL_WritePacket(int localClientNum);
typedef void(__cdecl* tCL_WritePacket)(int localClientNum);
tCL_WritePacket oCL_WritePacket = reinterpret_cast<tCL_WritePacket>(dwCL_WritePacket);

void __cdecl hk_predictplayerstate(int local_client_num);
typedef void(__cdecl* t_predictplayerstate)(int local_client_num);
t_predictplayerstate o_predictplayerstate = reinterpret_cast<t_predictplayerstate>(dw_predictplayerstate);

void __cdecl hk_bullethitevent(int local, int source, int hit, int weapon, vec3* sourcepos, vec3* position, vec3* normal, vec3* decal, int surftype, int event, uint8_t eventParam);
typedef void(__cdecl* t_bullethitevent)(int local, int source, int hit, int weapon, vec3* sourcepos, vec3* position, vec3* normal, vec3* decal, int surftype, int event, uint8_t eventParam);
t_bullethitevent o_bullethitevent = reinterpret_cast<t_bullethitevent>(dw_bullethitevent);

void __cdecl hk_lerpentityorigin(int localClientNum, scentity_t* cent);
typedef void(__cdecl* t_lerpentityorigin)(int localClientNum, scentity_t* cent);
t_lerpentityorigin o_lerpentityorigin = reinterpret_cast<t_lerpentityorigin>(dw_lerpentityorigin);

void __cdecl hk_entityevent(int localClientNum, scentity_t* cent, int event);
typedef void(__cdecl* t_entityevent)(int localClientNum, scentity_t* cent, int event);
t_entityevent o_entityevent = reinterpret_cast<t_entityevent>(dw_event);

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

WNDPROC	oWndProc;

LRESULT APIENTRY WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void Init(HWND hWindow)
{
    oWndProc = (WNDPROC)SetWindowLongPtr(hWindow, GWLP_WNDPROC, (__int3264)(LONG_PTR)WndProc);
}

void Remove(HWND hWindow)
{
    SetWindowLongPtr(hWindow, GWLP_WNDPROC, (LONG_PTR)oWndProc);
}

LRESULT APIENTRY WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (_menu.show && !ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam)) {
        return true;
    }
    return CallWindowProc(oWndProc, hwnd, uMsg, wParam, lParam);
}

HWND __cdecl hIN_MouseMove()
{
    if (_menu.show) {
        *(int*)0x0000000 = 0;
        *(int*)0x0000000 = 1;
        ShowCursor(1);
        return GetForegroundWindow();
    }
    return oIN_MouseMove();
}

HRESULT WINAPI hPresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags)
{

    _menu.present(pChain, SyncInterval, Flags);
    return oPresent(pChain, SyncInterval, Flags);

}

void __cdecl hk_lerpentityorigin(int localClientNum, scentity_t* cent)
{
    o_lerpentityorigin(localClientNum, cent);
    _hooks.lerpentityorigin(localClientNum, cent);
}

void __cdecl hCL_WritePacket(int localClientNum)
{
    _hooks.writepacket(localClientNum);
    oCL_WritePacket(localClientNum);
}

int __cdecl hCG_DrawActiveFrame(int localClientNum, int serverTime, int demoType, int cubemapShot, int cubemapSize, int renderScreen)
{
    //_antiaim.aa_ytotal += _antiaim.aa_ychange;
    //_antiaim.aa_ptotal += _antiaim.aa_pchange;
    _hooks.CG_DrawActiveFrame(localClientNum, serverTime, demoType, cubemapShot, cubemapSize, renderScreen);
    return oCG_DrawActiveFrame(localClientNum, serverTime, demoType, cubemapShot, cubemapSize, renderScreen);
}

void __cdecl hk_predictplayerstate(int local_client_num)
{
    _hooks.predictplayerstate(local_client_num);
    o_predictplayerstate(local_client_num);
}

void __cdecl hk_bullethitevent(int local, int source, int hit, int weapon, vec3* sourcepos, vec3* position, vec3* normal, vec3* decal, int surftype, int event, uint8_t eventParam)
{
    o_bullethitevent(local, source, hit, weapon, sourcepos, position, normal, decal, surftype, event, eventParam);
    _hooks.bullethitevent(local, source, hit, weapon, sourcepos, position, normal, decal, surftype, event, eventParam);
}

void __cdecl hk_entityevent(int localClientNum, scentity_t* cent, int event)
{
    if (event == 0x76)
    {
        char buffer[50];
        snprintf(buffer, 50, "%s killed %s", clientinfo_t[*(__int16*)((DWORD)(&cent->nextState) + 0xE0)].name, clientinfo_t[*(__int16*)((DWORD)(&cent->nextState) + 0xDE)].name);
        console.log(buffer, CON_INFO);
    }
    o_entityevent(localClientNum, cent, event);
}

DWORD WINAPI HackThread(HMODULE hModule) 
{
    attachHook(oPresent, hPresent);
    attachHook(oCG_DrawActiveFrame, hCG_DrawActiveFrame);
    attachHook(oCL_WritePacket, hCL_WritePacket);
    attachHook(oIN_MouseMove, hIN_MouseMove);
    attachHook(o_bullethitevent, hk_bullethitevent);
    attachHook(o_lerpentityorigin, hk_lerpentityorigin);
    attachHook(o_entityevent, hk_entityevent);
    _hooks.call_hook(0xE8, reinterpret_cast<BYTE*>(&hk_predictplayerstate), reinterpret_cast<BYTE*>(0x000000));
    Sleep(1000);
    _targetList.initBones();
    Init(_menu.hwnd);
    console.log("Injected!", CON_INFO);
    while (!GetAsyncKeyState(VK_INSERT));
    {

    }
    detachHook(oPresent, hPresent);
    detachHook(oCG_DrawActiveFrame, hCG_DrawActiveFrame);
    detachHook(oCL_WritePacket, hCL_WritePacket);
    detachHook(oIN_MouseMove, hIN_MouseMove);
    detachHook(o_bullethitevent, hk_bullethitevent);
    detachHook(o_lerpentityorigin, hk_lerpentityorigin);
    detachHook(o_entityevent, hk_entityevent);
    _hooks.call_unhook(0xE8, reinterpret_cast<BYTE*>(&hk_predictplayerstate), reinterpret_cast<BYTE*>(0x000000));
    Sleep(1000);
    Remove(_menu.hwnd);
    FreeLibraryAndExitThread(hModule, 0);
    return 0;

}


BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

