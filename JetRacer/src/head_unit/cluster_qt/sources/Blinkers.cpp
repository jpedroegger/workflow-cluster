#include "../includes/Blinkers.h"
#include <QHBoxLayout>

Blinkers::Blinkers(QWidget* parent, std::string dir, std::string mode, int x,
                   int y, int width, int height)
    : QWidget(parent), is_image1_visible(true), blinking(false)
{

    image_label = new QLabel(this);
    image_label->setAlignment(Qt::AlignCenter);
    blinking = false;
    is_image1_visible = true;
    toggle_timer = NULL;
    Color color1 = Color();
    int counter = color1.counter;
    if (dir == "left")
    {
        image1_array[0].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/"
                             "head_unit/cluster_qt/assets/icons/left_p.png");
        image1_array[1].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/"
                             "head_unit/cluster_qt/assets/icons/left_r.png");
        image1_array[2].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/"
                             "head_unit/cluster_qt/assets/icons/left_i.png");
        image1_array[3].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/"
                             "head_unit/cluster_qt/assets/icons/left_g.png");
        image2.load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/"
                    "cluster_qt/assets/icons/left_on.png");
        image1 = image1_array[counter];
    }
    else
    {
        image1_array[0].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/"
                             "head_unit/cluster_qt/assets/icons/right_p2.png");
        image1_array[1].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/"
                             "head_unit/cluster_qt/assets/icons/right_r.png");
        image1_array[2].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/"
                             "head_unit/cluster_qt/assets/icons/right_i.png");
        image1_array[3].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/"
                             "head_unit/cluster_qt/assets/icons/right_g.png");
        image2.load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/"
                    "cluster_qt/assets/icons/right_on.png");
        image1 = image1_array[counter];
    }

    if (image1.isNull() || image2.isNull())
    {
        qWarning() << "Failed to load images.";
    }

    image_label->setPixmap(image1);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(image_label);

    setLayout(layout);
    setMaximumWidth(105);
    setMinimumWidth(105);
    setGeometry(x, y, width, height);
}

Blinkers::~Blinkers()
{

    delete image_label;
    delete toggle_timer;
}

void Blinkers::toggleImage()
{
    if (is_image1_visible)
        image_label->setPixmap(image2);
    else
        image_label->setPixmap(image1);
    is_image1_visible = !is_image1_visible;
}

void Blinkers::turnOnBlinkers(bool on_off)
{
    if (on_off == true)
    {
        if (!blinking)
        {
            toggle_timer = new QTimer(this);
            connect(toggle_timer, &QTimer::timeout, this,
                    &Blinkers::toggleImage);
            toggle_timer->start(500);
            blinking = true;
        }
    }
    else
    {
        if (toggle_timer)
            toggle_timer->stop();
        if (is_image1_visible)
            is_image1_visible = false;
        image_label->setPixmap(image1);
        blinking = false;
    }
}

void Blinkers::changeColor(int array_index)
{
    image1 = image1_array[array_index];
    image_label->setPixmap(image1);
}

bool Blinkers::get_blinking() { return blinking; }

QTimer* Blinkers::getToggleTimer() { return toggle_timer; }
