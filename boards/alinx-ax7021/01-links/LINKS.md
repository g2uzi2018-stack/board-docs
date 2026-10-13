# AX7021 官方与参考链接

大文件、完整例程、工具链文档**只放链接**，不进本仓库。

## ALINX 官方（2023.1 为准）

- GitHub 例程（Vivado 2023.1）：https://github.com/alinxalinx/AX7021B_2023.1
- ReadTheDocs 中文总目录：https://ax7021b-20231-v101.readthedocs.io/zh-cn/latest/
- ReadTheDocs 用户手册：https://ax7021b-20231-v101.readthedocs.io/zh-cn/latest/AX7021B_UserManual_CN/AX7021B_UserManual.html
- 产品站：https://www.alinx.com/ （搜 AX7021 / AX7021B / AC7021）

> 官网偶见直链 PDF（如 `/public/upload/file/AX7021B_User_Manual.pdf`），部分网络会返回拦截页；优先用上面 ReadTheDocs，本仓库 `00-essential/AX7021B开发板用户手册.pdf` 亦可离线查阅。

## AMD / Xilinx（按需在线查，勿整包入库）

- Zynq-7000 产品页：https://www.amd.com/en/products/adaptive-socs-and-fpgas/soc/zynq-7000.html
- UG585 Zynq-7000 TRM（大）：AMD 文档站搜 `ug585`
- UG865 封装管脚：搜 `ug865`
- Vivado / Vitis / PetaLinux 2023.1 下载：https://www.xilinx.com/support/download.html

## 扩展模块（黑金 AN 系列，按需另下）

常见配套：AN5642 双目、AN108 / AN706 / AN926 AD、AN9767、AN071 触摸屏。  
原资料包 `配套模块/` 里有重复 zip，本仓库不收录；向经销商或 ALINX 售后要对应模块资料。

## 社区 / 相关

- PYNQ（Zynq 通用，非本板专用）：https://github.com/Xilinx/PYNQ
- 多端口以太网：官方例程见 GitHub `AX7021B_2023.1`

## 建议工具版本

| 工具 | 版本 |
|---|---|
| Vivado / Vitis | 2023.1 |
| PetaLinux | 2023.1 |
| 主机建议 | Ubuntu 22.04 VM |
