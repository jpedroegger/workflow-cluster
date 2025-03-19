#ifndef COLOR_H
#define COLOR_H

#include <QWidget>
#include <string>
#include <iostream>
#include <fstream>

class Color
{
    public:
        Color() : counter(getLastValue()) {};
        ~Color(){};
        Color&  operator=(const Color&) {return *this;}

        int    getLastValue(void)
        {
            int counter = 0;
            std::ifstream f("color.txt");
            if (!f.is_open())
            {
                std::cerr << "Error opening the file!";
                return counter;
            }
            std::string s;
            while (getline(f, s))
            {
                auto pos = s.find("index = ");
                if (pos != std::string::npos)
                {
                    try
                    {
                        counter = std::stoi(s.substr(pos + 8));
                    }
                    catch (const std::exception& e)
                    {
                        counter = 0;
                    } 
                }
            }
            f.close();
            return counter;
        }
        int     counter;

        QColor  main_color_array[4] = {"#312244", "#9A031E", "#FF99C8",
                                       "#283618"};
        QColor  main_color = main_color_array[counter];

        QColor  accent_color_array[4] = {"#4D194D", "#FB8B24", "#A9DEF9",
                                         "#BC6C25"};
        QColor  accent_color = accent_color_array[counter];

        QColor  alphabet_color_array[4] = {"#006466", "#E36414", "#E4C1F9",
                                           "#FEFAE0"};
        QColor  alphabet_color = alphabet_color_array[counter];

        QString background_array[4] = {"background-color: #212F45",
                                       "background-color: #5F0F40",
                                       "background-color: #D0F4DE",
                                       "background-color: #DDA15E"};
        QString background = background_array[counter];

        void    indent(void)
        {
            counter++;
            if (counter > 3)
                counter = 0;
            main_color = main_color_array[counter];
            accent_color = accent_color_array[counter];
            alphabet_color = alphabet_color_array[counter];
            background = background_array[counter];
            std::ofstream f("color.txt");

            f << "index = " << counter;
            f.close();
        };
};

#endif
