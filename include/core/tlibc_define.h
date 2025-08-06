#ifndef _H_TLIBCDEF_H
#define _H_TLIBCDEF_H


#include <stdint.h>
#include <stddef.h>

#define TLIBC_MAX_LENGTH_OF_IDENTIFIER 255
#define TLIBC_MAX_PATH_LENGTH 1024


#define TLIBC_UNUSED(x) (void)(x)

#define TLIBC_OFFSET_OF(type, member) ((size_t) &((type *)0)->member)

#define TLIBC_CONTAINER_OF(ptr, type, member) ((type *)((size_t)ptr - TLIBC_OFFSET_OF(type, member)))


#if defined(_WIN32) || defined(_WIN64)
#pragma warning ( disable : 4996 )

#include <stdlib.h>

#ifndef snprintf
#define snprintf _snprintf
#endif

#define strtoll(nptr, endptr, base)		_strtoi64(nptr, endptr, base)
#define strtoull(nptr, endptr, base)	_strtoui64(nptr, endptr, base)

#endif

#endif//_H_TLIBCDEF_H