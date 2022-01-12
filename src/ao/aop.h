/*
 * Copyright (c) 2022 Asserter, Org. All rights reserved.
 *         Use is subject to license terms.
 *            See LICENSE for details.
 */

#ifndef _AOP_H
#define _AOP_H

#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef enum aop {
	AOP_PASS,
	AOP_FAIL,
	AOP_SKIP
} aop_t;

/* (aop_t aop_t -> aop_t) */
#define AOP_CAT(aop1, aop2) \
	(((aop1) | (aop2)) == AOP_SKIP ? AOP_SKIP : ((aop1) | (aop2)) & AOP_FAIL)

/* (boolean boolean -> aop_t) */
#define AOP_BOOL_EQ(expected, actual) \
	((expected) && (actual) || (expected) == (actual) ? AOP_PASS : AOP_FAIL)

/* (boolean boolean -> aop_t) */
#define AOP_BOOL_EQSKP(expected, actual) \
	((expected) && (actual) || (expected) == (actual) ? AOP_PASS : AOP_SKIP)

/* (integral integral -> aop_t) */
#define AOP_EQ(expected, actual) \
	((expected) != (actual) ? AOP_FAIL : AOP_PASS)

/* (integral integral -> aop_t) */
#define AOP_EQSKP(expected, actual) \
	((expected) != (actual) ? AOP_SKIP : AOP_PASS)

/* Note: for aopmode the order is very important! */
typedef enum aopmode {
	AOPMODE_NE,
	AOPMODE_EQ,
	AOPMODE_LT,
	AOPMODE_LE,
	AOPMODE_GT,
	AOPMODE_GE
} aopmode_t;

/* (aopmode_t integral integral -> aop_t) */
#define AOP_CMP(mode, expected, actual) \
	((expected) == (actual) & (mode) || \
	 (expected) > (actual) & (mode) >> 1 || \
	 (expected) < (actual) & (mode) >> 2 || \
	 (expected) != (actual) & ~(mode) & 1 \
	? AOP_PASS : AOP_FAIL)

/* (aopmode_t integral integral -> aop_t) */
#define AOP_CMPSKP(mode, expected, actual) \
	((expected) == (actual) & (mode) || \
	 (expected) > (actual) & (mode) >> 1 || \
	 (expected) < (actual) & (mode) >> 2 || \
	 (expected) != (actual) & ~(mode) & 1 \
	? AOP_PASS : AOP_SKIP)

#ifdef __cplusplus
extern "c" {
#endif

aop_t aop_expr(bool actual);
aop_t aop_bool_eq(bool expected, bool actual);

aop_t aop_char_eq(char expected, char actual);
aop_t aop_shrt_eq(short expected, short actual);
aop_t aop_int_eq(int expected, int actual);
aop_t aop_long_eq(long expected, long actual);
aop_t aop_llong_eq(long long expected, long long actual);

aop_t aop_uchar_eq(unsigned char expected, unsigned char actual);
aop_t aop_ushrt_eq(unsigned short expected, unsigned short actual);
aop_t aop_uint_eq(unsigned expected, unsigned actual);
aop_t aop_ulong_eq(unsigned long expected, unsigned long actual);
aop_t aop_ullong_eq(unsigned long long expected, unsigned long long actual);

aop_t aop_size_eq(size_t expected, size_t actual);

aop_t aop_flt_eq(float expected, float actual, float reltol, float abstol);
aop_t aop_dbl_eq(double expected, double actual, double reltol, double abstol);
aop_t aop_ldbl_eq(long double expected, long double actual, long double reltol, long double abstol);

aop_t aop_str_eq(const char *expected, const char *actual);
aop_t aop_mem_eq(const void *expected, const void *actual, size_t n, size_t size);
aop_t aop_list_eq(const void *expected, const void *actual,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *));


aop_t aop_exprskp(bool actual);
aop_t aop_bool_eqskp(bool expected, bool actual);

aop_t aop_char_eqskp(char expected, char actual);
aop_t aop_shrt_eqskp(short expected, short actual);
aop_t aop_int_eqskp(int expected, int actual);
aop_t aop_long_eqskp(long expected, long actual);
aop_t aop_llong_eqskp(long long expected, long long actual);

