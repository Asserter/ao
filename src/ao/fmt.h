/*
 * Copyright (c) 2022 Asserter, Org. All rights reserved.
 *         Use is subject to license terms.
 *            See LICENSE for details.
 */

#ifndef _AO_FMT_H
#define _AO_FMT_H

#include <stdio.h>
#include <stdarg.h>
#include <ao/aop.h>

#define AOP_FMT_EQ(actual, expected, fmt, ...) \
	((actual) != (expected) ? (fprintf(stderr, (fmt), __VA_ARGS__), AOP_FAIL) : AOP_PASS)

#define AOP_FMT_SKIP_EQ(actual, expected, fmt, ...) \
	((actual) != (expected) ? (fprintf(stderr, (fmt), __VA_ARGS__), AOP_SKIP) : AOP_PASS)

#ifdef __cplusplus
extern "c" {
#endif

aop_t aop_fmt_expr(bool actual, const char *fmt, ...);

aop_t aop_fmt_char_eq(char actual, char expected, const char *fmt, ...);
aop_t aop_fmt_shrt_eq(short actual, short expected, const char *fmt, ...);
aop_t aop_fmt_int_eq(int actual, int expected, const char *fmt, ...);
aop_t aop_fmt_long_eq(long actual, long expected, const char *fmt, ...);
aop_t aop_fmt_llong_eq(long long actual, long long expected, const char *fmt, ...);

aop_t aop_fmt_uchar_eq(unsigned char actual, unsigned char expected, const char *fmt, ...);
aop_t aop_fmt_ushrt_eq(unsigned short actual, unsigned short expected, const char *fmt, ...);
aop_t aop_fmt_uint_eq(unsigned actual, unsigned expected, const char *fmt, ...);
aop_t aop_fmt_ulong_eq(unsigned long actual, unsigned long expected, const char *fmt, ...);
aop_t aop_fmt_ullong_eq(unsigned long long actual, unsigned long long expected, const char *fmt, ...);

aop_t aop_fmt_flt_eq(float actual, float expected, float reltol, float abstol, const char *fmt, ...);
aop_t aop_fmt_dbl_eq(double actual, double expected, double reltol, double abstol, const char *fmt, ...);

aop_t aop_fmt_str_eq(const char *actual, const char *expected, const char *fmt, ...);


aop_t aop_fmt_expr_skip(bool actual, const char *fmt, ...);

aop_t aop_fmt_char_skip_eq(char actual, char expected, const char *fmt, ...);
aop_t aop_fmt_shrt_skip_eq(short actual, short expected, const char *fmt, ...);
aop_t aop_fmt_int_skip_eq(int actual, int expected, const char *fmt, ...);
aop_t aop_fmt_long_skip_eq(long actual, long expected, const char *fmt, ...);
aop_t aop_fmt_llong_skip_eq(long long actual, long long expected, const char *fmt, ...);

aop_t aop_fmt_uchar_skip_eq(unsigned char actual, unsigned char expected, const char *fmt, ...);
aop_t aop_fmt_ushrt_skip_eq(unsigned short actual, unsigned short expected, const char *fmt, ...);
aop_t aop_fmt_uint_skip_eq(unsigned actual, unsigned expected, const char *fmt, ...);
aop_t aop_fmt_ulong_skip_eq(unsigned long actual, unsigned long expected, const char *fmt, ...);
aop_t aop_fmt_ullong_skip_eq(unsigned long long actual, unsigned long long expected, const char *fmt, ...);

aop_t aop_fmt_flt_skip_eq(float actual, float expected, float reltol, float abstol, const char *fmt, ...);
aop_t aop_fmt_dbl_skip_eq(double actual, double expected, double reltol, double abstol, const char *fmt, ...);

aop_t aop_fmt_str_skip_eq(const char *actual, const char *expected, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif	/* _AO_FMT_H */
