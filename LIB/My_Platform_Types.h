#ifndef MY_PLATFORM_TYPES_H_
#define MY_PLATFORM_TYPES_H_

#define NULL ((void*)0)

typedef unsigned char boolean;

typedef unsigned char uint8_t;
typedef signed char   sint8_t;


typedef unsigned int uint16_t;
typedef signed int   sint16_t;

typedef unsigned long uint32_t;
typedef signed long   sint32_t;

typedef unsigned long long uint64_t;
typedef signed long long   sint64_t;

typedef float  float32;
typedef double float64;

typedef volatile unsigned char vboolean;

typedef volatile unsigned char vuint8_t;
typedef volatile signed char   vsint8_t;


typedef volatile unsigned int vuint32_t;
typedef volatile signed int   vsint32_t;

typedef volatile unsigned long long vuint64_t;
typedef volatile signed long long   vsint64_t;

typedef volatile float  vfloat32;
typedef volatile double vfloat64;

#endif
