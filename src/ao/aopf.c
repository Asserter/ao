/*
 * Copyright (c) 2022 Asserter, Org. All rights reserved.
 *         Use is subject to license terms.
 *            See LICENSE for details.
 */

#include <ao/aopf.h>

#define BOOL_FMT(b) \
	((b) ? "true" : "false")

#define _AOPF_BOOL_IF(_aop) \
	if (aop == (_aop)) { \
		fstderr("Expected: %s\n*Actual*: %s\n", BOOL_FMT(expected), BOOL_FMT(actual)); \
		if (fmt && *fmt) { \
			va_list ap; \
			va_start(ap, fmt); \
			vfstderr(fmt, ap); \
			fstderr("\n"); \
			va_end(ap); \
		} \
	} \

#define _AOPF_STR_IF(_aop, sp) \
	if (aop == (_aop)) { \
		fstderr("Expected: "); \
		if (expected) \
			fstderr(sp"\n", expected); \
		else \
			fstderr("NULL\n"); \
		fstderr("*Actual*: "); \
		if (actual) \
			fstderr(sp"\n", actual); \
		else \
			fstderr("NULL\n"); \
		if (fmt && *fmt) { \
			va_list ap; \
			va_start(ap, fmt); \
			vfstderr(fmt, ap); \
			fstderr("\n"); \
			va_end(ap); \
		} \
	} \

#define _AOPF_IF(_aop, sp) \
	if (aop == (_aop)) { \
	    fstderr("Expected: "sp"\n*Actual*: "sp"\n", (expected), (actual)); \
		if (fmt && *fmt) { \
			va_list ap; \
			va_start(ap, fmt); \
			vfstderr(fmt, ap); \
			fstderr("\n"); \
			va_end(ap); \
		} \
	} \

aop_t aopf_expr(bool actual, const char *fmt, ...)
{
	if (!actual) {
		fstderr("Expected: true\n*Actual*: %s\n", BOOL_FMT(actual));
		if (fmt && *fmt) {
			va_list ap;
			va_start(ap, fmt);
			vfstderr(fmt, ap);
			fstderr("\n");
			va_end(ap);
		}
		return AOP_FAIL;
	}
	return AOP_PASS;
}

aop_t aopf_bool_eq(bool expected, bool actual, const char *fmt, ...)
{
	aop_t aop = expected && actual || expected == actual ? AOP_PASS : AOP_FAIL;
	_AOPF_BOOL_IF(AOP_FAIL);
	return aop;
}

aop_t aopf_char_eq(char expected, char actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aopf_shrt_eq(short expected, short actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_SHRT_SP);
	return aop;
}

aop_t aopf_int_eq(int expected, int actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_INT_SP);
	return aop;
}

aop_t aopf_long_eq(long expected, long actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_LONG_SP);
	return aop;
}

aop_t aopf_llong_eq(long long expected, long long actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_LLONG_SP);
	return aop;
}

aop_t aopf_uchar_eq(unsigned char expected, unsigned char actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aopf_ushrt_eq(unsigned short expected, unsigned short actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_USHRT_SP);
	return aop;
}

aop_t aopf_uint_eq(unsigned expected, unsigned actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_UINT_SP);
	return aop;
}

aop_t aopf_ulong_eq(unsigned long expected, unsigned long actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_ULONG_SP);
	return aop;
}

aop_t aopf_ullong_eq(unsigned long long expected, unsigned long long actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_ULLONG_SP);
	return aop;
}

aop_t aopf_size_eq(size_t expected, size_t actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_SIZE_SP);
	return aop;
}

aop_t aopf_flt_eq(float expected, float actual, float reltol, float abstol, const char *fmt, ...)
{
	aop_t aop = aop_flt_eq(expected, actual, reltol, abstol);
	_AOPF_IF(AOP_FAIL, AOPF_FLT_SP);
	return aop;
}

aop_t aopf_dbl_eq(double expected, double actual, double reltol, double abstol, const char *fmt, ...)
{
	aop_t aop = aop_dbl_eq(expected, actual, reltol, abstol);
	_AOPF_IF(AOP_FAIL, AOPF_DBL_SP);
	return aop;
}

aop_t aopf_ldbl_eq(long double expected, long double actual, long double reltol, long double abstol, const char *fmt, ...)
{
	aop_t aop = aop_ldbl_eq(expected, actual, reltol, abstol);
	_AOPF_IF(AOP_FAIL, AOPF_LDBL_SP);
	return aop;
}

aop_t aopf_str_eq(const char *expected, const char *actual, const char *fmt, ...)
{
	aop_t aop = aop_str_eq(expected, actual);
	_AOPF_STR_IF(AOP_FAIL, AOPF_STR_SP);
	return aop;
}

