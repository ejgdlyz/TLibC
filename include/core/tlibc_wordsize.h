#ifndef _H_TLIBC_WORDSIZE_H
#define _H_TLIBC_WORDSIZE_H

#if defined(_WIN32)
#define __WORDSIZE 32
#elif defined(_WIN64)
#define __WORDSIZE 64
#else
#include <bits/wordsize.h>
#endif

#endif//_H_TLIBC_WORDSIZE_H