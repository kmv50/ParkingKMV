#include "weboperations.h"

WebCore::WebOperations::WebOperations(QWebEnginePage *Document)
{
    this->Document = Document;
}

WebCore::WebOperations::~WebOperations(){
     std::map<QString,WebCore::WebTableEngine> ::const_iterator itr;

//    for(itr = TableAccessControl.begin(); itr != TableAccessControl.end(); ++itr){
//        WebCore::WebTableEngine t = itr->second();
//        delete t;
//    }
}

void WebCore::WebOperations::inputText(const QString &selector , const QString & Value ){
    QString query = "$('#"+selector+"').val('"+Value.toHtmlEscaped()+"')";
    Document->runJavaScript(query);
}

QString WebCore::WebOperations::inputText(const QString &selector){
    QString query = "$('#"+selector+"').val()";
    Document->runJavaScript(query,[&](const QVariant &result){
        query = result.toString();
    });
    return query;
}


WebCore::WebTableEngine * WebCore::WebOperations::CreateTable(const QString &Name, const QString &Target){
    WebCore::WebTableEngine *t = new WebCore::WebTableEngine(Document,Name,Target);
    TableAccessControl[Name] = t;
    return t;
}
