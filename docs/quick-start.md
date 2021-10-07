# 欢迎来到 EtherX 快速开始文档

EtherX 是基于 SDL2 等开源项目实现的以教学场景为目标的 C++ 游戏开发工具库  
在这里，我们将结合实例告诉你 EtherX 的基本用法

## 你将会学到些什么呢？

本次示例，我们将教你如何绘制一个跟随鼠标位置的圆形  
要实现这个程序，我们将涉及以下内容：

+ 帧率控制
+ 事件处理

如果你已经学习过以上内容，那么你只需要复制下最后的源代码阅读即可

## EtherX库链接

在使用 EtherX 之前，我们需要先将 EtherX 的静态库链接至我们的编译器，并将头文件添加到工程目录中
如果你不知道如何执行上述操作，请查阅 [这里](details/how-to-build.md)

# 我们需要一个窗口

> 神说，要有窗口，便有了窗口。

这样我们的图像才有地方绘制，才有了形形色色的界面。

我想，如果你初学 C++ 的话，你有可能一直在和一个黑框框打交道，

如果确实是这样的话，现在不一样了，让我们来创建一个可以显示图像的窗口吧！

```C++
#include "EtherX.h"

int main()
{
    ETHX_InitWindow("HelloEtherX", 800, 600);
    getchar();
    return 0;
}
```

在这个程序中，我们将 [EtherX.h](../EtherX/EtherX.h) 包含进来，

并使用 `ETHX_InitWindow` 创建了一个名字为 HelloEtherX 的尺寸为 800x600 的窗口，

编译运行一下试试结果？

然后你就会发现，首先是一个黑框框弹了出来，紧接着出现了一个窗口，

`getchar()` 用于卡住这个程序不让其退出，但是很快你会发现你既不能移动这个窗口，也不能关掉他，

这是因为这个窗口不处理 `事件`，这其中包括关闭窗口的事件，所以你没有办法操作他，你很快就会学到该怎么办的。

# 再来一个圆吧

创建窗口后，我们来绘制一个圆

```C++
	// 初始化窗口...

	ETHX_SetDrawColor({ 255,255,0,255 });
	ETHX_DrawCircle({ 50,50 }, 30, true);
	ETHX_UpdateWindow();
```

EtherX 的窗口在直接绘制一个形状时，会用窗口当前的颜色来绘制，

所以我们先用 `ETHX_SetDrawColor` 函数设置这个颜色，这里传入了一个 `ETHX_Color` 结构体的参数，

`ETHX_Color` 对象有四个成员，即 RGBA，对应着红色，绿色，蓝色及不透明度，取值范围均在 0~255 之间。

然后我们使用 `ETHX_DrawCircle` 函数绘制一个圆形，

第一个参数是 `ETHX_Point` 结构体，告诉了程序圆心的坐标，

第二个参数是 圆的半径，

第三个参数是 是否填充这个圆。

但如果仅仅只有这两个函数是不够的，EtherX会将这些图像储存在 `缓冲区` 里，

这个 `缓冲区` 可以保证 EtherX 能将多个图像一次性渲染在窗口中，

只有你使用 `ETHX_UpdateWindow` 函数时，EtherX 才会刷新窗口并渲染他们。

运行过后，一个黄色的实心圆便会出现在窗口左上角，窗口依然呆若木鸡（苦笑）。

# 帧率控制

想要我们的窗口稳定地更新图像，我们必须对窗口进行 `帧率控制`

设想一下，你在玩一个沙盒游戏的时候，当游戏内没有多少动物处理的时候，游戏很快就能跑完一次循环，比如它用了3毫秒，

但是如果动物一下子多了起来，游戏跑起来就吃力了，这次它用了15毫秒，

由于每次循环用时不同，游戏就会一下快一下慢的运行着，非常之反人类，

所以，如果我们需要让程序稳定地运行着，就必须在每次循环结束后 `延时` 一小段时间，强制每次循环用时相同，

至于怎么做，请看到我们的代码。

