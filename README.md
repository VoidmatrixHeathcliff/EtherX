# EtherX

EtherX 是基于 Windows GDI 的单文件绘图库，并对简易游戏开发相关功能进行了扩展支持

> 本项目是作者在阅读《Tricks Of The Windows Game Programming》时产生的想法，命名灵感来自 EasyX，但由于 EasyX 至今未开源，考虑到部分开发者的诉求，EtherX 希望在一定程度上成为 EasyX 的替代解决方案。  
>
> 注意：虽然命名十分相像，但本项目与 [EtherEngineX](https://github.com/EtherProject/EtherEngineX) 或 [EtherEngine](https://github.com/EtherProject/EtherEngine) 均没有直接联系！ 

## 本项目特点及预期功能

+ 单头文件引入，通过开关宏决定是否将相关功能编译进程序，最小依赖
+ 本项目由 Windows GDI 和相关 Win32 API 封装而成，仅适用于 Windows 平台
+ 本项目提供简单的图元绘制和文本渲染功能，以及 Windows 原生 GUI 组件的支持，并集成了基于 imgui 的现代化 GUI 的接口支持
+ 本项目提供音媒体播放、网络等游戏开发中常见功能的接口支持，相关实现依赖于第三方库
+ 本项目提供对 JSON 和 XML 等常见数据格式解析的接口支持，相关实现依赖于第三方库
+ 本项目提供对 Lua 接口的封装，开发者可以在开启相关宏后使用 Lua 编写游戏逻辑