PHP_ARG_ENABLE(blast, enable blast support,
[--enable-blast Enable blast support])

PHP_ARG_WITH(pthread, for pthread support,
[--with-pthread[=DIR] Include pthread support])

if test "$PHP_BLAST" != "no"; then
  if test -r $PHP_PTHREAD/include/pthread.h; then
    PTHREAD_DIR=$PHP_PTHREAD
  else
    AC_MSG_CHECKING(for pthread in default path)
    for i in /usr/local /usr; do
      if test -r $i/include/pthread.h; then
        PTHREAD_DIR=$i
        AC_MSG_RESULT(found in $i)
        break
      fi
    done
  fi

  if test -z "$PTHREAD_DIR"; then
    AC_MSG_RESULT(not found)
    AC_MSG_ERROR(Please install the pthread library with development support)
  fi

  PHP_CHECK_LIBRARY(pthread, pthread_create,
  [
    PHP_ADD_INCLUDE($PTHREAD_DIR/include)
    PHP_ADD_LIBRARY_WITH_PATH(pthread, $PTHREAD_DIR/$PHP_LIBDIR, PTHREAD_SHARED_LIBADD)
    AC_DEFINE(HAVE_PTHREAD,1,[ ])
  ], [
    AC_MSG_ERROR(blast module requires pthread library)
  ], [
    -L$PTHREAD_DIR/$PHP_LIBDIR
  ])

  PHP_NEW_EXTENSION(blast, blast.c, $ext_shared)
  PHP_SUBST(BLAST_SHARED_LIBADD)
  dnl CFLAGS="$CFLAGS -Wall -g -O0 -pedantic"
fi
