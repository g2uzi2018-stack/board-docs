# hardware-board-docs

精简公开的板卡研发资料库。按**板卡分子目录**，不按分支拆分。

目标：打开就能用的「必要文件」——手册、原理图、引脚、少量芯片手册 + 官方链接。  
刻意不做：多 GB 教程压缩包、重复 `(1)` 副本、AMD/Xilinx 全套 UG、CAD 源工程。

## 布局

```
boards/
  alinx-ax7021/          # 黑金 AX7021 / AX7021B（Zynq-7020，5×千兆）
    00-essential/        # 用户手册、原理图、尺寸、关键芯片手册
    01-links/            # 官方 GitHub / ReadTheDocs / 产品页（只放链接）
    examples/            # 例程索引（不打包大工程）
  yd-esp32-s3-n8r16/     # VCC-GND YD-ESP32-S3 族（见板卡 README 的型号说明）
    00-essential/
    01-links/
    examples/            # 短示例源码
```

风格参考私有仓库 ComTrans 的 `BoardName/00-essential/` 模式。

## 怎么用

1. 先读对应板卡的 `README.md` 和 `00-essential/README_zh.md`。
2. 大教程 / 完整 Vivado·IDF 工程：跟 `01-links/LINKS.md` 去官方仓库拉，不塞进本仓库。
3. 上传 GitHub 前请先在网页新建**空的公开仓库**，再在本机 `git init && git remote add ... && git push`（本整理环境未登录 `gh`）。

## 许可

- 本仓库原创的 README / 示例代码：MIT（`LICENSE`）。
- 厂商 PDF：版权仍归厂商，见 `NOTICE`。

## 体积

整理后整库约十几 MB（相对本地 ~9 GB 的 AX7021 资料包）。
