#pragma once

namespace t6
{
	struct vec3
	{
		float x, y, z;
	};

	struct vec2
	{
		float x, y;
	};

	template<typename RetType, typename... PackedParams>
	FORCEINLINE RetType CallFuncPtr(std::uintptr_t Address, PackedParams... UnpackedParams)
	{
		typedef RetType(*FuncTemplate)(PackedParams...);
		FuncTemplate FuncName = (FuncTemplate)Address;
		return FuncName(UnpackedParams...);
	}

	FORCEINLINE char* format(const char* format,...)
	{
		static char temp[50];
		va_list arg;
		va_start(arg, format);
		vsnprintf(temp, 50, format, arg);
		va_end(arg);
		return temp;
	}
}
