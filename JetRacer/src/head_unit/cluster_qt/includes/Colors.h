#ifndef COLOR_H
#define COLOR_H

#include <QWidget>
#include <string>
#include <iostream>

class Color
{
public:
    Color(){};
    ~Color(){};
    Color&  operator=(const Color&) {return *this;}
    
    int    getLastValue(void)
    {
        int counter = 0;
        ifstream f("color.txt");
        if (!f.is_open()) {
            cerr << "Error opening the file!";
            return counter;
        }
        std::string s;
        while (getline(f, s))
        {
            if (s.find("index = ") != std::string::npos)
            {
                try
                {
                    counter = atoi(s[std::string::npos]);
                }
                catch ()
                {
                  std::cout << "Something wrong with file: " << s[std::string::npos] << "\n";
                } 
            }
        }
        f.close();
        return counter;
    }
    int     counter = getLastValue();

    QColor  main_color_array[4] = {"#312244", "#9A031E", "#FF99C8", "#283618"};
    QColor  main_color = main_color_array[counter];

    QColor  accent_color_array[4] = {"#4D194D", "#FB8B24", "#A9DEF9", "#BC6C25"};
    QColor  accent_color = accent_color_array[counter];

    QColor  alphabet_color_array[4] = {"#006466", "#E36414", "#E4C1F9", "#FEFAE0"};
    QColor  alphabet_color = alphabet_color_array[counter];

    QString background_array[4] = {"background-color: #212F45", "background-color: #5F0F40", "background-color: #D0F4DE", "background-color: #DDA15E"};
    QString background = background_array[counter];

    void    indent(void)
    {
        this->counter++;
        if (this->counter > 3)
            this->counter = 0;
        this->main_color = main_color_array[counter];
        this->accent_color = accent_color_array[counter];
        this->alphabet_color = alphabet_color_array[counter];
        this->background = background_array[counter];
        ofstream f("color.txt");

        // Write to the file
        f << "index = " << counter;
        // Close the file
        f.close();
    };
};

#endif
