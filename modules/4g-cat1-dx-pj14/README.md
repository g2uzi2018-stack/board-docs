# DX-SMART DX-PJ14-V1.1（推测：DX-CT511 4G Cat.1 底板）

![实物](photo.jpg)

黑色底板带一根外接天线，丝印 `DX-PJ14-V1.1`、`VIN: DC5V-16V@10W`、`TX/RX LEVEL: 3.3V`。

**型号识别（待确认）**：大夏龙雀官网没有 PJ14 的单独页面。不过它的引脚和电源规格（`EN` 高电平使能、`VIN` 5–16 V/10 W、TX/RX）和官方 **DX-CT511 / DX-CT511N 4G 全网通 Cat.1 模块**规格书里那块底板的描述一致，所以推测这是 CT511 的底板。CT511N 多一个 GNSS 天线座，照片里只有一根天线，所以可能是不带 N 的 CT511。请看背面或屏蔽罩上的模组丝印，确认一下，顺便确认 SIM 卡座在哪。

## 引脚

| 引脚 | 说明 |
|---|---|
| EN | 使能，高电平有效（规格书底板说明写的是默认高）|
| VIN | 5–16 V，按 10 W 准备（4G 发射瞬间电流很大）|
| GND | 地 |
| TX | 模块串口输出 → MCU RX（3.3 V）|
| RX | 模块串口输入 ← MCU TX（3.3 V）|
| DIR | 用途**待确认**（可能是给 RS-485 用的方向控制，规格书里没对上）|
| 焊盘 GND/BOOT/VBUS/DM/DP/GND | 模组的 USB 口和 BOOT 脚，用来升级固件或通过 USB 调试（待确认）|

## 电气

- TX/RX 是 3.3 V 电平，可以直接接 ESP32-S3。
- **不要用 ESP32 板子的 5V 脚供电**：USB 口电流不够，模块联网时会掉电重启。用独立的 5–12 V 电源（≥2 A），并且和 ESP32 共地。
- 用 AT 指令：支持 TCP / UDP / HTTP / MQTT（官网 CT511N 参数）。默认波特率、AT 指令集：**待确认**，以规格书为准。

## 接 YD-ESP32-S3

ESP32-S3 只有 3 个 UART：UART0 是下载 / 日志口，UART1 给了 RS-485，UART2 给了 GNSS。4G 有两种接法：

| 模块 | ESP32-S3 | 说明 |
|---|---|---|
| TX | GPIO6 | 方案 A：日志改走 USB-CDC（Arduino 里 `USB CDC On Boot: Enabled`），把 UART0 重映射到 GPIO7(TX)/GPIO6(RX) 给 4G |
| RX | GPIO7 | 方案 B：不同时用 RS-485 时，把 UART1 切到这两个脚 |
| EN | 不接（默认高）或接到有余量的 GPIO | |
| VIN / GND | 外部 5–12 V / G（共地）| |

## 库

- Arduino：`HardwareSerial` 直接发 AT 指令；[TinyGSM](https://github.com/vshymanskyy/TinyGSM) 对这个模组是否兼容**待确认**。
- ESP-IDF：UART + AT；也可以用 `esp_modem` 组件走 PPP（模组是否支持 PPP 待确认）。

## 资料

- DX-CT511/DX-CT511N 规格书（大夏龙雀官方，含底板引脚表）：https://www.szdx-smart.com/static/upload/2025/07/26/202507262744.pdf
- 大夏龙雀 4G 模块分类：https://www.szdx-smart.com/cpzx-2.html
