#include "pch.h"

namespace t6 
{
	cMenu _menu;

	void cMenu::main_color_set(ImU32 base)
	{
		ImVec4 color = ImGui::ColorConvertU32ToFloat4(base);
		inactive = ImVec4(
			color.x * 0.75f,
			color.y * 0.75f,
			color.z * 0.75f,
			color.w);
		hovered = ImVec4(
			color.x + (1.0f - color.x) * 0.15f,
			color.y + (1.0f - color.y) * 0.15f,
			color.z + (1.0f - color.z) * 0.15f,
			color.w);
		frame_inactive = ImVec4(
			color.x * 0.25f,
			color.y * 0.25f,
			color.z * 0.25f,
			color.w);
		frame_hovered = ImVec4(
			frame_inactive.x + (1.0f - frame_inactive.x) * 0.15f,
			frame_inactive.y + (1.0f - frame_inactive.y) * 0.15f,
			frame_inactive.z + (1.0f - frame_inactive.z) * 0.15f,
			frame_inactive.w);
		frame_active = ImVec4(
			color.x + (1.0f - color.x) * 0.15f,
			color.y + (1.0f - color.y) * 0.15f,
			color.z + (1.0f - color.z) * 0.15f,
			color.w);
		ImGui::GetStyle().Colors[ImGuiCol_TitleBgActive] = color;
		ImGui::GetStyle().Colors[ImGuiCol_TitleBg] = color;
		ImGui::GetStyle().Colors[ImGuiCol_TabActive] = color;
		ImGui::GetStyle().Colors[ImGuiCol_TitleBgCollapsed] = inactive;
		ImGui::GetStyle().Colors[ImGuiCol_Tab] = inactive;
		ImGui::GetStyle().Colors[ImGuiCol_TabHovered] = hovered;
		ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = frame_inactive;
		ImGui::GetStyle().Colors[ImGuiCol_FrameBgHovered] = frame_hovered;
		ImGui::GetStyle().Colors[ImGuiCol_FrameBgActive] = frame_active;
		ImGui::GetStyle().Colors[ImGuiCol_SliderGrab] = color;
		ImGui::GetStyle().Colors[ImGuiCol_SliderGrabActive] = color;
	}

	void cMenu::present(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags)
	{
		if (!bInit)
		{
			pChain->GetDesc(&sd);
			pChain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&pDevice));
			pDevice->GetImmediateContext(&pContext);

			ImGui::CreateContext();

			ImGui_ImplWin32_Init(sd.OutputWindow);
			ImGui_ImplDX11_Init(pDevice, pContext);

			hwnd = sd.OutputWindow;

			_menu.io.DisplaySize;

			io = ImGui::GetIO();

			io.Fonts->AddFontFromMemoryCompressedTTF(&Aller_Rg_compressed_data, Aller_Rg_compressed_size, 15.0f);
			io.Fonts->Build();

			ImGui::SetMouseCursor(ImGuiMouseCursor_None);
			ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

