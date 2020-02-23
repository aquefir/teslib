/****************************************************************************\
 *                          Test Engineering Suite                          *
 *                                                                          *
 *                      Copyright © 2019 ARQADIUM, LLC                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

extern void tes_pre( int ac, char* av[] );
extern int tes_tests( void );
extern void tes_post( void );

void tes_fin( void )
{
	printf( "Test suite stopped prematurely. Exiting...\n" );
}

int main( int ac, char* av[] )
{
	int r;

	printf(
	   "TEST ENGINEERING SUITE\n\nCopyright (C) 2019-2020 ARQADIUM LLC\n"
		"All rights reserved.\n\n" );

	printf( "Executing pre-test function...\n" );
	tes_pre( ac, av );
	printf( "Executing tests...\n" );
	r = tes_tests( );
	printf( "Testing complete. Executing post-test function...\n" );
	tes_post( );

	printf( "Test suite complete!\n\nRESULT: %s\n%i tests failed in total.\n\n",
	   r == 0 ? "Success!" : "Failure.",
	   r );

	return r;
}
