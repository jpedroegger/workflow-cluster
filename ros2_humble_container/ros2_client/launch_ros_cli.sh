#!/bin/bash
docker run -it \
  --name ros2_client \
  --rm \
  --net=host \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -e DISPLAY=$DISPLAY \
  -e QT_QPA_PLATFORM=xcb \
  --privileged \
  --device=/dev/dri:/dev/dri \
  -v /dev/shm:/dev/shm \
  --group-add video \
  ros2_client_image
