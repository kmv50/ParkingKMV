#ifndef WEBTABLEENGINE_H
#define WEBTABLEENGINE_H
#include <webcorefunctions_global.h>
#include <vector>
#include <initializer_list>
#include <tabledefinitions.h>
#include <functional>
#include <QObject>
#include <QWebChannel>
#include <QWebEnginePage>

namespace WebCore {
class WEBCOREFUNCTIONSSHARED_EXPORT WebTableEngine: public QObject
{
    Q_OBJECT
public:
    WebTableEngine(QWebEnginePage *Document, const QString &TargetSelector , const QString Name);
    ~WebTableEngine();
    WebTableEngine * SetHeaders(std::initializer_list<QString> headers);
    WebTableEngine * SetCss(QString css){ this->css = css; return this;}
    WebTableEngine * appendButton(const QString &Value,const QString &CSSclass);

    //////////////////////////////////////////////////////
    void appendRow(WebCore::WebCoreRowModel row);
    void appendRow(std::initializer_list<WebCore::WebCoreNodeModel> row);
    ///-----------------------------------------------///


    void setTable(WebCore::WebCoreTableModel table);

    inline int getRowSelectd(){return RowSelected;}

    ///
    /// \brief RegisterOnClick Cuando se le de click a la tabla se llamara a esta Callback
    /// \param callback
    ///
   // inline void RegisterOnClick(std::function<void(int,WebCore::WebCoreRowModel)> callback){this->callback = callback;}
    void RenderTable();//falta implementar
private:
    QString Name;
    QString target;
    int RowSelected;

    QWebChannel *channel;

    QString css;

   // std::function<void(int,WebCore::WebCoreRowModel)> callback;

    std::vector<QString> headers;
    WebCore::WebCoreTableModel Model;
    std::vector<WebCore::WebCoreButton> botones;

    QString TableNodeToHtmlCode(WebCore::WebCoreNodeModel * Node);
    QWebEnginePage *Document;
public slots:
   // void TableClick();

    //Sobrecarga operadores
public:
    void operator<<( const WebCore::WebCoreRowModel& row)
    {
        appendRow(row);
    }
    WebCore::WebCoreRowModel operator>>(void *)
    {
        WebCore::WebCoreRowModel row;
        if(RowSelected > 0){
            row = Model[RowSelected];
        }
        return row;
    }
};
}



#endif // WEBTABLEENGINE_H
