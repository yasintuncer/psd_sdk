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
	
	std::wstring to_wstring(const char *ch)
	{
		std::string str = ch;
		std::wstring wstr(str.length(), 'L');
		std::copy(str.begin(), str.end(), wstr.begin());
		return wstr;
	}

	const wchar_t *to_wchar(const char *str)
	{
		return to_wstring(str).c_str();
	}


}

PSD_NAMESPACE_END
