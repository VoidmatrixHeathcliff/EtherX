# EtherX

EtherX 是基于 SDL2 等开源项目实现的以教学场景为目标的 C++ 游戏开发工具库

> 本项目命名灵感来自 EasyX，但由于 EasyX 至今尚未开源，且其过度依赖 Windows 编程模型，考虑到部分开发者的诉求，EtherX 希望在一定程度上成为 EasyX 的替代解决方案。需要注意的是，虽然命名十分相像，但本项目与 [EtherEngineX](https://github.com/EtherProject/EtherEngineX) 或 [EtherEngine](https://github.com/EtherProject/EtherEngine) 均没有直接联系！ 

## 本项目特点及预期功能

+ 单头文件依赖，通过开关宏决定是否将函数实现引入
+ 本项目由 SDL2 和相关开源项目封装而成，**支持 Windows，Mac，Linux 等平台**
+ 除去 **几何图元绘制、音媒体播放、图片及文字渲染等常见功能**，本项目将计划支持 **即时 GUI 、多种数据存储格式解析和网络等功能**
+ 相较于 EasyX 基于 Windows GDI 和相关系统接口进行开发，**EtherX 支持更多的图片和音媒体格式，在绘图方面使用 DirectX/OpenGL 进行硬件加速，且接口模型更加清晰简明，易学易用**
+ 本项目以教学为目的，考虑到对部分老旧设备支持，Release 目前只提供 Windows_x86 模式下的静态链接库版本，如需其他版本或其他操作系统支持，请自行编译源码
+ 本项目基于 MIT 协议开放源代码，**任何人都可以对源码及衍生作品进行修改、发布、出售和再许可**，但是使用者必须在相关的作品中声明其出处

## 教程及文档

> 文档正在维护……

+ [快速上手文档](docs/quick-start.md) 以一个简单的绘图游戏为例，介绍常用功能
+ 更多内容和函数接口详细介绍见 [完整参考手册](docs/README.md)

## 联系开发者

请直接 [提交 issue](https://github.com/VoidmatrixHeathcliff/EtherX/issues) 或 [发送邮件](Voidmatrix@qq.com)

## 赞助与支持

欢迎对作者进行赞助与支持，帮助作者维护和产出更好的作品

|                           微信                           |                            支付宝                             |
|:--------------------------------------------------------:|:-------------------------------------------------------------:|
| ![微信收款码](docs/support/wx_qrcode.jpg) | ![支付宝收款码](docs/support/zfb_qrcode.jpg) |