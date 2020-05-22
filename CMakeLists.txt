cmake_minimum_required(VERSION 2.8)
project (X448)

include_directories(
    include
    include/openssl
    include/arch_32
    src
    src/arch_32
)

add_library(x448 STATIC
    include/openssl/constant_time.h
    include/openssl/definitions.h
    include/openssl/numbers.h
    include/arch_32/arch_intrinsics.h
    include/arch_32/f_impl.h
    include/curve448utils.h
    include/field.h
    include/word.h
    include/point_448.h
    src/arch_32/f_impl.c
    src/curve448.c
    src/curve448_tables.c
    src/f_generic.c
    src/scalar.c
    src/curve448_local.h
)

install(
    TARGETS x448
    ARCHIVE DESTINATION lib
)
