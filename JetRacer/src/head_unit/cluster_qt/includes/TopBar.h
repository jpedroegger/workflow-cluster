#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

class TopBar : public QWidget
{
    Q_OBJECT

public:
    explicit TopBar(QWidget* parent = nullptr);
    ~TopBar();

    // Method to update the image at a specific index based on a condition
    bool setImageState(int index, bool state);
    void changeColor(int  array_index);

private:
    QHBoxLayout* layout;              // Layout to hold the images
    QVector<QLabel*> imageLabels;     // Vector to hold QLabel pointers for the images
    QVector<QPixmap> defaultImages;  // Vector to hold the default images
    QVector<QPixmap> defaultImages_array[5];
    QVector<QPixmap> altImages;      // Vector to hold the alternate images
    QStringList defaultImagePaths;
    QStringList defaultImagePaths_array[5];
    QStringList altImagePaths;
};

#endif // TOPBAR_H
