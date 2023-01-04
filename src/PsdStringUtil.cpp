#include "PsdPch.h"

#include "PsdStringUtil.h"
#include "PsdMemoryUtil.h"

#include <cwchar>
#include <cstdlib>
#include <cstring>
PSD_NAMESPACE_BEGIN

namespace stringUtil
{
	char *ConvertWString(const wchar_t *ws, Allocator *alloc)
	{
		if (ws == nullptr)
		{
			return nullptr;
		}
		char *buffer;
		size_t n = std::wcslen(ws) * 4 + 1;
		buffer = static_cast<char *>(memoryUtil::AllocateArray<char>(alloc, n));
		std::memset(buffer, 0, n);
		if (buffer == nullptr)
		{
			return nullptr;
		}
		std::wcstombs(buffer, ws, n);
		return buffer;
	}
	
	const wchar_t* ConvertString(const char* s)
	{
		if (s == nullptr)
		{
			return nullptr;
		}
		wchar_t* buffer;
		size_t n = std::strlen(s) + 1;
		buffer = static_cast<wchar_t*>(std::malloc(n * sizeof(wchar_t)));
		std::memset(buffer, 0, n * sizeof(wchar_t));
		if (buffer == nullptr)
		{
			return nullptr;
		}
		std::mbstowcs(buffer, s, n);
		return buffer;
	}



}

PSD_NAMESPACE_END
