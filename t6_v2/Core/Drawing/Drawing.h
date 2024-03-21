#pragma once

#include "../Game/Game.h"

namespace t6
{
	bool w2s_wrap(vec3* worldPos, vec2* outScreenPos);
	bool extra_w2s_wrap(vec3* worldPos, vec2* outScreenPos);

	class c_drawing
	{
	public:
		//Random
		float rgb_value;
		bool crosshair = true;
		ImVec4 crosshair_color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);

		//Tracers
		struct s_tracers
		{
			vec3 tracer_start3;
			vec3 tracer_end3;
			vec2 tracer_start2;
			vec2 tracer_end2;
			float tracer_alpha;
			bool last_shot;
		}tracers[18];
		int tracercount;
		bool use_tracers = true;
		bool rgb_tracers = true;
		vec3 tracer_color = { 1.0f, 1.0f, 1.0f };
		float tracer_thickness;

		//ESP
		bool bones = true;
		ImVec4 bones_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		bool rgb_bones;
		bool snaplines;
		ImVec4 snaplines_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		bool rgb_snaplines;
		bool names = true;
		ImVec4 names_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		bool rgb_names;
		int selected_border_type = 2;
		const char* border_types[3]{"None", "Box", "Corners"};
		ImVec4 border_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		bool rgb_borders;
		bool fill = true;
		ImVec4 fill_friendlycolor = ImVec4(0.0f, 1.0f, 0.0f, 0.2f);
		ImVec4 fill_hostilecolor = ImVec4(1.0f, 0.0f, 0.0f, 0.2f);
		bool rgb_friendlyfill;
		bool rgb_hostilefill;
		void draw_esp();
	}extern _drawing;
}