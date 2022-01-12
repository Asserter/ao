/*
 * Copyright (c) 2022 Asserter, Org. All rights reserved.
 *         Use is subject to license terms.
 *            See LICENSE for details.
 */

#include <ao/aop.h>

aop_t aop_expr(bool actual)
{
	return actual ? AOP_PASS : AOP_FAIL;
}

aop_t aop_char_eq(char actual, char expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_shrt_eq(short actual, short expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_int_eq(int actual, int expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_long_eq(long actual, long expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_llong_eq(long long actual, long long expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_uchar_eq(unsigned char actual, unsigned char expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_ushrt_eq(unsigned short actual, unsigned short expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_uint_eq(unsigned actual, unsigned expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_ulong_eq(unsigned long actual, unsigned long expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_ullong_eq(unsigned long long actual, unsigned long long expected)
{
	return AOP_EQ(actual, expected);
}

aop_t aop_flt_eq(float actual, float expected, float reltol, float abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	float tol;
	if (actual == expected)
		return AOP_PASS;
	tol = (fabsf(actual) > fabsf(expected) ? fabsf(actual) : fabsf(expected)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabsf(actual - expected) < tol ? AOP_PASS : AOP_FAIL;
}

aop_t aop_dbl_eq(double actual, double expected, double reltol, double abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	double tol;
	if (actual == expected)
		return AOP_PASS;
	tol = (fabs(actual) > fabs(expected) ? fabs(actual) : fabs(expected)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabs(actual - expected) < tol ? AOP_PASS : AOP_FAIL;
}

aop_t aop_str_eq(const char *actual, const char *expected)
{
	if (!actual || !expected) {
		if (actual != expected)
			return AOP_FAIL;
	}
	else if (strcmp(actual, expected))
		return AOP_FAIL;
	return AOP_PASS;
}

aop_t aop_mem_eq(const void *actual, const void *expected, size_t n, size_t size)
{
	size_t i;
	if (!actual || !expected)
		return AOP_EQ(actual, expected);
	for (i = 0; n--; i += size)
		if (memcmp((char *)actual+i, (char *)expected+i, size))
			return AOP_FAIL;
	return AOP_PASS;
}

aop_t aop_list_eq(const void *actual, const void *expected,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *))
{
	while (actual || expected) {
		if (cmp(actual, expected))
			return AOP_FAIL;
		actual = nxt(actual);
		expected = nxt(expected);
	}
	return AOP_PASS;
}


aop_t aop_expr_skip(bool actual)
{
	return actual ? AOP_PASS : AOP_SKIP;
}

aop_t aop_char_skip_eq(char actual, char expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_shrt_skip_eq(short actual, short expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_int_skip_eq(int actual, int expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_long_skip_eq(long actual, long expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_llong_skip_eq(long long actual, long long expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_uchar_skip_eq(unsigned char actual, unsigned char expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_ushrt_skip_eq(unsigned short actual, unsigned short expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_uint_skip_eq(unsigned actual, unsigned expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_ulong_skip_eq(unsigned long actual, unsigned long expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_ullong_skip_eq(unsigned long long actual, unsigned long long expected)
{
	return AOP_SKIP_EQ(actual, expected);
}

aop_t aop_flt_skip_eq(float actual, float expected, float reltol, float abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	float tol;
	if (actual == expected)
		return AOP_PASS;
	tol = (fabsf(actual) > fabsf(expected) ? fabsf(actual) : fabsf(expected)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabsf(actual - expected) < tol ? AOP_PASS : AOP_SKIP;
}

aop_t aop_dbl_skip_eq(double actual, double expected, double reltol, double abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	double tol;
	if (actual == expected)
		return AOP_PASS;
	tol = (fabs(actual) > fabs(expected) ? fabs(actual) : fabs(expected)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabs(actual - expected) < tol ? AOP_PASS : AOP_FAIL;
}

aop_t aop_str_skip_eq(const char *actual, const char *expected)
{
	if (!actual || !expected) {
		if (actual != expected)
			return AOP_SKIP;
	}
	else if (strcmp(actual, expected))
		return AOP_SKIP;
	return AOP_PASS;
}

aop_t aop_mem_skip_eq(const void *actual, const void *expected, size_t n, size_t size)
{
	size_t i;
	if (!actual || !expected)
		return AOP_EQ(actual, expected);
	for (i = 0; n--; i += size)
		if (memcmp((char *)actual+i, (char *)expected+i, size))
			return AOP_SKIP;
	return AOP_PASS;
}

aop_t aop_list_skip_eq(const void *actual, const void *expected,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *))
{
	while (actual || expected) {
		if (cmp(actual, expected))
			return AOP_SKIP;
		actual = nxt(actual);
		expected = nxt(expected);
	}
	return AOP_PASS;
}


aop_t aop_char_cmp(char actual, char expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}

aop_t aop_shrt_cmp(short actual, short expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}

aop_t aop_int_cmp(int actual, int expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}

aop_t aop_long_cmp(long actual, long expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}

aop_t aop_llong_cmp(long long actual, long long expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}


aop_t aop_uchar_cmp(unsigned char actual, unsigned char expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}

aop_t aop_ushrt_cmp(unsigned short actual, unsigned short expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}

aop_t aop_uint_cmp(unsigned actual, unsigned expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}

aop_t aop_ulong_cmp(unsigned long actual, unsigned long expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}

aop_t aop_ullong_cmp(unsigned long long actual, unsigned long long expected, aopmode_t mode)
{
	return AOP_CMP(actual, expected, mode);
}


aop_t aop_flt_cmp(float actual, float expected, float reltol, float abstol, aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_dbl_cmp(double actual, double expected, double reltol, double abstol, aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_str_cmp(const char *actual, const char *expected, aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_mem_cmp(const void *actual, const void *expected, size_t n, size_t size, aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}


aop_t aop_list_cmp(const void *actual, const void *expected,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *), aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}


aop_t aop_char_skip_cmp(char actual, char expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}

aop_t aop_shrt_skip_cmp(short actual, short expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}

aop_t aop_int_skip_cmp(int actual, int expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}

aop_t aop_long_skip_cmp(long actual, long expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}

aop_t aop_llong_skip_cmp(long long actual, long long expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}


aop_t aop_uchar_skip_cmp(unsigned char actual, unsigned char expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}

aop_t aop_ushrt_skip_cmp(unsigned short actual, unsigned short expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}

aop_t aop_uint_skip_cmp(unsigned actual, unsigned expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}

aop_t aop_ulong_skip_cmp(unsigned long actual, unsigned long expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}

aop_t aop_ullong_skip_cmp(unsigned long long actual, unsigned long long expected, aopmode_t mode)
{
	return AOP_SKIP_CMP(actual, expected, mode);
}


aop_t aop_flt_skip_cmp(float actual, float expected, float reltol, float abstol, aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_dbl_skip_cmp(double actual, double expected, double reltol, double abstol, aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_str_skip_cmp(const char *actual, const char *expected, aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_mem_skip_cmp(const void *actual, const void *expected, size_t n, size_t size, aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}


aop_t aop_list_skip_cmp(const void *actual, const void *expected,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *), aopmode_t mode)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}
