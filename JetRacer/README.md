# Suggested Project Structure for JetRacer

## Overview

The JetRacer project is organized into a modular structure, where each package represents a ROS2 node encapsulating a specific aspect of the system. The architecture is divided into three main layers, each with its own responsibility:

- **Bus Interfaces**: Directly interact with hardware data buses (CAN, I2C).
- **Peripherals**: Communicate with the bus interfaces and manage device-specific logic.
- **Head Unit**: Coordinates the peripherals and handles higher-level logic.

```
JetRacer/
├── src/
│   ├── bus_interfaces/
│   │   ├── can_interface/
│   │   │   ├── CMakeLists.txt
│   │   │   ├── package.xml
│   │   │   ├── src/
│   │   │   └── include/
│   │   ├── i2c_interface/
│   │       ├── CMakeLists.txt
│   │       ├── package.xml
│   │       ├── src/
│   │       └── include/
│   ├── peripherals/
│   │   ├── oled_display/
│   │   │   ├── CMakeLists.txt
│   │   │   ├── package.xml
│   │   │   ├── src/
│   │   │   └── include/
│   │   ├── servo_motor/
│   │   │   ├── CMakeLists.txt
│   │   │   ├── package.xml
│   │   │   ├── src/
│   │   │   └── include/
│   │   ├── dc_motors/
│   │   │   ├── CMakeLists.txt
│   │   │   ├── package.xml
│   │   │   ├── src/
│   │   │   └── include/
│   │   ├── speed_sensor/
│   │       ├── CMakeLists.txt
│   │       ├── package.xml
│   │       ├── src/
│   │       └── include/
│   ├── head_unit/
│   │   ├── coordinator/
│   │   │   ├── CMakeLists.txt
│   │   │   ├── package.xml
│   │   │   ├── src/
│   │   │   └── include/
│   │   ├── infotainment/
│   │       ├── CMakeLists.txt
│   │       ├── package.xml
│   │       ├── src/
│   │       └── include/
├── CMakeLists.txt
└── colcon.meta
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
