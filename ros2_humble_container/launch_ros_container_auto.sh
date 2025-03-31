#!/bin/bash
docker run -it \
  --name ros2_humble \
  --rm \
  --net=host \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -v /run/user/$(id -u)/wayland-0:/run/user/$(id -u)/wayland-0 \
  -e QT_QPA_PLATFORM=wayland \
  -e DISPLAY=$DISPLAY \
  -e WAYLAND_DISPLAY=$WAYLAND_DISPLAY \
  -e XDG_RUNTIME_DIR=/run/user/$(id -u) \
  -v /run/user/$(id -u):/run/user/$(id -u) \
  --privileged \
  --device=/dev/dri:/dev/dri \
  --device=/dev/i2c-1 \
  --device=/dev/input \
  -v /dev/shm:/dev/shm \
  -v /run/udev:/run/udev:ro \
  --group-add video \
  ros2_humble_image \
  /bin/bash -c "source /opt/ros/humble/setup.bash && source /root/ws/JetRacer/install/setup.bash && ros2 launch launch/JetRacer_auto_launch.py"

