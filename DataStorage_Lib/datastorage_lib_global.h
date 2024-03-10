#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DATASTORAGE_LIB_LIB)
#  define DATASTORAGE_LIB_EXPORT Q_DECL_EXPORT
# else
#  define DATASTORAGE_LIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define DATASTORAGE_LIB_EXPORT
#endif
