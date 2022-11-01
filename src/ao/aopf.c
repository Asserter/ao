/*
 * Copyright (c) 2022 Asserter, Org. All rights reserved.
 *         Use is subject to license terms.
 *            See LICENSE for details.
 */

#include <ao/aopf.h>

#define _AOP_FMT_IF(_aop) \
	if (aop == (_aop)) { \
		va_list ap; \
		va_start(ap, fmt); \
		vfprintf(stderr, fmt, ap); \
		va_end(ap); \
	} \

aop_t aop_exprf(bool actual, const char *fmt, ...)
{
	aop_t aop = actual ? AOP_PASS : AOP_FAIL;
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_char_eqf(char actual, char expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_shrt_eqf(short actual, short expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_int_eqf(int actual, int expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_long_eqf(long actual, long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_llong_eqf(long long actual, long long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}


aop_t aop_uchar_eqf(unsigned char actual, unsigned char expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_ushrt_eqf(unsigned short actual, unsigned short expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_uint_eqf(unsigned actual, unsigned expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_ulong_eqf(unsigned long actual, unsigned long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_ullong_eqf(unsigned long long actual, unsigned long long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_flt_eqf(float actual, float expected, float reltol, float abstol, const char *fmt, ...)
{
	aop_t aop = aop_flt_eq(actual, expected, reltol, abstol);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_dbl_eqf(double actual, double expected, double reltol, double abstol, const char *fmt, ...)
{
	aop_t aop = aop_dbl_eq(actual, expected, reltol, abstol);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_str_eqf(const char *actual, const char *expected, const char *fmt, ...)
{
	aop_t aop = aop_str_eq(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}


aop_t aop_exprfskp(bool actual, const char *fmt, ...)
{
	aop_t aop = actual ? AOP_PASS : AOP_SKIP;
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_char_eqfskp(char actual, char expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_shrt_eqfskp(short actual, short expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_int_eqfskp(int actual, int expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_long_eqfskp(long actual, long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_llong_eqfskp(long long actual, long long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}


aop_t aop_uchar_eqfskp(unsigned char actual, unsigned char expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_ushrt_eqfskp(unsigned short actual, unsigned short expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_uint_eqfskp(unsigned actual, unsigned expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_ulong_eqfskp(unsigned long actual, unsigned long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_ullong_eqfskp(unsigned long long actual, unsigned long long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}


aop_t aop_flt_eqfskp(float actual, float expected, float reltol, float abstol, const char *fmt, ...)
{
	aop_t aop = aop_flt_eqskp(actual, expected, reltol, abstol);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_dbl_eqfskp(double actual, double expected, double reltol, double abstol, const char *fmt, ...)
{
	aop_t aop = aop_dbl_eqskp(actual, expected, reltol, abstol);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}


aop_t aop_str_eqfskp(const char *actual, const char *expected, const char *fmt, ...)
{
	aop_t aop = aop_str_eqskp(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

#undef _AOP_FMT_IF
