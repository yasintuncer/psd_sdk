#pragma once

#include "PsdNamespace.h"
#include "PsdAllocator.h"
#include <string>

PSD_NAMESPACE_BEGIN

namespace stringUtil
{
	///
	/// \brief Convert wchar_t * to char *
	///
	/// \param ws The wide string
	/// \param alloc The mem allocator
	/// \return char* nullptr on error
	///
	char *ConvertWString(const wchar_t *ws, Allocator *alloc);

	///
	/// \brief Convert char * to wchar_t *
	///
	/// \param str The wide string
	/// \param alloc The mem allocator
	/// \return wchar_t* nullptr on error
	///
	wchar_t *ConvertString(const char *str, Allocator *alloc);
	std::wstring to_wstring(const char *ch);
	const wchar_t *to_wchar(const char *str);

}

PSD_NAMESPACE_END
