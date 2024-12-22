
# ESP8266 OLED Animation Project

This project demonstrates how to play an animation on an OLED display using the `SSD1306Wire` library for ESP8266/ESP32. The animation consists of a series of XBM images displayed sequentially on the screen.

## Requirements

Before starting, ensure you have the following:

- **Microcontroller**: ESP8266 or ESP32
- **Display**: OLED display with 108x57 px resolution supporting I2C
- **Software**:
  - Arduino IDE (with necessary libraries installed)
  - Libraries:
    - `SSD1306Wire` for OLED display handling

## Setup

1. Install the **SSD1306Wire** library via the Arduino IDE:
   - Go to `Tools` → `Manage Libraries...`
   - Search for `SSD1306Wire` and install it.

2. Connect the OLED display to the microcontroller:
   - SDA → D6
   - SCL → D5
   - Power and ground to the corresponding pins.

## Code

The project consists of two files:

### `main.ino`

```cpp
#include <Wire.h>
#include "SSD1306Wire.h"
#include "images.h"

SSD1306Wire display(0x3c, D6, D5);

const unsigned char* frames[] = {
    epd_bitmap_frame_00_delay_0,
    epd_bitmap_frame_01_delay_0,
    // ... other frames
    epd_bitmap_frame_81_delay_0
};

const int numFrames = sizeof(frames) / sizeof(frames[0]);
int currentFrame = 0;

void setup() {
    Wire.begin();
    display.init();
    display.flipScreenVertically(); // Flip the screen (optional)
    display.setContrast(255); // Set maximum contrast
}

void loop() {
    display.clear();
    display.drawXbm(0, 0, 108, 57, frames[currentFrame]);
    display.display();

    currentFrame = (currentFrame + 1) % numFrames;
    delay(100); // Delay between frames (adjust as needed)
}
```

### `images.h`

This file contains the XBM image definitions used in the animation. Each frame is represented as a byte array. Ensure the dimensions of the images match the screen resolution (108x57 px).

```cpp
#pragma once

const unsigned char epd_bitmap_frame_00_delay_0[] PROGMEM = {
    // XBM data for frame 0
};

const unsigned char epd_bitmap_frame_01_delay_0[] PROGMEM = {
    // XBM data for frame 1
};

// ... other frames
const unsigned char epd_bitmap_frame_81_delay_0[] PROGMEM = {
    // XBM data for frame 81
};
```

## How to Use

1. Open the `main.ino` file in Arduino IDE.
2. Add your `images.h` file in the same folder as the `.ino` file.
3. Connect your microcontroller and upload the sketch.
4. The animation will play on the OLED display.

## Customization

- **Frame Delay**: Adjust the `delay(100);` value in the `loop()` function for faster or slower animations.
- **Screen Resolution**: Ensure the images in `images.h` match the resolution of your OLED screen.

## Youtube

Youtube - https://www.youtube.com/shorts/l9-YgdeKRhc
