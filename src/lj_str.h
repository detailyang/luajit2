/*
** String handling.
** Copyright (C) 2005-2013 Mike Pall. See Copyright Notice in luajit.h
*/

#ifndef _LJ_STR_H
#define _LJ_STR_H

#include <stdarg.h>

#include "lj_obj.h"

/* String interning. */
LJ_FUNC int32_t LJ_FASTCALL lj_str_cmp(GCstr *a, GCstr *b);
LJ_FUNC void lj_str_resize(lua_State *L, MSize newmask);
LJ_FUNCA GCstr *lj_str_new(lua_State *L, const char *str, size_t len);
LJ_FUNC void LJ_FASTCALL lj_str_free(global_State *g, GCstr *s);

#define lj_str_newz(L, s)	(lj_str_new(L, s, strlen(s)))
#define lj_str_newlit(L, s)	(lj_str_new(L, "" s, sizeof(s)-1))

/* Type conversions. */
LJ_FUNC MSize LJ_FASTCALL lj_str_bufnum(char *s, cTValue *o);
LJ_FUNC const char *lj_str_buftv(char *buf, cTValue *o, MSize *lenp);
LJ_FUNCA GCstr * LJ_FASTCALL lj_str_fromnum(lua_State *L, const lua_Number *np);
LJ_FUNC GCstr * LJ_FASTCALL lj_str_fromint(lua_State *L, int32_t k);
LJ_FUNCA GCstr * LJ_FASTCALL lj_str_fromnumber(lua_State *L, cTValue *o);

#define LJ_STR_INTBUF		(1+10)
#define LJ_STR_NUMBUF		LUAI_MAXNUMBER2STR
#define LJ_STR_NUMBERBUF	LUAI_MAXNUMBER2STR

/* String formatting. */
LJ_FUNC const char *lj_str_pushvf(lua_State *L, const char *fmt, va_list argp);
LJ_FUNC const char *lj_str_pushf(lua_State *L, const char *fmt, ...)
#if defined(__GNUC__)
  __attribute__ ((format (printf, 2, 3)))
#endif
  ;

#endif
