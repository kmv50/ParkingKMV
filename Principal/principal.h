#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "principal_global.h"
#include <webbaseclass.h>

class PRINCIPALSHARED_EXPORT Principal  : public WebCore::WebBaseClass
{

public:
     Principal(QWebEnginePage *Document);
    ~Principal();
protected:
   virtual void LoadDataPage();

};

#endif // PRINCIPAL_H
