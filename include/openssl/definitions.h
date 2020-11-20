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

/*
 * The volatile is used to to ensure that the compiler generates code that reads
 * all values from the array and doesn't try to optimize this away. The standard
 * doesn't actually require this behavior if the original data pointed to is
 * not volatile, but compilers do this in practice anyway.
 *
 * There are also assembler versions of this function.
 */
static ossl_inline int CRYPTO_memcmp(const void * in_a,
                                     const void * in_b,
                                     size_t len)
{
    size_t i;
    const volatile unsigned char *a = (const unsigned char*) in_a;
    const volatile unsigned char *b = (const unsigned char*) in_b;
    unsigned char x = 0;

    for (i = 0; i < len; i++)
        x |= a[i] ^ b[i];

    return x;
}


#endif // DEFINITIONS
