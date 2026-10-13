# ALINX AX7021 / AX7021B

黑金（ALINX）Zynq-7000 开发板，工业级 **XC7Z020-2CLG484I**，核心板 **AC7021B** + 底板。

## 一眼规格

| 项目 | 内容 |
|---|---|
| SoC | XC7Z020-2CLG484I（双核 Cortex-A9 ≈767 MHz）|
| 逻辑 | 约 85K LC / 53.2K LUT / 220 DSP / 4.9 Mb BRAM |
| 内存 | 1 GB DDR3（2×512 MB）|
| 存储 | 256 Mbit QSPI + 8 GB eMMC + TF |
| 网络 | **5× 独立千兆 RJ45**（卖点）|
| 视频 | HDMI OUT 1080p60 |
| USB | 4× USB 2.0 + USB-UART + JTAG-USB |
| 扩展 | 2× 40-pin 2.54 mm（可接黑金双目/TFT/高速 AD 模块）|
| 供电 | 12 V / 3 A |
| 注意 | CLG484 **无 GTX** → 无硬核 PCIe / 高速收发器 |

## 目录

- [`00-essential/`](00-essential/) — 用户手册、底板/核心板原理图与尺寸、关键芯片手册
- [`01-links/`](01-links/LINKS.md) — 官方 2023.1 例程仓库、ReadTheDocs、产品页（大文件外链）
- [`examples/`](examples/EXAMPLES.md) — 官方例程名称索引

## 建议工具链

在 **Ubuntu 22.04** 虚拟机安装 Vivado / Vitis / PetaLinux **2023.1**（与官方 AX7021B_2023.1 对齐）。  
Debian 13 主机适合日常编辑与文档，不建议裸机硬装 Xilinx 工具。

## 本仓库刻意不收录

课程 `course_s1`～`s4` 多 GB zip、ClockBuilder、驱动重复包、AMD UG585/UG865 等大手册（改走链接）、`.DSN` / `.PcbDoc` / `.brd` CAD 源、115 MB「多端口以太网应用」zip。
