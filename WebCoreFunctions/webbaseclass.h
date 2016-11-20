#ifndef WEBBASECLASS_H
#define WEBBASECLASS_H
#include <weboperations.h>


namespace WebCore{
class WEBCOREFUNCTIONSSHARED_EXPORT WebBaseClass
{
public:
    WebBaseClass(QWebEnginePage *Document , const QString &Path );
    virtual ~WebBaseClass(){}
    virtual void Load();
protected:
    QWebEnginePage *Document;
    virtual void ReagPageFromResource(const QString &Path);
    virtual void LoadDataPage() = 0;
    void SetPage(QString &html);
    void RunScript(const QString &js);
    WebCore::WebOperations *control;
    void Clear();
    QString HtmlPage;
};
}
#endif // WEBBASECLASS_H
