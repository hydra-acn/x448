# Stand-alone build

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

# x448 Usage

Only two functions are important for x448 ECDH, both defined and documented in `include/point_448.h`.
* `c448_error_t x448_int(uint8_t* out, const uint8_t* base, const uint8_t* scalar);`
* `void x448_derive_public_key(uint8_t* out, const uint8_t* scalar);`

Workflow for Alice:
```
uint8_t* sk = generate_56_random_bytes();
uint8_t* pk = allocate_56_bytes();
x448_derive_public_key(pk, sk);

send_pk_to_bob(pk);

uint8_t* bob_pk = receive_56_bytes_from_bob();
uint8_t* shared_secret = allocate_56_bytes();
x448_int(shared_secret, bob_pk, sk);

// important: cleanup your memory after use (overwrite keys with 0, free/delete)!
```

# x25519 Usage

For x25519, the two relevant functions are defined and documented in `include/curve25519.h`.
* `int X25519(uint8_t out_shared_key[32], const uint8_t private_key[32], const uint8_t peer_public_value[32]);`
* `void X25519_public_from_private(uint8_t out_public_value[32], const uint8_t private_key[32]);`

Workflow is analogous to `x448`, but with 32 byte keys.


# Copyright notice

Copyright (c) 1998-2020 The OpenSSL Project
Copyright (c) 1995-1998 Eric A. Young, Tim J. Hudson
All rights reserved.

x448 code originally written by Mike Hamburg.


Modifications:

Copyright (c) 2020 David Schatz

Code copied from https://github.com/openssl/openssl
Version 3.0.0-alpha9

Files are copied from the following directories and files, but moved, stripped
and re-organized for standalone compilation. See further modification notices
per file.

* `crypto/ec/curve448`
* `crypto/ec/curve25519.c`
* `crypto/cryptlib.c`
* `include/crypto/ecx.h`
* `include/internal/numbers.h`
* `include/internal/constant_time.h`
* `include/openssl/e_os2.h`
