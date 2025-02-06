#include "../includes/Blinkers.h"
#include <QHBoxLayout>


/**
 * @brief Constructs a Blinkers widget with the specified parameters.
 *
 * This constructor initializes the Blinkers widget, loads the appropriate images based on the
 * direction (dir), and sets up the layout and initial state of the widget.
 *
 * @param parent The parent widget.
 * @param dir The direction of the blinkers (left or right).
 * @param mode The initial mode of the blinkers.
 * @param x The x-coordinate of the widget's position.
 * @param y The y-coordinate of the widget's position.
 * @param width The width of the widget.
 * @param height The height of the widget.
 *
 * @note If the images fail to load, a warning message will be logged.
 */
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
        image1_array[0].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/left_p.png");
        image1_array[1].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/left_r.png");
        image1_array[2].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/left_i.png");
        image1_array[3].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/left_g.png");
        image2.load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/left_on.png");
        image1 = image1_array[counter];
    }
    else
    {
        image1_array[0].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/right_p2.png");
        image1_array[1].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/right_r.png");
        image1_array[2].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/right_i.png");
        image1_array[3].load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/right_g.png");
        image2.load("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/right_on.png");
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

/**
 * @brief Destroys the Blinkers widget.
 *
 * This destructor cleans up dynamically allocated resources.
 */
Blinkers::~Blinkers()
{

    delete imageLabel;
    delete toggleTimer;
}

/**
 * @brief Toggles between the two images to create a blinking effect.
 *
 * This method switches the displayed image and updates the imageLabel.
 * It is called periodically by the toggleTimer to create the blinking animation.
 */
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

/**
 * @brief Turns the blinkers on or off.
 *
 * This method starts or stops the blinking effect by controlling the toggleTimer. If on_off is true,
 * the timer is started, and the images toggle every 500 milliseconds. If on_off is false, the timer
 * is stopped, and the widget displays the default image .
 *
 * @param on_off If true, the blinkers are turned on; if false, they are turned off.
 */
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

/**
 * @brief Changes the color of the displayed image.
 *
 * This method updates the image1 to the image corresponding to the provided array_index in the
 * image1_array. The imageLabel is then updated to display the new image.
 *
 * @param array_index The index of the image in the image1_array.
 */
void Blinkers::changeColor(int array_index)
{
    image1 = image1_array[array_index];
    imageLabel->setPixmap(image1);
}

/**
 * @brief A Getter that returns the current blinking state of the widget.
 *
 * @return true if the blinkers are currently blinking, false otherwise.
 */
bool Blinkers::getBlinking() { return blinking; }

/**
 * @brief Returns the QTimer used for toggling the images.
 *
 * This method provides access to the toggleTimer, which controls the blinking interval.
 *
 * @return A pointer to the QTimer object.
 */
QTimer* Blinkers::getToggleTimer() { return toggleTimer; }
