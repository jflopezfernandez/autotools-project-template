AC_PREREQ([2.69])
AC_INIT([Project],[1.0],[project-bugs@example.org])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AC_ARG_PROGRAM
AM_INIT_AUTOMAKE([1.11.2 dist-xz color-tests parallel-tests subdir-objects])
AM_SILENT_RULES([yes])

AM_SANITY_CHECK

AC_DEFUN([gl_PERL],
[
  dnl FIXME: don't hard-code 5.005
  AC_MSG_CHECKING([for perl5.005 or newer])
  if test "${PERL+set}" = set; then
    # 'PERL' is set in the user's environment.
    candidate_perl_names="$PERL"
    perl_specified=yes
  else
    candidate_perl_names='perl perl5'
    perl_specified=no
  fi

  found=no
  AC_SUBST([PERL])
  PERL="$am_missing_run perl"
  for perl in $candidate_perl_names; do
    # Run test in a subshell; some versions of sh will print an error if
    # an executable is not found, even if stderr is redirected.
    if ( $perl -e 'require 5.005; use File::Compare; use warnings;' ) > /dev/null 2>&1; then
      PERL=$perl
      found=yes
      break
    fi
  done

  AC_MSG_RESULT([$found])
  test $found = no && AC_MSG_WARN([
WARNING: You don't seem to have perl5.005 or newer installed, or you lack
         a usable version of the Perl File::Compare module.  As a result,
         you may be unable to run a few tests or to regenerate certain
         files if you modify the sources from which they are derived.
] )
])

gl_PERL

AC_PROG_CC_STDC
AM_PROG_CC_C_O
AC_PROG_CPP
AC_PROG_GCC_TRADITIONAL
AC_PROG_RANLIB
AC_PROG_LN_S

AC_CHECK_LIB(crypt, crypt, LIBCRYPT=-lcrypt)
AC_SUBST(LIBCRYPT)

AM_MAINTAINER_MODE
AC_CONFIG_FILES([Makefile src/Makefile])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([include/config.h:include/config.h.in])


AC_HEADER_STDC
AC_HEADER_TIME
AC_HEADER_DIRENT

AC_CHECK_HEADERS([unistd.h pthread.h])

AC_SEARCH_LIBS([pthread_create], [ptread])

AC_TYPE_SIGNAL

AC_CHECK_TYPE(socklen_t, ,
  [AC_DEFINE([socklen_t], int,
    [Define to int if <sys/types.h> does not define])],
  [IU_FLUSHLEFT([#include <sys/types.h>
                 #include <sys/socket.h>])])

AC_PROG_SED
AC_PROG_AWK

AC_PROG_CC
AC_C_CONST

AC_PROG_CXX
AC_PROG_INSTALL

AC_CHECK_FUNC(getopt_long)

# Need to create summary.sh for this
#AC_CONFIG_COMMANDS([summary], [sh ./summary.sh])

AC_OUTPUT
