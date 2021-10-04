# 欢迎来到 EtherX 快速开始文档

EtherX是一个以SDL作为底层，封装了一些简单易用的对象及函数的库，
在这里，我们将结合示例告诉你EtherX的基本用法

# 你将会学到些什么呢？

本次示例，我们将教你如何绘制一个跟着鼠标跑的的圆
这将涉及到帧率控制，事件获取
现在让我们开始吧!

# EtherX库链接

在使用EtherX之前，我们需要先将EtherX的静态库链接至我们的编译器
如果你不知道如何链接一个静态库，请查阅[这里](Details/how-to-build.md)

# 我们需要一个窗口

神说，要有窗口，便有了窗口。
这样我们的图像才有地方绘制，
才有了形形色色的界面。

我想，如果你初学C++的话，你有可能一直在和一个黑框框打交道
如果确实是这样的话，现在不一样了，让我们来创建一个可以显示图像的窗口吧！

```EtherX
#include "EtherX.h"

int main()
{
    ETHX_InitWindow("HelloEtherX", 800, 600);
    getchar();
    return 0;
}
```

在这个程序中，我们将EtherX.h包含进来，
并使用`ETHX_InitWindow`创建了一个名字为`HelloEtherX`的，长800个像素，宽600个像素的窗口，
并且以良好的编程习惯写下了一句`return 0;`（笑）

运行一下试试结果？

然后你就会发现，首先是一个黑框框弹了出来，紧接着出现了一个窗口
`getchar()`用于卡住这个程序不让其退出，但是很快你会发现你既不能移动这个窗口，也不能关掉他，
这是因为这个窗口不处理`事件`，这其中包括关闭窗口的事件，所以你没有办法操作他，你很快就会学到该怎么办的。

# 再来一个圆吧

在程序的第五、第六行之间加入如下代码

```EtherX
...
	ETHX_SetDrawColor({ 255,255,0,255 });
	ETHX_DrawCircle({ 50,50 }, 30, true);
	ETHX_UpdateWindow();
...
```

EtherX的窗口在直接绘制一个形状时，会用窗口当前的颜色来绘制
所以我们先用ETHX_SetDrawColor函数设置这个颜色，这里传入了一个ETHX_Color结构体的参数
ETHX_Color对象有四个成员，即RGBA，对应着红色，绿色，蓝色及不透明度，取值范围均在0~255之间

然后我们使用ETHX_DrawCircle函数绘制一个圆形，第一个参数是ETHX_Point结构体，告诉了程序圆心的坐标
第二个参数是圆的半径，第三个参数则是是否填充这个圆。

但如果仅仅只有这两个函数是不够的，EtherX会将这些图像储存在`缓冲区`里，
这个`缓冲区`可以保证EtherX能将多个图像一次性渲染在窗口中，
只有你使用ETHX_UpdateWindow函数时，EtherX才会刷新窗口并渲染他们。

运行过后，一个黄色的实心圆便会出现在窗口左上角，窗口依然呆若木鸡（苦笑）

# 帧率控制

想要窗口内稳定渲染会动的图像，我们必须对窗口进行`帧率控制`
窗口应当在一秒之内更新60次，或者...144次，这也就是我们所说的60帧和144帧
至于怎么做，请看到我们的代码

```EtherX
#include "EtherX.h"

int main()
{
	ETHX_InitWindow("test", 800, 600);
	bool isQuit = false;
	int nStartFrame, nCurrentFrame;

	while (!isQuit)
	{
		nStartFrame = ETHX_GetInitTime();

		ETHX_SetDrawColor({ 0,0,0,255 });
		ETHX_ClearWindow();

		ETHX_SetDrawColor({ 255,255,0,255 });
		ETHX_DrawCircle({ 50,50 }, 30, true);

		nCurrentFrame = ETHX_GetInitTime();
		ETHX_Sleep(1000 / 60 - (nCurrentFrame - nStartFrame));

        ETHX_UpdateWindow();
	}

	ETHX_QuitWindow();
	return 0;
}
```

可以看到，我们将绘制的操作全部放在了一个循环里，并用一个bool变量`isQuit`判断他是否退出
循环里设置了两次绘制颜色，这是因为EtherX清空窗口的时候会用一次当前颜色(黑色)，我们绘制圆时要用到另一个颜色(黄色)
`nStartFrame`和`nCurrentFrame`变量便是我们用来控制帧率的变量
我们想要每一次循环用时都是1/60秒，从而控制帧数为60帧，但一般程序很快就能运行完一次循环，我们就需要`延时`来控制

可以看到，在循环刚开始进行时，我们用函数`ETHX_GetInitTime`为`nStartFrame`变量赋了一次值
函数`ETHX_GetInitTime`用于获取从程序开始到现在的时间
执行完所有操作后，我们开始计算应当延时的时间，`1000 / 60`指的便是1000/60毫秒，表示一帧的时间
用它减去从本次循环开始的时间到执行完操作后的时间差，便得到了我们应该延时的时间，`帧率控制`便做好了

# 让我们来处理事件吧

这是最后一个部分了，获取事件并对特定的事件做出相对应的操作
这里我们获取键盘上任意一个键按下的事件，告诉程序退出，
和一个鼠标移动的事件，让小球的坐标更新为鼠标当前的坐标。

```EtherX
#include "EtherX.h"

int main()
{
	ETHX_InitWindow("test", 800, 600);
	bool isQuit = false;
	float nStartFrame, nCurrentFrame;
	const ETHX_Event* event;
	ETHX_Point point = { 0,0 };

	while (!isQuit)
	{
		nStartFrame = ETHX_GetInitTime();

		ETHX_SetDrawColor({ 0,0,0,255 });
		ETHX_ClearWindow();

		ETHX_SetDrawColor({ 255,255,0,255 });
		ETHX_DrawCircle(point, 30, true);

		while ((event = ETHX_UpdateEvent()) != nullptr)
		{
			if (event->type == ETHX_ET_KEYDOWN)
			{
				isQuit = true;
			}
			else if (event->type == ETHX_ET_MOUSEMOTION)
			{
				point.x = event->mouse_pos_x;
				point.y = event->mouse_pos_y;
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

我们先声明了一个const的`ETHX_Event`，因为我们不希望它被修改，
然后再声明了一个`ETHX_Point`，用于更新圆形的绘制坐标。

关于事件部分，
我们使用一个while循环并通过`ETHX_UpdateEvent`来获取事件，只要当前事件不为`nullptr`便处理它
这时候当前事件就储存在了event中，`ETHX_Event`的结构如下：

```Struct
struct ETHX_Event
{
	ETHX_EventType	type;
	ETHX_KeyCode	key_code;
	int				mouse_pos_x, mouse_pos_y;
	int				mouse_scroll_x, mouse_scroll_y;
	std::string		text;
};
```

如果为键盘键按下，我们便将isQuit设置为true，循环便能正常退出了，
如果为鼠标移动，我们便将圆形的绘制坐标更新为鼠标当前坐标，圆便能追随鼠标移动了。

以上便是EtherX的基本使用方法，
欢迎查阅完全文档，开始你的EtherX学习之路！