#include "login.h"

Login::Login(QWidget *parent) :
    QDialog(parent)
{
    render = new QWebEngineView(this);
    layout = new QVBoxLayout(this);
    layout->addWidget(render);
    layout->setMargin(0);
    this->setLayout(layout);
    this->resize(500,400);
    Document = new QWebEnginePage(render);
}

Login::~Login()
{
    delete channel;
    delete Document;
    delete render;
    delete layout;
}

void Login::RenderInit(){
    try{
        Document->setHtml(WebCoreFunctions::ReadFile(_BaseHtmlUrl+"login.html"));
        channel = new QWebChannel(Document);
        channel->registerObject("qt",this);
        Document->setWebChannel(channel);
        render->setPage(Document);
    }catch(QString e){
        QMessageBox::critical(this,"File Error",e,QMessageBox::Ok);
    }
}


/*QVariantMap Login::LoginAction(const QVariantMap &json){
   // qDebug() << json;
   QVariantMap result;
   result["State"] = "OK";
   return result;
}*/

void Login::LoginAction(const QVariantMap &json){
    this->done(QDialog::Accepted);
}
