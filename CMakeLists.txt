cmake_minimum_required(VERSION 2.8)
project (X448)

include_directories(
    include
    src
    src/arch_32
    src/openssl
)

add_library(x448 STATIC
    src/arch_32/f_impl.c
    src/curve448.c
    src/curve448_tables.c
    src/f_generic.c
    src/scalar.c
    include/point_448.h
    src/arch_32/arch_intrinsics.h
    src/arch_32/f_impl.h
    src/curve448_local.h
    src/curve448utils.h
    src/field.h
    src/openssl/constant_time.h
    src/openssl/definitions.h
    src/openssl/numbers.h
    src/word.h
)

install(TARGETS x448)