```C++
#include "EtherX.h"

int main()
{
	ETHX_InitWindow("HelloEtherX", 800, 600);
	bool isQuit = false;
	
	int nStartFrame, nCurrentFrame;
	ETHX_Point point = { 50,50 };

	while (!isQuit)
	{
		nStartFrame = ETHX_GetInitTime();

		ETHX_SetDrawColor({ 0,0,0,255 });
		ETHX_ClearWindow();

		ETHX_SetDrawColor({ 255,255,0,255 });
		ETHX_DrawCircle(point, 30, true);

		nCurrentFrame = ETHX_GetInitTime();
		ETHX_Sleep(1000 / 60 - (nCurrentFrame - nStartFrame));

        	ETHX_UpdateWindow();
	}

	ETHX_QuitWindow();
	return 0;
}
```

可以看到，我们将绘制的操作全部放在了一个循环里，并用一个bool变量`isQuit`判断他是否退出,

循环里设置了两次绘制颜色，这是因为EtherX清空窗口的时候会用一次当前颜色(黑色)，我们绘制圆时要用到另一个颜色(黄色),

`nStartFrame` 和 `nCurrentFrame` 变量便是我们用来控制帧率的变量,

我们想要每一次循环用时都是1/60秒，从而控制帧数为60帧，

因为 `ETHX_Sleep` 的单位是毫秒，所以我们用 `1000 / 60` 算出每帧的时间，

可以看到，在循环刚开始进行时，我们用函数 `ETHX_GetInitTime` 为 `nStartFrame` 变量赋了一次值，

函数 `ETHX_GetInitTime` 用于获取从程序开始到现在的时间，

然后我们在所有操作执行完后，又用该函数为 `nCurrentFrame` 变量赋了一次值，

这样我们便计算出了执行完所有操作后的用时，用 `1000 / 60` 减去这个用时就能得到我们应该延时的时间，

接下来用 `ETHX_Sleep` 让程序睡眠指定时间，`帧率控制` 便做好了。

# 让我们来处理事件吧

这是最后一个部分了，获取事件并对特定的事件做出相对应的操作，

这里我们获取键盘上任意一个键按下的事件，告诉程序退出，

和一个鼠标移动的事件，让小球的坐标更新为鼠标当前的坐标。

```C++
#include "EtherX.h"

int main()
{
	ETHX_InitWindow("test", 800, 600);
	bool isQuit = false;
	float nStartFrame, nCurrentFrame;

	ETHX_Event event;
	ETHX_Point point = { 50,50 };

	while (!isQuit)
	{
		nStartFrame = ETHX_GetInitTime();

		ETHX_SetDrawColor({ 0,0,0,255 });
		ETHX_ClearWindow();

		ETHX_SetDrawColor({ 255,255,0,255 });
		ETHX_DrawCircle(point, 30, true);

		while (ETHX_UpdateEvent(event))
		{
			if (event.type == ETHX_ET_QUIT)
			{
				isQuit = true;
			}
			else if (event.type == ETHX_ET_MOUSEMOTION)
			{
				point.x = event.mouse_pos_x;
				point.y = event.mouse_pos_y;
			}
		}

		nCurrentFrame = ETHX_GetInitTime();
		ETHX_Sleep(1000 / 60 - (nCurrentFrame - nStartFrame));

		ETHX_UpdateWindow();
	}
	
	ETHX_QuitWindow();
	return 0;
}
```

我们先声明了一个 `ETHX_Event` ，用于储存获取的事件，

然后再声明了一个 `ETHX_Point` ，用于更新圆形的绘制坐标。

我们通过 `ETHX_UpdateEvent` 来获取事件，因为该函数能返回是否成功获取到事件的bool值，所以我们可以把它放在while循环里进行判断。

这时候当前事件就储存在了 `event` 中，`ETHX_Event` 的结构如下：

```C++
struct ETHX_Event
{
	ETHX_EventType type;
	ETHX_KeyCode key_code;
	int mouse_pos_x, mouse_pos_y;
	int mouse_scroll_x, mouse_scroll_y;
	std::string text;
};
```

获取到事件后我们对事件的类型进行判断，

如果为关闭窗口事件，我们便将 `isQuit` 设置为 true，循环便能正常退出了，

如果为鼠标移动事件，我们便将圆形的绘制坐标更新为鼠标当前坐标，圆便能追随鼠标移动了。

以上便是 EtherX 的基本使用方法，欢迎查阅 [完全文档](README.md)，开始你的 EtherX 之路！
