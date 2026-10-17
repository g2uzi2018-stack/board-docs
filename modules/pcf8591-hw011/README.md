# PCF8591 AD/DA 模块（HW-011）

![实物](photo.jpg)

主芯片 NXP PCF8591：8 位 4 路 ADC + 1 路 DAC，I2C 接口。板上自带光敏电阻、热敏电阻、电位器，用跳线帽接到 ADC 输入，另有电源指示灯和 AOUT 指示灯。

## 引脚

| 排针 | 说明 |
|---|---|
| AOUT | DAC 输出 |
| AIN0–AIN3 | 模拟输入 |
| SCL / SDA | I2C（板载上拉电阻，阻值待确认）|
| GND / VCC | 2.5–6 V（芯片规格）|

## 跳线（常见 YL-40/HW-011 版本，具体对应以实物丝印为准，待确认）

| 跳线 | 连接 |
|---|---|
| P4 / J4 | AIN1 ← 热敏电阻 |
| P5 / J5 | AIN0 ← 光敏电阻 |
| P6 / J6 | AIN3 ← 电位器 |

要用外部信号时拔掉对应跳线帽。

## 电气与地址

- I2C 地址：`0x48`（7 位，A0–A2 在板上接地）。
- ADC 参考电压 = VREF，本模块 VREF 接 VCC，所以**测量范围 0–VCC**，分辨率 VCC/256。
- **用 3.3 V 供电**：这样 SDA/SCL 上拉到 3.3 V，可直接接 ESP32-S3。若用 5 V 供电，板载上拉会把总线拉到 5 V，不要直接接。
- 控制字节：bit6=DAC 使能，bit1..0=通道号；每次读取返回的是**上一次**转换结果，要先丢弃第一个字节。

## 接 YD-ESP32-S3

| 模块 | ESP32-S3 |
|---|---|
| SDA | GPIO8 |
| SCL | GPIO9 |
| VCC | 3V3 |
| GND | G |

## 库与示例

- Arduino 直接用 `Wire`：

```cpp
Wire.begin(8, 9);
Wire.beginTransmission(0x48); Wire.write(0x40 | ch); Wire.endTransmission(); // 选通道 + 开 DAC
Wire.requestFrom(0x48, 2); Wire.read(); int v = Wire.read();               // 丢弃旧值
```

- ESP-IDF：`i2c_master` 驱动，同样的控制字节。

## 资料

- PCF8591 数据手册（NXP，芯片已停产）：原官方链接 `https://www.nxp.com/docs/en/data-sheet/PCF8591.pdf` 目前返回 404，待找到官方存档地址。
