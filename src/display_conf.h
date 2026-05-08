#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <lvgl.h>
#include <LovyanGFX.hpp>
#include <SPI.h>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>

class LGFX : public lgfx::LGFX_Device {
public:
	LGFX() {
		{
			auto cfg = _bus_instance.config();
			cfg.panel = &_panel_instance;

			cfg.pin_d0 = GPIO_NUM_15;
			cfg.pin_d1 = GPIO_NUM_7;
			cfg.pin_d2 = GPIO_NUM_6;
			cfg.pin_d3 = GPIO_NUM_5;
			cfg.pin_d4 = GPIO_NUM_4;

			cfg.pin_d5 = GPIO_NUM_9;
			cfg.pin_d6 = GPIO_NUM_46;
			cfg.pin_d7 = GPIO_NUM_3;
			cfg.pin_d8 = GPIO_NUM_8;
			cfg.pin_d9 = GPIO_NUM_16;
			cfg.pin_d10 = GPIO_NUM_1;

			cfg.pin_d11 = GPIO_NUM_14;
			cfg.pin_d12 = GPIO_NUM_21;
			cfg.pin_d13 = GPIO_NUM_47;
			cfg.pin_d14 = GPIO_NUM_48;
			cfg.pin_d15 = GPIO_NUM_45;

			cfg.pin_henable = GPIO_NUM_41;
			cfg.pin_vsync = GPIO_NUM_40;
			cfg.pin_hsync = GPIO_NUM_39;
			cfg.pin_pclk = GPIO_NUM_0;
			cfg.freq_write = 15000000;

			cfg.hsync_polarity = 0;
			cfg.hsync_front_porch = 40;
			cfg.hsync_pulse_width = 48;
			cfg.hsync_back_porch = 40;

			cfg.vsync_polarity = 0;
			cfg.vsync_front_porch = 1;
			cfg.vsync_pulse_width = 31;
			cfg.vsync_back_porch = 13;

			cfg.pclk_active_neg = 1;
			cfg.de_idle_high = 0;
			cfg.pclk_idle_high = 0;

			_bus_instance.config(cfg);
		}

		{
			auto cfg = _panel_instance.config();
			cfg.memory_width = 800;
			cfg.memory_height = 480;
			cfg.panel_width = 800;
			cfg.panel_height = 480;
			cfg.offset_x = 0;
			cfg.offset_y = 0;
			_panel_instance.config(cfg);
		}

		_panel_instance.setBus(&_bus_instance);
		setPanel(&_panel_instance);
	}

private:
	lgfx::Bus_RGB _bus_instance;
	lgfx::Panel_RGB _panel_instance;
};

static LGFX lcd;

#include "touch.h"

namespace display_conf {

constexpr uint8_t kBacklightPin = 2;
constexpr uint8_t kBacklightChannel = 1;
constexpr uint16_t kScreenBufferDivisor = 15;
constexpr uint32_t kBacklightPwmFrequency = 300;
constexpr uint8_t kBacklightPwmResolution = 8;
constexpr uint8_t kBacklightFullBrightness = 255;

static lv_disp_draw_buf_t draw_buffer;
static lv_color_t draw_buffer_pixels[800 * 480 / kScreenBufferDivisor];
static lv_disp_drv_t display_driver;
static lv_indev_drv_t input_driver;

static void showStartupMessage() {
	lcd.fillScreen(TFT_BLACK);
	lcd.setTextSize(2);
	lcd.setTextColor(TFT_WHITE);
	lcd.setCursor(10, 10);
	lcd.println("CrowPanel ESP32 S3 7.0 inch using EEZ Studio and LVGL");
	lcd.println("by Arvinth Krishna G");
	lcd.println("Go to github.com/Arvinth-Krishna");
	lcd.println("EEZ_Studio_CrowPanel_ESP32_S3_7.0 for more details");
}

static void flushDisplay(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
	const uint32_t width = area->x2 - area->x1 + 1;
	const uint32_t height = area->y2 - area->y1 + 1;

	lcd.pushImageDMA(area->x1, area->y1, width, height,
									 (lgfx::rgb565_t *)&color_p->full);
	lv_disp_flush_ready(disp);
}

static void readTouch(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
	(void)indev_driver;

	if (touch_has_signal() && touch_touched()) {
		data->state = LV_INDEV_STATE_PR;
		data->point.x = touch_last_x;
		data->point.y = touch_last_y;
	} else {
		data->state = LV_INDEV_STATE_REL;
	}

	delay(15);
}

static void initBacklight() {
	ledcSetup(kBacklightChannel, kBacklightPwmFrequency, kBacklightPwmResolution);
	ledcAttachPin(kBacklightPin, kBacklightChannel);
	ledcWrite(kBacklightChannel, kBacklightFullBrightness);

	pinMode(kBacklightPin, OUTPUT);
	digitalWrite(kBacklightPin, LOW);
	delay(500);
	digitalWrite(kBacklightPin, HIGH);
}

static void init() {


	lcd.begin();
	showStartupMessage();
	delay(200);

	lv_init();
	touch_init();

	const uint32_t screen_width = lcd.width();
	const uint32_t screen_height = lcd.height();

	lv_disp_draw_buf_init(&draw_buffer, draw_buffer_pixels, nullptr,
												screen_width * screen_height / kScreenBufferDivisor);

	lv_disp_drv_init(&display_driver);
	display_driver.hor_res = screen_width;
	display_driver.ver_res = screen_height;
	display_driver.flush_cb = flushDisplay;
	display_driver.draw_buf = &draw_buffer;
	lv_disp_drv_register(&display_driver);

	lv_indev_drv_init(&input_driver);
	input_driver.type = LV_INDEV_TYPE_POINTER;
	input_driver.read_cb = readTouch;
	lv_indev_drv_register(&input_driver);

	initBacklight();
}

static void update() {
  
	lv_timer_handler();
}

} // namespace display_conf
