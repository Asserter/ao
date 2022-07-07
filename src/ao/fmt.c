/*
 * Copyright (c) 2022 Asserter, Org. All rights reserved.
 *         Use is subject to license terms.
 *            See LICENSE for details.
 */

#include <ao/fmt.h>

#define _AOP_FMT_IF(_aop) \
	if (aop == (_aop)) { \
		va_list ap; \
		va_start(ap, fmt); \
		vfprintf(stderr, fmt, ap); \
		va_end(ap); \
	} \

aop_t aop_fmt_expr(bool actual, const char *fmt, ...)
{
	aop_t aop = actual ? AOP_PASS : AOP_FAIL;
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_char_eq(char actual, char expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_shrt_eq(short actual, short expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_int_eq(int actual, int expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_long_eq(long actual, long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_llong_eq(long long actual, long long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}


aop_t aop_fmt_uchar_eq(unsigned char actual, unsigned char expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_ushrt_eq(unsigned short actual, unsigned short expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_uint_eq(unsigned actual, unsigned expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_ulong_eq(unsigned long actual, unsigned long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_ullong_eq(unsigned long long actual, unsigned long long expected, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_flt_eq(float actual, float expected, float reltol, float abstol, const char *fmt, ...)
{
	aop_t aop = aop_flt_eq(actual, expected, reltol, abstol);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_dbl_eq(double actual, double expected, double reltol, double abstol, const char *fmt, ...)
{
	aop_t aop = aop_dbl_eq(actual, expected, reltol, abstol);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}

aop_t aop_fmt_str_eq(const char *actual, const char *expected, const char *fmt, ...)
{
	aop_t aop = aop_str_eq(actual, expected);
	_AOP_FMT_IF(AOP_FAIL);
	return aop;
}


aop_t aop_fmt_expr_skip(bool actual, const char *fmt, ...)
{
	aop_t aop = actual ? AOP_PASS : AOP_SKIP;
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_char_skip_eq(char actual, char expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_shrt_skip_eq(short actual, short expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_int_skip_eq(int actual, int expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_long_skip_eq(long actual, long expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_llong_skip_eq(long long actual, long long expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}


aop_t aop_fmt_uchar_skip_eq(unsigned char actual, unsigned char expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_ushrt_skip_eq(unsigned short actual, unsigned short expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_uint_skip_eq(unsigned actual, unsigned expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_ulong_skip_eq(unsigned long actual, unsigned long expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_ullong_skip_eq(unsigned long long actual, unsigned long long expected, const char *fmt, ...)
{
	aop_t aop = AOP_SKIP_EQ(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}


aop_t aop_fmt_flt_skip_eq(float actual, float expected, float reltol, float abstol, const char *fmt, ...)
{
	aop_t aop = aop_flt_skip_eq(actual, expected, reltol, abstol);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

aop_t aop_fmt_dbl_skip_eq(double actual, double expected, double reltol, double abstol, const char *fmt, ...)
{
	aop_t aop = aop_dbl_skip_eq(actual, expected, reltol, abstol);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}


aop_t aop_fmt_str_skip_eq(const char *actual, const char *expected, const char *fmt, ...)
{
	aop_t aop = aop_str_skip_eq(actual, expected);
	_AOP_FMT_IF(AOP_SKIP);
	return aop;
}

#undef _AOP_FMT_IF
