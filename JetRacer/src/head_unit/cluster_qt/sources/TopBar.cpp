#include "../includes/TopBar.h"


/**
 * @brief Constructs a TopBar widget with the specified parameters.
 *
 * This constructor initializes the top bar widget, sets its geometry, and loads default and alternate
 * images for the icons. The widget displays a horizontal layout of icons, which can be toggled between
 * default and alternate states.
 *
 * @param parent The parent widget.
 * @param x The x-coordinate of the widget's position.
 * @param y The y-coordinate of the widget's position.
 * @param width The width of the widget.
 * @param height The height of the widget.
 */
TopBar::TopBar(QWidget* parent, int x, int y, int width, int height) : QWidget(parent)
{
    // Initialize layout
    layout = new QHBoxLayout(this);
    layout->setSpacing(1); // Optional: adjust spacing between images
    layout->setContentsMargins(0, 0, 0, 0); // Optional: adjust margins
    setGeometry(x, y, width, height);

    // Create default and alternate images
    Color color = Color();
    int index = color.counter;
    defaultImagePaths_array[0] = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_p.png", // Replace with your actual paths
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_p.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_p.png"
    };
    defaultImagePaths_array[1] = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_r.png", // Replace with your actual paths
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_r.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_r.png"
    };
    defaultImagePaths_array[2] = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_i.png", // Replace with your actual paths
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_i.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_i.png"
    };
    defaultImagePaths_array[3] = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_g.png", // Replace with your actual paths
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_g.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_g.png"
    };
    altImagePaths = {
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/wheel_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brake_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/abs_on.png", // Replace with your actual paths
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/med_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/max_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/fog_on.png",
        "/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/belt_on.png"
    };

    defaultImagePaths = defaultImagePaths_array[index];
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

/**
 * @brief Destroys the TopBar widget.
 *
 * This destructor cleans up any resources used by the widget.
 */
TopBar::~TopBar() {}

/**
 * @brief Sets the state of an image in the top bar.
 *
 * This method toggles the image at the specified index between its default and alternate states.
 *
 * @param index The index of the image to update.
 * @param state If true, the alternate image is displayed; if false, the default image is displayed.
 * @return true if the image was updated successfully, false if the index is invalid.
 */
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

/**
 * @brief Changes the color scheme of the top bar icons.
 *
 * This method updates the default images based on the provided array index, allowing the icons to
 * reflect a new color scheme.
 *
 * @param array_index The index of the color scheme.
 */
void    TopBar::changeColor(int  array_index)
{
    defaultImages = defaultImages_array[array_index];
    for (int i = 0; i < 6; ++i) {
        imageLabels[i]->setPixmap(defaultImages[i]);
    }
}
