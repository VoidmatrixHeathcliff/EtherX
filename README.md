# EtherX

EtherX 是基于 SDL2 等开源项目实现的以教学场景为目标的 C++ 游戏开发工具库

> 本项目命名灵感来自 EasyX，但由于 EasyX 至今尚未开源，且其过度依赖 Windows 编程模型，考虑到部分开发者的诉求，EtherX 希望在一定程度上成为 EasyX 的替代解决方案。需要注意的是，虽然命名十分相像，但本项目与 [EtherEngineX](https://github.com/EtherProject/EtherEngineX) 或 [EtherEngine](https://github.com/EtherProject/EtherEngine) 均没有直接联系！ 

## 项目简介

+ 单头文件依赖，通过开关宏决定是否将函数实现引入
+ 本项目由 SDL2 和相关开源项目封装而成，**支持 Windows，Mac，Linux 等平台**
+ 除去 **几何图元绘制、音媒体播放、图片及文字渲染等常见功能**，本项目将计划支持 **即时 GUI 、多种数据存储格式解析和网络等功能**
+ 相较于 EasyX 基于 Windows GDI 和相关系统接口进行开发，**EtherX 支持更多的图片和音媒体格式，在绘图方面使用 DirectX/OpenGL 进行硬件加速，且接口模型更加清晰简明，易学易用**
+ 本项目以教学为目的，考虑到对部分老旧设备支持，Release 目前只提供 Windows_x86 模式下的静态链接库版本，如需其他版本或其他操作系统支持，请自行编译源码
+ 本项目基于 MIT 协议开放源代码，**任何人都可以对源码及衍生作品进行修改、发布、出售和再许可**，但是使用者必须在相关的作品中声明其出处

## 本地编译

+ 如果您使用 MSVC 相关编译器，可以直接 [下载最新的 Release 版本](https://github.com/VoidmatrixHeathcliff/EtherX/releases)  
+ 项目工程是基于 VS2019 搭建的静态库导出项目，SDL2 及相关依赖库已静态编译完成，可以直接拉取编译  
+ 如果您希望得到其他版本的 EtherX 静态库，可以下载并编译下表所示的全部依赖项，将 [EtherX.h](https://github.com/VoidmatrixHeathcliff/EtherX/blob/main/EtherX/EtherX.h) 添加到您的项目中，并定义 `ETHERX_IMPLEMENTATION` 宏确保所有的函数实现添加到编译内容中

| 库名称                | 网址                                                                                     |
|:----------------------|:-----------------------------------------------------------------------------------------|
| **SDL - 2.0.17**      | [https://github.com/libsdl-org/SDL/](https://github.com/libsdl-org/SDL/)                 |
| **SDL_image - 2.0.5** | [https://www.libsdl.org/projects/SDL_image/](https://www.libsdl.org/projects/SDL_image/) |
| **SDL_gfx - 1.0.4**   | [https://sourceforge.net/projects/sdlgfx/](https://sourceforge.net/projects/sdlgfx/)     |
| **SDL_mixer - 2.0.4** | [https://www.libsdl.org/projects/SDL_mixer/](https://www.libsdl.org/projects/SDL_mixer/) |
| **SDL_ttf - 2.0.15**  | [https://www.libsdl.org/projects/SDL_ttf/](https://www.libsdl.org/projects/SDL_ttf/)     |

## 教程文档

+ [快速上手文档](docs/quick-start.md) 以数个深入浅出的示例介绍常用功能
+ 更多内容和函数接口介绍详见 [完整参考手册](docs/README.md)

## 联系开发者

请直接 [提交 issue](https://github.com/VoidmatrixHeathcliff/EtherX/issues) 或发送邮件至： Voidmatrix@qq.com  
QQ 群讨论组：**679412727**，[直接加入](https://jq.qq.com/?_wv=1027&k=Gdl3BnsU)

## 赞助与支持

EtherX 是一个非盈利性项目，感谢对作者进行赞助与支持，以帮助作者维护和产出更好的作品

> 您可以在备注中写明是否愿意将您添加至赞助者名单，并且备注您希望展示的账户名和是否愿意公开金额，默认展示付款账户名（敏感信息加密）和金额，截止目前为止的赞助者名单 [见此处](docs/support/sponsor-list.md)，排名不分先后

|                   微信                    |                    支付宝                    |
|:-----------------------------------------:|:--------------------------------------------:|
| ![微信收款码](docs/support/wx_qrcode.jpg) | ![支付宝收款码](docs/support/zfb_qrcode.jpg) |