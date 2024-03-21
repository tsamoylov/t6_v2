#include "pch.h"

namespace t6
{
	bool w2s_wrap(vec3* worldPos, vec2* outScreenPos)
	{
		return (WorldPosToScreenPos(0, worldPos, outScreenPos)
			&& outScreenPos->x > 0
			&& outScreenPos->y > 0
			&& outScreenPos->x < _menu.io.DisplaySize.x
			&& outScreenPos->y < _menu.io.DisplaySize.y);
	}
	bool extra_w2s_wrap(vec3* worldPos, vec2* outScreenPos)
	{
		return (extracam_w2s(0, worldPos, outScreenPos)
			&& outScreenPos->x > 0
			&& outScreenPos->y > 0
			&& outScreenPos->x < _menu.io.DisplaySize.x
			&& outScreenPos->y < _menu.io.DisplaySize.y);
	}
	c_drawing _drawing;
	void c_drawing::draw_esp()
	{
		for (int i = 0; i < 18; i++)
		{
			if (_targetList.TargetInfo[i].valid)
			{
				if (_targetList.TargetInfo[i].w2s && _targetList.TargetInfo[i].lifestate && (CG->nextSnap->ps.ClientNum != i))
				{
					float ydist = abs(_targetList.TargetInfo[i].originOut.y - _targetList.TargetInfo[i].bonesOut[j_helmet].y);
					float xdist = abs(_targetList.TargetInfo[i].bonesOut[j_helmet].x - _targetList.TargetInfo[i].originOut.x);
					float dist = sqrtf(powf(ydist, 2) + powf(xdist, 2));
					if (selected_border_type == 1) {
						_menu.draw->AddRect(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
							ImGui::ColorConvertFloat4ToU32(border_color));

					}
					if (selected_border_type == 2)
					{
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 3)),
							ImGui::ColorConvertFloat4ToU32(border_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 6), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
							ImGui::ColorConvertFloat4ToU32(border_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 3)),
							ImGui::ColorConvertFloat4ToU32(border_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 6), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
							ImGui::ColorConvertFloat4ToU32(border_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 3)),
							ImGui::ColorConvertFloat4ToU32(border_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 6), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
							ImGui::ColorConvertFloat4ToU32(border_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 3)),
							ImGui::ColorConvertFloat4ToU32(border_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 6), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
							ImGui::ColorConvertFloat4ToU32(border_color));
					}
					if (fill)
					{

						if (_targetList.TargetInfo[i].friendly)
						{
							_menu.draw->AddRectFilled(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
								ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
								ImGui::ColorConvertFloat4ToU32(fill_friendlycolor));
						}
						else if (!_targetList.TargetInfo[i].friendly)
						{
							if (_targetList.TargetInfo[i].visible)
							{
								_menu.draw->AddRectFilled(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
									ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
									IM_COL32(252, 110, 8, 150));
							}
							else
							{
								_menu.draw->AddRectFilled(ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)),
									ImVec2(_targetList.TargetInfo[i].bonesOut[j_mainroot].x + (dist / 3), _targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)),
									ImGui::ColorConvertFloat4ToU32(fill_hostilecolor));
							}
						}
					}
					if (bones)
					{
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_neck].x, _targetList.TargetInfo[i].bonesOut[j_neck].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_helmet].x, _targetList.TargetInfo[i].bonesOut[j_helmet].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_neck].x, _targetList.TargetInfo[i].bonesOut[j_neck].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_spineupper].x, _targetList.TargetInfo[i].bonesOut[j_spineupper].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_neck].x, _targetList.TargetInfo[i].bonesOut[j_neck].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_shoulder_le].x, _targetList.TargetInfo[i].bonesOut[j_shoulder_le].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_neck].x, _targetList.TargetInfo[i].bonesOut[j_neck].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_shoulder_ri].x, _targetList.TargetInfo[i].bonesOut[j_shoulder_ri].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_elbow_le].x, _targetList.TargetInfo[i].bonesOut[j_elbow_le].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_shoulder_le].x, _targetList.TargetInfo[i].bonesOut[j_shoulder_le].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_elbow_ri].x, _targetList.TargetInfo[i].bonesOut[j_elbow_ri].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_shoulder_ri].x, _targetList.TargetInfo[i].bonesOut[j_shoulder_ri].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_elbow_ri].x, _targetList.TargetInfo[i].bonesOut[j_elbow_ri].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_wrist_ri].x, _targetList.TargetInfo[i].bonesOut[j_wrist_ri].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_elbow_le].x, _targetList.TargetInfo[i].bonesOut[j_elbow_le].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_wrist_le].x, _targetList.TargetInfo[i].bonesOut[j_wrist_le].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_spinelower].x, _targetList.TargetInfo[i].bonesOut[j_spinelower].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_spineupper].x, _targetList.TargetInfo[i].bonesOut[j_spineupper].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_spinelower].x, _targetList.TargetInfo[i].bonesOut[j_spinelower].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_hip_le].x, _targetList.TargetInfo[i].bonesOut[j_hip_le].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_spinelower].x, _targetList.TargetInfo[i].bonesOut[j_spinelower].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_hip_ri].x, _targetList.TargetInfo[i].bonesOut[j_hip_ri].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_knee_ri].x, _targetList.TargetInfo[i].bonesOut[j_knee_ri].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_hip_ri].x, _targetList.TargetInfo[i].bonesOut[j_hip_ri].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_knee_le].x, _targetList.TargetInfo[i].bonesOut[j_knee_le].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_hip_le].x, _targetList.TargetInfo[i].bonesOut[j_hip_le].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_knee_le].x, _targetList.TargetInfo[i].bonesOut[j_knee_le].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_ankle_le].x, _targetList.TargetInfo[i].bonesOut[j_ankle_le].y), ImGui::ColorConvertFloat4ToU32(bones_color));
						_menu.draw->AddLine(ImVec2(_targetList.TargetInfo[i].bonesOut[j_knee_ri].x, _targetList.TargetInfo[i].bonesOut[j_knee_ri].y),
							ImVec2(_targetList.TargetInfo[i].bonesOut[j_ankle_ri].x, _targetList.TargetInfo[i].bonesOut[j_ankle_ri].y), ImGui::ColorConvertFloat4ToU32(bones_color));
					}
					if (names)
					{
						char buffer[0x50];
						snprintf(buffer, sizeof(buffer), "%s: [%.1fm]", clientinfo_t[i].name, _math.get3DDistance(centity_t(CG->nextSnap->ps.ClientNum)->cpose_t.origin, centity_t(i)->cpose_t.origin) * 0.0254);
						ImVec2 text_size = ImGui::CalcTextSize(buffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - text_size.x / 2) + 1, (_targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)) - text_size.y + 1),
							IM_COL32(0, 0, 0, 255), buffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - text_size.x / 2) - 1, (_targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)) - text_size.y - 1),
							IM_COL32(0, 0, 0, 255), buffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - text_size.x / 2) + 1, (_targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)) - text_size.y - 1),
							IM_COL32(0, 0, 0, 255), buffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - text_size.x / 2) - 1, (_targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)) - text_size.y + 1),
							IM_COL32(0, 0, 0, 255), buffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - text_size.x / 2), (_targetList.TargetInfo[i].bonesOut[j_mainroot].y - (dist / 2)) - text_size.y),
							ImGui::ColorConvertFloat4ToU32(names_color), buffer);
						char wbuffer[1024];
						snprintf(wbuffer, 1024, "%s", *(char**)((*(DWORD*)0x10A7E28) + (0x24 * baseweapon(*(int*)((DWORD)&clientinfo_t[i] + 0x5C4))) + 0x18));
						ImVec2 weap_size = ImGui::CalcTextSize(wbuffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - weap_size.x / 2) + 1, (_targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)) + 1),
							IM_COL32(0, 0, 0, 255), wbuffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - weap_size.x / 2) - 1, (_targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)) - 1),
							IM_COL32(0, 0, 0, 255), wbuffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - weap_size.x / 2) + 1, (_targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)) - 1),
							IM_COL32(0, 0, 0, 255), wbuffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - weap_size.x / 2) - 1, (_targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2)) + 1),
							IM_COL32(0, 0, 0, 255), wbuffer);
						_menu.draw->AddText(ImVec2(
							(_targetList.TargetInfo[i].bonesOut[j_mainroot].x - weap_size.x / 2), (_targetList.TargetInfo[i].bonesOut[j_mainroot].y + (dist / 2))),
							ImGui::ColorConvertFloat4ToU32(names_color), wbuffer);

					}
				}
				if (_targetList.TargetInfo[i].lifestate && (CG->nextSnap->ps.ClientNum != i))
				{
					if ((abs(remainder(_math.lookAt(centity_t(CG->clientNum)->cpose_t.origin, centity_t(i)->cpose_t.origin).y + CG->refdefViewAngles.y - 90.0f, 360.0000f)) < 90.0f) && (_targetList.TargetInfo[i].originOut.y < _menu.io.DisplaySize.y) && snaplines)
					{
						_menu.draw->AddLine(ImVec2(_menu.io.DisplaySize.x / 2.0f, _menu.io.DisplaySize.y),
							ImVec2(_targetList.TargetInfo[i].originOut.x, _targetList.TargetInfo[i].originOut.y),
							ImGui::ColorConvertFloat4ToU32(snaplines_color));
					}
				}
				if (use_tracers)
				{
					for (int i = 0; i < 18; i++)
					{
						if (rgb_tracers)
						{
							_menu.draw->AddLine(ImVec2(tracers[i].tracer_start2.x, tracers[i].tracer_start2.y), ImVec2(tracers[i].tracer_end2.x, tracers[i].tracer_end2.y), ImColor::HSV(rgb_value, 1.0f, 1.0f, tracers[i].tracer_alpha), 0.1f);
						}
						else
						{
							_menu.draw->AddLine(ImVec2(tracers[i].tracer_start2.x, tracers[i].tracer_start2.y), ImVec2(tracers[i].tracer_end2.x, tracers[i].tracer_end2.y), ImGui::ColorConvertFloat4ToU32(ImVec4(tracer_color.x, tracer_color.y, tracer_color.z, tracers[i].tracer_alpha)), 0.1f);
						}
						if (tracers[i].last_shot)
						{
							vec3 campos = CG->bThirdPerson ? _targetList.TargetInfo[CG->clientNum].bones[j_head] : CG->lastViewOrg;
							_menu.draw->AddLine(
								ImVec2
								(
									tracers[i].tracer_end2.x - 3.f,
									tracers[i].tracer_end2.y - 3.f
								),
								ImVec2
								(
									tracers[i].tracer_end2.x + 3.f,
									tracers[i].tracer_end2.y + 3.f
								),
								ImGui::ColorConvertFloat4ToU32(ImVec4(1, 0, 0, tracers[i].tracer_alpha)), 
								2.f
							);
							_menu.draw->AddLine(
								ImVec2
								(
									tracers[i].tracer_end2.x + 3.f,
									tracers[i].tracer_end2.y - 3.f
								),
								ImVec2
								(
									tracers[i].tracer_end2.x - 3.f,
									tracers[i].tracer_end2.y + 3.f
								),
								ImGui::ColorConvertFloat4ToU32(ImVec4(1, 0, 0, tracers[i].tracer_alpha)),
								2.f
							);
						}
					}
				}
				char buffer[50];
				snprintf(buffer, 50, "%d", *(int*)0x0000000);
				_menu.draw->AddText(ImVec2(0, 0), IM_COL32(255, 255, 255, 255), buffer);
				if (crosshair && CL_LocalClientIsInGame(0))
				{
					vec2 center = { ImGui::GetIO().DisplaySize.x / 2.f, ImGui::GetIO().DisplaySize.y / 2.f};
					//_menu.draw->AddRectFilled(ImVec2(center.x - 0.5f, center.y - 5.f), ImVec2(center.x, center.y + 5.f), ImGui::ColorConvertFloat4ToU32(crosshair_color));
					//_menu.draw->AddRectFilled(ImVec2(center.x + 5.f, center.y + 0.5f), ImVec2(center.x - 5.f, center.y), ImGui::ColorConvertFloat4ToU32(crosshair_color));
					_menu.draw->AddLine(ImVec2(center.x, center.y - 5.f), ImVec2(center.x, center.y + 5.f), ImGui::ColorConvertFloat4ToU32(crosshair_color), 1.f);
					_menu.draw->AddLine(ImVec2(center.x + 5.f, center.y), ImVec2(center.x - 5.f, center.y), ImGui::ColorConvertFloat4ToU32(crosshair_color), 1.f);
				}
			}
		}
	}
}