#include "webbaseclass.h"

WebCore::WebBaseClass::WebBaseClass(QWebEnginePage *Document, const QString &Path = NULL)
{
    this->Document = Document;
    if(Path != NULL){
        ReagPageFromResource(Path);
    }
    control = new WebCore::WebOperations(Document);
}

void WebCore::WebBaseClass::Clear(){
    delete control;
}

void WebCore::WebBaseClass::ReagPageFromResource(const QString &Path){
    try{
        HtmlPage =   WebCoreFunctions::ReadFile(Path);
    }catch(QString e){
        qDebug() << e;
    }
}

void WebCore::WebBaseClass::SetPage(QString &html){
    html.remove(QRegExp("[\\n\\t\\r]"));
    QString query = "document.getElementById('Main_WorkSpace').innerHTML = '"+html+"'";
    Document->runJavaScript(query);
}


void WebCore::WebBaseClass::Load(){
    //LoadDataPage();
    SetPage(HtmlPage);
}
