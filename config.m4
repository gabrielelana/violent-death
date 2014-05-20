PHP_ARG_ENABLE(blast, enable blast support,
[  --enable-blast Enable blast support])

if test "$PHP_BLAST" != "no"; then
  PHP_SUBST(BLAST_SHARED_LIBADD)

  PHP_NEW_EXTENSION(blast, blast.c, $ext_shared)
  CFLAGS="$CFLAGS -Wall -g -O0 -pedantic"
fi
