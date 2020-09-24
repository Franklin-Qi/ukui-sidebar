#include "labelfotmattext.h"

LabelFotmatText::LabelFotmatText()
{

}

/* 设置...字样 */
QString LabelFotmatText::SetFormatBody(QString text, QLabel *CopyDataLabal)
{
    QFontMetrics fontMetrics(CopyDataLabal->font());
    int LableWidth = CopyDataLabal->width();
    int fontSize = fontMetrics.width(text);
    QString formatBody = text;
    if(fontSize > (LableWidth - 10)) {
        //说明只存在一行，在最后面加...就行
        formatBody = formatBody + "aa";
        formatBody = fontMetrics.elidedText(formatBody, Qt::ElideRight, LableWidth - 10);
        m_bTooltips = true;
        return formatBody;
    }
    return formatBody;
}