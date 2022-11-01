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
#define AOP_MASK(oldaop, newaop) \
	(~((oldaop) | (newaop)) & 1)

/* (integral integral -> aop_t) */
#define AOP_EQ(actual, expected) \
	((actual) != (expected) ? AOP_FAIL : AOP_PASS)

/* (integral integral -> aop_t) */
#define AOP_EQSKP(actual, expected) \
	((actual) != (expected) ? AOP_SKIP : AOP_PASS)

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
#define AOP_CMP(mode, actual, expected) \
	((actual) == (expected) & (mode) || \
	 (actual) < (expected) & (mode) >> 1 || \
	 (actual) > (expected) & (mode) >> 2 || \
	 (actual) != (expected) & ~(mode) & 1 \
	? AOP_PASS : AOP_FAIL)

/* (aopmode_t integral integral -> aop_t) */
#define AOP_CMPSKP(mode, actual, expected) \
	((actual) == (expected) & (mode) || \
	 (actual) < (expected) & (mode) >> 1 || \
	 (actual) > (expected) & (mode) >> 2 || \
	 (actual) != (expected) & ~(mode) & 1 \
	? AOP_PASS : AOP_SKIP)

#ifdef __cplusplus
extern "c" {
#endif

aop_t aop_expr(bool actual);

aop_t aop_char_eq(char actual, char expected);
aop_t aop_shrt_eq(short actual, short expected);
aop_t aop_int_eq(int actual, int expected);
aop_t aop_long_eq(long actual, long expected);
aop_t aop_llong_eq(long long actual, long long expected);

aop_t aop_uchar_eq(unsigned char actual, unsigned char expected);
aop_t aop_ushrt_eq(unsigned short actual, unsigned short expected);
aop_t aop_uint_eq(unsigned actual, unsigned expected);
aop_t aop_ulong_eq(unsigned long actual, unsigned long expected);
aop_t aop_ullong_eq(unsigned long long actual, unsigned long long expected);

aop_t aop_flt_eq(float actual, float expected, float reltol, float abstol);
aop_t aop_dbl_eq(double actual, double expected, double reltol, double abstol);

aop_t aop_str_eq(const char *actual, const char *expected);
aop_t aop_mem_eq(const void *actual, const void *expected, size_t n, size_t size);
aop_t aop_list_eq(const void *actual, const void *expected,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *));


aop_t aop_exprskp(bool actual);

aop_t aop_char_eqskp(char actual, char expected);
aop_t aop_shrt_eqskp(short actual, short expected);
aop_t aop_int_eqskp(int actual, int expected);
aop_t aop_long_eqskp(long actual, long expected);
aop_t aop_llong_eqskp(long long actual, long long expected);

aop_t aop_uchar_eqskp(unsigned char actual, unsigned char expected);
aop_t aop_ushrt_eqskp(unsigned short actual, unsigned short expected);
aop_t aop_uint_eqskp(unsigned actual, unsigned expected);
aop_t aop_ulong_eqskp(unsigned long actual, unsigned long expected);
aop_t aop_ullong_eqskp(unsigned long long actual, unsigned long long expected);

aop_t aop_flt_eqskp(float actual, float expected, float reltol, float abstol);
aop_t aop_dbl_eqskp(double actual, double expected, double reltol, double abstol);

aop_t aop_str_eqskp(const char *actual, const char *expected);
aop_t aop_mem_eqskp(const void *actual, const void *expected, size_t n, size_t size);
aop_t aop_list_eqskp(const void *actual, const void *expected,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *));


aop_t aop_char_cmp(aopmode_t mode, char actual, char expected);
aop_t aop_shrt_cmp(aopmode_t mode, short actual, short expected);
aop_t aop_int_cmp(aopmode_t mode, int actual, int expected);
aop_t aop_long_cmp(aopmode_t mode, long actual, long expected);
aop_t aop_llong_cmp(aopmode_t mode, long long actual, long long expected);

aop_t aop_uchar_cmp(aopmode_t mode, unsigned char actual, unsigned char expected);
aop_t aop_ushrt_cmp(aopmode_t mode, unsigned short actual, unsigned short expected);
aop_t aop_uint_cmp(aopmode_t mode, unsigned actual, unsigned expected);
aop_t aop_ulong_cmp(aopmode_t mode, unsigned long actual, unsigned long expected);
aop_t aop_ullong_cmp(aopmode_t mode, unsigned long long actual, unsigned long long expected);

aop_t aop_flt_cmp(aopmode_t mode, float actual, float expected, float reltol, float abstol);
aop_t aop_dbl_cmp(aopmode_t mode, double actual, double expected, double reltol, double abstol);

aop_t aop_str_cmp(aopmode_t mode, const char *actual, const char *expected);
aop_t aop_mem_cmp(aopmode_t mode, const void *actual, const void *expected, size_t n, size_t size);
aop_t aop_list_cmp(aopmode_t mode, const void *actual, const void *expected,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *));


aop_t aop_char_cmpskp(aopmode_t mode, char actual, char expected);
aop_t aop_shrt_cmpskp(aopmode_t mode, short actual, short expected);
aop_t aop_int_cmpskp(aopmode_t mode, int actual, int expected);
aop_t aop_long_cmpskp(aopmode_t mode, long actual, long expected);
aop_t aop_llong_cmpskp(aopmode_t mode, long long actual, long long expected);

aop_t aop_uchar_cmpskp(aopmode_t mode, unsigned char actual, unsigned char expected);
aop_t aop_ushrt_cmpskp(aopmode_t mode, unsigned short actual, unsigned short expected);
aop_t aop_uint_cmpskp(aopmode_t mode, unsigned actual, unsigned expected);
aop_t aop_ulong_cmpskp(aopmode_t mode, unsigned long actual, unsigned long expected);
aop_t aop_ullong_cmpskp(aopmode_t mode, unsigned long long actual, unsigned long long expected);

aop_t aop_flt_cmpskp(aopmode_t mode, float actual, float expected, float reltol, float abstol);
aop_t aop_dbl_cmpskp(aopmode_t mode, double actual, double expected, double reltol, double abstol);

aop_t aop_str_cmpskp(aopmode_t mode, const char *actual, const char *expected);
aop_t aop_mem_cmpskp(aopmode_t mode, const void *actual, const void *expected, size_t n, size_t size);
aop_t aop_list_cmpskp(aopmode_t mode, const void *actual, const void *expected,
	int (*cmp)(const void *a, const void *e), void *(*nxt)(const void *l));

#ifdef __cplusplus
}
#endif

#endif	/* _AOP_H */
