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

aop_t aop_bool_eq(bool expected, bool actual)
{
	return (expected && actual || expected == actual ? AOP_PASS : AOP_FAIL);
}

aop_t aop_char_eq(char expected, char actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_shrt_eq(short expected, short actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_int_eq(int expected, int actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_long_eq(long expected, long actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_llong_eq(long long expected, long long actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_uchar_eq(unsigned char expected, unsigned char actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_ushrt_eq(unsigned short expected, unsigned short actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_uint_eq(unsigned expected, unsigned actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_ulong_eq(unsigned long expected, unsigned long actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_ullong_eq(unsigned long long expected, unsigned long long actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_size_eq(size_t expected, size_t actual)
{
	return AOP_EQ(expected, actual);
}

aop_t aop_flt_eq(float expected, float actual, float reltol, float abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	float tol;
	if (expected == actual)
		return AOP_PASS;
	tol = (fabsf(expected) > fabsf(actual) ? fabsf(expected) : fabsf(actual)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabsf(expected - actual) < tol ? AOP_PASS : AOP_FAIL;
}

aop_t aop_dbl_eq(double expected, double actual, double reltol, double abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	double tol;
	if (expected == actual)
		return AOP_PASS;
	tol = (fabs(expected) > fabs(actual) ? fabs(expected) : fabs(actual)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabs(expected - actual) < tol ? AOP_PASS : AOP_FAIL;
}

aop_t aop_ldbl_eq(long double expected, long double actual, long double reltol, long double abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	long double tol;
	if (expected == actual)
		return AOP_PASS;
	tol = (fabsl(expected) > fabsl(actual) ? fabsl(expected) : fabsl(actual)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabsl(expected - actual) < tol ? AOP_PASS : AOP_FAIL;
}

aop_t aop_str_eq(const char *expected, const char *actual)
{
	if (!expected || !actual)
		return AOP_EQ(expected, actual);
	else if (strcmp(expected, actual))
		return AOP_FAIL;
	return AOP_PASS;
}

aop_t aop_mem_eq(const void *expected, const void *actual, size_t n, size_t size)
{
	size_t i;
	if (!expected || !actual)
		return AOP_EQ(expected, actual);
	for (i = 0; n--; i += size)
		if (memcmp((char *)expected+i, (char *)actual+i, size))
			return AOP_FAIL;
	return AOP_PASS;
}

aop_t aop_list_eq(const void *expected, const void *actual,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *))
{
	while (expected || actual) {
		if (cmp(expected, actual))
			return AOP_FAIL;
		expected = nxt(expected);
		actual = nxt(actual);
	}
	return AOP_PASS;
}


aop_t aop_exprskp(bool actual)
{
	return actual ? AOP_PASS : AOP_SKIP;
}

aop_t aop_bool_eqskp(bool expected, bool actual)
{
	return (expected && actual || expected == actual ? AOP_PASS : AOP_SKIP);
}

aop_t aop_char_eqskp(char expected, char actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_shrt_eqskp(short expected, short actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_int_eqskp(int expected, int actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_long_eqskp(long expected, long actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_llong_eqskp(long long expected, long long actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_uchar_eqskp(unsigned char expected, unsigned char actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_ushrt_eqskp(unsigned short expected, unsigned short actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_uint_eqskp(unsigned expected, unsigned actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_ulong_eqskp(unsigned long expected, unsigned long actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_ullong_eqskp(unsigned long long expected, unsigned long long actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_size_eqskp(size_t expected, size_t actual)
{
	return AOP_EQSKP(expected, actual);
}

aop_t aop_flt_eqskp(float expected, float actual, float reltol, float abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	float tol;
	if (expected == actual)
		return AOP_PASS;
	tol = (fabsf(expected) > fabsf(actual) ? fabsf(expected) : fabsf(actual)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabsf(expected - actual) < tol ? AOP_PASS : AOP_SKIP;
}

aop_t aop_dbl_eqskp(double expected, double actual, double reltol, double abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	double tol;
	if (expected == actual)
		return AOP_PASS;
	tol = (fabs(expected) > fabs(actual) ? fabs(expected) : fabs(actual)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabs(expected - actual) < tol ? AOP_PASS : AOP_SKIP;
}

aop_t aop_ldbl_eqskp(long double expected, long double actual, long double reltol, long double abstol)
{
	/*
	 * Do: implement NaN and Inf support!
	 */
	long double tol;
	if (expected == actual)
		return AOP_PASS;
	tol = (fabsl(expected) > fabsl(actual) ? fabsl(expected) : fabsl(actual)) * reltol;
	if (abstol > tol)
		tol = abstol;
	return fabsl(expected - actual) < tol ? AOP_PASS : AOP_SKIP;
}

aop_t aop_str_eqskp(const char *expected, const char *actual)
{
	if (!expected || !actual)
		return AOP_EQSKP(expected, actual);
	else if (strcmp(expected, actual))
		return AOP_SKIP;
	return AOP_PASS;
}

aop_t aop_mem_eqskp(const void *expected, const void *actual, size_t n, size_t size)
{
	size_t i;
	if (!expected || !actual)
		return AOP_EQ(expected, actual);
	for (i = 0; n--; i += size)
		if (memcmp((char *)expected+i, (char *)actual+i, size))
			return AOP_SKIP;
	return AOP_PASS;
}

aop_t aop_list_eqskp(const void *expected, const void *actual,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *))
{
	while (expected || actual) {
		if (cmp(expected, actual))
			return AOP_SKIP;
		expected = nxt(expected);
		actual = nxt(actual);
	}
	return AOP_PASS;
}


aop_t aop_char_cmp(aopmode_t mode, char expected, char actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_shrt_cmp(aopmode_t mode, short expected, short actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_int_cmp(aopmode_t mode, int expected, int actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_long_cmp(aopmode_t mode, long expected, long actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_llong_cmp(aopmode_t mode, long long expected, long long actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_uchar_cmp(aopmode_t mode, unsigned char expected, unsigned char actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_ushrt_cmp(aopmode_t mode, unsigned short expected, unsigned short actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_uint_cmp(aopmode_t mode, unsigned actual, unsigned expected)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_ulong_cmp(aopmode_t mode, unsigned long expected, unsigned long actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_ullong_cmp(aopmode_t mode, unsigned long long expected, unsigned long long actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_size_cmp(aopmode_t mode, size_t expected, size_t actual)
{
	return AOP_CMP(mode, expected, actual);
}

aop_t aop_flt_cmp(aopmode_t mode, float expected, float actual, float reltol, float abstol)
{
	aop_t aop = AOP_SKIP;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_dbl_cmp(aopmode_t mode, double expected, double actual, double reltol, double abstol)
{
	aop_t aop = AOP_SKIP;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_ldbl_cmp(aopmode_t mode, long double expected, long double actual, long double reltol, long double abstol)
{
	aop_t aop = AOP_SKIP;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_str_cmp(aopmode_t mode, const char *expected, const char *actual)
{
	char e, a;
	if (!expected || !actual)
		return AOP_CMP(mode, expected, actual);
	do {
		e = *expected++, a = *actual++;
		if (AOP_CMP(mode, e, a))
			return AOP_FAIL;
	} while (e && a);
	return AOP_PASS;
}

aop_t aop_mem_cmp(aopmode_t mode, const void *expected, const void *actual, size_t n, size_t size)
{
	size_t i;
	if (!expected || !actual)
		return AOP_CMP(mode, expected, actual);
	for (i = 0; n--; i += size) {
		int e = memcmp((char *)expected+i, (char *)actual+i, size);
		if (AOP_CMP(mode, e, 0))
			return AOP_FAIL;
	}
	return AOP_PASS;
}

aop_t aop_list_cmp(aopmode_t mode, const void *expected, const void *actual,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *))
{
	while (expected || actual) {
		int e = cmp(expected, actual);
		if (AOP_CMP(mode, e, 0))
			return AOP_FAIL;
		expected = nxt(expected);
		actual = nxt(actual);
	}
	return AOP_PASS;
}


aop_t aop_char_cmpskp(aopmode_t mode, char expected, char actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_shrt_cmpskp(aopmode_t mode, short expected, short actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_int_cmpskp(aopmode_t mode, int expected, int actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_long_cmpskp(aopmode_t mode, long expected, long actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_llong_cmpskp(aopmode_t mode, long long expected, long long actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_uchar_cmpskp(aopmode_t mode, unsigned char expected, unsigned char actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_ushrt_cmpskp(aopmode_t mode, unsigned short expected, unsigned short actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_uint_cmpskp(aopmode_t mode, unsigned expected, unsigned actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_ulong_cmpskp(aopmode_t mode, unsigned long expected, unsigned long actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_ullong_cmpskp(aopmode_t mode, unsigned long long expected, unsigned long long actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_size_cmpskp(aopmode_t mode, size_t expected, size_t actual)
{
	return AOP_CMPSKP(mode, expected, actual);
}

aop_t aop_flt_cmpskp(aopmode_t mode, float expected, float actual, float reltol, float abstol)
{
	aop_t aop = AOP_SKIP;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_dbl_cmpskp(aopmode_t mode, double expected, double actual, double reltol, double abstol)
{
	aop_t aop = AOP_SKIP;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_ldbl_cmpskp(aopmode_t mode, long double expected, long double actual, long double reltol, long double abstol)
{
	aop_t aop = AOP_SKIP;
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aop_str_cmpskp(aopmode_t mode, const char *expected, const char *actual)
{
	char e, a;
	if (!expected || !actual)
		return AOP_CMPSKP(mode, (unsigned long long)expected, (unsigned long long)actual);
	do {
		e = *expected++, a = *actual++;
		if (AOP_CMPSKP(mode, e, a))
			return AOP_SKIP;
	} while (e && a);
	return AOP_PASS;
}

aop_t aop_mem_cmpskp(aopmode_t mode, const void *expected, const void *actual, size_t n, size_t size)
{
	size_t i;
	if (!expected || !actual)
		return AOP_CMPSKP(mode, expected, actual);
	for (i = 0; n--; i += size) {
		int e = memcmp((char *)expected+i, (char *)actual+i, size);
		if (AOP_CMPSKP(mode, e, 0))
			return AOP_SKIP;
	}
	return AOP_PASS;
}

aop_t aop_list_cmpskp(aopmode_t mode, const void *expected, const void *actual,
	int (*cmp)(const void *, const void *), void *(*nxt)(const void *))
{
	while (expected || actual) {
		int e = cmp(expected, actual);
		if (AOP_CMP(mode, e, 0))
			return AOP_SKIP;
		expected = nxt(expected);
		actual = nxt(actual);
	}
	return AOP_PASS;
}
