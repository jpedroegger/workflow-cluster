#include "../includes/TopBar.h"
#include <iostream>

TopBar::TopBar(QWidget* parent, int x, int y, int width, int height) : QWidget(parent)
{
    // Initialize layout
    layout = new QHBoxLayout(this);
    layout->setSpacing(1); // Optional: adjust spacing between images
    layout->setContentsMargins(0, 0, 0, 0); // Optional: adjust margins
    setGeometry(x, y, width, height);
    // Create default and alternate images
    defaultImagePaths_array[0] = {
        "assets/icons/wheel_p.png",
        "assets/icons/brake_p.png",
        "assets/icons/abs_p.png", // Replace with your actual paths
        "assets/icons/med_p.png",
        "assets/icons/max_p.png",
        "assets/icons/fog_p.png",
        "assets/icons/belt_p.png"
    };
    defaultImagePaths_array[1] = {
        "assets/icons/wheel_r.png",
        "assets/icons/brake_r.png",
        "assets/icons/abs_r.png", // Replace with your actual paths
        "assets/icons/med_r.png",
        "assets/icons/max_r.png",
        "assets/icons/fog_r.png",
        "assets/icons/belt_r.png"
    };
    defaultImagePaths_array[2] = {
        "assets/icons/wheel_i.png",
        "assets/icons/brake_i.png",
        "assets/icons/abs_i.png", // Replace with your actual paths
        "assets/icons/med_i.png",
        "assets/icons/max_i.png",
        "assets/icons/fog_i.png",
        "assets/icons/belt_i.png"
    };
    defaultImagePaths_array[3] = {
        "assets/icons/wheel_g.png",
        "assets/icons/brake_g.png",
        "assets/icons/abs_g.png", // Replace with your actual paths
        "assets/icons/med_g.png",
        "assets/icons/max_g.png",
        "assets/icons/fog_g.png",
        "assets/icons/belt_g.png"
    };
    altImagePaths = {
        "assets/icons/wheel_on.png",
        "assets/icons/brake_on.png",
        "assets/icons/abs_on.png", // Replace with your actual paths
        "assets/icons/med_on.png",
        "assets/icons/max_on.png",
        "assets/icons/fog_on.png",
        "assets/icons/belt_on.png"
    };

    defaultImagePaths = defaultImagePaths_array[0];
    // Load images into QPixmaps
    for (int j = 0; j < 4; j++)
    {
        for (const QString& path : defaultImagePaths_array[j]) {
            QPixmap pixmap(path);
            if (pixmap.isNull()) {
                qWarning() << "Failed to load default image:" << path;
            }
            defaultImages_array[j].append(pixmap);
        }
    }
    defaultImages = defaultImages_array[0];
    for (const QString& path : altImagePaths) {
        QPixmap pixmap(path);
        if (pixmap.isNull()) {
            qWarning() << "Failed to load alternate image:" << path;
        }
        altImages.append(pixmap);
    }

    // Create QLabel widgets for each image
    for (int i = 0; i < 6; ++i) {
        QLabel* label = new QLabel(this);
        label->setFixedSize(40, 40); // Optional: set a fixed size for the images
        //label->setScaledContents(true); // Ensure the image scales to fit the QLabel
        if (i < defaultImages.size()) {
            label->setPixmap(defaultImages[i]); // Set default image
        }
        imageLabels.append(label);
        layout->addWidget(label);
    }

    setLayout(layout);
    setMaximumWidth(250 * 2);
    setMinimumWidth(250 * 2);
}

TopBar::~TopBar() {}

bool    TopBar::setImageState(int index, bool state)
{
    if (index < 0 || index >= imageLabels.size()) {
        qWarning() << "Invalid index:" << index;
        return false;
    }

    // Set the image based on the state
    if (state) {
        imageLabels[index]->setPixmap(altImages[index]);
        return true;
    } else {
        imageLabels[index]->setPixmap(defaultImages[index]);
        return false;
    }
}

void    TopBar::changeColor(int  array_index)
{
    defaultImages = defaultImages_array[array_index];
    for (int i = 0; i < 6; ++i) {
        imageLabels[i]->setPixmap(defaultImages[i]);
    }
}
