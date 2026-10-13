# YD-ESP32-S3 必要信息

板卡：**源地 VCC-GND YD-ESP32-S3**（模组 ESP32-S3-WROOM-1）。  
双 Type-C：一侧 **CH343P 串口**，一侧 **ESP32-S3 原生 USB OTG**（GPIO19/20）。

## 本目录文件

| 文件 | 用途 |
|------|------|
| `README_zh.md` | 先看这个 |
| `pinout.jpg` | **官方引脚图**（来自 vcc-gnd `IMG/img11.jpg`）|
| `PINOUT.md` | 排针对照表 |
| `board_photo.png` / `board_overview.png` | 认板 |
| `block_diagram.png` | 功能框图 |
| `schematic_v1.4.pdf` | 板级原理图（与官方仓库 SHA 一致，当前正版 **V1.4**）|
| `mechanical_metric.pdf` / `mechanical_inch.pdf` | 结构尺寸 |
| `esp32-s3-wroom-1_datasheet_en.pdf` / `_cn.pdf` | 乐鑫模组手册 |

未收录：MicroPython 固件包、下载工具安装包、Altium 源文件（官方仓库有 `.PcbDoc`，体积大）。

## 两个 Type-C 怎么用

1. **CH343P 口**：烧录 + `Serial` 日志，最省心。
2. **原生 USB 口**：USB Device / OTG / JTAG；固件异常时可按住 BOOT 再按 RST 进下载模式。

## 关键 GPIO

| 功能 | GPIO |
|------|-----:|
| BOOT | 0 |
| USB D− / D+ | 19 / 20 |
| UART0 TX / RX | 43 / 44 |
| RGB LED (WS2812) | 48 |

外部勿用（八线 Flash/PSRAM）：**35、36、37**。启动相关慎用：0、45、46。

## 确认你手上的容量 SKU

1. 看 WROOM 金属盖丝印（常见 `N16R8`）。
2. 烧 [`../examples/arduino/03_flash_psram_check`](../examples/arduino/03_flash_psram_check/)。
3. 再设 Arduino / ESP-IDF 的 Flash 与 PSRAM。

## 上电注意

1. 先单独 USB，不接外设。
2. 万用表确认 3V3 / 5V / GND（克隆板有过 5V 脚异常反馈）。
3. 不清楚跳线焊盘（RGB / IN-OUT / USB-OTG）含义前不要短接。
4. 认准源地正品；华强北仿板问题见官方仓库说明。

## 来源

- https://github.com/vcc-gnd/YD-ESP32-S3
- https://github.com/rtek1000/YD-ESP32-23
- https://www.espressif.com/（WROOM-1 datasheet）
