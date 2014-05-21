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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_blast.h"

#include <unistd.h>
#include <pthread.h>

/* {{{ blast_functions[]
 *
 * Every user visible function must have an entry in blast_functions[].
 */
const zend_function_entry blast_functions[] = {
	PHP_FE(die_violently, NULL)
	PHP_FE(die_violently_after, NULL)
	PHP_FE_END
};
/* }}} */

/* {{{ blast_module_entry */
zend_module_entry blast_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"blast",
	blast_functions,
	PHP_MINIT(blast),
	PHP_MSHUTDOWN(blast),
	NULL,
	NULL,
	PHP_MINFO(blast),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_BLAST_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_BLAST
ZEND_GET_MODULE(blast)
#endif

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(blast)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(blast)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(blast)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "blast support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/*
 * {{{ proto void die_violently(void)
 * If you call this you will die instantly and painfully
 */
PHP_FUNCTION(die_violently)
{
  int ms_to_wait = 0;
  wait_and_die(&ms_to_wait);
}
/* }}} */

/*
 * {{{ proto void die_violently_after(int ms_to_wait)
 * If you call this you will die instantly and painfully
 */
PHP_FUNCTION(die_violently_after)
{
  pthread_t thread;
  int *ms_to_wait = calloc(1, sizeof(int));

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", ms_to_wait) == FAILURE) {
    return;
  }
  if (pthread_create(&thread, NULL, wait_and_die, ms_to_wait)) {
    fprintf(stderr, "PHP-BLAST-EXTENSION: Unable to create thread... giving up\n");
    exit(1);
  }
}
/* }}} */

void *wait_and_die(void *ms_to_wait)
{
  usleep((*(int*)ms_to_wait) * 1000);
	// I don't know about you but I find it beautiful
	*(int*)0 = 0;
}
