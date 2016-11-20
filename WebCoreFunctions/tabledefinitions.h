#ifndef TABLEDEFINITIONS_H
#define TABLEDEFINITIONS_H
#include <QString>
#include <vector>
#include <map>
namespace WebCore{

typedef std::map<QString,QString> WebCoreNodeModel;
typedef std::vector<WebCoreNodeModel> WebCoreRowModel;
typedef std::vector<WebCoreRowModel> WebCoreTableModel;
typedef struct WebCoreButton{
    QString Value;
    QString css;
}WebCoreButton;
}

#endif // TABLEDEFINITIONS_H
