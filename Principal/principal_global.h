#ifndef PRINCIPAL_GLOBAL_H
#define PRINCIPAL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PRINCIPAL_LIBRARY)
#  define PRINCIPALSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PRINCIPALSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PRINCIPAL_GLOBAL_H
