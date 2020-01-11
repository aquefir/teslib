/****************************************************************************\
 *                          Test Engineering Suite                          *
 *                                                                          *
 *                      Copyright © 2019 ARQADIUM, LLC                      *
 *                           All rights reserved.                           *
\****************************************************************************/

#ifndef INC_API__TES_BATTERY_H
#define INC_API__TES_BATTERY_H

#define TES_ASSERT_EQ( X, Y ) \
	(void)( ( ( ( ( X ) == ( Y ) ) && \
	           tes_pass_eq( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_fatal_eq( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_ASSERT_NE( X, Y ) \
	(void)( ( ( ( ( X ) != ( Y ) ) && \
	           tes_pass_ne( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_fatal_ne( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_ASSERT_GT( X, Y ) \
	(void)( ( ( ( ( X ) > ( Y ) ) && \
	           tes_pass_gt( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_fatal_gt( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_ASSERT_GE( X, Y ) \
	(void)( ( ( ( ( X ) >= ( Y ) ) && \
	           tes_pass_ge( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_fatal_ge( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_ASSERT_LE( X, Y ) \
	(void)( ( ( ( ( X ) <= ( Y ) ) && \
	           tes_pass_le( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_fatal_le( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_ASSERT_LT( X, Y ) \
	(void)( ( ( ( ( X ) < ( Y ) ) && \
	           tes_pass_lt( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_fatal_lt( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_ASSERT_TRUE( X ) \
	(void)( ( ( ( X ) && tes_pass_true( #X, __FILE__, __LINE__ ) ) || \
	      tes_fatal_true( #X, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_ASSERT_FALSE( X ) \
	(void)( ( ( ( !( X ) ) && tes_pass_false( #X, __FILE__, __LINE__ ) ) || \
	      tes_fatal_false( #X, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_ASSERT_STR_EQ( X, Y ) \
	(void)( ( ( tes_chkstr( ( X ), ( Y ) ) && \
	           tes_pass_str_eq( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_fatal_str_eq( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_ASSERT_STR_NE( X, Y ) \
	(void)( ( ( !tes_chkstr( ( X ), ( Y ) ) && \
	           tes_pass_str_ne( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_fatal_str_ne( #X, #Y, __FILE__, __LINE__ ), \
	   0 )

#define TES_EXPECT_EQ( X, Y ) \
	(void)( ( ( ( ( X ) == ( Y ) ) && \
	           tes_pass_eq( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_warn_eq( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_EXPECT_NE( X, Y ) \
	(void)( ( ( ( ( X ) != ( Y ) ) && \
	           tes_pass_ne( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_warn_ne( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_EXPECT_GT( X, Y ) \
	(void)( ( ( ( ( X ) > ( Y ) ) && \
	           tes_pass_gt( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_warn_gt( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_EXPECT_GE( X, Y ) \
	(void)( ( ( ( ( X ) >= ( Y ) ) && \
	           tes_pass_ge( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_warn_ge( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_EXPECT_LE( X, Y ) \
	(void)( ( ( ( ( X ) <= ( Y ) ) && \
	           tes_pass_le( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_warn_le( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_EXPECT_LT( X, Y ) \
	(void)( ( ( ( ( X ) < ( Y ) ) && \
	           tes_pass_lt( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_warn_lt( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_EXPECT_TRUE( X ) \
	(void)( ( ( ( X ) && tes_pass_true( #X, __FILE__, __LINE__ ) ) || \
	      tes_warn_true( #X, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_EXPECT_FALSE( X ) \
	(void)( ( ( !( X ) && tes_pass_false( #X, __FILE__, __LINE__ ) ) || \
	      tes_warn_false( #X, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_EXPECT_STR_EQ( X, Y ) \
	(void)( ( ( ( tes_chkstr( ( X ), ( Y ) ) == 1 ) && \
	           tes_pass_str_eq( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_warn_str_eq( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )
#define TES_EXPECT_STR_NE( X, Y ) \
	(void)( ( ( ( !tes_chkstr( ( X ), ( Y ) ) == 0 ) && \
	           tes_pass_str_ne( #X, #Y, __FILE__, __LINE__ ) ) || \
	      tes_warn_str_ne( #X, #Y, __FILE__, __LINE__ ) ), \
	   0 )

#ifdef __cplusplus
extern "C" {
#endif

extern int tes_fatal_eq( const char*, const char*, const char*, unsigned );
extern int tes_fatal_ne( const char*, const char*, const char*, unsigned );
extern int tes_fatal_gt( const char*, const char*, const char*, unsigned );
extern int tes_fatal_ge( const char*, const char*, const char*, unsigned );
extern int tes_fatal_le( const char*, const char*, const char*, unsigned );
extern int tes_fatal_lt( const char*, const char*, const char*, unsigned );
extern int tes_fatal_true( const char*, const char*, unsigned );
extern int tes_fatal_false( const char*, const char*, unsigned );
extern int tes_fatal_str_eq(
   const char*, const char*, const char*, unsigned );
extern int tes_fatal_str_ne(
   const char*, const char*, const char*, unsigned );

extern int tes_warn_eq( const char*, const char*, const char*, unsigned );
extern int tes_warn_ne( const char*, const char*, const char*, unsigned );
extern int tes_warn_gt( const char*, const char*, const char*, unsigned );
extern int tes_warn_ge( const char*, const char*, const char*, unsigned );
extern int tes_warn_le( const char*, const char*, const char*, unsigned );
extern int tes_warn_lt( const char*, const char*, const char*, unsigned );
extern int tes_warn_true( const char*, const char*, unsigned );
extern int tes_warn_false( const char*, const char*, unsigned );
extern int tes_warn_str_eq( const char*, const char*, const char*, unsigned );
extern int tes_warn_str_ne( const char*, const char*, const char*, unsigned );

extern int tes_pass_eq( const char*, const char*, const char*, unsigned );
extern int tes_pass_ne( const char*, const char*, const char*, unsigned );
extern int tes_pass_gt( const char*, const char*, const char*, unsigned );
extern int tes_pass_ge( const char*, const char*, const char*, unsigned );
extern int tes_pass_le( const char*, const char*, const char*, unsigned );
extern int tes_pass_lt( const char*, const char*, const char*, unsigned );
extern int tes_pass_true( const char*, const char*, unsigned );
extern int tes_pass_false( const char*, const char*, unsigned );
extern int tes_pass_str_eq( const char*, const char*, const char*, unsigned );
extern int tes_pass_str_ne( const char*, const char*, const char*, unsigned );

extern int tes_chkstr( const char*, const char* );

#ifdef __cplusplus
}
#endif

#endif /* INC_API__TES_BATTERY_H */
