# How to build PlatformIO based project

1. [Install PlatformIO Core](https://docs.platformio.org/page/core.html)
2. Download [development platform with examples](https://github.com/platformio/platform-espressif32/archive/develop.zip)
3. Extract ZIP archive
4. Run these commands:

```shell
# Change directory to example
$ cd platform-espressif32/examples/espidf-blink

# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Build specific environment
$ pio run -e esp32dev

# Upload firmware for the specific environment
$ pio run -e esp32dev --target upload

# Clean build files
$ pio run --target clean
```

## IR Codes

### Stereo

Power:
`0x7E8154AB`

```
  IR_YamahaReceiverOFF [{'data':'7E81FE01','type':'NEC','length':32}]
  IR_YamahaReceiverON [{'data':'7E817E81','type':'NEC','length':32}]
```

### Projector

On:
`0x4CB340BF`

Off:
`0x4CB3748B`

| Number as read | Name               | Datasheet                                                                    |
| -------------- | ------------------ | ---------------------------------------------------------------------------- |
| R315           | Saw resonator      | https://pdf1.alldatasheet.com/datasheet-pdf/view/1151976/REYCONNS/R315A.html |
| 102            | Resistor?          | https://datasheet.lcsc.com/szlcsc/Ever-Ohms-Tech-CR1206F0RP05_C245444.pdf    |
| 103            | Resistor?          |                                                                              |
| 154            | Resistor?          |                                                                              |
| 155            | Resistor?          |                                                                              |
| 273            | Resistor?          |                                                                              |
| 392            | Resistor?          |                                                                              |
| HS 1527C G2DG0 | OTP Encoder        | https://datasheetspdf.com/datasheet/HS1527.html                              |
| J3Y            | NPN SMD Transistor |                                                                              |
| R25            | NPN Transistor     |                                                                              |
| 2TY            | Transistor         | https://www.rcscomponents.kiev.ua/datasheets/s8550-2ty-datasheet.pdf         |

### Projector screen

Up

`Received 5321682 / 24bit Protocol: 1`

Down
`Received 5321684 / 24bit Protocol: 1`
