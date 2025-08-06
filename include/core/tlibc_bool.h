#ifndef _H_TLIBC_BOOL_H
#define _H_TLIBC_BOOL_H

#ifndef __cplusplus

#if defined(_WIN32) || defined(_WIN64)
#  ifndef bool
#    define bool    int
#  endif

#  ifndef true
#    define true    1
#  endif

#  ifndef false
#    define false   0
#  endif

#else
#    include <stdbool.h>
#endif
#endif

#endif//_H_TLIBC_BOOL_H