aop_t aopf_mem_eq(const void *expected, const void *actual, size_t n, size_t size, const char *fmt, ...)
{
	aop_t aop = aop_mem_eq(expected, actual, n, size);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aopf_exprskp(bool actual, const char *fmt, ...)
{
	if (!actual) {
		fstderr("Expected: true\n*Actual*: %s\n", BOOL_FMT(actual));
		if (fmt && *fmt) {
			va_list ap;
			va_start(ap, fmt);
			vfstderr(fmt, ap);
			fstderr("\n");
			va_end(ap);
		}
		return AOP_SKIP;
	}
	return AOP_PASS;
}

aop_t aopf_bool_eqskp(bool expected, bool actual, const char *fmt, ...)
{
	aop_t aop = AOP_BOOL_EQSKP(expected, actual);
	_AOPF_BOOL_IF(aop);
	return aop;
}

aop_t aopf_char_eqskp(char expected, char actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aopf_shrt_eqskp(short expected, short actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_SHRT_SP);
	return aop;
}

aop_t aopf_int_eqskp(int expected, int actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_INT_SP);
	return aop;
}

aop_t aopf_long_eqskp(long expected, long actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_LONG_SP);
	return aop;
}

aop_t aopf_llong_eqskp(long long expected, long long actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_LLONG_SP);
	return aop;
}

aop_t aopf_uchar_eqskp(unsigned char expected, unsigned char actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aopf_ushrt_eqskp(unsigned short expected, unsigned short actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_USHRT_SP);
	return aop;
}

aop_t aopf_uint_eqskp(unsigned expected, unsigned actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_UINT_SP);
	return aop;
}

aop_t aopf_ulong_eqskp(unsigned long expected, unsigned long actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_ULONG_SP);
	return aop;
}

aop_t aopf_ullong_eqskp(unsigned long long expected, unsigned long long actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQSKP(expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_ULLONG_SP);
	return aop;
}

aop_t aopf_size_eqskp(size_t expected, size_t actual, const char *fmt, ...)
{
	aop_t aop = AOP_EQ(expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_SIZE_SP);
	return aop;
}

aop_t aopf_flt_eqskp(float expected, float actual, float reltol, float abstol, const char *fmt, ...)
{
	aop_t aop = aop_flt_eqskp(expected, actual, reltol, abstol);
	_AOPF_IF(AOP_SKIP, AOPF_FLT_SP);
	return aop;
}

aop_t aopf_dbl_eqskp(double expected, double actual, double reltol, double abstol, const char *fmt, ...)
{
	aop_t aop = aop_dbl_eqskp(expected, actual, reltol, abstol);
	_AOPF_IF(AOP_SKIP, AOPF_DBL_SP);
	return aop;
}

aop_t aopf_ldbl_eqskp(long double expected, long double actual, long double reltol, long double abstol, const char *fmt, ...)
{
	aop_t aop = aop_ldbl_eqskp(expected, actual, reltol, abstol);
	_AOPF_IF(AOP_SKIP, AOPF_LDBL_SP);
	return aop;
}

aop_t aopf_str_eqskp(const char *expected, const char *actual, const char *fmt, ...)
{
	aop_t aop = aop_str_eqskp(expected, actual);
	_AOPF_STR_IF(AOP_SKIP, AOPF_STR_SP);
	return aop;
}

aop_t aopf_mem_eqskp(const void *expected, const void *actual, size_t n, size_t size, const char *fmt, ...)
{
	aop_t aop = aop_mem_eqskp(expected, actual, n, size);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}


aop_t aopf_char_cmp(aopmode_t mode, char expected, char actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aopf_shrt_cmp(aopmode_t mode, short expected, short actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_SHRT_SP);
	return aop;
}

aop_t aopf_int_cmp(aopmode_t mode, int expected, int actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_INT_SP);
	return aop;
}

aop_t aopf_long_cmp(aopmode_t mode, long expected, long actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_LONG_SP);
	return aop;
}
aop_t aopf_llong_cmp(aopmode_t mode, long long expected, long long actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_LLONG_SP);
	return aop;
}

aop_t aopf_uchar_cmp(aopmode_t mode, unsigned char expected, unsigned char actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aopf_ushrt_cmp(aopmode_t mode, unsigned short expected, unsigned short actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_USHRT_SP);
	return aop;
}

aop_t aopf_uint_cmp(aopmode_t mode, unsigned expected, unsigned actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_UINT_SP);
	return aop;
}

aop_t aopf_ulong_cmp(aopmode_t mode, unsigned long expected, unsigned long actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_ULONG_SP);
	return aop;
}

aop_t aopf_ullong_cmp(aopmode_t mode, unsigned long long expected, unsigned long long actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_ULLONG_SP);
	return aop;
}

aop_t aopf_size_cmp(aopmode_t mode, size_t expected, size_t actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMP(mode, expected, actual);
	_AOPF_IF(AOP_FAIL, AOPF_SIZE_SP);
	return aop;
}

