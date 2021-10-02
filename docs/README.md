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
+ [struct ETHX_Image](#ETHX_Image)
+ [struct ETHX_Font](#ETHX_Font)
+ [struct ETHX_Music](#ETHX_Music)
+ [struct ETHX_Sound](#ETHX_Sound)
+ [enum ETHX_MessageBoxStyle](#ETHX_MessageBoxStyle)
+ [enum ETHX_WindowStyle](#ETHX_WindowStyle)
+ [enum ETHX_ImageStyle](#ETHX_ImageStyle)
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
    - [ETHX_SetImageColorKey()](#ETHX_SetImageColorKey)
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
    - [ETHX_DrawImage()](#ETHX_DrawImage)

***

<a id="ETHX_Point"></a>
### struct ETHX_Point
+ **功能：** 用以描述点的位置
+ **成员及简介：**
    | 成员    | 简介                          |
    |:--------|:------------------------------|
    | `int x` | 点在窗口坐标系下坐标的 x 分量 |
    | `int y` | 点在窗口坐标系下坐标的 y 分量 |
+ **相关内容：**
    - [ETHX_DrawPoint()](#ETHX_DrawPoint)

***

<a id="ETHX_Event"></a>
### struct ETHX_Event
+ **功能：** 用以描述交互事件
+ **成员及简介：**
    | 成员                    | 简介                                                  |
    |:------------------------|:------------------------------------------------------|
    | `ETHX_EventType type`   | 事件类型                                              |
    | `ETHX_KeyCode key_code` | 键盘事件对应的键码                                    |
    | `int mouse_pos_x`       | 鼠标移动事件对应的鼠标在当前窗口坐标系下坐标的 x 分量 |
    | `int mouse_pos_y`       | 鼠标移动事件对应的鼠标在当前窗口坐标系下坐标的 y 分量 |
    | `int mouse_scroll_x`    | 鼠标滚轮事件对应的 x 方向滚动距离，向左为负，向右为正 |
    | `int mouse_scroll_y`    | 鼠标滚轮事件对应的 x 方向滚动距离，向前为负，向后为正 |
    | `std::string text`      | 文本输入事件对应的文本输入内容                        |
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

***

<a id="ETHX_Image"></a>
### struct ETHX_Image
+ **功能：** 用以描述图像对象
+ **成员及简介：** 未公开
+ **相关内容：**
    - [enum ETHX_ImageStyle](#ETHX_ImageStyle)
    - [ETHX_LoadImage()](#ETHX_LoadImage)
    - [ETHX_DrawImage()](#ETHX_DrawImage)

***

<a id="ETHX_Font"></a>
### struct ETHX_Font
+ **功能：** 用以描述字体对象
+ **成员及简介：** 未公开
+ **相关内容：**
    - [enum ETHX_FontStyle](#ETHX_FontStyle)
    - [ETHX_LoadFont()](#ETHX_LoadFont)
    - [ETHX_DrawText()](#ETHX_DrawText)
    - [ETHX_CreateTextImage()](#ETHX_CreateTextImage)

***

<a id="ETHX_Music"></a>
### struct ETHX_Music
+ **功能：** 用以描述音乐对象
+ **成员及简介：** 未公开
+ **相关内容：**
    - [ETHX_LoadMusic()](#ETHX_LoadMusic)
    - [ETHX_PlayMusic()](#ETHX_PlayMusic)

***

<a id="ETHX_Sound"></a>
### struct ETHX_Sound
+ **功能：** 用以描述音效对象
+ **成员及简介：** 未公开
+ **相关内容：**
    - [ETHX_LoadSound()](#ETHX_LoadSound)
    - [ETHX_PlaySound()](#ETHX_PlaySound)

***

<a id="ETHX_MessageBoxStyle"></a>
### enum ETHX_MessageBoxStyle
+ **功能：** 用以描述消息提示框类型
+ **成员及简介：**
    | 成员                  | 简介                     |
    |:----------------------|:-------------------------|
    | `ETHX_MSGBOX_ERROR`   | 消息提示框为错误         |
    | `ETHX_MSGBOX_WARNING` | 消息提示框为警告         |
    | `ETHX_MSGBOX_INFO`    | 消息提示框为普通提示信息 |
+ **相关内容：**
    - [ETHX_ShowMessageBox()](#ETHX_ShowMessageBox)
    - [ETHX_ShowConfirmMessageBox()](#ETHX_ShowConfirmMessageBox)

***

<a id="ETHX_WindowStyle"></a>
### enum ETHX_WindowStyle
+ **功能：** 用以描述窗口类型
+ **成员及简介：**
    | 成员                     | 简介           |
    |:-------------------------|:---------------|
    | `ETHX_WINDOW_FULLSCREEN` | 全屏窗口       |
    | `ETHX_WINDOW_BORDERLESS` | 无边框窗口     |
    | `ETHX_WINDOW_RESIZABLE`  | 窗口大小可变   |
    | `ETHX_WINDOW_MAXIMIZED`  | 窗口默认最大化 |
    | `ETHX_WINDOW_MINIMIZED`  | 窗口默认最小化 |
+ **相关内容：**
    - [ETHX_InitWindow()](#ETHX_InitWindow)

***

<a id="ETHX_ImageStyle"></a>
### enum ETHX_ImageStyle
+ **功能：** 用以描述图片对象翻转类型
+ **成员及简介：**
    | 成员                   | 简介         |
    |:-----------------------|:-------------|
    | `ETHX_IMAGE_FLIP_NONE` | 图片无翻转   |
    | `ETHX_IMAGE_FLIP_H`    | 图片水平翻转 |
    | `ETHX_IMAGE_FLIP_V`    | 图片竖直翻转 |
+ **相关内容：**
    - [ETHX_DrawImage()](#ETHX_DrawImage)

***

<a id="ETHX_FontStyle"></a>
### enum ETHX_FontStyle
+ **功能：** 用以描述字体样式
+ **成员及简介：**
    | 成员                      | 简介         |
    |:--------------------------|:-------------|
    | `ETHX_FONT_NORMAL`        | 默认样式字体 |
    | `ETHX_FONT_BOLD`          | 加粗字体     |
    | `ETHX_FONT_ITALIC`        | 斜体字体     |
    | `ETHX_FONT_UNDERLINE`     | 下划线字体   |
    | `ETHX_FONT_STRIKETHROUGH` | 删除线字体   |
+ **相关内容：**
    - [ETHX_SetFontStyle()](#ETHX_SetFontStyle)
    - [ETHX_GetFontStyle()](#ETHX_GetFontStyle)

***

<a id="ETHX_EventType"></a>
### enum ETHX_EventType
+ **功能：** 用以描述事件类型
+ **成员及简介：**
    | 成员                      | 简介         | 成员                       | 简介         |
    |:--------------------------|:-------------|:---------------------------|:-------------|
    | `ETHX_ET_WINDOWSHOWN`     | 窗口显示     | `ETHX_ET_WINDOWFOCUS_LOST` | 窗口失去焦点 |
    | `ETHX_ET_WINDOWHIDDEN`    | 窗口隐藏     | `ETHX_ET_WINDOWCLOSE`      | 窗口关闭     |
    | `ETHX_ET_WINDOWEXPOSED`   | 窗口暴露     | `ETHX_ET_KEYDOWN`          | 键盘按键按下 |
    | `ETHX_ET_WINDOWMOVED`     | 窗口移动     | `ETHX_ET_KEYUP`            | 键盘按键抬起 |
    | `ETHX_ET_WINDOWRESIZED`   | 窗口大小改变 | `ETHX_ET_MOUSEMOTION`      | 鼠标移动     |
    | `ETHX_ET_WINDOWMINIMIZED` | 最大化窗口   | `ETHX_ET_MOUSEDOWN`        | 鼠标按键按下 |
    | `ETHX_ET_WINDOWMAXIMIZED` | 最小化窗口   | `ETHX_ET_MOUSEUP`          | 鼠标按键抬起 |
    | `ETHX_ET_WINDOWENTER`     | 光标进入窗口 | `ETHX_ET_MOUSESCROLL`      | 鼠标滚轮滚动 |
    | `ETHX_ET_WINDOWLEAVE`     | 光标离开窗口 | `ETHX_ET_TEXTINPUT`        | 文本输入     |
    | `ETHX_ET_WINDOWFOCUS_GET` | 窗口获得焦点 | `ETHX_ET_QUIT`             | 程序退出     |
+ **相关内容：**
    - [enum ETHX_Event](#ETHX_Event)
    - [ETHX_UpdateEvent()](#ETHX_UpdateEvent)

***

<a id="ETHX_KeyCode"></a>
### enum ETHX_KeyCode
+ **功能：** 用以描述键盘按键键码
+ **成员及简介：**
    | 成员           | 简介            |
    |:---------------|:----------------|
    | `ETHX_KC_0`    | 数字：0         |
    | `ETHX_KC_1`    | 数字：1         |
    | `ETHX_KC_2`    | 数字：2         |
    | `ETHX_KC_3`    | 数字：3         |
    | `ETHX_KC_4`    | 数字：4         |
    | `ETHX_KC_5`    | 数字：5         |
    | `ETHX_KC_6`    | 数字：6         |
    | `ETHX_KC_7`    | 数字：7         |
    | `ETHX_KC_8`    | 数字：8         |
    | `ETHX_KC_9`    | 数字：9         |
    | `ETHX_KCP_0`   | 小键盘数字：0   |
    | `ETHX_KCP_00`  | 小键盘数字：00  |
    | `ETHX_KCP_000` | 小键盘数字：000 |
    | `ETHX_KCP_0`   | 小键盘数字：0   |
    | `ETHX_KCP_1`   | 小键盘数字：1   |
    | `ETHX_KCP_2`   | 小键盘数字：2   |
    | `ETHX_KCP_3`   | 小键盘数字：3   |
    | `ETHX_KCP_4`   | 小键盘数字：4   |
    | `ETHX_KCP_5`   | 小键盘数字：5   |
    | `ETHX_KCP_6`   | 小键盘数字：6   |
    | `ETHX_KCP_7`   | 小键盘数字：7   |
    | `ETHX_KCP_8`   | 小键盘数字：8   |
    | `ETHX_KCP_9`   | 小键盘数字：9   |
+ **相关内容：**
    - [enum ETHX_Event](#ETHX_Event)