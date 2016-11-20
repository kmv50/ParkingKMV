#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QVBoxLayout>
#include <QUrl>
#include <utilwebcore.h>
#include <QMessageBox>
#include <vector>
#include <QVariantMap>
#include <QWebChannel>


using namespace std;

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void RenderInit();
private:
    QWebEngineView *render;
    QVBoxLayout *layout;
    vector<QWebEngineProfile *> LoadsScripts;
    QWebChannel *channel;
    QWebEnginePage *Document;
public slots:
   // QVariantMap LoginAction(const QVariantMap &json);
     void LoginAction(const QVariantMap &json);
};

#endif // LOGIN_H
