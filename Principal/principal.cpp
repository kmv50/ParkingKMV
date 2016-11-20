#include "principal.h"


Principal::Principal(QWebEnginePage *Document)
    :WebCore::WebBaseClass(Document,"://HtmlForms/HtmlForms/Principal.html")
{
    qDebug() << "Creando Principal";

}

Principal::~Principal(){

}



void Principal::LoadDataPage(){

}
