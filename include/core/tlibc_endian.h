#ifndef _H_TLIBC_ENDIAN_H
#define _H_TLIBC_ENDIAN_H

#if defined(_WIN32) || defined(_WIN64)
#  define TLIBC_BIG_ENDIAN (4321)
#  define TLIBC_LITTLE_ENDIAN (1234)
#  define TLIBC_BYTE_ORDER TLIBC_LITTLE_ENDIAN

#  define	tlibc_swap64(x)     (((uint64_t)(x) << 56) | \
	(((uint64_t)(x) << 40) & 0xff000000000000ULL) | \
	(((uint64_t)(x) << 24) & 0xff0000000000ULL) | \
	(((uint64_t)(x) << 8)  & 0xff00000000ULL) | \
	(((uint64_t)(x) >> 8)  & 0xff000000ULL) | \
	(((uint64_t)(x) >> 24) & 0xff0000ULL) | \
	(((uint64_t)(x) >> 40) & 0xff00ULL) | \
	((uint64_t)(x)  >> 56))

#  define tlibc_swap32(x) \
	((((x) & 0xff000000) >> 24)                                  \
	| (((x) & 0x00ff0000) >> 8)                                 \
	| (((x) & 0x0000ff00) << 8)                                 \
	| (((x) & 0x000000ff) << 24))                                  

#  define tlibc_swap16(x) \
	((((x) & 0xff00) >> 8)                                  \
	| (((x) & 0x00ff) << 8))                                 


#  if TLIBC_BYTE_ORDER == TLIBC_LITTLE_ENDIAN
#    define htole16(x) (x)
#    define htole32(x) (x)
#    define htole64(x) (x)
#    define le16toh(x) (x)
#    define le32toh(x) (x)
#    define le64toh(x) (x)

#    define htobe16(x) tlibc_swap16(x)
#    define htobe32(x) tlibc_swap32(x)
#    define htobe64(x) tlibc_swap64(x)
#    define be16toh(x) tlibc_swap64(x)
#    define be32toh(x) tlibc_swap32(x)
#    define be64toh(x) tlibc_swap64(x)

#  elif TLIBC_BYTE_ORDER == TLIBC_BIG_ENDIAN
#    define htole16(x) tlibc_swap16(x)
#    define htole32(x) tlibc_swap32(x)
#    define htole64(x) tlibc_swap64(x)
#    define le16toh(x) tlibc_swap64(x)
#    define le32toh(x) tlibc_swap32(x)
#    define le64toh(x) tlibc_swap64(x)

#    define htobe16(x) (x)
#    define htobe32(x) (x)
#    define htobe64(x) (x)
#    define be16toh(x) (x)
#    define be32toh(x) (x)
#    define be64toh(x) (x)
#  else
#    error Unknown TLIBC_BYTE_ORDER
#  endif

#else
#include <endian.h>
#endif


#endif//_H_TLIBC_ENDIAN_H