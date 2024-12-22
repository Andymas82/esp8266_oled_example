#include <Wire.h>
#include "SSD1306Wire.h"
#include "images.h"

SSD1306Wire display(0x3c, D6, D5);

const unsigned char* frames[] = {
 epd_bitmap_frame_00_delay_0,
	epd_bitmap_frame_01_delay_0,
	epd_bitmap_frame_02_delay_0,
	epd_bitmap_frame_03_delay_0,
	epd_bitmap_frame_04_delay_0,
	epd_bitmap_frame_05_delay_0,
	epd_bitmap_frame_06_delay_0,
	epd_bitmap_frame_07_delay_0,
	epd_bitmap_frame_08_delay_0,
	epd_bitmap_frame_09_delay_0,
	epd_bitmap_frame_10_delay_0,
	epd_bitmap_frame_11_delay_0,
	epd_bitmap_frame_12_delay_0,
	epd_bitmap_frame_13_delay_0,
	epd_bitmap_frame_14_delay_0,
	epd_bitmap_frame_15_delay_0,
	epd_bitmap_frame_16_delay_0,
	epd_bitmap_frame_17_delay_0,
	epd_bitmap_frame_18_delay_0,
	epd_bitmap_frame_19_delay_0,
	epd_bitmap_frame_20_delay_0,
	epd_bitmap_frame_21_delay_0,
	epd_bitmap_frame_22_delay_0,
	epd_bitmap_frame_23_delay_0,
	epd_bitmap_frame_24_delay_0,
	epd_bitmap_frame_25_delay_0,
	epd_bitmap_frame_26_delay_0,
	epd_bitmap_frame_27_delay_0,
	epd_bitmap_frame_28_delay_0,
	epd_bitmap_frame_29_delay_0,
	epd_bitmap_frame_30_delay_0,
	epd_bitmap_frame_31_delay_0,
	epd_bitmap_frame_32_delay_0,
	epd_bitmap_frame_33_delay_0,
	epd_bitmap_frame_34_delay_0,
	epd_bitmap_frame_35_delay_0,
	epd_bitmap_frame_36_delay_0,
	epd_bitmap_frame_37_delay_0,
	epd_bitmap_frame_38_delay_0,
	epd_bitmap_frame_39_delay_0,
	epd_bitmap_frame_40_delay_0,
	epd_bitmap_frame_41_delay_0,
	epd_bitmap_frame_42_delay_0,
	epd_bitmap_frame_43_delay_0,
	epd_bitmap_frame_44_delay_0,
	epd_bitmap_frame_45_delay_0,
	epd_bitmap_frame_46_delay_0,
	epd_bitmap_frame_47_delay_0,
	epd_bitmap_frame_48_delay_0,
	epd_bitmap_frame_49_delay_0,
	epd_bitmap_frame_50_delay_0,
	epd_bitmap_frame_51_delay_0,
	epd_bitmap_frame_52_delay_0,
	epd_bitmap_frame_53_delay_0,
	epd_bitmap_frame_54_delay_0,
	epd_bitmap_frame_55_delay_0,
	epd_bitmap_frame_56_delay_0,
	epd_bitmap_frame_57_delay_0,
	epd_bitmap_frame_58_delay_0,
	epd_bitmap_frame_59_delay_0,
	epd_bitmap_frame_60_delay_0,
	epd_bitmap_frame_61_delay_0,
	epd_bitmap_frame_62_delay_0,
	epd_bitmap_frame_63_delay_0,
	epd_bitmap_frame_64_delay_0,
	epd_bitmap_frame_65_delay_0,
	epd_bitmap_frame_66_delay_0,
	epd_bitmap_frame_67_delay_0,
	epd_bitmap_frame_68_delay_0,
	epd_bitmap_frame_69_delay_0,
	epd_bitmap_frame_70_delay_0,
	epd_bitmap_frame_71_delay_0,
	epd_bitmap_frame_72_delay_0,
	epd_bitmap_frame_73_delay_0,
	epd_bitmap_frame_74_delay_0,
	epd_bitmap_frame_75_delay_0,
	epd_bitmap_frame_76_delay_0,
	epd_bitmap_frame_77_delay_0,
	epd_bitmap_frame_78_delay_0,
	epd_bitmap_frame_79_delay_0,
	epd_bitmap_frame_80_delay_0,
	epd_bitmap_frame_81_delay_0

  
};

const int numFrames = sizeof(frames) / sizeof(frames[0]);
int currentFrame = 0;

void setup() {
    Wire.begin();
    display.init();
    display.flipScreenVertically(); // Depending on your display setup
    display.setContrast(255); // Adjust the contrast value if needed
}

void loop() {
    display.clear();
    display.drawXbm(0, 12, 108, 57, frames[currentFrame]);
    display.display();

    delay(25); // Adjust the delay time as needed for animation speed

    currentFrame = (currentFrame + 1) % numFrames;
}
