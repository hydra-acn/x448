#include "openssl/definitions.h"

/// Returns 1 on success and 0 on failure (i.e. if the shared secret is all zero)
int X25519(uint8_t out_shared_key[32],
           const uint8_t private_key[32],
           const uint8_t peer_public_value[32]);

void X25519_public_from_private(uint8_t out_public_value[32],
                                const uint8_t private_key[32]);
