#include "login.h"
#include <mainwindow.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*QPixmap pixmap("://HtmlContext/image/Splash.jpg");
       QSplashScreen splash(pixmap);
       splash.show();*/
    MainWindow w;
    Login login;
    login.RenderInit();
    if(login.exec() == QDialog::Accepted){
        w.Run();
    }

    return a.exec();
}
