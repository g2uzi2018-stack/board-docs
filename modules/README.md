# 小模块资料（配合 YD-ESP32-S3 使用）

常见淘宝小模块的引脚、电平、接线和库。照片是实物（已压缩）。标「待确认」的条目是照片和公开资料都没法确定的，以实测或卖家资料为准。

| 目录 | 模块 | 接口 | 主芯片 |
|---|---|---|---|
| [max485-rs485](max485-rs485/README.md) | TTL 转 RS-485 | UART | MAX485 |
| [pcf8591-hw011](pcf8591-hw011/README.md) | AD/DA 模块 HW-011 | I2C | PCF8591 |
| [w5500-ethernet](w5500-ethernet/README.md) | 以太网模块 | SPI | W5500 |
| [tft-2.8-ili9341-spi](tft-2.8-ili9341-spi/README.md) | 2.8" TFT 240×320 + 电阻触摸 + SD 卡 | SPI | ILI9341（待确认）+ XPT2046 类 |
| [oled-0.96-ssd1306-i2c](oled-0.96-ssd1306-i2c/README.md) | 0.96" OLED 128×64 | I2C | SSD1306（待确认）|

## 全部模块同时接到 YD-ESP32-S3 的推荐 GPIO 分配

原则：避开 GPIO0/3/45/46（strapping 引脚）、GPIO19/20（USB）、GPIO43/44（UART0 下载口）、GPIO35–37（N16R8 的八线 PSRAM 占用）、GPIO48（板载 RGB）。引脚位置见 [`boards/yd-esp32-s3/00-essential/PINOUT.md`](../boards/yd-esp32-s3/00-essential/PINOUT.md)。

| 功能 | GPIO | 用于 |
|---|---|---|
| I2C SDA / SCL | 8 / 9 | OLED、PCF8591（共用一条总线，地址不冲突）|
| SPI SCK / MOSI / MISO | 12 / 11 / 13 | TFT、触摸、SD 卡、W5500 共用 SPI2(FSPI) |
| TFT CS / DC / RST / LED | 10 / 14 / 21 / 47 | TFT |
| 触摸 T_CS / T_IRQ | 1 / 2 | XPT2046 |
| SD_CS | 42 | TFT 背面 SD 卡座 |
| W5500 CS / INT / RST | 41 / 40 / 39 | W5500 |
| UART1 TX / RX | 17 / 18 | MAX485 DI / RO |
| RS-485 DE+RE | 16 | MAX485 收发方向 |

注：GPIO39–42 是 JTAG 引脚，用 USB-JTAG（内置）调试时不受影响；如果要外接 JTAG 调试器，把这几个换成 GPIO4–7。W5500 跑高速 SPI 时，也可以单独开一条 SPI3 给它，减少和屏幕抢总线。

**通用电平提醒**：ESP32-S3 的 GPIO 是 3.3 V，**不耐 5 V**。下面凡是模块用 5 V 供电的，都要看它的输出引脚会不会把 5 V 送进 ESP32。
