/// copied from various sources in openssl to avoid linking against libcrypto

#ifndef DEFINITIONS
#define DEFINITIONS

#include <stdint.h>
#include <stddef.h>
#include <string.h>

/* ossl_inline: portable inline definition usable in public headers */
#if !defined(inline) && !defined(__cplusplus)
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/* just use inline */
#define ossl_inline inline
#elif defined(__GNUC__) && __GNUC__ >= 2
#define ossl_inline __inline__
#elif defined(_MSC_VER)
/*
   * Visual Studio: inline is available in C++ only, however
   * __inline is available for C, see
   * http://msdn.microsoft.com/en-us/library/z8y1yy88.aspx
   */
#define ossl_inline __inline
#else
#define ossl_inline
#endif
#else
#define ossl_inline inline
#endif

#ifdef DEBUG_UNUSED
#define __owur __attribute__((__warn_unused_result__))
#else
#define __owur
#endif

static ossl_inline void OPENSSL_cleanse(void* ptr, size_t len)
{
    memset(ptr, 0, len);
}

#endif // DEFINITIONS
