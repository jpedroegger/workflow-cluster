#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include "Colors.h"
#include <iostream>


/**
 * @brief This class sets a Bar of icons in the Widget.
 * @details It updates the icons state and changes its colour.
 */
class TopBar : public QWidget
{
    Q_OBJECT

public:
    explicit TopBar(QWidget* parent = nullptr, int x = 0, int y = 0, int width = 0, int height = 0);
    ~TopBar() override ;

    // Method to update the image at a specific index based on a condition
    bool    setImageState(int index, bool state);
    void    changeColor(int  array_index);

private:
    QHBoxLayout*        layout;              // Layout to hold the images
    QVector<QLabel*>    imageLabels;     // Vector to hold QLabel pointers for the images
    QVector<QPixmap>    defaultImages;  // Vector to hold the default images
    QVector<QPixmap>    defaultImages_array[4];
    QVector<QPixmap>    altImages;      // Vector to hold the alternate images
    QStringList         defaultImagePaths;
    QStringList         defaultImagePaths_array[4];
    QStringList         altImagePaths;
};

#endif // TOPBAR_H
