#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTSHAREDPCH_LIB)
#  define QTSHAREDPCH_EXPORT Q_DECL_EXPORT
# else
#  define QTSHAREDPCH_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTSHAREDPCH_EXPORT
#endif
