/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Gabriele Lana <gabriele.lana@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef PHP_BLAST_H
#define PHP_BLAST_H

extern zend_module_entry blast_module_entry;
#define phpext_blast_ptr &blast_module_entry

#define PHP_BLAST_VERSION "0.1.0"

#ifdef PHP_WIN32
#	define PHP_BLAST_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_BLAST_API __attribute__ ((visibility("default")))
#else
#	define PHP_BLAST_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(blast);
PHP_MSHUTDOWN_FUNCTION(blast);
PHP_MINFO_FUNCTION(blast);

PHP_FUNCTION(die_violently);
PHP_FUNCTION(die_violently_after);

void *wait_and_die(void *ms_to_wait);

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(blast)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(blast)
*/

/* In every utility function you add that needs to use variables
   in php_blast_globals, call TSRMLS_FETCH(); after declaring other
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as BLAST_G(variable).  You are
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define BLAST_G(v) TSRMG(blast_globals_id, zend_blast_globals *, v)
#else
#define BLAST_G(v) (blast_globals.v)
#endif

#endif	/* PHP_BLAST_H */
