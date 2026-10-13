# AX7021 例程索引（指针，无大工程）

完整工程请克隆官方仓库，不要把 Vivado 工程 commit 进本资料库。

```bash
git clone --depth 1 https://github.com/alinxalinx/AX7021B_2023.1
```

文档教程（S1～S4）与 2023.1 对齐：  
https://ax7021b-20231-v101.readthedocs.io/zh-cn/latest/

## 建议入门顺序（对应 ReadTheDocs 章节名）

1. **S1 · PL LED** — 「PL的 Hello World LED实验」
2. **S1 · 裸机 UART** — 「体验ARM，裸机输出 Hello World」
3. **S1 · PS 控 PL LED / 按键中断**
4. **S1 · 以太网 LwIP** — 「以太网实验（LWIP）」
5. **S1 · HDMI / VDMA** — 「HDMI输出实验」「使用VDMA驱动HDMI显示」
6. **多网口** — 五口独立千兆是本板卖点，基础通后再做（见官方 GitHub 出厂例程）
7. **S2 扩展模块** — AN108/AN706 AD、OV5640 摄像头等（需对应 AN 模块）
8. **S4 Linux / PetaLinux** — 按需

## 本目录为何几乎为空

Vivado 工程、bitstream、rootfs 动辄数百 MB～数 GB，不适合公开精简资料库。  
研发时把官方 repo 和本 `00-essential` 手册并排放即可。
