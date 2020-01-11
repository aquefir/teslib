/****************************************************************************\
 *                          Test Engineering Suite                          *
 *                                                                          *
 *                      Copyright © 2019 ARQADIUM, LLC                      *
 *                           All rights reserved.                           *
\****************************************************************************/

#include "tes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void tes_post( void );
extern void tes_fin( void );

#define LOG_FATAL( ) fprintf( stdout, "This failure is fatal. Exiting...\n" )

#define DECL_TES_FATAL( NN, STR ) \
	int tes_fatal_##NN( \
	   const char* x, const char* y, const char* f, unsigned l ) \
	{ \
		log_fail2( STR, x, y, f, l ); \
		LOG_FATAL( ); \
		atexit( tes_fin ); \
		atexit( tes_post ); \
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

#define DECL_TES_PASS( NN, STR ) \
	int tes_pass_##NN( \
	   const char* x, const char* y, const char* f, unsigned l ) \
	{ \
		log_pass2( STR, x, y, f, l ); \
		return 1; \
	} \
	struct _tes_dummy

static void log_fail2( const char* cus,
   const char* x,
   const char* y,
   const char* file,
   unsigned line )
{
	fprintf( stdout,
	   "[FAILED] file: \"%s\"; line: %u; Expression: %s %s %s\n",
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
	   "[PASSED] file: \"%s\"; line: %u; Expression: %s %s %s\n",
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
	   "[FAILED] file: \"%s\"; line: %u; Expression: %s %s\n",
	   file,
	   line,
	   x,
	   cus );
}

static void log_pass1(
   const char* cus, const char* x, const char* file, unsigned line )
{
	fprintf( stdout,
	   "[PASSED] file: \"%s\"; line: %u; Expression: %s %s\n",
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

DECL_TES_FATAL( eq, "==" );
DECL_TES_FATAL( ne, "!=" );
DECL_TES_FATAL( gt, ">" );
DECL_TES_FATAL( ge, ">=" );
DECL_TES_FATAL( le, "<=" );
DECL_TES_FATAL( lt, "<" );
DECL_TES_FATAL( str_eq, "===" );
DECL_TES_FATAL( str_ne, "!==" );

DECL_TES_WARN( eq, "==" );
DECL_TES_WARN( ne, "!=" );
DECL_TES_WARN( gt, ">" );
DECL_TES_WARN( ge, ">=" );
DECL_TES_WARN( le, "<=" );
DECL_TES_WARN( lt, "<" );
DECL_TES_WARN( str_eq, "===" );
DECL_TES_WARN( str_ne, "!==" );

DECL_TES_PASS( eq, "==" );
DECL_TES_PASS( ne, "!=" );
DECL_TES_PASS( gt, ">" );
DECL_TES_PASS( ge, ">=" );
DECL_TES_PASS( le, "<=" );
DECL_TES_PASS( lt, "<" );
DECL_TES_PASS( str_eq, "===" );
DECL_TES_PASS( str_ne, "!==" );

int tes_fatal_true( const char* x, const char* f, unsigned l )
{
	log_fail1( "was false", x, f, l );
	LOG_FATAL( );

	atexit( tes_fin );
	atexit( tes_post );

	exit( 1 );

	return 0;
}

int tes_fatal_false( const char* x, const char* f, unsigned l )
{
	log_fail1( "was true", x, f, l );
	LOG_FATAL( );

	atexit( tes_fin );
	atexit( tes_post );

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
