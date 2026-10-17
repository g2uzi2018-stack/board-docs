# board-docs

精简的板卡研发资料库。按**板卡分子目录**组织，不按分支拆分。

打开就能用的必要文件：用户手册、原理图、引脚、少量芯片手册，以及指向官方完整例程的链接。  
本仓库**不**收录多 GB 教程压缩包、重复副本、AMD/Xilinx 全套 UG、CAD 源工程。

仓库地址：https://github.com/g2uzi2018-stack/board-docs

## 布局

```
boards/
  alinx-ax7021/     # 黑金 AX7021 / AX7021B（Zynq-7020，5×千兆）
    00-essential/   # 用户手册、原理图、尺寸、关键芯片手册
    01-links/       # 官方 GitHub / ReadTheDocs / 产品页
    examples/       # 例程索引（不打包大工程；AX7021 请用 2023.1）
  yd-esp32-s3/      # 源地 VCC-GND YD-ESP32-S3（ESP32-S3-WROOM-1，双 Type-C）
    00-essential/
    01-links/
    examples/       # Arduino 短示例
modules/            # 小模块，用途见下方「模块简报」
```

每个板卡目录里，先读 `README.md`，再进 `00-essential/`。小模块先读 [modules/README.md](modules/README.md)。

## 模块简报

`modules/` 收的是配合板卡用的小模块：引脚、电平、接线和库。每块只记用途，细节进对应目录。

| 目录 | 用途 |
|---|---|
| [max485-rs485](modules/max485-rs485/README.md) | TTL/UART ↔ RS-485 总线转换，远距离/多节点串口通信 |
| [pcf8591-hw011](modules/pcf8591-hw011/README.md) | I2C 8 位 AD/DA，可接光敏/热敏/电位器或外部模拟量 |
| [w5500-ethernet](modules/w5500-ethernet/README.md) | SPI 硬核 TCP/IP 以太网，给 MCU 加有线网口 |
| [tft-2.8-ili9341-spi](modules/tft-2.8-ili9341-spi/README.md) | 2.8 寸 240×320 SPI 彩屏+电阻触摸+SD |
| [oled-0.96-ssd1306-i2c](modules/oled-0.96-ssd1306-i2c/README.md) | 0.96 寸 128×64 I2C OLED，调试状态显示 |
| [usb-ttl-dx-pj15](modules/usb-ttl-dx-pj15/README.md) | USB-C 转 TTL 串口调试下载线 |
| [gnss-dx-pj17-lyno-n10](modules/gnss-dx-pj17-lyno-n10/README.md) | DX-PJ17 底板，产品型 DX-GP10-A（内置陶瓷天线），UART 输出 NMEA |
| [mcp2515-can](modules/mcp2515-can/README.md) | SPI CAN 控制器+收发，接车载/机器人 CAN 总线 |
| [4g-cat1-dx-pj14](modules/4g-cat1-dx-pj14/README.md) | DX-PJ14 底板，产品型 DX-CT511-A（4G Cat.1，无板载 GNSS） |

## 怎么用

1. 打开对应板卡的 `README.md` 与 `00-essential/README_zh.md`。
2. 完整 Vivado / ESP-IDF 工程与大教程：按该板卡 `01-links/LINKS.md` 从官方仓库拉取。
3. AX7021 工具链与例程以 **Vivado / Vitis / PetaLinux 2023.1** 与 [alinxalinx/AX7021B_2023.1](https://github.com/alinxalinx/AX7021B_2023.1) 为准，不要用 2017 旧课件工程。

## 许可

- 本仓库原创 README / 示例代码：MIT（见 `LICENSE`）。
- 厂商 PDF：版权归厂商，见 `NOTICE`。
