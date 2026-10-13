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
```

每个板卡目录里，先读 `README.md`，再进 `00-essential/`。

## 怎么用

1. 打开对应板卡的 `README.md` 与 `00-essential/README_zh.md`。
2. 完整 Vivado / ESP-IDF 工程与大教程：按该板卡 `01-links/LINKS.md` 从官方仓库拉取。
3. AX7021 工具链与例程以 **Vivado / Vitis / PetaLinux 2023.1** 与 [alinxalinx/AX7021B_2023.1](https://github.com/alinxalinx/AX7021B_2023.1) 为准，不要用 2017 旧课件工程。

## 许可

- 本仓库原创 README / 示例代码：MIT（见 `LICENSE`）。
- 厂商 PDF：版权归厂商，见 `NOTICE`。
