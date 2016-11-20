#ifndef WEBOPERATIONS_H
#define WEBOPERATIONS_H
#include <webcorefunctions_global.h>
#include <utilwebcore.h>
#include <QWebChannel>
#include <QWebEnginePage>
#include <webtableengine.h>
#include <map>

namespace WebCore{
class WEBCOREFUNCTIONSSHARED_EXPORT  WebOperations
{
public:
    WebOperations(QWebEnginePage *Document);
    ~WebOperations();
    //////////////Input Test/////////////
    void inputText(const QString &selector , const QString & Value );
    QString inputText(const QString &selector);
    //------------------------------//


    /////////////Input Radio///////////
    void radioButton(const QString &selector , const QString & Value );
    QString radioButton(const QString &selector);
    //------------------------------//

    /////////////Input Check///////////
    void CheckBox(const QString &selector , const QString & Value );
    QString CheckBox(const QString &selector);
    //------------------------------//

    /////////////Input Combo///////////
    void ComboBox(const QString &selector , const QString & Value );
    QString ComboBox(const QString &selector);
    //------------------------------//

    //////////////TableView//////////////////
    WebTableEngine *CreateTable(const QString & Name , const QString & Target);

    void Clear();

private:
    QWebEnginePage *Document;
    std::map<QString,WebCore::WebTableEngine * > TableAccessControl;
};
}

#endif // WEBOPERATIONS_H
