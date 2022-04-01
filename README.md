# GD32F310-FreeRTOS


[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/kings669/GD32F310-FreeRTOS)

## 背景

抽空参加了`极术社区`组织的[「免费申请」基于Arm Cortex-M4的兆易创新GD32F310开发板试用活动](https://aijishu.com/e/1120000000306632),想着能不能把现在STM32上面做的一些项目复刻一下，发现这款开发板的`ROM`和`RAM`的比较小，适合做一些小型的项目。  
本仓库目的：  

1. 将STM32上面的一些方法可以移植到GD32当中去，将基本外设驱动复刻.
2. FreeRTOS在本项目中使用
3. 搭建BSP层和Task层  


MCU：**GD32F310K8T6**  
RTOS：**FreeRTOS v202112.00**  

## 使用说明

*此处将会在极术社区发布* 

- [【GD32F310开发板试用】GD32F310移植FreeRTOS](https://aijishu.com/a/1060000000314175) 

## 相关仓库及资源

- [FreeRTOS](https://github.com/FreeRTOS/FreeRTOS) —— 一个迷你操作系统内核的小型嵌入式系统
- [GD32F3x0 Firmware Library](http://www.gd32mcu.com/cn/download/7?kw=GD32F3)) —— GD32Fx0系列固件库
- [GD32F3x0系列MCU固件库使用指南](http://www.gd32mcu.com/download/down/document_id/217/path_type/2)——使用指南，可以参考配置
- [其他资源](https://aijishu.com/a/1060000000306188)——可以前往极术社区

## 维护者

[@kings669](https://github.com/kings669)

## 如何贡献

非常欢迎你的加入！[提一个 Issue](https://github.com/kings669/GD32F310-FreeRTOS/issues) 或者[提交一个 Pull Request](https://github.com/kings669/GD32F310-FreeRTOS/pulls)。

## 使用许可
[MIT](LICENSE) © Richard Littauer