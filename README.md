# 💡 ESP32 FreeRTOS Blink Task

This repository contains a simple FreeRTOS project for the ESP32 microcontroller that blinks an onboard LED. The project is developed using **PlatformIO** in **Visual Studio Code**.

## 📄 Project Description

This is a beginner-friendly project demonstrating the use of a FreeRTOS task to control a GPIO pin. A single task, `blinkLedTask`, is created to toggle an LED's state with a 1-second delay, creating a continuous blinking effect.

## ✨ Key Features

* **FreeRTOS Task:** Utilizes a dedicated FreeRTOS task to manage the blinking logic. ⚙️

* **GPIO Control:** Toggles an LED connected to a specific GPIO pin (GPIO2). 🔌

* **PlatformIO:** Built and managed using the PlatformIO ecosystem, ensuring cross-platform compatibility and ease of use. 💻

* **Task Scheduling:** Demonstrates the use of `vTaskDelay` for non-blocking time delays within a task. ⏱️

## ✅ Prerequisites

To compile and upload this project, you need to have the following installed:

* **Visual Studio Code** 🖥️

* **PlatformIO Extension for VS Code** 🚀

## 💻 Hardware Requirements

* **ESP32 Development Board:** Any standard ESP32 board will work. 🤖

* **LED:** An LED is typically required, though many ESP32 boards have an onboard LED connected to GPIO2.

* **Resistor:** A current-limiting resistor (e.g., 220Ω) if connecting an external LED.

## ▶️ Getting Started

1.  **Clone the repository:**

    ```
    git clone [your_repo_url]
    cd esp32-freertos-blink
    ```

2.  **Open in VS Code:** Open the project folder in Visual Studio Code.

3.  **Build:** In the PlatformIO sidebar, click on "Build" to compile the project.

4.  **Upload:** Connect your ESP32 board to your computer via USB. In the PlatformIO sidebar, click on "Upload" to flash the compiled firmware to the board. ⚡

## 👨‍💻 Code Overview

The core logic is contained within `main.c`.

### 📁 `main.c`
```c++
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Define the GPIO pin for the LED
#define LED_GPIO 2

// Task function to blink the LED
void blinkLedTask(void* parameters){
    while(1){
        // Turn the LED on
        gpio_set_level(LED_GPIO, 1);
        // Wait for 1000 milliseconds (1 second)
        vTaskDelay(pdMS_TO_TICKS(1000));
        // Turn the LED off
        gpio_set_level(LED_GPIO, 0);
        // Wait for 1000 milliseconds (1 second)
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

// Main application entry point
void app_main() {
    // Set the GPIO pin as an output
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    // Create the task and pin it to core 1
    xTaskCreatePinnedToCore(blinkLedTask, "blink_task", 2048, NULL, 5, NULL, 1);
}
```

### 📝 Key Functions Explained

* `gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);`: Configures GPIO2 as an output pin.

* `xTaskCreatePinnedToCore(...);`: Creates a new FreeRTOS task.

    * `blinkLedTask`: The function that the task will execute.

    * `"blink_task"`: The name of the task for debugging.

    * `2048`: The stack size (in bytes) for the task.

    * `NULL`: No parameters are passed to the task.

    * `5`: The priority of the task.

    * `NULL`: No handle to the task is returned.

    * `1`: The task is pinned to CPU core 1.

* `vTaskDelay(pdMS_TO_TICKS(1000));`: Puts the task to sleep for 1000 milliseconds, allowing other tasks to run. `pdMS_TO_TICKS` is a macro that converts milliseconds to FreeRTOS tick counts.
