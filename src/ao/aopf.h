/*
 * Copyright (c) 2022 Asserter, Org. All rights reserved.
 *         Use is subject to license terms.
 *            See LICENSE for details.
 */

#ifndef _AO_AOPF_H
#define _AO_AOPF_H

#include <ao/aop.h>
#include <ao/fstd.h>

#define AOPF_SHRT_SP        "%hd"
#define AOPF_INT_SP         "%d"
#define AOPF_LONG_SP        "%ld"
#define AOPF_LLONG_SP       "%lld"

#define AOPF_USHRT_SP       "%hu"
#define AOPF_UINT_SP        "%u"
#define AOPF_ULONG_SP       "%lu"
#define AOPF_ULLONG_SP      "%llu"

#define AOPF_SIZE_SP        "zu"

#define AOPF_FLT_SP         "%g"
#define AOPF_DBL_SP         "%g"
#define AOPF_LDBL_SP        "%Lg"

#define AOPF_STR_SP         "\"%s\""

#ifdef __cplusplus
extern "c" {
#endif

aop_t aopf_expr(bool actual, const char *fmt, ...);
aop_t aopf_bool_eq(bool expected, bool actual, const char *fmt, ...);

aop_t aopf_char_eq(char expected, char actual, const char *fmt, ...);
aop_t aopf_shrt_eq(short expected, short actual, const char *fmt, ...);
aop_t aopf_int_eq(int expected, int actual, const char *fmt, ...);
aop_t aopf_long_eq(long expected, long actual, const char *fmt, ...);
aop_t aopf_llong_eq(long long expected, long long actual, const char *fmt, ...);

aop_t aopf_uchar_eq(unsigned char expected, unsigned char actual, const char *fmt, ...);
aop_t aopf_ushrt_eq(unsigned short expected, unsigned short actual, const char *fmt, ...);
aop_t aopf_uint_eq(unsigned expected, unsigned actual, const char *fmt, ...);
aop_t aopf_ulong_eq(unsigned long expected, unsigned long actual, const char *fmt, ...);
aop_t aopf_ullong_eq(unsigned long long expected, unsigned long long actual, const char *fmt, ...);

aop_t aopf_size_eq(size_t expected, size_t actual, const char *fmt, ...);

aop_t aopf_flt_eq(float expected, float actual, float reltol, float abstol, const char *fmt, ...);
aop_t aopf_dbl_eq(double expected, double actual, double reltol, double abstol, const char *fmt, ...);
aop_t aopf_ldbl_eq(long double expected, long double actual, long double reltol, long double abstol, const char *fmt, ...);

aop_t aopf_str_eq(const char *expected, const char *actual, const char *fmt, ...);
aop_t aopf_mem_eq(const void *expected, const void *actual, size_t n, size_t size, const char *fmt, ...);


aop_t aopf_exprskp(bool actual, const char *fmt, ...);
aop_t aopf_bool_eqskp(bool expected, bool actual, const char *fmt, ...);

aop_t aopf_char_eqskp(char expected, char actual, const char *fmt, ...);
aop_t aopf_shrt_eqskp(short expected, short actual, const char *fmt, ...);
aop_t aopf_int_eqskp(int expected, int actual, const char *fmt, ...);
aop_t aopf_long_eqskp(long expected, long actual, const char *fmt, ...);
aop_t aopf_llong_eqskp(long long expected, long long actual, const char *fmt, ...);

aop_t aopf_uchar_eqskp(unsigned char expected, unsigned char actual, const char *fmt, ...);
aop_t aopf_ushrt_eqskp(unsigned short expected, unsigned short actual, const char *fmt, ...);
aop_t aopf_uint_eqskp(unsigned expected, unsigned actual, const char *fmt, ...);
aop_t aopf_ulong_eqskp(unsigned long expected, unsigned long actual, const char *fmt, ...);
aop_t aopf_ullong_eqskp(unsigned long long expected, unsigned long long actual, const char *fmt, ...);

aop_t aopf_size_eqskp(size_t expected, size_t actual, const char *fmt, ...);

aop_t aopf_flt_eqskp(float expected, float actual, float reltol, float abstol, const char *fmt, ...);
aop_t aopf_dbl_eqskp(double expected, double actual, double reltol, double abstol, const char *fmt, ...);
aop_t aopf_ldbl_eqskp(long double expected, long double actual, long double reltol, long double abstol, const char *fmt, ...);

aop_t aopf_str_eqskp(const char *expected, const char *actual, const char *fmt, ...);
aop_t aopf_mem_eqskp(const void *expected, const void *actual, size_t n, size_t size, const char *fmt, ...);


aop_t aopf_char_cmp(aopmode_t mode, char expected, char actual, const char *fmt, ...);
aop_t aopf_shrt_cmp(aopmode_t mode, short expected, short actual, const char *fmt, ...);
aop_t aopf_int_cmp(aopmode_t mode, int expected, int actual, const char *fmt, ...);
aop_t aopf_long_cmp(aopmode_t mode, long expected, long actual, const char *fmt, ...);
aop_t aopf_llong_cmp(aopmode_t mode, long long expected, long long actual, const char *fmt, ...);

aop_t aopf_uchar_cmp(aopmode_t mode, unsigned char expected, unsigned char actual, const char *fmt, ...);
aop_t aopf_ushrt_cmp(aopmode_t mode, unsigned short expected, unsigned short actual, const char *fmt, ...);
aop_t aopf_uint_cmp(aopmode_t mode, unsigned expected, unsigned actual, const char *fmt, ...);
aop_t aopf_ulong_cmp(aopmode_t mode, unsigned long expected, unsigned long actual, const char *fmt, ...);
aop_t aopf_ullong_cmp(aopmode_t mode, unsigned long long expected, unsigned long long actual, const char *fmt, ...);

aop_t aopf_size_cmp(aopmode_t mode, size_t expected, size_t actual, const char *fmt, ...);

aop_t aopf_flt_cmp(aopmode_t mode, float expected, float actual, float reltol, float abstol, const char *fmt, ...);
aop_t aopf_dbl_cmp(aopmode_t mode, double expected, double actual, double reltol, double abstol, const char *fmt, ...);
aop_t aopf_ldbl_cmp(aopmode_t mode, long double expected, long double actual, long double reltol, long double abstol, const char *fmt, ...);

aop_t aopf_str_cmp(aopmode_t mode, const char *expected, const char *actual, const char *fmt, ...);
aop_t aopf_mem_cmp(aopmode_t mode, const void *expected, const void *actual, size_t n, size_t size, const char *fmt, ...);


aop_t aopf_char_cmpskp(aopmode_t mode, char expected, char actual, const char *fmt, ...);
aop_t aopf_shrt_cmpskp(aopmode_t mode, short expected, short actual, const char *fmt, ...);
aop_t aopf_int_cmpskp(aopmode_t mode, int expected, int actual, const char *fmt, ...);
aop_t aopf_long_cmpskp(aopmode_t mode, long expected, long actual, const char *fmt, ...);
aop_t aopf_llong_cmpskp(aopmode_t mode, long long expected, long long actual, const char *fmt, ...);

aop_t aopf_uchar_cmpskp(aopmode_t mode, unsigned char expected, unsigned char actual, const char *fmt, ...);
aop_t aopf_ushrt_cmpskp(aopmode_t mode, unsigned short expected, unsigned short actual, const char *fmt, ...);
aop_t aopf_uint_cmpskp(aopmode_t mode, unsigned expected, unsigned actual, const char *fmt, ...);
aop_t aopf_ulong_cmpskp(aopmode_t mode, unsigned long expected, unsigned long actual, const char *fmt, ...);
aop_t aopf_ullong_cmpskp(aopmode_t mode, unsigned long long expected, unsigned long long actual, const char *fmt, ...);

aop_t aopf_size_cmpskp(aopmode_t mode, size_t expected, size_t actual, const char *fmt, ...);

aop_t aopf_flt_cmpskp(aopmode_t mode, float expected, float actual, float reltol, float abstol, const char *fmt, ...);
aop_t aopf_dbl_cmpskp(aopmode_t mode, double expected, double actual, double reltol, double abstol, const char *fmt, ...);
aop_t aopf_ldbl_cmpskp(aopmode_t mode, long double expected, long double actual, long double reltol, long double abstol, const char *fmt, ...);

aop_t aopf_str_cmpskp(aopmode_t mode, const char *expected, const char *actual, const char *fmt, ...);
aop_t aopf_mem_cmpskp(aopmode_t mode, const void *expected, const void *actual, size_t n, size_t size, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif	/* _AO_AOPF_H */
