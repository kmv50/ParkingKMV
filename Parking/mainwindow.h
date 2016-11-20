#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QVBoxLayout>
#include <QUrl>
#include <utilwebcore.h>
#include <principal.h>

class MainWindow: public QWebEngineView
{
public:
    explicit MainWindow(QWidget *parent = 0);
    void Run();
    ~MainWindow();
private:
    QWebEnginePage *Document;
    QWebChannel *channel;
    void * CurrentDocument;
    void ClearDocument();
    void RegisterDocument(WebCore::WebBaseClass *obj);
public slots: //Ui_Menus
    void MostrarPrincipal();
};

#endif // MAINWINDOW_H
