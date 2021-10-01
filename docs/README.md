# EtherX 完全参考手册

在这里您可以找到关于 EtherX 的一切，但是在查阅此文档之前，我们建议您先阅读 [快速上手文档](quick-start.md)

如果您在阅读期间发现有任何错误或建议，欢迎 [提交 issue](https://github.com/VoidmatrixHeathcliff/EtherX/issues) 或发送邮件至： Voidmatrix@qq.com

## 快速索引

<details>
    <summary>💼 结构体和枚举</summary>

+ [struct ETHX_Color](#ETHX_Color)
+ [struct ETHX_Rect](#ETHX_Rect)
+ [struct ETHX_Point](#ETHX_Point)
+ [struct ETHX_Event](#ETHX_Event)
+ [struct ETHX_Sprite](#ETHX_Sprite)
+ [struct ETHX_Font](#ETHX_Font)
+ [struct ETHX_Music](#ETHX_Music)
+ [struct ETHX_Sound](#ETHX_Sound)
+ [enum ETHX_MessageBoxStyle](#ETHX_MessageBoxStyle)
+ [enum ETHX_WindowStyle](#ETHX_WindowStyle)
+ [enum ETHX_SpriteStyle](#ETHX_SpriteStyle)
+ [enum ETHX_FontStyle](#ETHX_FontStyle)
+ [enum ETHX_EventType](#ETHX_EventType)
+ [enum ETHX_KeyCode](#ETHX_KeyCode)
    
</details>

<details>
    <summary>🖥 窗口控制相关函数</summary>
</details>

<details>
    <summary>🖼 绘图相关函数</summary>
</details>

<details>
    <summary>🎼 音媒体播控相关函数</summary>
</details>

<details>
    <summary>🕹 交互事件相关函数</summary>
</details>

<details>
    <summary>⏲ 时间控制相关函数</summary>
</details>

## 详细介绍

<a id="ETHX_Color"></a>
### struct ETHX_Color
+ **功能：** 用以描述 EtherX 中的颜色
+ **成员及简介：**
    | 成员      | 简介                                        |
    |:----------|:--------------------------------------------|
    | `Uint8 r` | 颜色的红色分量，取值范围为 0~255            |
    | `Uint8 g` | 颜色的绿色分量，取值范围为 0~255            |
    | `Uint8 b` | 颜色的蓝色分量，取值范围为 0~255            |
    | `Uint8 a` | 颜色的 α 通道，描述透明度，取值范围为 0~255 |
+ **相关内容：**
    - [ETHX_SetSpriteColorKey()](#ETHX_SetSpriteColorKey)
    - [ETHX_SetDrawColor()](#ETHX_SetDrawColor)

***

<a id="ETHX_Rect"></a>
### struct ETHX_Rect
+ **功能：** 用以描述矩形位置和大小
+ **成员及简介：**
    | 成员    | 简介                                      |
    |:--------|:------------------------------------------|
    | `int x` | 矩形左上角顶点在窗口坐标系下坐标的 x 分量 |
    | `int y` | 矩形左上角顶点在窗口坐标系下坐标的 y 分量 |
    | `int w` | 矩形宽度                                  |
    | `int h` | 矩形高度                                  |
+ **相关内容：**
    - [ETHX_DrawRectangle()](#ETHX_DrawRectangle)
    - [ETHX_DrawSprite()](#ETHX_DrawSprite)

***

<a id="ETHX_Point"></a>
### struct ETHX_Point
+ **功能：** 用以描述点的位置
+ **成员及简介：**
    | 成员    | 简介                                      |
    |:--------|:------------------------------------------|
    | `int x` | 点在窗口坐标系下坐标的 x 分量 |
    | `int y` | 点在窗口坐标系下坐标的 y 分量 |
+ **相关内容：**
    - [ETHX_DrawPoint()](#ETHX_DrawPoint)

***

<a id="ETHX_Event"></a>
### struct ETHX_Event
+ **功能：** 用以描述交互事件
+ **成员及简介：**
    | 成员    | 简介                                      |
    |:--------|:------------------------------------------|
    | `ETHX_EventType type` | 事件类型 |
    | `ETHX_KeyCode key_code` | 键盘事件对应的键码 |
    | `int mouse_pos_x` | 鼠标移动事件对应的鼠标在当前窗口坐标系下坐标的 x 分量 |
    | `int mouse_pos_y` | 鼠标移动事件对应的鼠标在当前窗口坐标系下坐标的 y 分量 |
    | `int mouse_scroll_x` | 鼠标滚轮事件对应的 x 方向滚动距离，向左为负，向右为正 |
    | `int mouse_scroll_y` | 鼠标滚轮事件对应的 x 方向滚动距离，向前为负，向后为正 |
    | `std::string text` | 文本输入事件对应的文本输入内容 |
+ **备注：**  
在非此事件发生时尝试获取对应的成员值可能会导致不可预知的结果，请先根据 `type` 判断当前事件类型再进行对应值的获取，示例如下：
```c++
// ETHX_Event* pEvent = ...

// 正确用法，在鼠标移动事件发生时才去访问对应成员的值
if (pEvent->type == ETHX_ET_MOUSEMOTION)
    int x = pEvent->mouse_pos_x, y = pEvent->mouse_pos_y;

// 错误用法，此时的 text 成员可能访问异常
if (pEvent->type == ETHX_ET_MOUSEMOTION)
    std::string input = pEvent->text;

```
+ **相关内容：**
    - [enum ETHX_EventType](#ETHX_EventType)
    - [enum ETHX_KeyCode](#ETHX_KeyCode)
    - [ETHX_UpdateEvent()](#ETHX_UpdateEvent)
