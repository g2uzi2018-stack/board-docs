# DX-SMART DX-PJ17 GNSS 底板（DX-GP10-A，内置陶瓷天线）

![实物](photo.jpg)

大夏龙雀 DX-PJ17-V2.0 底板，产品型是 **DX-GP10-A**（内置陶瓷天线）。丝印 `DX-PJ17-V2.0`。屏蔽罩上可能印着 LYNO `N10`、标签 `DDH-01-N0001`，按 DX-GP10-A 使用。板上有纽扣备用电池（热启动、保存星历）、`1PPS` 灯和 `TXD` 灯。

核心模组 DX-GP10 是 3.3 V 的 LCC；这块 GP10-A 底板是 5 V 产品。英文产品页给出的规格：GPS + BDS + GLONASS，定位精度 <2 m，更新率 1 Hz，1PPS，速度精度 <0.1 m/s，供电 5 V，标准 UART，输出 NMEA。

## 引脚

| 引脚 | 说明 |
|---|---|
| WAKE | 休眠控制。内部上拉，悬空或高电平为全工作；一直拉低进入 Standby（射频和基带停，RTC / 备份 RAM 仍保留上次定位）。松开或拉高后回到全工作，类似热启动。不用就悬空 |
| VDD | 底板供电。规格书底板范围 3.6–6 V，产品页标 **5 V**。3.3 V 低于下限 |
| GND | 地 |
| TXD | 模块输出 NMEA → MCU RX。核心模组 IO 为 3.3 V |
| RXD | 模块输入 ← MCU TX（发配置命令用），3.3 V |
| 1PPS | 定位成功后默认每秒一个脉冲，频率 1 Hz，脉宽可配置。定位前没有输出。板上 1PPS 灯此时约 1 秒闪一次 |

## 电气与协议

- 输出 NMEA-0183，8N1。核心模组规格书默认波特率 9600，最大 115200。底板上电后的实际波特率**待确认**：先试 9600，没有语句再试 115200。备用电池断开时，改过的波特率掉电不保存。
- 卫星系统：GPS + BDS + GLONASS。定位精度 <2 m，更新率 1 Hz。
- 排针串口按核心模组的 3.3 V 接，可以直接接 ESP32-S3。VDD 接 5 V，底板给核心模组降压。
- 要在室外或窗边才能定位。第一次冷启动可能要几十秒到几分钟；纽扣电池接着时，下次上电能热启动。

## 接 YD-ESP32-S3（UART2）

| 模块 | ESP32-S3 |
|---|---|
| TXD | GPIO5（UART2 RX）|
| RXD | GPIO4（UART2 TX）|
| 1PPS | 默认不接；需要授时时，TFT 背光改接 3V3，把 GPIO47 空出来给它 |
| VDD / GND | 5V / G |
| WAKE | 悬空 |

## 库

- Arduino：`HardwareSerial gps(2); gps.begin(9600, SERIAL_8N1, 5, 4);`，再用 [TinyGPSPlus](https://github.com/mikalhart/TinyGPSPlus) 解析 NMEA。9600 没有语句时把波特率改成 115200 再试。
- ESP-IDF：UART 驱动按行读，再解析 `$GxRMC` / `$GxGGA`。1PPS 可以接到 GPIO 中断或 MCPWM capture 上做授时。

## 资料

- DX-GP10-A 英文产品页（内置陶瓷天线，5 V）：https://en.szdx-smart.com/EN/cpzx/Positioning%20module/GNSSpositioningmodule/147.html
- 同系列列表（GP10-A 为 5 V，核心 DX-GP10 为 3.3 V）：https://en.szdx-smart.com/EN/cpzx/Positioning%20module/GNSSpositioningmodule.html
- DX-GP10 核心模组规格书（3.3 V LCC，含底板引脚、WAKE / 1PPS）：http://www.szdx-smart.com/static/upload/2025/07/26/202507263173.pdf
