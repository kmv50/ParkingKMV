#ifndef WEBCOREFUNCTIONS_H
#define WEBCOREFUNCTIONS_H
#include <QString>
#include <QFile>
#include <localdefinitions.h>

namespace WebCoreFunctions {
    void InjectJavaScript(const QString &url);
    QString ReadFile(const QString  &url);
}


#endif // WEBCOREFUNCTIONS_H
