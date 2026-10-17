# DX-SMART DX-PJ17-V2.0 GNSS 定位模块（LYNO N10）

![实物](photo.jpg)

大夏龙雀的 GNSS 底板，丝印 `DX-PJ17-V2.0`，屏蔽罩上是 LYNO 的 `N10` 模组（标签 `DDH-01-N0001`），带纽扣备用电池（用于热启动、保存星历）、`1PPS` 和 `TXD` 指示灯，天线接口在板上（陶瓷 / 外接天线规格待确认）。

## 引脚

| 引脚 | 说明 |
|---|---|
| WAKE | 唤醒 / 待机控制（极性待确认，不用就悬空）|
| VDD | 供电（电压范围待确认，先试 3.3 V；规格书没拿到前不要直接上 5 V）|
| GND | 地 |
| TXD | 模块输出 NMEA → MCU RX |
| RXD | 模块输入 ← MCU TX（发配置命令用）|
| 1PPS | 秒脉冲输出，上升沿对齐整秒（定位后才有）|

## 电气与协议

- 输出 NMEA-0183。默认波特率**待确认**（常见是 9600 或 115200，两种都试一下）。
- 支持哪些卫星系统（GPS / 北斗 / GLONASS / Galileo）、更新率、配置命令格式：**待确认**，需要 LYNO N10 规格书。
- IO 电平 3.3 V（待确认）。如果 VDD 接的是 3.3 V，可以直接接 ESP32-S3。
- 要在室外或窗边才能定位，第一次冷启动可能要几十秒到几分钟。

## 接 YD-ESP32-S3（UART2）

| 模块 | ESP32-S3 |
|---|---|
| TXD | GPIO5（UART2 RX）|
| RXD | GPIO4（UART2 TX）|
| 1PPS | 默认不接；需要授时时，TFT 背光改接 3V3，把 GPIO47 空出来给它 |
| VDD / GND | 3V3 / G |
| WAKE | 悬空 |

## 库

- Arduino：`HardwareSerial gps(2); gps.begin(9600, SERIAL_8N1, 5, 4);`，再用 [TinyGPSPlus](https://github.com/mikalhart/TinyGPSPlus) 解析 NMEA。
- ESP-IDF：UART 驱动按行读，再解析 `$GxRMC` / `$GxGGA` 语句。1PPS 可以接到 GPIO 中断或 MCPWM capture 上做授时。

## 资料

- LYNO N10 规格书 / 大夏龙雀 PJ17 页面：**待补**（官网暂未检索到）。大夏龙雀定位模块分类：https://www.szdx-smart.com/cpzx-2.html