aop_t aopf_flt_cmp(aopmode_t mode, float expected, float actual, float reltol, float abstol, const char *fmt, ...)
{
	aop_t aop = aop_flt_cmp(mode, expected, actual, reltol, abstol);
	_AOPF_IF(AOP_FAIL, AOPF_FLT_SP);
	return aop;
}

aop_t aopf_dbl_cmp(aopmode_t mode, double expected, double actual, double reltol, double abstol, const char *fmt, ...)
{
	aop_t aop = aop_dbl_cmp(mode, expected, actual, reltol, abstol);
	_AOPF_IF(AOP_FAIL, AOPF_DBL_SP);
	return aop;
}

aop_t aopf_ldbl_cmp(aopmode_t mode, long double expected, long double actual, long double reltol, long double abstol, const char *fmt, ...)
{
	aop_t aop = aop_ldbl_cmp(mode, expected, actual, reltol, abstol);
	_AOPF_IF(AOP_FAIL, AOPF_LDBL_SP);
	return aop;
}

aop_t aopf_str_cmp(aopmode_t mode, const char *expected, const char *actual, const char *fmt, ...)
{
	aop_t aop = aop_str_cmp(mode, expected, actual);
	_AOPF_STR_IF(AOP_FAIL, AOPF_STR_SP);
	return aop;
}

aop_t aopf_mem_cmp(aopmode_t mode, const void *expected, const void *actual, size_t n, size_t size, const char *fmt, ...)
{
	aop_t aop = aop_mem_cmp(mode, expected, actual, n, size);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}


aop_t aopf_char_cmpskp(aopmode_t mode, char expected, char actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aopf_shrt_cmpskp(aopmode_t mode, short expected, short actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_SHRT_SP);
	return aop;
}

aop_t aopf_int_cmpskp(aopmode_t mode, int expected, int actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_INT_SP);
	return aop;
}

aop_t aopf_long_cmpskp(aopmode_t mode, long expected, long actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_LONG_SP);
	return aop;
}
aop_t aopf_llong_cmpskp(aopmode_t mode, long long expected, long long actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_LLONG_SP);
	return aop;
}

aop_t aopf_uchar_cmpskp(aopmode_t mode, unsigned char expected, unsigned char actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

aop_t aopf_ushrt_cmpskp(aopmode_t mode, unsigned short expected, unsigned short actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_USHRT_SP);
	return aop;
}

aop_t aopf_uint_cmpskp(aopmode_t mode, unsigned expected, unsigned actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_UINT_SP);
	return aop;
}

aop_t aopf_ulong_cmpskp(aopmode_t mode, unsigned long expected, unsigned long actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_ULONG_SP);
	return aop;
}

aop_t aopf_ullong_cmpskp(aopmode_t mode, unsigned long long expected, unsigned long long actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_ULLONG_SP);
	return aop;
}

aop_t aopf_size_cmpskp(aopmode_t mode, size_t expected, size_t actual, const char *fmt, ...)
{
	aop_t aop = AOP_CMPSKP(mode, expected, actual);
	_AOPF_IF(AOP_SKIP, AOPF_SIZE_SP);
	return aop;
}

aop_t aopf_flt_cmpskp(aopmode_t mode, float expected, float actual, float reltol, float abstol, const char *fmt, ...)
{
	aop_t aop = aop_flt_cmpskp(mode, expected, actual, reltol, abstol);
	_AOPF_IF(AOP_SKIP, AOPF_FLT_SP);
	return aop;
}

aop_t aopf_dbl_cmpskp(aopmode_t mode, double expected, double actual, double reltol, double abstol, const char *fmt, ...)
{
	aop_t aop = aop_dbl_cmpskp(mode, expected, actual, reltol, abstol);
	_AOPF_IF(AOP_SKIP, AOPF_DBL_SP);
	return aop;
}

aop_t aopf_ldbl_cmpskp(aopmode_t mode, long double expected, long double actual, long double reltol, long double abstol, const char *fmt, ...)
{
	aop_t aop = aop_ldbl_cmpskp(mode, expected, actual, reltol, abstol);
	_AOPF_IF(AOP_SKIP, AOPF_LDBL_SP);
	return aop;
}

aop_t aopf_str_cmpskp(aopmode_t mode, const char *expected, const char *actual, const char *fmt, ...)
{
	aop_t aop = aop_str_cmpskp(mode, expected, actual);
	_AOPF_STR_IF(AOP_SKIP, AOPF_STR_SP);
	return aop;
}

aop_t aopf_mem_cmpskp(aopmode_t mode, const void *expected, const void *actual, size_t n, size_t size, const char *fmt, ...)
{
	aop_t aop = aop_mem_cmpskp(mode, expected, actual, n, size);
#ifndef DEBUG
#error "Unsupplied Implementation"
#endif
	return aop;
}

#undef _AOPF_IF
#undef _AOPF_STR_IF
#undef _AOPF_BOOL_IF
