#include "PsdPch.h"

#include "PsdStringUtil.h"
#include "PsdMemoryUtil.h"
#include <cwchar>
#include <cstdlib>
#include <cstring>
#include <codecvt>
#include <string>
#include <locale>

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
		std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
		std::string narrow = converter.to_bytes(ws);
		std::strcpy(buffer, narrow.c_str());
		return buffer;
	}

	const wchar_t *ConvertString(const char *s)
	{	if( s == nullptr )
		{
			return nullptr;
		}
		wchar_t *buffer;
		size_t n = std::strlen(s) + 1;
		buffer = static_cast<wchar_t *>(std::malloc(n * sizeof(wchar_t)));
		std::memset(buffer, 0, n * sizeof(wchar_t));
		if (buffer == nullptr)
		{
			return nullptr;
		}
		
		//for turkish character exception
		std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
		std::wstring wide = converter.from_bytes(s);
		std::wcscpy(buffer, wide.c_str());
		return buffer;
	}

}

PSD_NAMESPACE_END
