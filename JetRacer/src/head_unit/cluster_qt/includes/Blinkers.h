#ifndef BLINKERS_H
#define BLINKERS_H

#include "Colors.h"
#include <QLabel>
#include <QPixmap>
#include <QTimer>


/**
 * @brief The class represents a widget that simulates blinking indicators.
 * @details It uses a QTimer to toggle between two images, creating a blinking effect. 
 * The class supports turning the blinkers on/off and changing the color of the images.
 */

class Blinkers : public QWidget
{
        Q_OBJECT

    public:
        explicit Blinkers(QWidget* parent = nullptr, std::string dir = "left",
                          std::string mode = "off", int x = 0, int y = 0,
                          int width = 0, int height = 0);
        virtual ~Blinkers();

        void turnOnBlinkers(bool on_off);
        bool get_blinking(void);
        void changeColor(int array_index);
        QTimer* getToggleTimer(void);

    private slots:
        void toggleImage(); // Slot to toggle the image

    private:
        QLabel* imageLabel; // QLabel to display the image
        QPixmap image1;     // First image
        QPixmap image1_array[4];
        QPixmap image2;       // Second image
        QTimer* toggleTimer;  // Timer for toggling
        bool isImage1Visible; // Boolean to track the current image
        bool blinking;
};

#endif
