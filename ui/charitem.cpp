#include "charitem.h"


CharItem::CharItem(QWidget *parent) :
    QPushButton(parent)
{
    this->setStyleSheet("QPushButton{\
        color: rgb(255, 255, 255);\
        background-color: rgb(167, 205, 255);\
        border:none;\
        padding: 0px;\
        font-family: \"Verdana\";\
        font-size: 15px;\
        text-align: center;\
    }\
    QPushButton:hover, QPushButton:pressed , QPushButton:checked\
    {\
        background-color: rgb(85, 170, 255);\
        text-align: right;\
        padding-right: 2px;\
        font-weight:100\
    }\
    QPushButton:hover\
    {\
        background-image: url(:/icon/icons/dark/appbar.navigate.next.png);\
        background-repeat:no-repeat;\
        background-position: center left;\
    }\
    QPushButton:pressed, QPushButton:checked\
    {\
        background-image: url(:/icon/icons/light/appbar.navigate.next.png);\
        background-repeat:no-repeat;\
        background-position: center left;\
    }");
}
