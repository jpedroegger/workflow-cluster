# Arduino State Machine with FreeRTOS and CAN Bus

This project implements a state machine using FreeRTOS on an Arduino platform. The application communicates over a CAN bus using the MCP2515 module, processes incoming CAN messages to update states, and controls LEDs to reflect these states.

## Features
- **State Machine**: Handles different states for blinkers and LED stripe.
- **CAN Bus Communication**: Listens for CAN messages and updates states accordingly.
- **FreeRTOS Tasks**: Runs tasks for CAN message handling and LED blinking concurrently.

---

## File Structure
- **`setup()`**: Initializes serial communication, CAN settings, pins, and tasks.
- **`loop()`**: Empty because the application is fully managed by FreeRTOS tasks.
- **`lib.cpp`**: Contains task definitions and helper functions for state management and CAN communication.

---

## Dependencies
Make sure to install the following libraries:
- **Arduino_FreeRTOS**: Provides FreeRTOS capabilities for Arduino.
- **ArduinoLog**: A lightweight logging library.
- **MCP2515 Library**: For CAN bus communication.

---

## Pin Configuration
| Pin Name           | Function                 |
|--------------------|--------------------------|
| `LEFT_BLINKER_PIN` | Left blinker LED         |
| `RIGHT_BLINKER_PIN`| Right blinker LED        |
| `SENSOR_PIN`       | Input for speed sensor   |
| `CS_PIN` (Pin 9)   | Chip select for MCP2515  |

---

## How It Works
1. **Setup**:
   - Initializes serial communication and logging.
   - Configures the MCP2515 CAN module.
   - Creates FreeRTOS tasks for handling CAN messages and blinking LEDs.

2. **Tasks**:
   - **`handleCanFrames`**:
     - Listens for incoming CAN messages.
     - Updates state based on the message `can_id` and `data`.
   - **`blinkBlinkers`**:
     - Controls LED blinking based on the current state of the blinkers.

3. **Error Handling**:
   - Logs errors and halts the program by blinking both LEDs if critical errors occur.

---

## CAN Message Structure
- **Incoming CAN Frames**:
  - `can_id` 0x100: Updates blinker state (`data[0]`).
  - `can_id` 0x200: Updates LED stripe state (`data[0]`).
  - `can_id` 0x300: Sends speed readings back to the CAN bus.

- **Outgoing CAN Frame**:
  - `can_id` 0x200: Sends speed readings in `data[0]` (low byte) and `data[1]` (high byte).

---

## State Definitions
### Blinker States
| State      | Description                   |
|------------|-------------------------------|
| `IDLE`     | LEDs are off                  |
| `TURN_LEFT`| Left LED blinks               |
| `TURN_RIGHT`| Right LED blinks             |
| `WARNINGS` | Both LEDs blink alternately   |
| `FULL`     | Both LEDs are fully on        |

### LED Stripe States
| State   | Description       |
|---------|-------------------|
| `OFF`   | LEDs are off      |
| `ORANGE`| Orange color       |
| `BLUE`  | Blue color         |

