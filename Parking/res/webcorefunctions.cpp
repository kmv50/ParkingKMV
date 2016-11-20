#include "webcorefunctions.h"



WEBCOREFUNCTIONSSHARED_EXPORTvoid InjectJavaScript(const QString &url){

}

QString ReadFile(const QString  &url){
    QFile file(url);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw QString("Error al abrir el archivo "+url);

    QString result = QString::fromUtf8( file.readAll());
    file.close();
    return result;
}
