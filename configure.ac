#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([tutorial], [0.1.0], [adamkoehn1@gmail.com])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([GLFW], [glfw3], [], [AC_MSG_ERROR([could not find glfw3])])
PKG_CHECK_MODULES([GLEW], [glew], [], [AC_MSG_ERROR([could not find glew])])
PKG_CHECK_MODULES([STB], [stb], [], [AC_MSG_ERROR([could not find stb])])
PKG_CHECK_MODULES([GLM], [glm], [], [AC_MSG_ERROR([could not find glm])])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
