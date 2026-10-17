# 2.8" TFT SPI 240×320 V1.2（红板，带触摸 + SD 卡）

![实物背面](photo.jpg)

背面丝印 `2.8 TFT SPI 240X320 V1.2`。常见同款（红板、14 针）驱动为 **ILI9341**（本板驱动 IC 在 FPC 内，看不到，**待确认**，初始化失败可以试 ST7789），电阻触摸控制器为 XPT2046 或兼容芯片。右下 4 针为 SD 卡座。

## 引脚

| 引脚 | 说明 |
|---|---|
| VCC | 3.3–5 V（板载 LDO，丝印 U1；待确认）|
| GND | 地 |
| CS | LCD 片选 |
| RESET | LCD 复位，低有效 |
| DC | 数据/命令 |
| SDI(MOSI) | LCD 数据输入 |
| SCK | SPI 时钟 |
| LED | 背光，高电平亮（有限流电阻；可直接接 3V3 常亮）|
| SDO(MISO) | LCD 数据输出（读屏用，可不接）|
| T_CLK / T_CS / T_DIN / T_DO / T_IRQ | 触摸 SPI + 触摸中断（低有效）|
| SD_CS / SD_MOSI / SD_MISO / SD_SCK | SD 卡 SPI |

## 电气

- **信号电平按 3.3 V**：这类板子 VCC 端有 LDO，但信号线一般直通屏幕 IC（不耐 5 V）。ESP32-S3 本来就是 3.3 V，直接接即可。
- LCD SPI 模式 0，ILI9341 写入常用 40 MHz（杜邦线建议 20–27 MHz）；XPT2046 时钟需低（≤2 MHz）。
- 触摸、SD、LCD 可以共用一条 SPI（SCK/MOSI/MISO 并联），各自独立 CS。

## 接 YD-ESP32-S3（共用 SPI2）

| 模块 | ESP32-S3 |
|---|---|
| SCK、T_CLK、SD_SCK | GPIO12 |
| SDI(MOSI)、T_DIN、SD_MOSI | GPIO11 |
| SDO(MISO)、T_DO、SD_MISO | GPIO13 |
| CS | GPIO10 |
| DC | GPIO14 |
| RESET | GPIO21 |
| LED | GPIO47（或 3V3）|
| T_CS / T_IRQ | GPIO1 / GPIO2 |
| SD_CS | GPIO42 |
| VCC / GND | 3V3 / G |

## 库

- Arduino：[TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)（`User_Setup.h` 选 `ILI9341_DRIVER`，填上表引脚，`TOUCH_CS 1`，自带 XPT2046 触摸校准）；或 Adafruit_ILI9341 + [XPT2046_Touchscreen](https://github.com/PaulStoffregen/XPT2046_Touchscreen)；LVGL 做 UI。
- ESP-IDF：[esp_lcd](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/api-reference/peripherals/lcd/index.html) + 组件 [esp_lcd_ili9341](https://components.espressif.com/components/espressif/esp_lcd_ili9341)；触摸用 `esp_lcd_touch_xpt2046` 组件。

## 资料

- ILI9341 数据手册（Ilitek 原版无稳定官方直链，以下为 Adafruit 镜像）：https://cdn-shop.adafruit.com/datasheets/ILI9341.pdf
- XPT2046 数据手册：待补（芯茂微官方直链未确认）。
