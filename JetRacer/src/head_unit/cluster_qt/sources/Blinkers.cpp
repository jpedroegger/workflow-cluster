#include "../includes/Blinkers.h"
#include <QHBoxLayout>

Blinkers::Blinkers(QWidget* parent, std::string dir, std::string mode, int x,
                   int y, int width, int height)
    : QWidget(parent), isImage1Visible(true), blinking(false)
{

    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);
    blinking = false;
    isImage1Visible = true;
    toggleTimer = NULL;
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

    imageLabel->setPixmap(image1);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);

    setLayout(layout);
    setMaximumWidth(105);
    setMinimumWidth(105);
    setGeometry(x, y, width, height);
}

Blinkers::~Blinkers()
{

    delete imageLabel;
    delete toggleTimer;
}

void Blinkers::toggleImage()
{
    // Toggle between the two images
    if (isImage1Visible)
    {
        imageLabel->setPixmap(image2);
    }
    else
    {
        imageLabel->setPixmap(image1);
    }

    // Flip the visibility flag
    isImage1Visible = !isImage1Visible;
}

void Blinkers::turnOnBlinkers(bool on_off)
{
    if (on_off == true)
    {
        if (!blinking)
        {
            toggleTimer = new QTimer(this);
            connect(toggleTimer, &QTimer::timeout, this,
                    &Blinkers::toggleImage);
            toggleTimer->start(500);
            blinking = true;
        }
    }
    else
    {
        if (toggleTimer)
            toggleTimer->stop();
        if (isImage1Visible)
            isImage1Visible = false;
        imageLabel->setPixmap(image1);
        blinking = false;
    }
}

void Blinkers::changeColor(int array_index)
{
    image1 = image1_array[array_index];
    imageLabel->setPixmap(image1);
}

bool Blinkers::get_blinking() { return blinking; }

QTimer* Blinkers::getToggleTimer() { return toggleTimer; }