aop_t aop_uchar_eqskp(unsigned char expected, unsigned char actual);
aop_t aop_ushrt_eqskp(unsigned short expected, unsigned short actual);
aop_t aop_uint_eqskp(unsigned expected, unsigned actual);
aop_t aop_ulong_eqskp(unsigned long expected, unsigned long actual);
aop_t aop_ullong_eqskp(unsigned long long expected, unsigned long long actual);

aop_t aop_size_eq(size_t expected, size_t actual);

aop_t aop_flt_eqskp(float expected, float actual, float reltol, float abstol);
aop_t aop_dbl_eqskp(double expected, double actual, double reltol, double abstol);
aop_t aop_ldbl_eqskp(long double expected, long double actual, long double reltol, long double abstol);

aop_t aop_str_eqskp(const char *expected, const char *actual);
aop_t aop_mem_eqskp(const void *expected, const void *actual, size_t n, size_t size);
aop_t aop_list_eqskp(const void *expected, const void *actual,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *));


aop_t aop_char_cmp(aopmode_t mode, char expected, char actual);
aop_t aop_shrt_cmp(aopmode_t mode, short expected, short actual);
aop_t aop_int_cmp(aopmode_t mode, int expected, int actual);
aop_t aop_long_cmp(aopmode_t mode, long expected, long actual);
aop_t aop_llong_cmp(aopmode_t mode, long long expected, long long actual);

aop_t aop_uchar_cmp(aopmode_t mode, unsigned char expected, unsigned char actual);
aop_t aop_ushrt_cmp(aopmode_t mode, unsigned short expected, unsigned short actual);
aop_t aop_uint_cmp(aopmode_t mode, unsigned expected, unsigned actual);
aop_t aop_ulong_cmp(aopmode_t mode, unsigned long expected, unsigned long actual);
aop_t aop_ullong_cmp(aopmode_t mode, unsigned long long expected, unsigned long long actual);

aop_t aop_size_cmp(aopmode_t mode, size_t expected, size_t actual);

aop_t aop_flt_cmp(aopmode_t mode, float expected, float actual, float reltol, float abstol);
aop_t aop_dbl_cmp(aopmode_t mode, double expected, double actual, double reltol, double abstol);
aop_t aop_ldbl_cmp(aopmode_t mode, long double expected, long double actual, long double reltol, long double abstol);

aop_t aop_str_cmp(aopmode_t mode, const char *expected, const char *actual);
aop_t aop_mem_cmp(aopmode_t mode, const void *expected, const void *actual, size_t n, size_t size);
aop_t aop_list_cmp(aopmode_t mode, const void *expected, const void *actual,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *));


aop_t aop_char_cmpskp(aopmode_t mode, char expected, char actual);
aop_t aop_shrt_cmpskp(aopmode_t mode, short expected, short actual);
aop_t aop_int_cmpskp(aopmode_t mode, int expected, int actual);
aop_t aop_long_cmpskp(aopmode_t mode, long expected, long actual);
aop_t aop_llong_cmpskp(aopmode_t mode, long long expected, long long actual);

aop_t aop_uchar_cmpskp(aopmode_t mode, unsigned char expected, unsigned char actual);
aop_t aop_ushrt_cmpskp(aopmode_t mode, unsigned short expected, unsigned short actual);
aop_t aop_uint_cmpskp(aopmode_t mode, unsigned expected, unsigned actual);
aop_t aop_ulong_cmpskp(aopmode_t mode, unsigned long expected, unsigned long actual);
aop_t aop_ullong_cmpskp(aopmode_t mode, unsigned long long expected, unsigned long long actual);

aop_t aop_size_cmpskp(aopmode_t mode, size_t expected, size_t actual);

aop_t aop_flt_cmpskp(aopmode_t mode, float expected, float actual, float reltol, float abstol);
aop_t aop_dbl_cmpskp(aopmode_t mode, double expected, double actual, double reltol, double abstol);
aop_t aop_ldbl_cmpskp(aopmode_t mode, long double expected, long double actual, long double reltol, long double abstol);

aop_t aop_str_cmpskp(aopmode_t mode, const char *expected, const char *actual);
aop_t aop_mem_cmpskp(aopmode_t mode, const void *expected, const void *actual, size_t n, size_t size);
aop_t aop_list_cmpskp(aopmode_t mode, const void *expected, const void *actual,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *));

#ifdef __cplusplus
}
#endif

#endif	/* _AOP_H */
