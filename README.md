# Stand-alone build

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

# Usage

Only two functions are important for x448 ECDH, both defined and documented in `include point_448.h`.
* `c448_error_t x448_int(uint8_t out, const uint8_t* base, const uint8_t* scalar)`
* `void x448_derive_public_key(uint8_t* out, const uint8_t* scalar`

Workflow for Alice:
```
uint8_t* sk = generate_56_random_bytes();
uint8_t* pk = allocate_56_bytes();
x448_derive_public_key(pk, sk);

uint8_t* bob_pk = receive_56_bytes_from_bob();
uint8_t* shared_secret = allocate_56_bytes();
x448_int(shared_secret, bob_pk, sk);

// cleanup your memory after use, overwrite keys with 0!
```

# Copyright notice:

Copyright (c) 1998-2020 The OpenSSL Project
Copyright (c) 1995-1998 Eric A. Young, Tim J. Hudson

All rights reserved.

Originally written by Mike Hamburg


Modifications:

Copyright (c) 2020 David Schatz (david.schatz@tu-ilmenau.de)

Code copied from https://github.com/openssl/openssl
Version 1.1.1f

Files are copied from the following directories, but moved, stripped and
re-organized for standalone compilation

* crypto/ec/curve448
* include/internal

