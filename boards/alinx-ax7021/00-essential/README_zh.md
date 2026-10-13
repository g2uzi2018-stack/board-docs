# AX7021 必要资料

这个目录只留研发开板最常用的 PDF。本地原始包约 9.4 GB，这里压到约 11 MB。

## 先看这些

| 文件 | 用途 |
|---|---|
| `AX7021B开发板用户手册.pdf` | **首选**整板说明（B 版，含 AC7021B 核心板）|
| `AX7021B底板原理图.pdf` | 底板原理图（网口 / HDMI / USB / 扩展座）|
| `AC7021核心板原理图.pdf` | SoM 原理图 |
| `AC7021核心板PCB图.pdf` | 核心板 PCB 参考 |
| `AC7021尺寸结构.pdf` / `AX7021尺寸结构.pdf` | 结构尺寸 |
| `AX7021底板原理图_旧版.pdf` | 非 B 旧底板对照（仅参考）|
| `SD卡恢复出厂状态.pdf` | SD 镜像恢复步骤 |
| `chip-datasheets/` | 板上关键芯片摘录（见下）|

## chip-datasheets/ 里有什么

| 文件 | 芯片 |
|---|---|
| `ds187-XC7Z010-XC7Z020-Data-Sheet.pdf` | XC7Z020 器件手册 |
| `ds190-Zynq-7000-Overview.pdf` | Zynq-7000 总览 |
| `KSZ9031RNX.pdf` | 千兆 PHY |
| `W25Q256FV.pdf` | QSPI Flash |
| `cp2102.pdf` | USB-UART（板载桥接参考）|

**没有**放：UG585 TRM、UG865 封装、HDMI 标准全文等（体积大且官网随时更新）→ 见 `../01-links/LINKS.md`。

## 开板最小路径

1. 读用户手册：电源、JTAG、串口、启动模式（JTAG / QSPI / SD / eMMC）。
2. 对照底板原理图确认 5 路网口与扩展座引脚。
3. 按官方 `AX7021B_2023.1` 跑第一个 LED / UART / 单网口例程。
4. 再碰多网口、HDMI、摄像头 / AD 扩展模块。

## 来源

本地：`学习资料/黑金/AX7021_2017/`（已去重精简）。  
官方更新请以 ALINX GitHub / ReadTheDocs 为准。
