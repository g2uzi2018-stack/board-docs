# YD-ESP32-S3 必要信息

风格对齐 ComTrans `YD-ESP32-S3_N16R8/00-essential/`：少量文件，先能开发。

## 这个目录有什么

| 文件 | 用途 |
|---|---|
| `README_zh.md` | 先看这个 |
| `PINOUT.md` | 排针对照（文字版，最常用）|
| `board_photo.png` / `board_overview.png` | 认板 |
| `block_diagram.png` | 功能框图 |
| `schematic_v1.4.pdf` | 板级原理图（V1.4；板丝印若是 V1.3 勿 100% 盲信，但够用）|
| `mechanical_metric.pdf` / `mechanical_inch.pdf` | 结构尺寸 |
| `esp32-s3-wroom-1_datasheet_en.pdf` | 乐鑫模组手册（英）|
| `esp32-s3-wroom-1_datasheet_cn.pdf` | 乐鑫模组手册（中）|

未收录：厂家 MicroPython 固件包、下载工具安装包、超大 PCB 渲染图、Altium `.PcbDoc`。

## 板子核心信息

- 模组：ESP32-S3-WROOM-1（容量以你板上的丝印 / 检测为准）
- USB-UART：CH343P（沁恒）
- RGB：WS2812，**GPIO48**
- 双 Type-C：CH343 + 原生 USB（GPIO19/20）
- 按键：RST、BOOT（GPIO0）

## 关键 GPIO

| 功能 | GPIO |
|---|---:|
| BOOT | 0 |
| USB D- / D+ | 19 / 20 |
| UART0 TX / RX | 43 / 44 |
| RGB LED | 48 |

**外部勿用（八线 Flash/PSRAM 模组）**：GPIO35、36、37。  
启动相关慎用：GPIO0、45、46。

## 型号核对（N8R16）

1. 看模组金属盖丝印（常有 N16R8 等）。
2. 烧 `../examples/` 里的 Flash/PSRAM 检测。
3. 再设 IDE 的 Flash Size / PSRAM。

公开 YD SKU 常见 **N8R8 / N16R8**；若你确实测到 8 MB Flash + 16 MB PSRAM，按检测结果配工具链即可，PCB 仍与本资料一致。

## 上电注意

1. 先单独 USB，不接外设。
2. 万用表确认 3V3 / 5V / GND（网上有克隆板 5V 脚异常反馈）。
3. 入门不要同时插两个 Type-C。
4. 不清楚跳线焊盘含义前不要短接。

## 来源

- https://github.com/vcc-gnd/YD-ESP32-S3
- https://github.com/rtek1000/YD-ESP32-23
- https://www.espressif.com/（WROOM-1 datasheet）
- 排针表摘自 VCC-GND README
