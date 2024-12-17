# Suggested Project Structure for JetRacer

## Overview

The JetRacer project is organized into a modular structure, where each package represents a ROS2 node encapsulating a specific aspect of the system. The architecture is divided into three main layers, each with its own responsibility:

- **Bus Interfaces**: Directly interact with hardware via different protocols (CAN, I2C).
- **Peripherals**: Communicate with the bus interfaces and manage device-specific logic.
- **Head Unit**: Coordinates the peripherals and handles higher-level logic.

```
├── bus_interfaces
│   ├── can_interface
│   └── i2c_interface
├── drivers
│   ├── custom_msgs
│   ├── ina219_driver
│   ├── pca9685_driver
│   └── ssd1306_driver
├── head_unit
│   ├── display_routine
│   └── teleop
├── peripherals
│   ├── battery
│   ├── camera
│   ├── dc_motors
│   ├── oled_display
│   ├── servo_motor
│   └── speed_sensor
└── tests
    └── i2c_peripheral_stress_test
```

## Layered Architecture

The project structure follows a clear layered architecture that helps isolate responsibilities and ensures modularity. The three main layers are:

### 1. **Bus Interfaces (can_interface, i2c_interface)**
These packages manage the direct interaction with hardware data buses. They are the closest to the hardware and abstract the communication with physical devices such as CAN and I2C interfaces.  
- **Responsibility**: Communicate with hardware via data buses (CAN, I2C).  
- **ROS2 Mechanism**: Provide services or topics for peripheral nodes to interact with hardware.

### 2. **Peripherals (oled_display, servo, dc_motors)**
Peripherals interact with bus interfaces using ROS2 topics (for CAN read operations) and services (for I2C read/write operations). Each peripheral package encapsulates logic for controlling specific devices such as displays, motors, or servos.  
- **Responsibility**: Manage device-specific logic and communicate with bus interfaces.  
- **ROS2 Mechanism**: Subscribe to topics or call services to read/write data via bus interfaces.

### 3. **Head Unit (coordinator, infotainment)**
The head unit represents the higher-level logic of the system, coordinating the operation of peripherals and providing user interaction functionality (e.g., infotainment system, control coordination).  
- **Responsibility**: Coordinate and manage the operation of peripherals.  
- **ROS2 Mechanism**: Provide high-level functionalities and user interactions through nodes that communicate with peripheral nodes.

## Modularity and Separation of Concerns

This structure ensures that:

- **Bus Interfaces**: Abstraction of hardware communication for flexibility and scalability.
- **Peripherals**: Device-specific logic, simplifying testing and debugging.
- **Head Unit**: Higher-level coordination and user interaction, ensuring easy maintenance and extendability.

By maintaining a clear separation of concerns, the architecture enhances system flexibility, modularity, and ease of maintenance.

## Build Instructions

To build the JetRacer project, follow these steps:

1. Open a terminal and navigate to the root directory of the project:
    ```bash
    cd JetRacer
    ```

2. Build the project using `colcon`:
    ```bash
    colcon build --symlink-install
    ```

This will compile the source code and set up the appropriate environment for running the nodes.

3. Execute thee launch script
```
	ros2 lauch launch/JetRacer_launch.py
```

4. Open a terminal to launch the rqt console and start playing with topics, or directly publish into topics

```
	rqt
```
OR
```
	ros2 topic list
	ros2 topic pub cmd_display custom_msgs/Display '{line1: "Hello world"}' --once
```
