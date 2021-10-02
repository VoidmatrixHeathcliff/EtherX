# EtherX 完全参考手册

在这里您可以找到关于 EtherX 的一切，但是在查阅此文档之前，我们建议您先阅读 [快速上手文档](quick-start.md)  
如果您在阅读期间发现有任何错误或建议，欢迎 [提交 issue](https://github.com/VoidmatrixHeathcliff/EtherX/issues) 或发送邮件至： Voidmatrix@qq.com

## 快速索引

<details>
    <summary>💼 结构体和枚举</summary>

| 结构体和枚举                                       | 简介                     |
|:---------------------------------------------------|:-------------------------|
| [struct ETHX_Color](#ETHX_Color)                   | 用以描述 EtherX 中的颜色 |
| [struct ETHX_Rect](#ETHX_Rect)                     | 用以描述矩形位置和大小   |
| [struct ETHX_Point](#ETHX_Point)                   | 用以描述点的位置         |
| [struct ETHX_Event](#ETHX_Event)                   | 用以描述交互事件         |
| [struct ETHX_Image](#ETHX_Image)                   | 用以描述图像对象         |
| [struct ETHX_Font](#ETHX_Font)                     | 用以描述字体对象         |
| [struct ETHX_Music](#ETHX_Music)                   | 用以描述音乐对象         |
| [struct ETHX_Sound](#ETHX_Sound)                   | 用以描述音效对象         |
| [enum ETHX_MessageBoxStyle](#ETHX_MessageBoxStyle) | 用以描述消息提示框样式   |
| [enum ETHX_WindowStyle](#ETHX_WindowStyle)         | 用以描述窗口样式         |
| [enum ETHX_ImageStyle](#ETHX_ImageStyle)           | 以描述图像对象翻转样式   |
| [enum ETHX_FontStyle](#ETHX_FontStyle)             | 用以描述字体样式         |
| [enum ETHX_EventType](#ETHX_EventType)             | 用以描述事件类型         |
| [enum ETHX_KeyCode](#ETHX_KeyCode)                 | 用以描述键盘按键键码     |
    
</details>

<details>
    <summary>🖥 窗口控制相关函数</summary>

| 函数名                                                      | 简介                         |
|:------------------------------------------------------------|:-----------------------------|
| [ETHX_InitWindow()](#ETHX_InitWindow)                       | 初始化 EtherX 并创建窗口     |
| [ETHX_QuitWindow()](#ETHX_QuitWindow)                       | 退出 EtherX 并关闭窗口       |
| [ETHX_ShowMessageBox()](#ETHX_ShowMessageBox)               | 显示信息提示框               |
| [ETHX_ShowConfirmMessageBox()](#ETHX_ShowConfirmMessageBox) | 显示信息提示确认窗口         |
| [ETHX_SetWindowTitle()](#ETHX_SetWindowTitle)               | 重新设置窗口标题             |
| [ETHX_GetWindowTitle()](#ETHX_GetWindowTitle)               | 获取窗口标题                 |
| [ETHX_SetWindowFullscreen()](#ETHX_SetWindowFullscreen)     | 设置窗口是否全屏             |
| [ETHX_SetWindowSize()](#ETHX_SetWindowSize)                 | 设置窗口大小                 |
| [ETHX_GetWindowSize()](#ETHX_GetWindowSize)                 | 获取窗口大小                 |
| [ETHX_GetWindowSize_HDPI()](#ETHX_GetWindowSize_HDPI)       | 获取高分辨率下窗口的实际大小 |
| [ETHX_SetWindowIcon()](#ETHX_SetWindowIcon)                 | 设置窗口图标                 |
| [ETHX_ClearWindow()](#ETHX_ClearWindow)                     | 清空窗口内容                 |
| [ETHX_UpdateWindow()](#ETHX_UpdateWindow)                   | 刷新窗口                     |

</details>

<details>
    <summary>🖼 绘图相关函数</summary>

| 函数名                                            | 简介                               |
|:--------------------------------------------------|:-----------------------------------|
| [ETHX_LoadImage()](#ETHX_LoadImage)               | 加载图像对象                       |
| [ETHX_SetImageColorKey()](#ETHX_SetImageColorKey) | 设置图像对象指定的透明颜色是否启用 |
| [ETHX_SetImageAplha()](#ETHX_SetImageAplha)       | 设置图像透明度                     |
| [ETHX_GetImageSize()](#ETHX_GetImageSize)         | 获取图像尺寸                       |
| [ETHX_DrawImage()](#ETHX_DrawImage)               | 绘制图像                           |
| [ETHX_SetDrawColor()](#ETHX_SetDrawColor)         | 设置绘图颜色                       |
| [ETHX_GetDrawColor()](#ETHX_GetDrawColor)         | 获取当前绘图颜色                   |
| [ETHX_DrawPoint()](#ETHX_DrawPoint)               | 绘制点                             |
| [ETHX_DrawLine()](#ETHX_DrawLine)                 | 绘制线段                           |
| [ETHX_DrawRectangle()](#ETHX_DrawRectangle)       | 绘制矩形                           |
| [ETHX_DrawCircle()](#ETHX_DrawCircle)             | 绘制圆                             |
| [ETHX_DrawEllipse()](#ETHX_DrawEllipse)           | 绘制椭圆                           |
| [ETHX_DrawPie()](#ETHX_DrawPie)                   | 绘制扇形                           |
| [ETHX_DrawTriangle()](#ETHX_DrawTriangle)         | 绘制三角形                         |
| [ETHX_LoadFont()](#ETHX_LoadFont)                 | 加载字体对象                       |
| [ETHX_SetFontStyle()](#ETHX_SetFontStyle)         | 设置字体样式                       |
| [ETHX_GetFontStyle()](#ETHX_GetFontStyle)         | 获取字体样式                       |
| [ETHX_GetTextSize()](#ETHX_GetTextSize)           | 获取指定字体的文本尺寸             |
| [ETHX_DrawText()](#ETHX_DrawText)                 | 绘制文本内容                       |
| [ETHX_CreateTextImage()](#ETHX_CreateTextImage)   | 创建文本图像                       |

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

<details>
    <summary>📌 附加内容</summary>

+ [窗口坐标系](#window-coordinate-system)
+ [图像坐标系](#image-coordinate-system)

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
    - [附加内容：窗口坐标系](#window-coordinate-system)

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
    - [附加内容：窗口坐标系](#window-coordinate-system)

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
    - [附加内容：窗口坐标系](#window-coordinate-system)

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
+ **功能：** 用以描述消息提示框样式
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
+ **功能：** 用以描述窗口样式
+ **成员及简介：**
    | 成员                     | 简介           |
    |:-------------------------|:---------------|
    | `ETHX_WINDOW_DEFAULT`    | 窗口默认样式   |
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
+ **功能：** 用以描述图像对象翻转样式
+ **成员及简介：**
    | 成员                   | 简介         |
    |:-----------------------|:-------------|
    | `ETHX_IMAGE_FLIP_NONE` | 图像无翻转   |
    | `ETHX_IMAGE_FLIP_H`    | 图像水平翻转 |
    | `ETHX_IMAGE_FLIP_V`    | 图像竖直翻转 |
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
    |         成员         |                             简介                             |           成员            |       简介        |
    |:--------------------:|:------------------------------------------------------------:|:-------------------------:|:-----------------:|
    |     `ETHX_KC_0`      |                              0                               |       `ETHX_KC_TAB`       |        Tab        |
    |     `ETHX_KC_1`      |                              1                               |    `ETHX_KC_CAPSLOCK`     |     大小写锁      |
    |     `ETHX_KC_2`      |                              2                               |     `ETHX_KC_NUMLOCK`     |      数字锁       |
    |     `ETHX_KC_3`      |                              3                               |   `ETHX_KC_PRINTSCREEN`   |       截屏        |
    |     `ETHX_KC_4`      |                              4                               |   `ETHX_KC_SCROLLLOCK`    |     滚动锁定      |
    |     `ETHX_KC_5`      |                              5                               |      `ETHX_KC_PAUSE`      |       暂停        |
    |     `ETHX_KC_6`      |                              6                               |    `ETHX_KC_AUDIOMUTE`    |       静音        |
    |     `ETHX_KC_7`      |                              7                               |    `ETHX_KC_AUDIOPREV`    |      上一首       |
    |     `ETHX_KC_8`      |                              8                               |    `ETHX_KC_AUDIONEXT`    |      下一首       |
    |     `ETHX_KC_9`      |                              9                               |    `ETHX_KC_AUDIOPLAY`    |       播放        |
    |    `ETHX_KCP_F1`     |                              F1                              |    `ETHX_KC_AUDIOSTOP`    |       停止        |
    |    `ETHX_KCP_F2`     |                              F2                              |    `ETHX_KC_VOLUMEUP`     |      音量 +       |
    |    `ETHX_KCP_F3`     |                              F3                              |   `ETHX_KC_VOLUMEDOWN`    |      音量 -       |
    |    `ETHX_KCP_F4`     |                              F4                              |  `ETHX_KC_BRIGHTNESSUP`   |      亮度 +       |
    |    `ETHX_KCP_F5`     |                              F5                              | `ETHX_KC_BRIGHTNESSDOWN`  |      亮度 -       |
    |    `ETHX_KCP_F6`     |                              F6                              |    `ETHX_KC_BACKQUOTE`    |         `         |
    |    `ETHX_KCP_F7`     |                              F7                              |     `ETHX_KC_EXCLAIM`     |         !         |
    |    `ETHX_KCP_F8`     |                              F8                              |       `ETHX_KC_AT`        |         @         |
    |    `ETHX_KCP_F9`     |                              F9                              |      `ETHX_KC_HASH`       |         #         |
    |    `ETHX_KC_F10`     |                             F10                              |     `ETHX_KC_DOLLAR`      |         $         |
    |    `ETHX_KC_F11`     |                             F11                              |      `ETHX_KC_CARET`      |         ^         |
    |    `ETHX_KC_F12`     |                             F12                              |    `ETHX_KC_AMPERSAND`    |         &         |
    |    `ETHX_KC_F13`     |                             F13                              |    `ETHX_KC_ASTERISK`     |         *         |
    |    `ETHX_KC_F14`     |                             F14                              |    `ETHX_KC_LEFTPAREN`    |         (         |
    |    `ETHX_KC_F15`     |                             F15                              |   `ETHX_KC_RIGHTPAREN`    |         )         |
    |    `ETHX_KC_F16`     |                             F16                              |      `ETHX_KC_MINUS`      |         -         |
    |    `ETHX_KC_F17`     |                             F17                              |   `ETHX_KC_UNDERSCORE`    |         _         |
    |    `ETHX_KC_F18`     |                             F18                              |      `ETHX_KC_PLUS`       |         +         |
    |    `ETHX_KC_F19`     |                             F19                              |     `ETHX_KC_EQUALS`      |         =         |
    |    `ETHX_KC_F20`     |                             F20                              |   `ETHX_KC_LEFTBRACKET`   |         [         |
    |    `ETHX_KC_F21`     |                             F21                              |  `ETHX_KC_RIGHTBRACKET`   |         ]         |
    |    `ETHX_KC_F22`     |                             F22                              |   `ETHX_KCP_LEFTBRACE`    |         {         |
    |    `ETHX_KC_F23`     |                             F23                              |   `ETHX_KCP_RIGHTBRACE`   |         }         |
    |    `ETHX_KC_F24`     |                             F24                              |      `ETHX_KC_COLON`      |         :         |
    |     `ETHX_KC_A`      |                              A                               |    `ETHX_KC_SEMICOLON`    |         ;         |
    |     `ETHX_KC_B`      |                              B                               |    `ETHX_KC_BACKSLASH`    |         \         |
    |     `ETHX_KC_C`      |                              C                               |      `ETHX_KC_QUOTE`      |         ‘         |
    |     `ETHX_KC_D`      |                              D                               |    `ETHX_KC_DBLQUOTE`     |         "         |
    |     `ETHX_KC_E`      |                              E                               |      `ETHX_KC_LESS`       |         <         |
    |     `ETHX_KC_F`      |                              F                               |     `ETHX_KC_GREATER`     |         >         |
    |     `ETHX_KC_G`      |                              G                               |      `ETHX_KC_COMMA`      |         ,         |
    |     `ETHX_KC_H`      |                              H                               |     `ETHX_KC_PERIOD`      |         .         |
    |     `ETHX_KC_I`      |                              I                               |    `ETHX_KC_QUESTION`     |         ?         |
    |     `ETHX_KC_J`      |                              J                               |      `ETHX_KC_SLASH`      |         /         |
    |     `ETHX_KC_K`      |                              K                               |   `ETHX_KC_VERTICALBAR`   |        \|         |
    |     `ETHX_KC_L`      |                              L                               |       `ETHX_KC_WWW`       |        WWW        |
    |     `ETHX_KC_M`      |                              M                               |      `ETHX_KC_MAIL`       |       Email       |
    |     `ETHX_KC_N`      |                              N                               |       `ETHX_KCP_0`        |     小键盘：0     |
    |     `ETHX_KC_O`      |                              O                               |       `ETHX_KCP_00`       |    小键盘：00     |
    |     `ETHX_KC_P`      |                              P                               |      `ETHX_KCP_000`       |    小键盘：000    |
    |     `ETHX_KC_Q`      |                              Q                               |       `ETHX_KCP_0`        |     小键盘：0     |
    |     `ETHX_KC_R`      |                              R                               |       `ETHX_KCP_1`        |     小键盘：1     |
    |     `ETHX_KC_S`      |                              S                               |       `ETHX_KCP_2`        |     小键盘：2     |
    |     `ETHX_KC_T`      |                              T                               |       `ETHX_KCP_3`        |     小键盘：3     |
    |     `ETHX_KC_U`      |                              U                               |       `ETHX_KCP_4`        |     小键盘：4     |
    |     `ETHX_KC_V`      |                              V                               |       `ETHX_KCP_5`        |     小键盘：5     |
    |     `ETHX_KC_W`      |                              W                               |       `ETHX_KCP_6`        |     小键盘：6     |
    |     `ETHX_KC_X`      |                              X                               |       `ETHX_KCP_7`        |     小键盘：7     |
    |     `ETHX_KC_Y`      |                              Y                               |       `ETHX_KCP_8`        |     小键盘：8     |
    |     `ETHX_KC_Z`      |                              Z                               |       `ETHX_KCP_9`        |     小键盘：9     |
    |    `ETHX_KC_ESC`     |                             Esc                              |       `ETHX_KCP_A`        |     小键盘：A     |
    |   `ETHX_KC_ENTER`    |                            Enter                             |       `ETHX_KCP_B`        |     小键盘：B     |
    | `ETHX_KC_BACKSPACE`  |                          Backspace                           |       `ETHX_KCP_C`        |     小键盘：C     |
    |   `ETHX_KC_RIGHT`    |                              →                               |       `ETHX_KCP_D`        |     小键盘：D     |
    |    `ETHX_KC_LEFT`    |                              ←                               |       `ETHX_KCP_E`        |     小键盘：E     |
    |    `ETHX_KC_DOWN`    |                              ↓                               |       `ETHX_KCP_F`        |     小键盘：F     |
    |     `ETHX_KC_UP`     |                              ↑                               |     `ETHX_KCP_ENTER`      |   小键盘：Enter   |
    |   `ETHX_KC_INSERT`   |                            Insert                            |   `ETHX_KCP_BACKSPACE`    | 小键盘：Backspace |
    |   `ETHX_KC_DELETE`   |                            Delete                            |     `ETHX_KC_KP_TAB`      |    小键盘：Tab    |
    |    `ETHX_KC_HOME`    |                             Home                             |    `ETHX_KC_KP_EXCLAM`    |     小键盘：!     |
    |    `ETHX_KC_END`     |                             End                              |      `ETHX_KC_KP_AT`      |     小键盘：@     |
    |   `ETHX_KC_PAGEUP`   |                            PageUp                            |     `ETHX_KC_KP_HASH`     |   小键盘：Hash    |
    |  `ETHX_KC_PAGEDOWN`  |                           PageDown                           |     `ETHX_KCP_CARET`      |     小键盘：^     |
    |  `ETHX_KC_LEFTCTRL`  |                           左 Ctrl                            |   `ETHX_KCP_AMPERSAND`    |     小键盘：&     |
    |  `ETHX_KC_LEFTGUI`   | 左 GUI（在 Windows 下为 Windows 键，在 Mac 下为 Control 键） |  `ETHX_KCP_DBLAMPERSAND`  |    小键盘：&&     |
    |  `ETHX_KC_LEFTALT`   |                            左 Alt                            |    `ETHX_KCP_ASTERISK`    |     小键盘：*     |
    | `ETHX_KC_LEFTSHIFT`  |                           左 Shift                           |   `ETHX_KCP_LEFTPAREN`    |     小键盘：(     |
    | `ETHX_KC_RIGHTCTRL`  |                           右 Ctrl                            |   `ETHX_KCP_RIGHTPAREN`   |     小键盘：)     |
    |  `ETHX_KC_RIGHTGUI`  | 右 GUI（在 Windows 下为 Windows 键，在 Mac 下为 Control 键） |     `ETHX_KCP_MINUS`      |     小键盘：-     |
    |  `ETHX_KC_RIGHTALT`  |                            右 Alt                            |      `ETHX_KCP_PLUS`      |     小键盘：+     |
    | `ETHX_KC_RIGHTSHIFT` |                           右 Shift                           |     `ETHX_KCP_EQUALS`     |     小键盘：=     |
    |   `ETHX_KC_SPACE`    |                             空格                             | `ETHX_KCP_DBLVERTICALBAR` |   小键盘：\|\|    |
+ **备注：**  
ETHX_KeyCode 结构体仅表示键码表，部分字符可能无法通过物理按键触发
+ **相关内容：**
    - [enum ETHX_Event](#ETHX_Event)
    - [ETHX_UpdateEvent()](#ETHX_UpdateEvent)

***

<a id="ETHX_InitWindow"></a>
### ETHX_InitWindow()
+ **功能：** 初始化 EtherX 并创建窗口
+ **函数原型：**
    ```c++
        void ETHX_InitWindow(const std::string& title, int width, int height, ETHX_WindowStyle style = ETHX_WINDOW_DEFAULT);
    ```
+ **参数简介：**
    | 参数     | 简介                                   |
    |:---------|:---------------------------------------|
    | `title`  | 窗口标题                               |
    | `width`  | 窗口宽度                               |
    | `height` | 窗口高度                               |
    | `style`  | 窗口样式，默认为有边框且大小固定的窗口 |
+ **返回值简介：** 无
+ **备注：**  
ETHX_InitWindow 用以初始化 EtherX 内部组件，必须在调用其他 EtherX 函数前调用
+ **代码示例：**
    ```c++
        // 创建一个标题为 HelloWorld 的尺寸为 1280x720 的大小可变并且默认最大化的窗口
        ETHX_InitWindow(
            "HelloWorld",
            1280, 720,
            ETHX_WINDOW_RESIZABLE | ETHX_WINDOW_MAXIMIZED
        );
    ```
+ **相关内容：**
    - [enum ETHX_WindowStyle](#ETHX_WindowStyle)
    - [ETHX_QuitWindow()](#ETHX_QuitWindow)

***

<a id="ETHX_QuitWindow"></a>
### ETHX_QuitWindow()
+ **功能：** 退出 EtherX 并关闭窗口
+ **函数原型：**
    ```c++
        void ETHX_QuitWindow();
    ```
+ **参数简介：** 无
+ **返回值简介：** 无
+ **相关内容：**
    - [ETHX_InitWindow()](#ETHX_InitWindow)

***

<a id="ETHX_ShowMessageBox"></a>
### ETHX_ShowMessageBox()
+ **功能：** 显示信息提示框
+ **函数原型：**
    ```c++
        void ETHX_ShowMessageBox(const std::string& title, const std::string& msg, ETHX_MessageBoxStyle style);
    ```
+ **参数简介：** 
    | 参数    | 简介           |
    |:--------|:---------------|
    | `title` | 信息提示框标题 |
    | `msg`   | 信息提示框内容 |
    | `style` | 信息提示框样式 |
+ **返回值简介：** 无
+ **相关内容：**
    - [enum ETHX_MessageBoxStyle](#ETHX_MessageBoxStyle)
    - [ETHX_ShowConfirmMessageBox()](#ETHX_ShowConfirmMessageBox)

***

<a id="ETHX_ShowConfirmMessageBox"></a>
### ETHX_ShowConfirmMessageBox()
+ **功能：** 显示信息提示确认窗口
+ **函数原型：**
    ```c++
    bool ETHX_ShowConfirmMessageBox(const std::string& title, const std::string& msg, ETHX_MessageBoxStyle style, std::string& ok_text = "OK", const std::string& cancel_text = "Cancel");
    ```
+ **参数简介：** 
    | 参数          | 简介                          |
    |:--------------|:------------------------------|
    | `title`       | 信息提示框标题                |
    | `msg`         | 信息提示框内容                |
    | `style`       | 信息提示框样式                |
    | `ok_text`     | 确认按钮文本，默认为 `OK`     |
    | `cancel_text` | 取消按钮文本，默认为 `Cancel` |
+ **返回值简介：** 用户点击确认按钮返回 `true`，反之返回 `false`
+ **代码示例：**
    ```c++
    // 如果用户点击确认按钮输出 Yes，反之输出 No
    if (ETHX_ShowConfirmMessageBox("Question", "Are you OK ?", ETHX_MSGBOX_WARNING))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    ```
+ **相关内容：**
    - [enum ETHX_MessageBoxStyle](#ETHX_MessageBoxStyle)
    - [ETHX_ShowMessageBox()](#ETHX_ShowMessageBox)

***

<a id="ETHX_SetWindowTitle"></a>
### ETHX_SetWindowTitle()
+ **功能：** 重新设置窗口标题
+ **函数原型：**
    ```c++
    void ETHX_SetWindowTitle(std::string title);
    ```
+ **参数简介：** 
    | 参数    | 简介         |
    |:--------|:-------------|
    | `title` | 新的窗口标题 |
+ **返回值简介：** 无
+ **相关内容：**
    - [ETHX_InitWindow()](#ETHX_InitWindow)
    - [ETHX_GetWindowTitle()](#ETHX_GetWindowTitle)

***

<a id="ETHX_GetWindowTitle"></a>
### ETHX_GetWindowTitle()
+ **功能：** 获取窗口标题
+ **函数原型：**
    ```c++
    std::string ETHX_GetWindowTitle();
    ```
+ **参数简介：** 无
+ **返回值简介：** 窗口当前标题
+ **相关内容：**
    - [ETHX_InitWindow()](#ETHX_InitWindow)
    - [ETHX_SetWindowTitle()](#ETHX_SetWindowTitle)

***

<a id="ETHX_SetWindowFullscreen"></a>
### ETHX_SetWindowFullscreen()
+ **功能：** 设置窗口是否全屏
+ **函数原型：**
    ```c++
    ETHX_SetWindowFullscreen(bool flag);
    ```
+ **参数简介：** 
    | 参数   | 简介     |
    |:-------|:---------|
    | `flag` | 是否全屏 |
+ **返回值简介：** 无
+ **相关内容：**
    - [ETHX_InitWindow()](#ETHX_InitWindow)

***

<a id="ETHX_SetWindowSize"></a>
### ETHX_SetWindowSize()
+ **功能：** 设置窗口大小
+ **函数原型：**
    ```c++
    void ETHX_SetWindowSize(int width, int height);
    ```
+ **参数简介：** 
    | 参数     | 简介     |
    |:---------|:---------|
    | `width`  | 窗口宽度 |
    | `height` | 窗口高度 |
+ **返回值简介：** 无
+ **相关内容：**
    - [ETHX_InitWindow()](#ETHX_InitWindow)
    - [ETHX_GetWindowSize()](#ETHX_GetWindowSize)

***

<a id="ETHX_GetWindowSize"></a>
### ETHX_GetWindowSize()
+ **功能：** 获取窗口大小
+ **函数原型：**
    ```c++
    void ETHX_GetWindowSize(int& width, int& height);
    ```
+ **参数简介：** 
    | 参数     | 简介     |
    |:---------|:---------|
    | `width`  | 窗口宽度 |
    | `height` | 窗口高度 |
+ **返回值简介：** 无
+ **代码示例：**
    ```c++
    int width, height;
    ETHX_GetWindowSize(width, height);
    std::cout << "width: " << width << " height: " << height << std::endl;
    ```
+ **相关内容：**
    - [ETHX_GetWindowSize()](#ETHX_GetWindowSize)
    - [ETHX_GetWindowSize_HDPI()](#ETHX_GetWindowSize_HDPI)

***

<a id="ETHX_GetWindowSize_HDPI"></a>
### ETHX_GetWindowSize()
+ **功能：** 获取高分辨率下窗口的实际大小
+ **函数原型：**
    ```c++
    void ETHX_GetWindowSize_HDPI(int& width, int& height);
    ```
+ **参数简介：** 
    | 参数     | 简介     |
    |:---------|:---------|
    | `width`  | 窗口宽度 |
    | `height` | 窗口高度 |
+ **返回值简介：** 无
+ **备注：**  
由于高分辨率的存在，在某些设备上使用 ETHX_GetWindowSize_HDPI 函数获取到的尺寸为实际可绘图尺寸
+ **代码示例：**
    ```c++
    int width, height;
    ETHX_GetWindowSize(width, height);
    std::cout << "Actually Drawable Size:" << std::endl;
    std::cout << "width: " << width << " height: " << height << std::endl;
    ```
+ **相关内容：**
    - [ETHX_GetWindowSize()](#ETHX_GetWindowSize)

***

<a id="ETHX_SetWindowIcon"></a>
### ETHX_SetWindowIcon()
+ **功能：** 设置窗口图标
+ **函数原型：**
    ```c++
    void ETHX_SetWindowIcon(ETHX_Image* image);
    ```
+ **参数简介：** 
    | 参数    | 简介             |
    |:--------|:-----------------|
    | `image` | 窗口图标图像对象 |
+ **返回值简介：** 无
+ **相关内容：**
    - [ETHX_LoadImage()](#ETHX_LoadImage)

***

<a id="ETHX_ClearWindow"></a>
### ETHX_ClearWindow()
+ **功能：** 清空窗口内容
+ **函数原型：**
    ```c++
    void ETHX_ClearWindow();
    ```
+ **参数简介：** 无
+ **返回值简介：** 无
+ **相关内容：**
    - [ETHX_UpdateWindow()](#ETHX_UpdateWindow)

***

<a id="ETHX_UpdateWindow"></a>
### ETHX_UpdateWindow()
+ **功能：** 刷新窗口
+ **函数原型：**
    ```c++
    void ETHX_UpdateWindow();
    ```
+ **参数简介：** 无
+ **返回值简介：** 无
+ **备注：**  
EtherX 所有的窗口绘图操作都在渲染缓冲区中进行，只有调用 ETHX_UpdateWindow 函数后才会将先前的绘制操作实际刷新到屏幕上

***

<a id="ETHX_LoadImage"></a>
### ETHX_LoadImage()
+ **功能：** 加载图像对象
+ **函数原型：**
    - **原型 1：**
        ```c++
        ETHX_Image* ETHX_LoadImage(const std::string& path);
        ```
        + **参数简介：**  
            | 参数   | 简介         |
            |:-------|:-------------|
            | `path` | 图像文件路径 |
        + **返回值简介：** 图像对象指针，加载失败则返回 `nullptr`
    - **原型 2：**
        ```c++
        ETHX_API ETHX_Image* ETHX_LoadImage(void* data, size_t size);
        ```
        + **参数简介：**  
            | 参数   | 简介                   |
            |:-------|:-----------------------|
            | `data` | 存储图像数据的内存指针 |
            | `size` | 图像数据大小           |
        + **返回值简介：** 图像对象指针，加载失败则返回 `nullptr`
+ **备注：**  
图像对象指针可以直接使用 `delete` 销毁内存
+ **代码示例：**
    ```c++
    ETHX_Image* pImage;
    // 检查是否加载成功，若失败则输出提示信息
    if (!(pImage = ETHX_LoadImage("Hello.png")))
        std::cout << "Load Image Error !" << std::endl;
    // 销毁图像对象内存
    delete pImage; pImage = nullptr;
    ```
+ **相关内容：**
    - [struct ETHX_Image](#ETHX_Image)
    - [ETHX_DrawImage()](#ETHX_DrawImage)

***

<a id="ETHX_SetImageColorKey"></a>
### ETHX_SetImageColorKey()
+ **功能：** 设置图像对象指定的透明颜色是否启用
+ **函数原型：**
    ```c++
    void ETHX_SetImageColorKey(ETHX_Image* image, const ETHX_Color& color, bool flag);
    ```
+ **参数简介：**  
    | 参数    | 简介         |
    |:--------|:-------------|
    | `image` | 图像对象     |
    | `color` | 指定颜色     |
    | `bool`  | 是否启用透明 |
+ **返回值简介：** 无
+ **备注：**  
启用后的指定颜色将变为完全透明，常用于抠除不支持透明通道的图像格式（如：JPG）图像的指定颜色部分
+ **相关内容：**
    - [struct ETHX_Image](#ETHX_Image)
    - [ETHX_SetImageAplha()](#ETHX_SetImageAplha)

***

<a id="ETHX_SetImageAplha"></a>
### ETHX_SetImageAplha()
+ **功能：** 设置图像透明度
+ **函数原型：**
    ```c++
    void ETHX_SetImageAplha(ETHX_Image* image, Uint8 alpha);
    ```
+ **参数简介：**  
    | 参数    | 简介                     |
    |:--------|:-------------------------|
    | `image` | 图像对象                 |
    | `alpha` | 透明度，取值范围为 0~255 |
+ **返回值简介：** 无
+ **相关内容：**
    - [struct ETHX_Image](#ETHX_Image)
    - [ETHX_SetImageColorKey()](#ETHX_SetImageColorKey)

***

<a id="ETHX_GetImageSize"></a>
### ETHX_GetImageSize()
+ **功能：** 获取图像尺寸
+ **函数原型：**
    ```c++
    void ETHX_GetImageSize(ETHX_Image* image, int& width, int& height);
    ```
+ **参数简介：**  
    | 参数     | 简介     |
    |:---------|:---------|
    | `image`  | 图像对象 |
    | `width`  | 图像宽度 |
    | `height` | 图像高度 |
+ **返回值简介：** 无
+ **代码示例：**
    ```c++
    // ETHX_Image* pImage = ...

    int width, height;
    ETHX_GetImageSize(pImage, width, height);
    std::cout << "width: " << width << " height: " << height << std::endl;
    ```
+ **相关内容：**
    - [struct ETHX_Image](#ETHX_Image)

***

<a id="ETHX_DrawImage"></a>
### ETHX_DrawImage()
+ **功能：** 绘制图像
+ **函数原型：**
    - **原型 1：**
        ```c++
        void ETHX_DrawImage(ETHX_Image* image, const ETHX_Point& pos);
        ```
        + **参数简介：**  
            | 参数    | 简介                               |
            |:--------|:-----------------------------------|
            | `image` | 图像对象                           |
            | `pos`   | 图像左上角顶点在屏幕坐标系下的位置 |
        + **返回值简介：** 无
    - **原型 2：**
        ```c++
        void ETHX_DrawImage(ETHX_Image* image, const ETHX_Rect& show_rect);
        ```
        + **参数简介：**  
            | 参数        | 简介                         |
            |:------------|:-----------------------------|
            | `image`     | 图像对象                     |
            | `show_rect` | 图像在屏幕坐标系下的显示区域 |
        + **返回值简介：** 无
    - **原型 3：**
        ```c++
        void ETHX_DrawImage(ETHX_Image* image, const ETHX_Rect& show_rect, const ETHX_Rect& clip_rect);
        ```
        + **参数简介：**  
            | 参数        | 简介                         |
            |:------------|:-----------------------------|
            | `image`     | 图像对象                     |
            | `show_rect` | 图像在屏幕坐标系下的显示区域 |
            | `clip_rect` | 图像在图像坐标系下的裁剪区域 |
        + **返回值简介：** 无
    - **原型 4：**
        ```c++
        ETHX_API void ETHX_DrawImage(ETHX_Image* image, const ETHX_Rect& show_rect, const ETHX_Rect& clip_rect, const ETHX_Point& center, double angle, ETHX_ImageStyle style = ETHX_IMAGE_FLIP_NONE);
        ```
        + **参数简介：**  
            | 参数        | 简介                                         |
            |:------------|:---------------------------------------------|
            | `image`     | 图像对象                                     |
            | `show_rect` | 图像在屏幕坐标系下的显示区域                 |
            | `clip_rect` | 图像在图像坐标系下的裁剪区域                 |
            | `center`    | 图像在图像坐标系下的旋转中心位置             |
            | `angle`     | 图像在图像坐标系下的旋转角度，逆时针为正方向 |
            | `style`     | 图像在图像坐标系下的翻转样式，默认为无翻转   |
        + **返回值简介：** 无
+ **备注：**  
ETHX_DrawImage 四个重载的应用场景总结：
    | 参数   | 简介                                           |
    |:-------|:-----------------------------------------------|
    | 重载 1 | 仅需要设置图像显示位置、图像默认大小显示时使用 |
    | 重载 2 | 需要对图像进行缩放显示时使用                   |
    | 重载 3 | 需要对图像进行区域显示（裁剪）时使用           |
    | 重载 4 | 需要对图像进行旋转或翻转显示时使用             |
+ **代码示例：**
    ```c++
    // ETHX_Image* pImage = ...

    // 将图像铺满窗口
    ETHX_Rect show_rect;
    show_rect.x = 0, show_rect.y = 0;
    ETHX_GetWindowSize(show_rect.w, show_rect.h);
    ETHX_DrawImage(pImage, show_rect);
    ```
+ **相关内容：**
    - [enum ETHX_ImageStyle](#ETHX_ImageStyle)
    - [struct ETHX_Rect](#ETHX_Rect)
    - [struct ETHX_Point](#ETHX_Point)
    - [struct ETHX_Image](#ETHX_Image)
    - [ETHX_DrawImage()](#ETHX_DrawImage)
    - [附加内容：窗口坐标系](#window-coordinate-system)
    - [附加内容：图像坐标系](#image-coordinate-system)

***

<a id="ETHX_SetDrawColor"></a>
### ETHX_SetDrawColor()
+ **功能：** 设置绘图颜色
+ **函数原型：**
    ```c++
    void ETHX_SetDrawColor(const ETHX_Color& color);
    ```
+ **参数简介：**  
    | 参数    | 简介     |
    |:--------|:---------|
    | `color` | 绘图颜色 |
+ **返回值简介：** 无
+ **备注：**  
在设置绘图颜色后，后续所有的清屏、图元绘制和字体渲染都将使用此颜色
+ **相关内容：**
    - [struct ETHX_Color](#ETHX_Color)
    - [ETHX_GetDrawColor()](#ETHX_GetDrawColor)

***

<a id="ETHX_GetDrawColor"></a>
### ETHX_GetDrawColor()
+ **功能：** 获取当前绘图颜色
+ **函数原型：**
    ```c++
    ETHX_Color ETHX_GetDrawColor();
    ```
+ **参数简介：无
+ **返回值简介：** 当前绘图颜色
+ **相关内容：**
    - [struct ETHX_Color](#ETHX_Color)
    - [ETHX_SetDrawColor()](#ETHX_SetDrawColor)

***

<a id="ETHX_DrawPoint"></a>
### ETHX_DrawPoint()
+ **功能：** 绘制点
+ **函数原型：**
    ```c++
    void ETHX_DrawPoint(const ETHX_Point& point);
    ```
+ **参数简介：  
    | 参数    | 简介                   |
    |:--------|:-----------------------|
    | `point` | 点在窗口坐标系下的位置 |
+ **返回值简介：** 无
+ **相关内容：**
    - [struct ETHX_Point](#ETHX_Point)

***

<a id="ETHX_DrawLine"></a>
### ETHX_DrawLine()
+ **功能：** 绘制线段
+ **函数原型：**
    - **原型 1：**
        ```c++
        void ETHX_DrawLine(const ETHX_Point& begin, const ETHX_Point& end);
        ```
        + **参数简介：**  
            | 参数    | 简介     |
            |:--------|:---------|
            | `begin` | 线段起点 |
            | `end`   | 线段终点 |
        + **返回值简介：** 无
    - **原型 2：**
        ```c++
        void ETHX_DrawLine(const ETHX_Point& begin, const ETHX_Point& end, Uint8 width);
        ```
        + **参数简介：**  
            | 参数    | 简介     |
            |:--------|:---------|
            | `begin` | 线段起点 |
            | `end`   | 线段终点 |
            | `width` | 线条宽度 |
        + **返回值简介：** 无
+ **相关内容：**
    - [struct ETHX_Point](#ETHX_Point)

***

<a id="ETHX_DrawRectangle"></a>
### ETHX_DrawRectangle()
+ **功能：** 绘制矩形
+ **函数原型：**
    - **原型 1：**
        ```c++
        void ETHX_DrawRectangle(const ETHX_Rect& rect, bool fill = false);
        ```
        + **参数简介：**  
            | 参数   | 简介                     |
            |:-------|:-------------------------|
            | `rect` | 矩形在窗口坐标系下的区域 |
            | `fill` | 是否填充，默认为不填充   |
        + **返回值简介：** 无
    - **原型 2：**
        ```c++
        void ETHX_DrawRectangle(const ETHX_Rect& rect, int radius, bool fill = false);
        ```
        + **参数简介：**  
            | 参数     | 简介                     |
            |:---------|:-------------------------|
            | `rect`   | 矩形在窗口坐标系下的区域 |
            | `radius` | 矩形圆角所在圆的半径大小 |
            | `fill`   | 是否填充，默认为不填充   |
        + **返回值简介：** 无
+ **相关内容：**
    - [struct ETHX_Rect](#ETHX_Rect)

***

<a id="ETHX_DrawCircle"></a>
### ETHX_DrawCircle()
+ **功能：** 绘制圆
+ **函数原型：**
    ```c++
    void ETHX_DrawCircle(const ETHX_Point& center, int radius, bool fill = false);
    ```
+ **参数简介：**  
    | 参数     | 简介                     |
    |:---------|:-------------------------|
    | `center` | 圆心在窗口坐标系下的位置 |
    | `radius` | 圆的半径大小             |
    | `fill`   | 是否填充，默认为不填充   |
+ **返回值简介：** 无
+ **相关内容：**
    - [struct ETHX_Point](#ETHX_Point)

***

<a id="ETHX_DrawEllipse"></a>
### ETHX_DrawEllipse()
+ **功能：** 绘制椭圆
+ **函数原型：**
    ```c++
    void ETHX_DrawEllipse(const ETHX_Point& center, int radius_x, int radius_y, bool fill = false);
    ```
+ **参数简介：**  
    | 参数       | 简介                                |
    |:-----------|:------------------------------------|
    | `center`   | 椭圆圆心在窗口坐标系下的位置        |
    | `radius_x` | 椭圆在窗口坐标系下 x 轴方向半径大小 |
    | `radius_y` | 椭圆在窗口坐标系下 x 轴方向半径大小 |
    | `fill`     | 是否填充，默认为不填充              |
+ **返回值简介：** 无
+ **相关内容：**
    - [struct ETHX_Point](#ETHX_Point)

***

<a id="ETHX_DrawPie"></a>
### ETHX_DrawPie()
+ **功能：** 绘制扇形
+ **函数原型：**
    ```c++
    void ETHX_DrawPie(const ETHX_Point& center, int radius, int start_angle, int end_angle, bool fill = false);
    ```
+ **参数简介：**  
    | 参数          | 简介                                   |
    |:--------------|:---------------------------------------|
    | `center`      | 扇形所在圆的圆心在窗口坐标系下的位置   |
    | `radius`      | 扇形所在圆的半径大小                   |
    | `start_angle` | 扇形所在圆的的起始角度，逆时针为正方向 |
    | `end_angle`   | 扇形所在圆的的终止角度，逆时针为正方向 |
    | `fill`        | 是否填充，默认为不填充                 |
+ **返回值简介：** 无
+ **相关内容：**
    - [struct ETHX_Point](#ETHX_Point)

***

<a id="ETHX_DrawTriangle"></a>
### ETHX_DrawTriangle()
+ **功能：** 绘制三角形
+ **函数原型：**
    ```c++
    void ETHX_DrawTriangle(const ETHX_Point& point_1, const ETHX_Point& point_2, const ETHX_Point& point_3, bool fill = false);
    ```
+ **参数简介：**  
    | 参数      | 简介                                  |
    |:----------|:--------------------------------------|
    | `point_1` | 三角形第 1 个顶点在窗口坐标系下的位置 |
    | `point_2` | 三角形第 2 个顶点在窗口坐标系下的位置 |
    | `point_3` | 三角形第 3 个顶点在窗口坐标系下的位置 |
    | `fill`    | 是否填充，默认为不填充                |
+ **返回值简介：** 无
+ **相关内容：**
    - [struct ETHX_Point](#ETHX_Point)

***

<a id="ETHX_LoadFont"></a>
### ETHX_LoadFont()
+ **功能：** 加载字体对象
+ **函数原型：**
    - **原型 1：**
        ```c++
        ETHX_Font* ETHX_LoadFont(const std::string& path, int ptsize);
        ```
        + **参数简介：**  
            | 参数     | 简介         |
            |:---------|:-------------|
            | `path`   | 图像文件路径 |
            | `ptsize` | 字体大小     |
        + **返回值简介：** 字体对象指针，加载失败则返回 `nullptr`
    - **原型 2：**
        ```c++
        ETHX_Font* ETHX_LoadFont(void* data, size_t size, int ptsize);
        ```
        + **参数简介：**  
            | 参数     | 简介                   |
            |:---------|:-----------------------|
            | `data`   | 存储字体数据的内存指针 |
            | `size`   | 字体数据大小           |
            | `ptsize` | 字体大小               |
        + **返回值简介：** 字体对象指针，加载失败则返回 `nullptr`
+ **备注：**  
字体对象指针可以直接使用 `delete` 销毁内存；  
字体大小为在 72DPI 下的字体大小，这通常代表着单位为像素的文本高度
+ **代码示例：**
    ```c++
    ETHX_Font* pFont;
    // 检查是否加载成功，若失败则输出提示信息
    if (!(pFont = ETHX_LoadFont("MyFont.ttf", 75)))
        std::cout << "Load Font Error !" << std::endl;
    // 销毁字体对象内存
    delete pFont; pFont = nullptr;
    ```
+ **相关内容：**
    - [struct ETHX_Font](#ETHX_Font)
    - [ETHX_DrawText()](#ETHX_DrawText)
    - [ETHX_CreateTextImage()](#ETHX_CreateTextImage)

***

<a id="ETHX_SetFontStyle"></a>
### ETHX_SetFontStyle()
+ **功能：** 设置字体样式
+ **函数原型：**
    ```c++
    void ETHX_SetFontStyle(ETHX_Font* font, ETHX_FontStyle style);
    ```
+ **参数简介：**  
    | 参数    | 简介     |
    |:--------|:---------|
    | `font`  | 字体对象 |
    | `style` | 字体样式 |
+ **返回值简介：** 无
+ **代码示例：**
    ```c++
    // ETHX_Font* pFont = ...
    
    // 设置字体样式为加粗和斜体
    ETHX_SetFontStyle(pFont, ETHX_FONT_BOLD | ETHX_FONT_ITALIC);
    ```
+ **相关内容：**
    - [enum ETHX_FontStyle](#ETHX_FontStyle)
    - [struct ETHX_Font](#ETHX_Font)
    - [ETHX_GetFontStyle()](#ETHX_GetFontStyle)

***

<a id="ETHX_GetFontStyle"></a>
### ETHX_GetFontStyle()
+ **功能：** 获取字体样式
+ **函数原型：**
    ```c++
    int ETHX_GetFontStyle(ETHX_Font* font);
    ```
+ **参数简介：**  
    | 参数   | 简介     |
    |:-------|:---------|
    | `font` | 字体对象 |
+ **返回值简介：** 字体样式，可以按位判断是否具有指定样式
+ **代码示例：**
    ```c++
    // ETHX_Font* pFont = ...
    
    // 若字体样式包含粗体则输出信息
    int style = ETHX_SetFontStyle(pFont);
    if (style | ETHX_FONT_BOLD)
        std::cout << "BOLD FONT !" << std::endl;
    ```
+ **相关内容：**
    - [enum ETHX_FontStyle](#ETHX_FontStyle)
    - [struct ETHX_Font](#ETHX_Font)
    - [ETHX_SetFontStyle()](#ETHX_SetFontStyle)

***

<a id="ETHX_GetTextSize"></a>
### ETHX_GetTextSize()
+ **功能：** 获取指定字体的文本尺寸
+ **函数原型：**
    ```c++
    void ETHX_GetTextSize(ETHX_Font* font, const std::string& text, int& width, int& height);
    ```
+ **参数简介：**  
    | 参数     | 简介     |
    |:---------|:---------|
    | `font`   | 字体对象 |
    | `text`   | 文本内容 |
    | `width`  | 文本宽度 |
    | `height` | 文本高度 |
+ **返回值简介：** 无
+ **备注：**  
虽然可以使用 ETHX_CreateTextImage 生成文本图像后再通过 ETHX_GetImageSize 获取其渲染后尺寸，但是使用 ETHX_GetTextSize 则可以避免渲染带来的性能浪费，仅仅通过字体内置的字符宽高数据计算出渲染后的尺寸
+ **代码示例：**
    ```c++
    // ETHX_Font* pFont = ...
    
    // 获取并输出字符串 HelloWorld 使用指定字体渲染后的文本尺寸
    int width, height;
    ETHX_GetTextSize(pFont, "HelloWorld", width, height);
    std::cout << "Text width: " << width << std::endl;
    std::cout << "Text height: " << height << std::endl;
    ```
+ **相关内容：**
    - [struct ETHX_Font](#ETHX_Font)

***

<a id="ETHX_DrawText"></a>
### ETHX_DrawText()
+ **功能：** 绘制文本内容
+ **函数原型：**
    - **原型 1：**
        ```c++
        void ETHX_DrawText(ETHX_Font* font, const std::string& text, const ETHX_Point& pos);
        ```
        + **参数简介：**  
            | 参数   | 简介                               |
            |:-------|:-----------------------------------|
            | `font` | 字体对象                           |
            | `text` | 文本内容                           |
            | `pos`  | 文本左上角顶点在屏幕坐标系下的位置 |
        + **返回值简介：** 无
    - **原型 2：**
        ```c++
        void ETHX_DrawText(ETHX_Font* font, const std::string& text, const ETHX_Rect& show_rect);
        ```
        + **参数简介：**  
            | 参数        | 简介                     |
            |:------------|:-------------------------|
            | `font`      | 字体对象                 |
            | `text`      | 文本内容                 |
            | `show_rect` | 文本屏幕坐标系下显示区域 |
        + **返回值简介：** 无
+ **备注：**  
ETHX_DrawText 为简化版本的字体渲染，在此函数内部，EtherX 先通过调用 ETHX_CreateTextImage 创建字体图像，然后再通过 ETHX_DrawImage 将图像渲染到窗口上，最后会销毁此字体图像；  
若需手动控制被渲染出字体的生命周期，防止因频繁创建销毁导致性能浪费，请使用 ETHX_CreateTextImage 创建并保存渲染后的字体图像，详见 [ETHX_CreateTextImage](#ETHX_CreateTextImage) 示例代码
+ **代码示例：**
    ```c++
    // ETHX_Font* pFont = ...

    // 将 HelloWorld 字符串以默认大小渲染到窗口左上角
    ETHX_Point point = { 0, 0 };
    ETHX_DrawText(pFont, "HelloWorld", point);
    ```
+ **相关内容：**
    - [struct ETHX_Font](#ETHX_Font)
    - [ETHX_CreateTextImage()](#ETHX_CreateTextImage)

***

<a id="ETHX_CreateTextImage"></a>
### ETHX_CreateTextImage()
+ **功能：** 创建文本图像
+ **函数原型：**
    ```c++
    ETHX_Image* ETHX_CreateTextImage(ETHX_Font* font, const std::string& text);
    ```
+ **参数简介：**  
    | 参数   | 简介     |
    |:-------|:---------|
    | `font` | 字体对象 |
    | `text` | 文本内容 |
+ **返回值简介：** 文本图像，创建失败则返回 `nullptr`
+ **备注：**  
相较于 ETHX_DrawText，ETHX_CreateTextImage 可以返回并缓存创建出的文本图像，从而节省频繁渲染创建文本图像所带来的性能损耗；
并且由于返回值为 EtherX 的通用图像格式，应用于图像的函数如：裁剪、透明度变换等操作同样也可作用于文本图像
+ **代码示例：**
    ```c++
    // ETHX_Font* pFont = ...
    
    // 使用文本图像的方式将 HelloWorld 字符串以默认大小渲染到窗口左上角 
    ETHX_Image* pImage = ETHX_CreateTextImage(pFont, "HelloWorld");
    ETHX_Point point = { 0, 0 };
    ETHX_DrawImage(pFont, pImage, point);
    ```
+ **相关内容：**
    - [struct ETHX_Image](#ETHX_Image)
    - [struct ETHX_Font](#ETHX_Font)
    - [ETHX_DrawText()](#ETHX_DrawText)