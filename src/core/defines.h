#pragma once

//* Unsigned int types.

/** Unsigned 8-bit integer */
typedef unsigned char u8;

/** Unsigned 16-bit integer */
typedef unsigned short u16;

/** Unsigned 32-bit integer */
typedef unsigned int u32;

/** Unsigned 64-bit integer */
typedef unsigned long long u64;

//* Signed int types.

/** Signed 8-bit integer */
typedef signed char i8;

/** Signed 16-bit integer */
typedef signed short i16;

/** Signed 32-bit integer */
typedef signed int i32;

/** Signed 64-bit integer */
typedef signed long long i64;

//* Floating point types

/** 32-bit floating point number */
typedef float f32;

/** 64-bit floating point number */
typedef double f64;

//* Boolean types

/** 32-bit boolean type */
typedef int b32;

/** 8-bit boolean type */
typedef _Bool b8;

#define StaticAssert _Static_assert

//* Ensure all types are of the correct size.

StaticAssert(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
StaticAssert(sizeof(u16) == 2, "Expected u16 to be 2 byte.");
StaticAssert(sizeof(u32) == 4, "Expected u32 to be 4 byte.");
StaticAssert(sizeof(u64) == 8, "Expected u64 to be 8 byte.");

StaticAssert(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
StaticAssert(sizeof(i16) == 2, "Expected i16 to be 2 byte.");
StaticAssert(sizeof(i32) == 4, "Expected i32 to be 4 byte.");
StaticAssert(sizeof(i64) == 8, "Expected i64 to be 8 byte.");

StaticAssert(sizeof(f32) == 4, "Expected f32 to be 4 byte.");
StaticAssert(sizeof(f64) == 8, "Expected f64 to be 8 byte.");

StaticAssert(sizeof(b32) == 4, "Expected b32 to be 4 byte.");
StaticAssert(sizeof(b8) == 1, "Expected b8 to be 1 byte.");

//* Boolean values

#define true 1
#define false 0

//* Platform detection

// Windows OS
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#  define OS_WINDOWS 1
#  ifndef _WIN64
#    error "64-bit is required on Windows!"
#  endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#  define OS_LINUX 1
#  if defined(__ANDROID__)
#    define OS_ANDROID 1
#  endif
#elif defined(__unix__)
// Catch anything not caught by the above.
#  define OS_UNIX 1
#elif defined(_POSIX_VERSION)
// Posix
#  define OS_POSIX 1
#elif __APPLE__
// Apple platforms
#  define OS_APPLE 1
#  include <TargetConditionals.h>
#  if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#    define OS_IOS 1
#    define OS_IOS_SIMULATOR 1
#  elif TARGET_OS_IPHONE
#    define OS_IOS 1
#  else
#    error "Unknown Apple platform"
#  endif
#else
#  error "Unknown platform!"
#endif

//* Memory units

/** Gets the number of bytes from amount of terabytes (TiB) (1024*1024*1024*1024) */
#define TB(amount) ((abount) * 1024ULL * 1024ULL * 1024ULL * 1024ULL)
/** Gets the number of bytes from amount of gibibytes (GiB) (1024*1024*1024) */
#define GB(amount) ((amount) * 1024ULL * 1024ULL * 1024ULL)
/** Gets the number of bytes from amount of mebibytes (MiB) (1024*1024) */
#define MB(amount) ((amount) * 1024ULL * 1024ULL)
/** Gets the number of bytes from amount of kibibytes (KiB) (1024) */
#define KB(amount) ((amount) * 1024ULL)

//* Clamps, Mins, Maxes

#define Min(A, B) (((A) < (B)) ? (A) : (B))
#define Max(A, B) (((A) > (B)) ? (A) : (B))
#define ClampTop(A, X) Min(A, X)
#define ClampBot(X, B) Max(X, B)
#define Clamp(A, X, B) (((X) < (A)) ? (A) : ((X) > (B)) ? (B) \
                                                        : (X))
