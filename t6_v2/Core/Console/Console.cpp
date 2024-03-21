#include "pch.h"

namespace t6
{
	c_console console;
	void c_console::push_back()
	{
		for (int i = 14; i >= 0; i--)
		{
			//memcpy(line[i + 1], line[i], sizeof(line[i]));
			//snprintf(line[i+1], sizeof(line[i+1]), "%s", line[i]);
			strcpy_s(line[i + 1], sizeof(line[i]), line[i]);
			//line[i + 1] = line[i];
		}
	}
	void c_console::log(const char* text, e_reason reason)
	{
		const char* s_reason = "";
		switch (reason)
		{
		case CON_INFO:
			s_reason = "INFO";
			break;
		case CON_DEBUG:
			s_reason = "DEBUG";
			break;
		case CON_ERROR:
			s_reason = "ERROR";
			break;
		}
		static std::tm tm;
		time_t time = std::time(nullptr);
		localtime_s(&tm, &time);
		console.logprintf("[%02d:%02d:%02d][%s] %s", (tm.tm_hour % 12), tm.tm_min, tm.tm_sec, s_reason, text);
	}
	void c_console::logprintf(const char* format, ...)
	{
		static char temp[100];
		va_list arg;
		va_start(arg, format);
		vsnprintf(temp, 100, format, arg);
		va_end(arg);
		push_back();
		strcpy_s(line[0], sizeof(temp), temp);
	}
}