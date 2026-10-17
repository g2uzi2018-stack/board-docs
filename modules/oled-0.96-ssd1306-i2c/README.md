# 0.96" I2C OLED 128×64

![实物](photo.jpg)

4 针 `GND VCC SCL SDA`（排序以丝印为准，有的版本 VCC 在前）。驱动 IC 一般是 **SSD1306**（待确认；少数同款为 SH1106，显示偏移 2 列就是 SH1106）。

## 引脚

| 引脚 | 说明 |
|---|---|
| VCC | 3.3–5 V（板载 LDO 和电荷泵；待确认）|
| GND | 地 |
| SCL / SDA | I2C，板载上拉（上拉到模块内部 3.3 V，一般可直接接 ESP32，待确认）|

## 地址与电气

- I2C 地址：`0x3C`（背面电阻改焊可改成 `0x3D`）。与 PCF8591 的 `0x48` 不冲突，可共用总线。
- I2C 速率 400 kHz 没问题。
- 接 ESP32-S3 建议 VCC 用 3V3，最省心。

## 接 YD-ESP32-S3

| 模块 | ESP32-S3 |
|---|---|
| SDA | GPIO8 |
| SCL | GPIO9 |
| VCC / GND | 3V3 / G |

## 库

- Arduino：[U8g2](https://github.com/olikraus/u8g2)（SSD1306/SH1106 都支持，中文字库也有），或 [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)（`Wire.begin(8, 9)` 后 `display.begin(SSD1306_SWITCHCAPVCC, 0x3C)`）。
- ESP-IDF：`esp_lcd` 自带 SSD1306 面板驱动（`esp_lcd_new_panel_ssd1306`），见 [LCD 文档](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/api-reference/peripherals/lcd/index.html)。

## 资料

- SSD1306 数据手册（Solomon Systech 原版无稳定官方直链，以下为 Adafruit 镜像）：https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf
