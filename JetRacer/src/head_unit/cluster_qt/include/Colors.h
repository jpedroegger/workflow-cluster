#ifndef COLOR_H
#define COLOR_H

#include <QWidget>
#include <string>

class Color
{
public:
    Color(){};
    ~Color(){};
    Color& operator=(const Color&) {return *this;}
    QColor main_color = "#312244";
    QColor accent_color = "#4D194D";
    QColor alphabet_color = "#006466";
    const QString background = "background-color: #212F45";
    
};

#endif
