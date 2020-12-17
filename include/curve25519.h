/*
 * Copyright 2020 The OpenSSL Project Authors. All Rights Reserved.
 * Modifications Copyright 2020 David Schatz
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 *
 * Original file: include/crypto/ecx.h
 */

#include "openssl/definitions.h"

/// Returns 1 on success and 0 on failure (i.e. if the shared secret is all zero)
int X25519(uint8_t out_shared_key[32],
           const uint8_t private_key[32],
           const uint8_t peer_public_value[32]);

void X25519_public_from_private(uint8_t out_public_value[32],
                                const uint8_t private_key[32]);
