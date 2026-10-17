# DX-SMART DX-PJ14 4G Cat.1 底板（DX-CT511-A）

![实物](photo.jpg)

大夏龙雀 DX-PJ14-V1.1 底板，产品型是 **DX-CT511-A**。丝印 `DX-PJ14-V1.1`、`VIN: DC5V-16V@10W`、`TX/RX LEVEL: 3.3V`。板上只有一根 LTE 天线，没有 GNSS 天线座。板载 GNSS 属于 DX-CT511N，这块板没有。

技术手册里的同款底板带 Nano-SIM 卡槽。官网产品页把不带 GNSS 的这一档写作 DX-CT511。

## 引脚

| 引脚 | 说明 |
|---|---|
| EN | 使能，高电平有效，默认高 |
| VIN | 5–16 V，按 10 W 准备（4G 发射瞬间电流很大）|
| GND | 地 |
| TX | 模块串口输出 → MCU RX（3.3 V）|
| RX | 模块串口输入 ← MCU TX（3.3 V）|
| DIR | 用途**待确认** |
| 焊盘 GND/BOOT/VBUS/DM/DP/GND | 用途**待确认** |

## 电气

- 排针 TX/RX 是 3.3 V（丝印 `TX/RX LEVEL: 3.3V`），可以直接接 ESP32-S3。核心模组串口域是 1.8 V，底板已经转到 3.3 V。
- **不要用 ESP32 板子的 5V 脚供电**：USB 口电流不够，模块联网时会掉电重启。用独立的 5–12 V 电源（≥2 A），并且和 ESP32 共地。
- 默认 UART **115200 8N1**，上电进入 AT 指令模式。
- 协议：TCP / UDP / HTTP / MQTT。

## 接 YD-ESP32-S3

ESP32-S3 只有 3 个 UART：UART0 是下载 / 日志口，UART1 给了 RS-485，UART2 给了 GNSS。4G 有两种接法：

| 模块 | ESP32-S3 | 说明 |
|---|---|---|
| TX | GPIO6 | 方案 A：日志改走 USB-CDC（Arduino 里 `USB CDC On Boot: Enabled`），把 UART0 重映射到 GPIO7(TX)/GPIO6(RX) 给 4G |
| RX | GPIO7 | 方案 B：不同时用 RS-485 时，把 UART1 切到这两个脚 |
| EN | 不接（默认高）或接到有余量的 GPIO | |
| VIN / GND | 外部 5–12 V / G（共地）| |

## 库

- Arduino：`HardwareSerial lte(0); lte.begin(115200, SERIAL_8N1, 6, 7);`，直接发 AT。方案 B 改用 `HardwareSerial lte(1)`，RX/TX 引脚仍是 6 / 7。
- ESP-IDF：UART 驱动发 AT。

## 资料

- 技术手册（DX-CT511 / DX-CT511N，含底板引脚；带 N 才有 GNSS）：http://www.szdx-smart.com/static/upload/2025/07/26/202507262744.pdf
- 串口应用指导（默认 115200 8N1，AT 模式）：https://el.psy.congroo.com/wp-content/uploads/2025/02/DX-CT511CT511N_%E4%B8%B2%E5%8F%A3UART_%E5%BA%94%E7%94%A8%E6%8C%87%E5%AF%BC.pdf
- 社区使用笔记（DX-CT511-A 的 TCP / UDP / HTTP / MQTT。文中「Gps定位」一节是 CT511N 的指令，本板不用）：https://www.cnblogs.com/tianwuyvlianshui/p/18857883
- 产品页（DX-CT511，5–16 V，TCP / UDP / HTTP / MQTT，UART）：https://www.szdx-smart.com/lyzhq/lyzRJ45/129.html
