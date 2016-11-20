#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QWebEngineView(parent)
{
    Document = new QWebEnginePage(this);
    channel = new QWebChannel(Document);
    CurrentDocument = NULL;
}

MainWindow::~MainWindow(){
    delete channel;
    delete Document;
}


void MainWindow::ClearDocument(){
    if(CurrentDocument != NULL){
        delete (WebCore::WebBaseClass *) CurrentDocument;
        CurrentDocument = NULL;
    }
}

void MainWindow::RegisterDocument(WebCore::WebBaseClass *obj){
    CurrentDocument = (WebCore::WebBaseClass *)obj;
}


void MainWindow::Run(){
    try{
        Document->setHtml(WebCoreFunctions::ReadFile(_BaseHtmlUrl+"MainWindow.html"));
    }catch(QString e){
        QMessageBox::critical(this,"IO Error",e,QMessageBox::Ok);
        return;
    }
    channel->registerObject("mainWindow",this);
    Document->setWebChannel(channel);
    this->setPage(Document);
    this->showMaximized();
    MostrarPrincipal();
}


void MainWindow::MostrarPrincipal(){
    ClearDocument();
      Principal *obj = new Principal(Document);
      obj->Load();
    RegisterDocument((WebCore::WebBaseClass *)obj);
}
