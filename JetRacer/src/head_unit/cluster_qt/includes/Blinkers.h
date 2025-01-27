#ifndef BLINKERS_H
#define BLINKERS_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

class Blinkers : public QWidget
{
    Q_OBJECT

public:
    explicit Blinkers(QWidget* parent = nullptr, std::string dir = "left", std::string mode = "off", int x = 0, int y = 0, int width = 0, int height = 0);
    virtual ~Blinkers();

    void    turnOnBlinkers(bool  on_off);
    bool    get_blinking(void);
    void    changeColor(int  array_index);

private slots:
    void toggleImage(); // Slot to toggle the image

private:
    QLabel* imageLabel;         // QLabel to display the image
    //QLabel* imageLabel_array[4];
    QPixmap image1;             // First image
    QPixmap image1_array[4];             
    QPixmap image2;             // Second image
    bool isImage1Visible;       // Boolean to track the current image
    QTimer* toggleTimer;        // Timer for toggling
    bool blinking;
};

#endif
