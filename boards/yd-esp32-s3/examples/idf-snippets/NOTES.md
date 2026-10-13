# ESP-IDF 片段提示

```bash
idf.py set-target esp32s3
idf.py menuconfig   # Component config → ESP PSRAM → support for external RAM
idf.py -p /dev/ttyACM0 flash monitor
```

Hello：用官方 `examples/get-started/hello_world`。  
PSRAM：`examples/system/himem` 或在 hello_world 里打印 `esp_psram_get_size()`。  
RGB：GPIO48 + RMT/WS2812 例程（`led_strip`）。

串口优先走 CH343 对应设备节点；原生 USB 需另行配置 USB Serial/JTAG。
