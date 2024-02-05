#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PHRASESMANAGER_LIB_LIB)
#  define PHRASESMANAGER_LIB_EXPORT Q_DECL_EXPORT
# else
#  define PHRASESMANAGER_LIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define PHRASESMANAGER_LIB_EXPORT
#endif
