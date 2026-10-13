# AX7021 例程索引（指针，无大工程）

完整工程请克隆官方仓库，不要把 Vivado 工程 commit 进本资料库。

```bash
git clone --depth 1 https://github.com/alinxalinx/AX7021B_2023.1
```

## 典型入门顺序（名称以官方仓库/文档为准）

1. **PS 跑通**：UART 打印、PS LED / GPIO
2. **PL LED / 按键**：AXI GPIO 或直连 EMIO
3. **单网口 LwIP** 或 Linux 单口 ping
4. **HDMI 输出**（SiI9134 路径）
5. **多网口**：五口独立千兆是本板核心卖点，放在基础通后再做
6. **扩展模块**：摄像头 / 高速 AD（需对应 AN 模块资料）

具体章节目录以 ReadTheDocs 为准：  
https://ax7021b-20231-v101.readthedocs.io/zh-cn/latest/

## 本目录为何几乎为空

Vivado 工程、bitstream、rootfs 动辄数百 MB～数 GB，不适合公开精简资料库。  
研发时把官方 repo 和本 `00-essential` 手册并排放即可。