			ImGui::GetStyle().WindowRounding = 5.0f;
			ImGui::GetStyle().WindowTitleAlign = ImVec2(0.5f, 0.5f);
			ImGui::GetStyle().WindowMenuButtonPosition = ImGuiDir_None;
			ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImGui::ColorConvertU32ToFloat4(IM_COL32(0, 0, 0, 255));
			ImGui::GetStyle().FrameRounding = 5.0f;
			ImGui::GetStyle().GrabRounding = 2.5f;
			active = ImGui::ColorConvertU32ToFloat4(IM_COL32(124, 0, 247, 255));
			main_color_set(ImGui::ColorConvertFloat4ToU32(active));
			check_color = ImGui::ColorConvertU32ToFloat4(IM_COL32(207, 109, 23, 255));
			fov = *(float*)(Dvar_FindVarFromString("cg_fov") + 0x18);
			thirdperson = CG->bThirdPerson;
			show = false;
			bInit = true;
		}
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		draw = ImGui::GetBackgroundDrawList();
		io = ImGui::GetIO();
		_drawing.rgb_value = (clock() % 2000) / 2000.f;
		ImGui::GetStyle().Colors[ImGuiCol_CheckMark] = check_color;
		if (console.show)
		{
			draw->AddRectFilled(ImVec2(io.DisplaySize.x - 500, 0), ImVec2(io.DisplaySize.x, 250.f), IM_COL32(255, 255, 255, 25));
			float y = 250.0f;
			for (int i = 0; i < 16; i++)
			{
				if (console.line[i])
				{
					ImVec2 textSize = ImGui::CalcTextSize(console.line[i], 0, false, 500.f);
					y -= textSize.y;
					draw->AddText(io.Fonts->Fonts[0], 15.0f, ImVec2(io.DisplaySize.x - 500 + 1, y + 1), IM_COL32(0, 0, 0, 255), console.line[i], 0, 500.f);
					draw->AddText(io.Fonts->Fonts[0], 15.0f, ImVec2(io.DisplaySize.x - 500 - 1, y - 1), IM_COL32(0, 0, 0, 255), console.line[i], 0, 500.f);
					draw->AddText(io.Fonts->Fonts[0], 15.0f, ImVec2(io.DisplaySize.x - 500 + 1, y - 1), IM_COL32(0, 0, 0, 255), console.line[i], 0, 500.f);
					draw->AddText(io.Fonts->Fonts[0], 15.0f, ImVec2(io.DisplaySize.x - 500 - 1, y + 1), IM_COL32(0, 0, 0, 255), console.line[i], 0, 500.f);
					draw->AddText(io.Fonts->Fonts[0], 15.0f, ImVec2(io.DisplaySize.x - 500, y), IM_COL32(255, 255, 255, 255), console.line[i], 0, 500.f);
				}
			}
		}
		if (show) {
			ImGui::Begin("t6", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
			if (ImGui::BeginTabBar("main"))
			{
				if (ImGui::BeginTabItem("Aimbot"))
				{
					ImGui::Text("Aimbot");
					ImGui::Separator();
					ImGui::Combo("Type", &_aimbot.selected_type, _aimbot.types, IM_ARRAYSIZE(_aimbot.types));
					if (ImGui::IsItemEdited())
					{
						switch (_aimbot.selected_type)
						{
						case 0:
							aimbot = false;
							silent_aim = false;
							break;
						case 1:
							aimbot = true;
							silent_aim = false;
							break;
						case 2:
							aimbot = false;
							silent_aim = true;
							break;
						}
					}
					ImGui::NewLine();
					ImGui::Text("Extra Options");
					ImGui::Separator();
					ImGui::Checkbox("Target Priority", &target_stick);
					ImGui::Checkbox("Autofire", &autofire);
					ImGui::EndTabItem();

				}
				if (ImGui::BeginTabItem("Anti Aim"))
				{
					ImGui::Text("Anti Aim");
					ImGui::Separator();
					ImGui::Combo("Yaw", &_antiaim.aa_yselected_type, _antiaim.aa_ytype, IM_ARRAYSIZE(_antiaim.aa_ytype));
					if (!_antiaim.aa_yselected_type || (_antiaim.aa_yselected_type == 3))
					{
						ImGui::NewLine();
					}
					else if (_antiaim.aa_yselected_type == 1)
					{
						ImGui::SliderFloat("Yaw Direction", &_antiaim.aa_ydir, -180.0f, 180.0f, "%.1f", 1.0f);
					}
					else if (_antiaim.aa_yselected_type == 2)
					{
						ImGui::SliderFloat("Yaw Delta", &_antiaim.aa_ychange, -100.0f, 100.0f, "%.1f", 1.0f);
					}
					ImGui::Combo("Pitch", &_antiaim.aa_pselected_type, _antiaim.aa_ptype, IM_ARRAYSIZE(_antiaim.aa_ptype));
					if (!_antiaim.aa_pselected_type || (_antiaim.aa_pselected_type == 3))
					{
						ImGui::NewLine();
					}
					else if (_antiaim.aa_pselected_type == 1)
					{
						ImGui::SliderFloat("Pitch Direction", &_antiaim.aa_pdir, -85.0f, 85.0f, "%.1f", 1.0f);
					}
					else if (_antiaim.aa_pselected_type == 2)
					{
						ImGui::SliderFloat("Pitch Delta", &_antiaim.aa_pchange, -100.0f, 100.0f, "%.1f", 1.0f);
					}
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Visuals"))
				{
					ImGui::Text("ESP");
					ImGui::Separator();
					ImGui::Combo("Border", &_drawing.selected_border_type, _drawing.border_types, IM_ARRAYSIZE(_drawing.border_types));
					ImGui::SameLine();
					ImGui::ColorEdit4("Border Color", &_drawing.border_color.x, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::NewLine();
					ImGui::Checkbox("Fill", &_drawing.fill);
					ImGui::SameLine();
					ImGui::ColorEdit4("Friendly Color", &_drawing.fill_friendlycolor.x, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::SameLine();
					ImGui::ColorEdit4("Hostile Color", &_drawing.fill_hostilecolor.x, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel, &_drawing.rgb_hostilefill);
					ImGui::NewLine();
					ImGui::Checkbox("Bones", &_drawing.bones);
					ImGui::SameLine();
					ImGui::ColorEdit4("Bone Color", &_drawing.bones_color.x, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::NewLine();
					ImGui::Checkbox("Names", &_drawing.names);
					ImGui::SameLine();
					ImGui::ColorEdit4("Name Color", &_drawing.names_color.x, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::NewLine();
					ImGui::Checkbox("Snaplines", &_drawing.snaplines);
					ImGui::SameLine();
					ImGui::ColorEdit4("Snapline Color", &_drawing.snaplines_color.x, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::NewLine();
					ImGui::Text("Crosshair");
					ImGui::Separator();
					ImGui::Checkbox("Crosshair", &_drawing.crosshair);
					ImGui::SameLine();
					ImGui::ColorEdit4("Crosshair Color", &_drawing.crosshair_color.x, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::NewLine();
					ImGui::Text("Tracers");
					ImGui::Separator();
					ImGui::Checkbox("Draw Tracers", &_drawing.use_tracers);
					ImGui::SameLine();
					ImGui::Checkbox("RGB Tracers", &_drawing.rgb_tracers);
					ImGui::SameLine();
					ImGui::ColorEdit3("Tracer Color", &_drawing.tracer_color.x, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::NewLine();
					ImGui::Text("Dvars");
					ImGui::Separator();
					ImGui::SliderFloat("FOV", &fov, 65.0f, 150.0f, "%.1f", 1.0f);
					if(ImGui::IsItemEdited())
					{
						*(float*)(Dvar_FindVarFromString("cg_fov") + 0x18) = fov;
						*(float*)(Dvar_FindVarFromString("cg_fov_default") + 0x18) = fov;
						*(bool*)(Dvar_FindVarFromString("cg_fov") + 0x14) = 0;
						*(bool*)(Dvar_FindVarFromString("cg_fov_default") + 0x14) = 0;
					}
					ImGui::Checkbox("Third Person", &thirdperson);
					if (ImGui::IsItemDeactivatedAfterEdit())
					{
						*(bool*)(Dvar_FindVarFromString("cg_thirdPerson") + 0x38) = thirdperson;
						*(bool*)(Dvar_FindVarFromString("cg_thirdPerson") + 0x14) = 0;
						CG->bThirdPerson = thirdperson;
					}
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Removals"))
				{
					ImGui::Checkbox("No Recoil", &_removals.norecoil);
					ImGui::Checkbox("No Spread", &_removals.nospread);
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Lobby"))
				{
					ImGui::Text("Lobby Info");
					ImGui::Separator();
					if (ImGui::BeginTable("Players", 3, ImGuiTableFlags_BordersH | ImGuiTableFlags_BordersV))
					{
						for (int row = 0; row < 18; row++)
						{
							if (lobby_data->partyMembers[row].status)
							{
								ImGui::TableNextRow();
								for (int column = 0; column < 3; column++)
								{
									ImGui::TableSetColumnIndex(column);
									switch (column)
									{
									case 0:
										ImGui::Text("%s", lobby_data->partyMembers[row].gamertag);
										break;
									case 1:
										ImGui::Text("temp");
										break;
									case 2:
										ImGui::Text("%llu",getxuid(lobby_data->partyMembers[row].gamertag));
										break;
									}
								}
							}
						}
						ImGui::EndTable();
					}
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Stats"))
				{
					ImGui::Text("Stats");
					ImGui::Separator();
					static int prestige;
					ImGui::InputInt("Prestige", &prestige);
					ImGui::SameLine();
					if (ImGui::Button("Set##Prestige"))
					{
						_stats.set_prestige(prestige);
					}
					static int rank;
					ImGui::InputInt("Rank", &rank);
					ImGui::SameLine();
					if (ImGui::Button("Set##Rank"))
					{
						_stats.set_rank(rank);
					}
					if (ImGui::Button("Unlock All"))
					{
						_stats.unlockall();
					}
					if (ImGui::Button("Spoof Camos"))
					{
						*((uint64_t*)0x25EAC00) = -1;
					}
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Colors"))
				{
					ImGui::ColorEdit3("Main Color", (float*)&active, 0, &main_color_rgb);
					main_color_set(main_color_rgb ? ImGui::ColorConvertFloat4ToU32(ImColor::HSV(_drawing.rgb_value, 1.0f, 1.0f, active.w)) : ImGui::ColorConvertFloat4ToU32(active));
					ImGui::ColorEdit3("Check Box Color", (float*)&check_color);
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Test"))
				{
					ImGui::NewLine();
					static char commandbuffer[50];
					if (ImGui::InputTextWithHint("Execute Cbuf", "Cbuf Command", commandbuffer, sizeof(commandbuffer), ImGuiInputTextFlags_EnterReturnsTrue))
					{
						addtext(0, commandbuffer);
					}
					ImGui::NewLine();
					static char relbuffer[50];
					if (ImGui::InputTextWithHint("Execute Reliable", "Reliable Command", relbuffer, sizeof(relbuffer), ImGuiInputTextFlags_EnterReturnsTrue))
					{
						relcmd(0, relbuffer);
					}
					ImGui::NewLine();
					static char chatbuffer[50];
					ImGui::InputTextWithHint("##channel_print", "Your Text Here", chatbuffer, sizeof(chatbuffer));
					ImGui::SameLine();
					static int selected_channel;
					ImGui::SetNextItemWidth(45.0f);
					ImGui::Combo("##channel", &selected_channel, "1\0 2\0 3\0 4\0 5\0 6\0 7\0 8\0 9\0 10\0 11\0 12\0 13\0");
					ImGui::SameLine();
					if (ImGui::Button("Send"))
					{
						static char newbuffer[50];
						snprintf(newbuffer, sizeof(newbuffer), "%s\n", chatbuffer);
						deathmessage(0, selected_channel + 1, newbuffer, 0, 390, 0);
					}
					ImGui::NewLine();
					static char console_print[50];
					ImGui::InputTextWithHint("##console_print", "Print to Console", console_print, sizeof(console_print));
					ImGui::SameLine();
					if (ImGui::Button("Send##console"))
					{
						console.log(console_print, CON_DEBUG);
						//console.log(console_print);
					}
					ImGui::EndTabItem();
				}
				ImGui::EndTabBar();
			}
			ImGui::End();
		}
		if (CL_LocalClientIsInGame(0))
		{
			_drawing.draw_esp();
		}
		if (GetAsyncKeyState(VK_NUMPAD0) & 1)
		{
			show = !show;
		}
		if (GetAsyncKeyState(VK_ADD) & 1)
		{
			console.show = !console.show;
		}
		if (GetAsyncKeyState(VK_NUMPAD8) & 1)
		{
			console.log(format("%d", clientinfo_t[CG->clientNum].infoValid), CON_DEBUG);
			console.log(format("%d", clientinfo_t[18].infoValid), CON_DEBUG);
		}
		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			s_clientactive->viewangles.x = 0;
			s_clientactive->viewangles.y = 0;

		}
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
}