#include "webtableengine.h"

WebCore::WebTableEngine::WebTableEngine(QWebEnginePage *Document, const QString &TargetSelector , const QString Name)
{
    target = TargetSelector;
    if(Name != ""){
       this->Name = Name;
       channel = new QWebChannel(Document);
       channel->registerObject(Name,this);
       Document->setWebChannel(channel);
    }
    this->Document = Document;
}

WebCore::WebTableEngine::~WebTableEngine(){
    channel->deregisterObject(this);
    delete channel;
}

WebCore::WebTableEngine * WebCore::WebTableEngine::SetHeaders(std::initializer_list<QString> headers){
    this->headers = headers;
    return this;
}

WebCore::WebTableEngine *WebCore::WebTableEngine::appendButton(const QString &Value, const QString &CSSclass){
    WebCore::WebCoreButton boton;
    boton.Value = Value;
    boton.css = CSSclass;
    botones.push_back(boton);
    return this;
}


void WebCore::WebTableEngine::appendRow(WebCore::WebCoreRowModel row){
    Model.push_back(row);
}

void WebCore::WebTableEngine::appendRow(std::initializer_list<WebCore::WebCoreNodeModel> row){
    Model.push_back(row);
}


void WebCore::WebTableEngine::setTable(WebCore::WebCoreTableModel table){
    Model = table;
}

void WebCore::WebTableEngine::RenderTable(){
  QString htmlTable = "<table class='"+css+"' ><thead>";
  foreach (QString header, headers) {
     htmlTable += "<th>"+header+"</th>";
  }
  htmlTable += "</thead><tbody>";

  for(unsigned int i = 0 ; i < Model.size() ; i++ ){
       WebCore::WebCoreRowModel *Row = &Model[i];
       for(unsigned int x = 0 ; x < Row->size() ; x++){
           htmlTable += TableNodeToHtmlCode((WebCore::WebCoreNodeModel *)&Row[x]);
       }
  }



  htmlTable += "</tbody></table>";
  Document->runJavaScript("$('#"+target+"').html("+htmlTable.toHtmlEscaped()+")");

}

QString WebCore::WebTableEngine::TableNodeToHtmlCode(WebCore::WebCoreNodeModel *Node){
  return "Falta implementar";
}
