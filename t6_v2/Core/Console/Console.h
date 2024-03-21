#pragma once
#include "../Game/Game.h"

namespace t6
{
	enum e_reason
	{
		CON_DEBUG,
		CON_INFO,
		CON_ERROR
	};
	class c_console
	{
	public:
		char line[16][100];
		void push_back();
		void log(const char* text, e_reason reason);
		void logprintf(const char* format,...);
		bool show;
	}extern console;
}