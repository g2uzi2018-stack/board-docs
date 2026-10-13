# YD-ESP32-S3（源地 / VCC-GND）

**已确认板卡**：源地工作室（VCC-GND Studio）**YD-ESP32-S3** 核心板。  
PCB 背面常见丝印 `YD-ESP32-23`（同板型）；模组为乐鑫 **ESP32-S3-WROOM-1**。

这不是乐鑫官方 DevKitC-1，而是 VCC-GND 设计的双 Type-C 开发板。正版资料与原理图见 [vcc-gnd/YD-ESP32-S3](https://github.com/vcc-gnd/YD-ESP32-S3)。

## 两个 Type-C（你的描述正确）

| 接口 | 芯片 / 走线 | 用途 |
|------|-------------|------|
| **USB 转串口** | 沁恒 **CH343P** | 供电、烧录、串口日志（入门只插这个） |
| **原生 USB / OTG** | ESP32-S3 **GPIO19 (D−) / GPIO20 (D+)** | USB CDC、USB JTAG、USB OTG；也可供电与烧录 |

入门阶段不要同时插两个 Type-C。需要原生 USB 功能时再接 OTG 口。

## 板上跳线焊盘（默认多为断开）

部分板子有 `RGB` / `IN-OUT` / `USB-OTG` 焊盘（见 rtek1000 说明）：

| 焊盘 | 闭合后作用 | 注意 |
|------|------------|------|
| **RGB** | 接通 WS2812 数据 | 若不亮可检查是否需焊短 |
| **IN-OUT** | USB VBUS 与 5Vin 旁路二极管连通 | 闭合后 USB 可给 5Vin 供电；外接 5V 时勿让 USB 反灌冲突 |
| **USB-OTG** | 两个 Type-C 的 VBUS 并在一起 | 一般保持断开；除非清楚电源拓扑 |

不清楚含义前**不要短接**。细节见 [rtek1000/YD-ESP32-23](https://github.com/rtek1000/YD-ESP32-23)。

## Flash / PSRAM 变体

同一 PCB 可焊不同容量的 WROOM-1。公开常见 SKU：

| 模组后缀 | Flash | PSRAM |
|----------|------:|------:|
| N8R2 | 8 MB | 2 MB |
| N8R8 | 8 MB | 8 MB |
| **N16R8** | 16 MB | 8 MB（市面最常见） |

「N8R16」**不是**源地公开常见命名。请看模组金属盖丝印，或烧 `examples/arduino/03_flash_psram_check` 再设 IDE 的 Flash Size / PSRAM。

## 板上要点

- RGB：WS2812，**GPIO48**（不是普通 `digitalWrite` LED）
- UART0 TX/RX：GPIO43 / GPIO44（走 CH343；旁路 TX/RX LED）
- BOOT：GPIO0；RST：外部复位
- 八线 Flash/PSRAM 模组：**GPIO35 / 36 / 37 外部不可用**
- 引脚图：`00-essential/pinout.jpg` + `PINOUT.md`

## 目录

- [`00-essential/`](00-essential/) — 原理图、手册、引脚、板照
- [`01-links/`](01-links/LINKS.md) — 官方与乐鑫文档入口
- [`examples/`](examples/) — Hello / RGB / 容量检测

## Arduino 建议参数

```text
Board: ESP32S3 Dev Module
Flash Size: 按检测或丝印（常见 16MB）
PSRAM: OPI / Octal（有 PSRAM 时）
Upload Port: CH343 对应串口
RGB LED: GPIO48
```
