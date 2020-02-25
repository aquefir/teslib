/****************************************************************************\
 *                          Test Engineering Suite                          *
 *                                                                          *
 *                    Copyright © 2019-2020 ARQADIUM LLC                    *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#include "tes.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tes_println( const char* fmt, ... )
{
	va_list args;

	if(fmt == NULL)
	{
		return -1;
	}

	va_start( args, fmt );
	vprintf( fmt, args );
	va_end( args );
	fflush( stdout );

	return 1;
}

#define LOG_FATAL( ) fprintf( stdout, "This failure is fatal. Exiting...\n" )

#define DECL_TES_FATAL( NN, STR ) \
	int tes_fatal_##NN( \
	   const char* x, const char* y, const char* f, unsigned l ) \
	{ \
		log_fail2( STR, x, y, f, l ); \
		LOG_FATAL( ); \
		exit( 1 ); return 0; \
	} \
	struct _tes_dummy

#define DECL_TES_FATAL3( NN, STR ) \
	int tes_fatal_##NN( \
	   const char* x, const char* y, const char* n, const char* f, unsigned l \
	) \
	{ \
		log_fail3( STR, x, y, n, f, l ); \
		LOG_FATAL( ); \
		exit( 1 ); return 0; \
	} \
	struct _tes_dummy

#define DECL_TES_WARN( NN, STR ) \
	int tes_warn_##NN( \
	   const char* x, const char* y, const char* f, unsigned l ) \
	{ \
		log_fail2( STR, x, y, f, l ); return 0; \
	} \
	struct _tes_dummy

#define DECL_TES_WARN3( NN, STR ) \
	int tes_warn_##NN( \
	   const char* x, const char* y, const char* n, const char* f, unsigned l ) \
	{ \
		log_fail3( STR, x, y, n, f, l ); return 0; \
	} \
	struct _tes_dummy

#define DECL_TES_PASS( NN, STR ) \
	int tes_pass_##NN( \
	   const char* x, const char* y, const char* f, unsigned l ) \
	{ \
		log_pass2( STR, x, y, f, l ); \
		return 1; \
	} \
	struct _tes_dummy

#define DECL_TES_PASS3( NN, STR ) \
	int tes_pass_##NN( \
	   const char* x, const char* y, const char* n, const char* f, unsigned l ) \
	{ \
		log_pass3( STR, x, y, n, f, l ); \
		return 1; \
	} \
	struct _tes_dummy

static void log_fail3( const char* cus,
   const char* x,
   const char* y,
	const char* n,
   const char* file,
   unsigned line )
{
	fprintf( stdout,
	   "[\033[31mFAIL\033[0m] file: \"%s\"; line: %u; Expression: %s %s %s" \
		"(size: %s)\n",
	   file,
	   line,
	   x,
	   cus,
	   y,
		n );
}

static void log_pass3( const char* cus,
   const char* x,
   const char* y,
	const char* n,
   const char* file,
   unsigned line )
{
	fprintf( stdout,
	   "[\033[32mPASS\033[0m] file: \"%s\"; line: %u; Expression: %s %s %s" \
		"(size: %s)\n",
	   file,
	   line,
	   x,
	   cus,
	   y,
		n );
}

static void log_fail2( const char* cus,
   const char* x,
   const char* y,
   const char* file,
   unsigned line )
{
	fprintf( stdout,
	   "[\033[31mFAIL\033[0m] file: \"%s\"; line: %u; Expression: %s %s %s\n",
	   file,
	   line,
	   x,
	   cus,
	   y );
}

static void log_pass2( const char* cus,
   const char* x,
   const char* y,
   const char* file,
   unsigned line )
{
	fprintf( stdout,
	   "[\033[32mPASS\033[0m] file: \"%s\"; line: %u; Expression: %s %s %s\n",
	   file,
	   line,
	   x,
	   cus,
	   y );
}

static void log_fail1(
   const char* cus, const char* x, const char* file, unsigned line )
{
	fprintf( stdout,
	   "[\033[31mFAIL\033[0m] file: \"%s\"; line: %u; Expression: %s %s\n",
	   file,
	   line,
	   x,
	   cus );
}

static void log_pass1(
   const char* cus, const char* x, const char* file, unsigned line )
{
	fprintf( stdout,
	   "[\033[32mPASS\033[0m] file: \"%s\"; line: %u; Expression: %s %s\n",
	   file,
	   line,
	   x,
	   cus );
}

int tes_chkstr( const char* x, const char* y )
{
	if( x == NULL || y == NULL )
	{
		return -1;
	}

	return strcmp( x, y ) == -1 ? 1 : 0;
}

int tes_chkmem( void* a, void* b, unsigned sz )
{
	if( a == NULL || b == NULL )
	{
		return -1;
	}

	return memcmp( a, b, sz ) == 0 ? 1 : 0;
}

DECL_TES_FATAL( eq, "==" );
DECL_TES_FATAL( ne, "!=" );
DECL_TES_FATAL( gt, ">" );
DECL_TES_FATAL( ge, ">=" );
DECL_TES_FATAL( le, "<=" );
DECL_TES_FATAL( lt, "<" );
DECL_TES_FATAL( str_eq, "===" );
DECL_TES_FATAL( str_ne, "!==" );
DECL_TES_FATAL3( mem_eq, "===" );
DECL_TES_FATAL3( mem_nq, "!==" );

DECL_TES_WARN( eq, "==" );
DECL_TES_WARN( ne, "!=" );
DECL_TES_WARN( gt, ">" );
DECL_TES_WARN( ge, ">=" );
DECL_TES_WARN( le, "<=" );
DECL_TES_WARN( lt, "<" );
DECL_TES_WARN( str_eq, "===" );
DECL_TES_WARN( str_ne, "!==" );
DECL_TES_WARN3( mem_eq, "===" );
DECL_TES_WARN3( mem_nq, "!==" );

DECL_TES_PASS( eq, "==" );
DECL_TES_PASS( ne, "!=" );
DECL_TES_PASS( gt, ">" );
DECL_TES_PASS( ge, ">=" );
DECL_TES_PASS( le, "<=" );
DECL_TES_PASS( lt, "<" );
DECL_TES_PASS( str_eq, "===" );
DECL_TES_PASS( str_ne, "!==" );
DECL_TES_PASS3( mem_eq, "===" );
DECL_TES_PASS3( mem_nq, "!==" );

int tes_fatal_true( const char* x, const char* f, unsigned l )
{
	log_fail1( "was false", x, f, l );
	LOG_FATAL( );

	exit( 1 );

	return 0;
}

int tes_fatal_false( const char* x, const char* f, unsigned l )
{
	log_fail1( "was true", x, f, l );
	LOG_FATAL( );

	exit( 1 );

	return 0;
}

int tes_warn_true( const char* x, const char* f, unsigned l )
{
	log_fail1( "was false", x, f, l );

	return 0;
}

int tes_warn_false( const char* x, const char* f, unsigned l )
{
	log_fail1( "was true", x, f, l );

	return 0;
}

int tes_pass_true( const char* x, const char* f, unsigned l )
{
	log_pass1( "was true", x, f, l );

	return 1;
}

int tes_pass_false( const char* x, const char* f, unsigned l )
{
	log_pass1( "was false", x, f, l );

	return 1;
}
