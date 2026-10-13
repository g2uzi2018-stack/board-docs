# 示例说明

短代码，用于确认板子活着、RGB、Flash/PSRAM 容量。  
不是完整工程；Arduino 可直接新建 sketch 粘贴，IDF 片段按注释接入。

| 路径 | 作用 |
|---|---|
| `arduino/01_hello_serial/` | 串口 Hello |
| `arduino/02_rgb_gpio48/` | WS2812 RGB（GPIO48）|
| `arduino/03_flash_psram_check/` | 打印 Flash / PSRAM 大小（核对 N8R16 vs N16R8）|
| `idf-snippets/` | IDF 侧等价提示 |

Arduino 板型选 **ESP32S3 Dev Module**，上传口选 **CH343** 对应串口。
