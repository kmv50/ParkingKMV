#include <utilwebcore.h>


QString WebCoreFunctions::ReadFile(const QString  &url){
    QFile file(url);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw QString("Error al abrir el archivo "+url);

    QString result = QString::fromUtf8( file.readAll());
    file.close();
    return result;
}
