#include "../includes/TopBar.h"
#include <iostream>

TopBar::TopBar(QWidget* parent, int x, int y, int width, int height) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    layout->setSpacing(1);
    layout->setContentsMargins(0, 0, 0, 0);
    setGeometry(x, y, width, height);

    Color color = Color();
    int index = color.counter;
    default_image_paths_array[0] = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_p.png"
    };
    default_image_paths_array[1] = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_r.png"
    };
    default_image_paths_array[2] = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_i.png"
    };
    default_image_paths_array[3] = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_g.png"
    };
    alt_image_paths = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_on.png"
    };

    default_image_paths = default_image_paths_array[index];

    for (int j = 0; j < 4; j++)
    {
        for (const QString& path : default_image_paths_array[j]) {
            QPixmap pixmap(path);
            if (pixmap.isNull()) {
                qWarning() << "Failed to load default image:" << path;
            }
            default_images_array[j].append(pixmap);
        }
    }
    default_images = default_images_array[0];
    for (const QString& path : alt_image_paths) {
        QPixmap pixmap(path);
        if (pixmap.isNull()) {
            qWarning() << "Failed to load alternate image:" << path;
        }
        alt_images.append(pixmap);
    }


    for (int i = 0; i < 6; ++i) {
        QLabel* label = new QLabel(this);
        label->setFixedSize(40, 40);
    
        if (i < default_images.size()) {
            label->setPixmap(default_images[i]);
        }
        image_labels.append(label);
        layout->addWidget(label);
    }

    setLayout(layout);
    setMaximumWidth(250 * 2);
    setMinimumWidth(250 * 2);
}

TopBar::~TopBar() {}

bool    TopBar::setImageState(int index, bool state)
{
    if (index < 0 || index >= image_labels.size()) {
        qWarning() << "Invalid index:" << index;
        return false;
    }


    if (state) {
        image_labels[index]->setPixmap(alt_images[index]);
        return true;
    } else {
        image_labels[index]->setPixmap(default_images[index]);
        return false;
    }
}

void    TopBar::changeColor(int  array_index)
{
    default_images = default_images_array[array_index];
    for (int i = 0; i < 6; ++i) {
        image_labels[i]->setPixmap(default_images[i]);
    }
}
