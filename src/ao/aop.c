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


aop_t aop_exprskp(bool actual)
{
	return actual ? AOP_PASS : AOP_SKIP;
}

aop_t aop_char_eqskp(char actual, char expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_shrt_eqskp(short actual, short expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_int_eqskp(int actual, int expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_long_eqskp(long actual, long expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_llong_eqskp(long long actual, long long expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_uchar_eqskp(unsigned char actual, unsigned char expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_ushrt_eqskp(unsigned short actual, unsigned short expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_uint_eqskp(unsigned actual, unsigned expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_ulong_eqskp(unsigned long actual, unsigned long expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_ullong_eqskp(unsigned long long actual, unsigned long long expected)
{
	return AOP_EQSKP(actual, expected);
}

aop_t aop_flt_eqskp(float actual, float expected, float reltol, float abstol)
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

aop_t aop_dbl_eqskp(double actual, double expected, double reltol, double abstol)
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

aop_t aop_str_eqskp(const char *actual, const char *expected)
{
	if (!actual || !expected) {
		if (actual != expected)
			return AOP_SKIP;
	}
	else if (strcmp(actual, expected))
		return AOP_SKIP;
	return AOP_PASS;
}

aop_t aop_mem_eqskp(const void *actual, const void *expected, size_t n, size_t size)
{
	size_t i;
	if (!actual || !expected)
		return AOP_EQ(actual, expected);
	for (i = 0; n--; i += size)
		if (memcmp((char *)actual+i, (char *)expected+i, size))
			return AOP_SKIP;
	return AOP_PASS;
}

aop_t aop_list_eqskp(const void *actual, const void *expected,
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


aop_t aop_char_cmp(aopmode_t mode, char actual, char expected)
{
	return AOP_CMP(mode, actual, expected);
}

aop_t aop_shrt_cmp(aopmode_t mode, short actual, short expected)
{
	return AOP_CMP(mode, actual, expected);
}

aop_t aop_int_cmp(aopmode_t mode, int actual, int expected)
{
	return AOP_CMP(mode, actual, expected);
}

aop_t aop_long_cmp(aopmode_t mode, long actual, long expected)
{
	return AOP_CMP(mode, actual, expected);
}

aop_t aop_llong_cmp(aopmode_t mode, long long actual, long long expected)
{
	return AOP_CMP(mode, actual, expected);
}


aop_t aop_uchar_cmp(aopmode_t mode, unsigned char actual, unsigned char expected)
{
	return AOP_CMP(mode, actual, expected);
}

aop_t aop_ushrt_cmp(aopmode_t mode, unsigned short actual, unsigned short expected)
{
	return AOP_CMP(mode, actual, expected);
}

aop_t aop_uint_cmp(aopmode_t mode, unsigned actual, unsigned expected)
{
	return AOP_CMP(mode, actual, expected);
}

aop_t aop_ulong_cmp(aopmode_t mode, unsigned long actual, unsigned long expected)
{
	return AOP_CMP(mode, actual, expected);
}

aop_t aop_ullong_cmp(aopmode_t mode, unsigned long long actual, unsigned long long expected)
{
	return AOP_CMP(mode, actual, expected);
}


aop_t aop_flt_cmp(aopmode_t mode, float actual, float expected, float reltol, float abstol)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_dbl_cmp(aopmode_t mode, double actual, double expected, double reltol, double abstol)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_str_cmp(aopmode_t mode, const char *actual, const char *expected)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_mem_cmp(aopmode_t mode, const void *actual, const void *expected, size_t n, size_t size)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}


aop_t aop_list_cmp(aopmode_t mode, const void *actual, const void *expected,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *))
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}


aop_t aop_char_cmpskp(aopmode_t mode, char actual, char expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}

aop_t aop_shrt_cmpskp(aopmode_t mode, short actual, short expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}

aop_t aop_int_cmpskp(aopmode_t mode, int actual, int expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}

aop_t aop_long_cmpskp(aopmode_t mode, long actual, long expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}

aop_t aop_llong_cmpskp(aopmode_t mode, long long actual, long long expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}


aop_t aop_uchar_cmpskp(aopmode_t mode, unsigned char actual, unsigned char expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}

aop_t aop_ushrt_cmpskp(aopmode_t mode, unsigned short actual, unsigned short expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}

aop_t aop_uint_cmpskp(aopmode_t mode, unsigned actual, unsigned expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}

aop_t aop_ulong_cmpskp(aopmode_t mode, unsigned long actual, unsigned long expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}

aop_t aop_ullong_cmpskp(aopmode_t mode, unsigned long long actual, unsigned long long expected)
{
	return AOP_CMPSKP(mode, actual, expected);
}


aop_t aop_flt_cmpskp(aopmode_t mode, float actual, float expected, float reltol, float abstol)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_dbl_cmpskp(aopmode_t mode, double actual, double expected, double reltol, double abstol)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_str_cmpskp(aopmode_t mode, const char *actual, const char *expected)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_mem_cmpskp(aopmode_t mode, const void *actual, const void *expected, size_t n, size_t size)
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}


aop_t aop_list_cmpskp(aopmode_t mode, const void *actual, const void *expected,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *))
{
	aop_t aop = AOP_PASS;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}
