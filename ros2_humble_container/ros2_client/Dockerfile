FROM arm64v8/ros:humble

# Install visualization tools and required Qt dependencies
RUN apt-get update && apt-get install -y \
    ros-humble-rqt \
    ros-humble-rqt-image-view \
    ros-humble-image-view \
    ros-humble-image-transport-plugins \
    ros-humble-rviz2 \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    libqt5gui5 \
    libqt5widgets5 \
    qtwayland5 \
    libxcb-xinerama0 \
    libxcb-icccm4 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-render-util0 \
    libxcb-xkb1 \
    libxkbcommon-x11-0 \
    && rm -rf /var/lib/apt/lists/*

# Set ROS Domain ID to match your main container
ENV ROS_DOMAIN_ID=4

# Create wrapper script to handle Qt platform selection
RUN echo '#!/bin/bash \n\
if [ -n "$WAYLAND_DISPLAY" ]; then \n\
  export QT_QPA_PLATFORM=wayland \n\
elif [ -n "$DISPLAY" ]; then \n\
  export QT_QPA_PLATFORM=xcb \n\
else \n\
  export QT_QPA_PLATFORM=offscreen \n\
fi \n\
exec "$@"' > /usr/local/bin/qt-launcher && \
    chmod +x /usr/local/bin/qt-launcher

# Set up workspace directory
WORKDIR /root/ws

# Entry point
CMD ["/bin/bash", "-c", "source /opt/ros/humble/setup.bash && bash"]
