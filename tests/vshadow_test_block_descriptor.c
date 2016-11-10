/*
 * Library block_descriptor type testing program
 *
 * Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "vshadow_test_libcerror.h"
#include "vshadow_test_libvshadow.h"
#include "vshadow_test_macros.h"
#include "vshadow_test_memory.h"
#include "vshadow_test_unused.h"

#include "../libvshadow/libvshadow_block_descriptor.h"

#if defined( __GNUC__ )

/* Tests the libvshadow_block_descriptor_initialize function
 * Returns 1 if successful or 0 if not
 */
int vshadow_test_block_descriptor_initialize(
     void )
{
	libcerror_error_t *error                        = NULL;
	libvshadow_block_descriptor_t *block_descriptor = NULL;
	int result                                      = 0;

	/* Test block_descriptor initialization
	 */
	result = libvshadow_block_descriptor_initialize(
	          &block_descriptor,
	          &error );

	VSHADOW_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        VSHADOW_TEST_ASSERT_IS_NOT_NULL(
         "block_descriptor",
         block_descriptor );

        VSHADOW_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libvshadow_block_descriptor_free(
	          &block_descriptor,
	          &error );

	VSHADOW_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        VSHADOW_TEST_ASSERT_IS_NULL(
         "block_descriptor",
         block_descriptor );

        VSHADOW_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libvshadow_block_descriptor_initialize(
	          NULL,
	          &error );

	VSHADOW_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        VSHADOW_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	block_descriptor = (libvshadow_block_descriptor_t *) 0x12345678UL;

	result = libvshadow_block_descriptor_initialize(
	          &block_descriptor,
	          &error );

	VSHADOW_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        VSHADOW_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	block_descriptor = NULL;

#if defined( HAVE_VSHADOW_TEST_MEMORY )

	/* Test libvshadow_block_descriptor_initialize with malloc failing
	 */
	vshadow_test_malloc_attempts_before_fail = 0;

	result = libvshadow_block_descriptor_initialize(
	          &block_descriptor,
	          &error );

	if( vshadow_test_malloc_attempts_before_fail != -1 )
	{
		vshadow_test_malloc_attempts_before_fail = -1;

		if( block_descriptor != NULL )
		{
			libvshadow_block_descriptor_free(
			 &block_descriptor,
			 NULL );
		}
	}
	else
	{
		VSHADOW_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		VSHADOW_TEST_ASSERT_IS_NULL(
		 "block_descriptor",
		 block_descriptor );

		VSHADOW_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libvshadow_block_descriptor_initialize with memset failing
	 */
	vshadow_test_memset_attempts_before_fail = 0;

	result = libvshadow_block_descriptor_initialize(
	          &block_descriptor,
	          &error );

	if( vshadow_test_memset_attempts_before_fail != -1 )
	{
		vshadow_test_memset_attempts_before_fail = -1;

		if( block_descriptor != NULL )
		{
			libvshadow_block_descriptor_free(
			 &block_descriptor,
			 NULL );
		}
	}
	else
	{
		VSHADOW_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		VSHADOW_TEST_ASSERT_IS_NULL(
		 "block_descriptor",
		 block_descriptor );

		VSHADOW_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_VSHADOW_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( block_descriptor != NULL )
	{
		libvshadow_block_descriptor_free(
		 &block_descriptor,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvshadow_block_descriptor_free function
 * Returns 1 if successful or 0 if not
 */
int vshadow_test_block_descriptor_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libvshadow_block_descriptor_free(
	          NULL,
	          &error );

	VSHADOW_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        VSHADOW_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc VSHADOW_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] VSHADOW_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc VSHADOW_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] VSHADOW_TEST_ATTRIBUTE_UNUSED )
#endif
{
	VSHADOW_TEST_UNREFERENCED_PARAMETER( argc )
	VSHADOW_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ )

	VSHADOW_TEST_RUN(
	 "libvshadow_block_descriptor_initialize",
	 vshadow_test_block_descriptor_initialize );

	VSHADOW_TEST_RUN(
	 "libvshadow_block_descriptor_free",
	 vshadow_test_block_descriptor_free );

#endif /* defined( __GNUC__ ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

