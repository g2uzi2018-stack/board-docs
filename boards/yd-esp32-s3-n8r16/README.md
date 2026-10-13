# YD-ESP32-S3（N8R16 标注说明）

VCC-GND（源地）**YD-ESP32-S3** 开发板族：黑 PCB、双 Type-C、CH343P 转串口、GPIO48 WS2812 RGB。  
模组为 **ESP32-S3-WROOM-1**，同一 PCB 可焊不同 Flash/PSRAM 容量。

## 关于「N8R16」

| 写法 | Flash | PSRAM | 说明 |
|---|---:|---:|---|
| N8R2 | 8 MB | 2 MB | YD 官方列出过 |
| **N8R8** | 8 MB | 8 MB | YD 官方列出过 |
| **N16R8** | 16 MB | 8 MB | 最常见；ComTrans 仓库用的就是这个 |
| **N8R16** | 8 MB | 16 MB | **不是**公开常见的 YD SKU 命名 |

你口头说的是 N8R16。公开资料里 YD 常见是 N8R2 / N8R8 / **N16R8**；乐鑫 WROOM-1 量产表也以 R2/R8 为主，16 MB PSRAM 更少见。  

**本目录按「同一 PCB 族 + WROOM-1」整理。** 上电后用 `examples/` 里的容量检测 sketch 确认真实 Flash/PSRAM，再改 Arduino/IDF 的分区与 PSRAM 选项。若检测是 16+8，实际就是 N16R8。

## 目录

- [`00-essential/`](00-essential/) — 原理图、手册、引脚表、板照（ComTrans 同款精简风格）
- [`01-links/`](01-links/LINKS.md) — 官方与第三方完整仓库
- [`examples/`](examples/) — 串口 Hello / RGB / PSRAM 检测短代码

## 两个 Type-C

1. **CH343P 口**：烧录 + 串口日志（入门只插这个）
2. **原生 USB 口**：GPIO19/20，CDC / JTAG / OTG

## 快速参数（Arduino）

```text
Board: ESP32S3 Dev Module
Flash Size: 按检测结果（8MB 或 16MB）
PSRAM: OPI / Octal（若有 PSRAM）
RGB: GPIO48（WS2812，不是普通 digitalWrite）
```
