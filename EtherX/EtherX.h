#ifndef _ETHERX_H_
#define _ETHERX_H_

/**********************************************************
* 
* EtherX - 基于 SDL2 的 EasyX 开源跨平台全套解决方案
* 
* Version:	202110.0.1
* Author:	Voidmatrix
* Email:	Voidmatrix@qq.com
* Document:	https://github.com/VoidmatrixHeathcliff/EtherX
*			https://gitee.com/Voidmatrix/EtherX
* 
***********************************************************/

#ifndef __cplusplus
#error ETHERX IS ONLY FOR C++
#endif

#ifdef ETHERX_IMPLEMENTATION
#define ETHX_API __declspec(dllexport)
#else
#define ETHX_API
#endif // ETHERX_IMPLEMENTATION

#include <string>

typedef uint8_t Uint8;
typedef uint32_t Uint32;

typedef struct ETHX_Image ETHX_Image;
typedef struct ETHX_Font ETHX_Font;
typedef struct ETHX_Music ETHX_Music;
typedef struct ETHX_Sound ETHX_Sound;

enum ETHX_MessageBoxStyle
{
	ETHX_MSGBOX_ERROR = 0x00000010,
	ETHX_MSGBOX_WARNING = 0x00000020,
	ETHX_MSGBOX_INFO = 0x00000040,
};

enum ETHX_WindowStyle
{
	ETHX_WINDOW_DEFAULT = 0x00000004,
	ETHX_WINDOW_FULLSCREEN = 0x00001000,
	ETHX_WINDOW_BORDERLESS = 0x00000010,
	ETHX_WINDOW_RESIZABLE = 0x00000020,
	ETHX_WINDOW_MAXIMIZED = 0x00000080,
	ETHX_WINDOW_MINIMIZED = 0x00000040,
};

enum ETHX_ImageStyle
{
	ETHX_IMAGE_FLIP_NONE = 0x00000000,
	ETHX_IMAGE_FLIP_H = 0x00000001,
	ETHX_IMAGE_FLIP_V = 0x00000002,
};

enum ETHX_FontStyle
{
	ETHX_FONT_NORMAL = 0x00,
	ETHX_FONT_BOLD = 0x01,
	ETHX_FONT_ITALIC = 0x02,
	ETHX_FONT_UNDERLINE = 0x04,
	ETHX_FONT_STRIKETHROUGH = 0x08,
};

enum ETHX_EventType
{
	// Window Event
	ETHX_ET_WINDOWSHOWN = 1,
	ETHX_ET_WINDOWHIDDEN = 2,
	ETHX_ET_WINDOWEXPOSED = 3,
	ETHX_ET_WINDOWMOVED = 4,
	ETHX_ET_WINDOWRESIZED = 5,
	ETHX_ET_WINDOWMINIMIZED = 7,
	ETHX_ET_WINDOWMAXIMIZED = 8,
	ETHX_ET_WINDOWENTER = 10,
	ETHX_ET_WINDOWLEAVE = 11,
	ETHX_ET_WINDOWFOCUS_GET = 12,
	ETHX_ET_WINDOWFOCUS_LOST = 13,
	ETHX_ET_WINDOWCLOSE = 14,

	// Key Event
	ETHX_ET_KEYDOWN = 768,
	ETHX_ET_KEYUP = 769,

	// Mouse Event
	ETHX_ET_MOUSEMOTION = 1024,
	ETHX_ET_MOUSEDOWN = 1025,
	ETHX_ET_MOUSEUP = 1026,
	ETHX_ET_MOUSESCROLL = 1027,

	// TextInput Event
	ETHX_ET_TEXTINPUT = 771,

	// Other Event
	ETHX_ET_QUIT = 256,
};

enum ETHX_KeyCode
{
	ETHX_KC_0 = 48,
	ETHX_KC_1,
	ETHX_KC_2,
	ETHX_KC_3,
	ETHX_KC_4,
	ETHX_KC_5,
	ETHX_KC_6,
	ETHX_KC_7,
	ETHX_KC_8,
	ETHX_KC_9,
	ETHX_KCP_0 = 1073741922,
	ETHX_KCP_00 = 1073742000,
	ETHX_KCP_000 = 1073742001,
	ETHX_KCP_1 = 1073741913,
	ETHX_KCP_2,
	ETHX_KCP_3,
	ETHX_KCP_4,
	ETHX_KCP_5,
	ETHX_KCP_6,
	ETHX_KCP_7,
	ETHX_KCP_8,
	ETHX_KCP_9,
	ETHX_KC_F1 = 1073741882,
	ETHX_KC_F2,
	ETHX_KC_F3,
	ETHX_KC_F4,
	ETHX_KC_F5,
	ETHX_KC_F6,
	ETHX_KC_F7,
	ETHX_KC_F8,
	ETHX_KC_F9,
	ETHX_KC_F10,
	ETHX_KC_F11,
	ETHX_KC_F12,
	ETHX_KC_F13 = 1073741928,
	ETHX_KC_F14,
	ETHX_KC_F15,
	ETHX_KC_F16,
	ETHX_KC_F17,
	ETHX_KC_F18,
	ETHX_KC_F19,
	ETHX_KC_F20,
	ETHX_KC_F21,
	ETHX_KC_F22,
	ETHX_KC_F23,
	ETHX_KC_F24,
	ETHX_KC_A = 97,
	ETHX_KC_B,
	ETHX_KC_C,
	ETHX_KC_D,
	ETHX_KC_E,
	ETHX_KC_F,
	ETHX_KC_G,
	ETHX_KC_H,
	ETHX_KC_I,
	ETHX_KC_J,
	ETHX_KC_K,
	ETHX_KC_L,
	ETHX_KC_M,
	ETHX_KC_N,
	ETHX_KC_O,
	ETHX_KC_P,
	ETHX_KC_Q,
	ETHX_KC_R,
	ETHX_KC_S,
	ETHX_KC_T,
	ETHX_KC_U,
	ETHX_KC_V,
	ETHX_KC_W,
	ETHX_KC_X,
	ETHX_KC_Y,
	ETHX_KC_Z,
	ETHX_KCP_A = 1073742012,
	ETHX_KCP_B,
	ETHX_KCP_C,
	ETHX_KCP_D,
	ETHX_KCP_E,
	ETHX_KCP_F,
	ETHX_KC_ESC = 27,
	ETHX_KC_ENTER = 13,
	ETHX_KCP_ENTER = 1073741912,
	ETHX_KC_BACKSPACE = 8,
	ETHX_KCP_BACKSPACE = 1073742011,
	ETHX_KC_RIGHT = 1073741903,
	ETHX_KC_LEFT,
	ETHX_KC_DOWN,
	ETHX_KC_UP,
	ETHX_KC_INSERT = 1073741897,
	ETHX_KC_DELETE = 127,
	ETHX_KC_HOME = 1073741898,
	ETHX_KC_END = 1073741901,
	ETHX_KC_PAGEUP = 1073741899,
	ETHX_KC_PAGEDOWN = 1073741902,
	ETHX_KC_LEFTCTRL = 1073742048,
	ETHX_KC_LEFTGUI = 1073742051,
	ETHX_KC_LEFTALT = 1073742050,
	ETHX_KC_LEFTSHIFT = 1073742049,
	ETHX_KC_RIGHTCTRL = 1073742052,
	ETHX_KC_RIGHTGUI = 1073742055,
	ETHX_KC_RIGHTALT = 1073742054,
	ETHX_KC_RIGHTSHIFT = 1073742053,
	ETHX_KC_SPACE = 32,
	ETHX_KC_TAB = 9,
	ETHX_KC_KP_TAB = 1073742010,
	ETHX_KC_CAPSLOCK = 1073741881,
	ETHX_KC_NUMLOCK = 1073741907,
	ETHX_KC_PRINTSCREEN = 1073741894,
	ETHX_KC_SCROLLLOCK = 1073741895,
	ETHX_KC_PAUSE = 1073741896,
	ETHX_KC_AUDIOMUTE = 1073742086,
	ETHX_KC_AUDIOPREV = 1073742083,
	ETHX_KC_AUDIONEXT = 1073742082,
	ETHX_KC_AUDIOPLAY = 1073742085,
	ETHX_KC_AUDIOSTOP = 1073742084,
	ETHX_KC_VOLUMEUP = 1073741952,
	ETHX_KC_VOLUMEDOWN = 1073741953,
	ETHX_KC_BRIGHTNESSUP = 1073742100,
	ETHX_KC_BRIGHTNESSDOWN = 1073742099,
	ETHX_KC_BACKQUOTE = 96,
	ETHX_KC_EXCLAIM = 33,
	ETHX_KC_KP_EXCLAM = 1073742031,
	ETHX_KC_AT = 64,
	ETHX_KC_KP_AT = 1073742030,
	ETHX_KC_HASH = 35,
	ETHX_KC_KP_HASH = 1073742028,
	ETHX_KC_DOLLAR = 36,
	ETHX_KC_CARET = 94,
	ETHX_KCP_CARET = 1073742019,
	ETHX_KC_AMPERSAND = 38,
	ETHX_KCP_AMPERSAND = 1073742023,
	ETHX_KCP_DBLAMPERSAND = 1073742024,
	ETHX_KC_ASTERISK = 42,
	ETHX_KCP_ASTERISK = 1073741909,
	ETHX_KC_LEFTPAREN = 40,
	ETHX_KCP_LEFTPAREN = 1073742006,
	ETHX_KC_RIGHTPAREN = 41,
	ETHX_KCP_RIGHTPAREN = 1073742007,
	ETHX_KC_MINUS = 45,
	ETHX_KCP_MINUS = 1073741910,
	ETHX_KC_UNDERSCORE = 95,
	ETHX_KC_PLUS = 43,
	ETHX_KCP_PLUS = 1073741911,
	ETHX_KC_EQUALS = 61,
	ETHX_KCP_EQUALS = 1073741927,
	ETHX_KC_LEFTBRACKET = 91,
	ETHX_KC_RIGHTBRACKET = 93,
	ETHX_KCP_LEFTBRACE = 1073742008,
	ETHX_KCP_RIGHTBRACE = 1073742009,
	ETHX_KC_COLON = 58,
	ETHX_KC_SEMICOLON = 59,
	ETHX_KC_BACKSLASH = 92,
	ETHX_KC_QUOTE = 39,
	ETHX_KC_DBLQUOTE = 34,
	ETHX_KC_LESS = 60,
	ETHX_KC_GREATER = 62,
	ETHX_KC_COMMA = 44,
	ETHX_KC_PERIOD = 46,
	ETHX_KC_QUESTION = 63,
	ETHX_KC_SLASH = 47,
	ETHX_KC_VERTICALBAR = 1073742025,
	ETHX_KCP_DBLVERTICALBAR = 1073742026,
	ETHX_KC_WWW = 1073742088,
	ETHX_KC_MAIL = 1073742089,
};

struct ETHX_Color
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
};

struct ETHX_Rect
{
	int x, y;
	int w, h;
};

struct ETHX_Point
{
	int x;
	int y;
};

struct ETHX_Event
{
	ETHX_EventType	type;
	ETHX_KeyCode	key_code;
	int				mouse_pos_x, mouse_pos_y;
	int				mouse_scroll_x, mouse_scroll_y;
	std::string		text;
};

// Window API
ETHX_API void ETHX_InitWindow(const std::string& title, int width, int height, ETHX_WindowStyle style = ETHX_WINDOW_DEFAULT);
ETHX_API void ETHX_QuitWindow();
ETHX_API void ETHX_ShowMessageBox(const std::string& title, const std::string& msg, ETHX_MessageBoxStyle style);
ETHX_API bool ETHX_ShowConfirmMessageBox(const std::string& title, const std::string& msg, ETHX_MessageBoxStyle style,
	const std::string& ok_text = "OK", const std::string& cancel_text = "Cancel");
ETHX_API void ETHX_SetWindowTitle(std::string title);
ETHX_API std::string ETHX_GetWindowTitle();
ETHX_API void ETHX_SetWindowFullscreen(bool flag);
ETHX_API void ETHX_SetWindowSize(int width, int height);
ETHX_API void ETHX_GetWindowSize(int& width, int& height);
ETHX_API void ETHX_GetWindowSize_HDPI(int& width, int& height);
ETHX_API void ETHX_SetWindowIcon(ETHX_Image* image);
ETHX_API void ETHX_ClearWindow();
ETHX_API void ETHX_UpdateWindow();

// Graphic API
ETHX_API ETHX_Image* ETHX_LoadImage(const std::string& path);
ETHX_API ETHX_Image* ETHX_LoadImage(void* data, size_t size);
ETHX_API void ETHX_SetImageColorKey(ETHX_Image* image, const ETHX_Color& color, bool flag);
ETHX_API void ETHX_SetImageAplha(ETHX_Image* image, Uint8 alpha);
ETHX_API void ETHX_GetImageSize(ETHX_Image* image, int& width, int& height);
ETHX_API void ETHX_DrawImage(ETHX_Image* image, const ETHX_Point& pos);
ETHX_API void ETHX_DrawImage(ETHX_Image* image, const ETHX_Rect& show_rect);
ETHX_API void ETHX_DrawImage(ETHX_Image* image, const ETHX_Rect& show_rect, const ETHX_Rect& clip_rect);
ETHX_API void ETHX_DrawImage(ETHX_Image* image, const ETHX_Rect& show_rect, 
	const ETHX_Rect& clip_rect, const ETHX_Point& center, double angle, ETHX_ImageStyle style = ETHX_IMAGE_FLIP_NONE);
ETHX_API void ETHX_SetDrawColor(const ETHX_Color& color);
ETHX_API ETHX_Color ETHX_GetDrawColor();
ETHX_API void ETHX_DrawPoint(const ETHX_Point& point);
ETHX_API void ETHX_DrawLine(const ETHX_Point& begin, const ETHX_Point& end);
ETHX_API void ETHX_DrawLine(const ETHX_Point& begin, const ETHX_Point& end, Uint8 width);
ETHX_API void ETHX_DrawRectangle(const ETHX_Rect& rect, bool fill = false);
ETHX_API void ETHX_DrawRectangle(const ETHX_Rect& rect, int radius, bool fill = false);
ETHX_API void ETHX_DrawCircle(const ETHX_Point& center, int radius, bool fill = false);
ETHX_API void ETHX_DrawEllipse(const ETHX_Point& center, int radius_x, int radius_y, bool fill = false);
ETHX_API void ETHX_DrawPie(const ETHX_Point& center, int radius, int start_angle, int end_angle, bool fill = false);
ETHX_API void ETHX_DrawTriangle(const ETHX_Point& point_1, const ETHX_Point& point_2, const ETHX_Point& point_3, bool fill = false);
ETHX_API ETHX_Font* ETHX_LoadFont(const std::string& path, int ptsize);
ETHX_API ETHX_Font* ETHX_LoadFont(void* data, size_t size, int ptsize);
ETHX_API void ETHX_SetFontStyle(ETHX_Font* font, ETHX_FontStyle style);
ETHX_API int ETHX_GetFontStyle(ETHX_Font* font);
ETHX_API void ETHX_GetTextSize(ETHX_Font* font, const std::string& text, int& width, int& height);
ETHX_API void ETHX_DrawText(ETHX_Font* font, const std::string& text, const ETHX_Point& pos);
ETHX_API void ETHX_DrawText(ETHX_Font* font, const std::string& text, const ETHX_Rect& show_rect);
ETHX_API ETHX_Image* ETHX_CreateTextImage(ETHX_Font* font, const std::string& text);

// Media API
ETHX_API ETHX_Music* ETHX_LoadMusic(const std::string& path);
ETHX_API void ETHX_PlayMusic(ETHX_Music* music, int loops, bool fade_in = false, int delay = 0);
ETHX_API void ETHX_StopMusic(bool fade_out = false, int delay = 0);
ETHX_API bool ETHX_CheckMusicPlaying();
ETHX_API void ETHX_PauseMusic();
ETHX_API void ETHX_ResumeMusic();
ETHX_API void ETHX_RewindMusic();
ETHX_API void ETHX_SetMusicVolume(int volume);
ETHX_API int ETHX_GetMusicVolume();
ETHX_API ETHX_Sound* ETHX_LoadSound(const std::string& path);
ETHX_API ETHX_Sound* ETHX_LoadSound(void* data, size_t size);
ETHX_API void ETHX_PlaySound(ETHX_Sound* sound, int loops);
ETHX_API void ETHX_SetSoundVolume(ETHX_Sound* sound, int volume);
ETHX_API int ETHX_GetSoundVolume(ETHX_Sound* sound);

// Interactivity API
ETHX_API bool ETHX_UpdateEvent(ETHX_Event& event);

// Time API
ETHX_API void ETHX_Sleep(Uint32 ms);
ETHX_API Uint32 ETHX_GetInitTime();

#ifdef ETHERX_IMPLEMENTATION

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL2_gfxPrimitives.h>

struct ETHX_Image
{
	SDL_Surface* _pSurface;
	SDL_Texture* _pTexture;
	~ETHX_Image()
	{
		SDL_FreeSurface(_pSurface); _pSurface = nullptr;
		SDL_DestroyTexture(_pTexture); _pTexture = nullptr;
	}
};

struct ETHX_Font
{
	TTF_Font* _pFont;
	~ETHX_Font()
	{
		TTF_CloseFont(_pFont); _pFont = nullptr;
	}
};

struct ETHX_Music
{
	Mix_Music* _pMusic;
	~ETHX_Music()
	{
		Mix_FreeMusic(_pMusic); _pMusic = nullptr;
	}
};

struct ETHX_Sound
{
	Mix_Chunk* _pSound;
	~ETHX_Sound()
	{
		Mix_FreeChunk(_pSound); _pSound = nullptr;
	}
};

SDL_Window* _pWindow = nullptr;
SDL_Renderer* _pWRenderer = nullptr;

/*
* *****************************************
* 
* Window API Implementation
* 
* *****************************************
*/

void ETHX_InitWindow(const std::string& title, int width, int height, ETHX_WindowStyle style)
{
	if (_pWindow) return;

	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

	_pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, style);
	_pWRenderer = SDL_CreateRenderer(_pWindow, -1, SDL_RENDERER_ACCELERATED);

#ifdef __WINDOWS__
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");
#else
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
#endif	// __WINDOWS__

	SDL_StartTextInput();
}

void ETHX_QuitWindow()
{
	IMG_Quit();
	Mix_CloseAudio(); Mix_Quit();
	TTF_Quit();

	SDL_DestroyRenderer(_pWRenderer); _pWRenderer = nullptr;
	SDL_DestroyWindow(_pWindow); _pWindow = nullptr;

	SDL_Quit();
}

void ETHX_ShowMessageBox(const std::string& title, const std::string& msg, ETHX_MessageBoxStyle style)
{
	SDL_ShowSimpleMessageBox(style, title.c_str(), msg.c_str(), _pWindow);
}

bool ETHX_ShowConfirmMessageBox(const std::string& title, const std::string& msg, ETHX_MessageBoxStyle style,
	const std::string& ok_text, const std::string& cancel_text)
{
	const SDL_MessageBoxButtonData _data_button[2] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, ok_text.c_str() },
		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, cancel_text.c_str() },
	};
	const SDL_MessageBoxColorScheme _color_scheme = {
		{
			{ 255, 0, 0 },
			{ 0, 255, 0 },
			{ 255, 255, 0 },
			{ 0, 0, 255 },
			{ 255, 0, 255 }
		}
	};
	const SDL_MessageBoxData _data_message_box = {
		style, 
		_pWindow, title.c_str(), msg.c_str(),
		2, _data_button, & _color_scheme
	};

	int _id_button = 0;
	SDL_ShowMessageBox(&_data_message_box, &_id_button);

	return _id_button;
}

void ETHX_SetWindowTitle(const std::string& title)
{
	SDL_SetWindowTitle(_pWindow, title.c_str());
}

std::string ETHX_GetWindowTitle()
{
	return SDL_GetWindowTitle(_pWindow);
}

void ETHX_SetWindowFullscreen(bool flag)
{
	SDL_SetWindowFullscreen(_pWindow, flag ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

void ETHX_SetWindowSize(int width, int height)
{
	SDL_SetWindowSize(_pWindow, width, height);
}

void ETHX_GetWindowSize(int& width, int& height)
{
	SDL_GetWindowSize(_pWindow, &width, &height);
}

void ETHX_GetWindowSize_HDPI(int& width, int& height)
{
	SDL_GetRendererOutputSize(_pWRenderer, &width, &height);
}

void ETHX_SetWindowIcon(ETHX_Image* image)
{
	SDL_SetWindowIcon(_pWindow, image->_pSurface);
}

void ETHX_ClearWindow()
{
	SDL_RenderClear(_pWRenderer);
}

void ETHX_UpdateWindow()
{
	SDL_RenderPresent(_pWRenderer);
}

/*
* *****************************************
*
* Graphic API Implementation
*
* *****************************************
*/

inline bool _check_image_is_valid(ETHX_Image* image);
inline bool _check_font_is_valid(ETHX_Font* font);

ETHX_Image* ETHX_LoadImage(const std::string& path)
{
	ETHX_Image* _image = new ETHX_Image();

	if (!(_image->_pSurface = IMG_Load(path.c_str())))
	{
		delete _image; _image = nullptr;
		return nullptr;
	}

	if (!(_image->_pTexture = SDL_CreateTextureFromSurface(_pWRenderer, _image->_pSurface)))
	{
		SDL_FreeSurface(_image->_pSurface); _image->_pSurface = nullptr;
		delete _image; _image = nullptr;
		return nullptr;
	}

	return _image;
}

ETHX_Image* ETHX_LoadImage(void* data, size_t size)
{
	ETHX_Image* _image = new ETHX_Image();

	if (!(_image->_pSurface = IMG_Load_RW(SDL_RWFromMem(data, size), 1)))
	{
		delete _image; _image = nullptr;
		return nullptr;
	}

	if (!(_image->_pTexture = SDL_CreateTextureFromSurface(_pWRenderer, _image->_pSurface)))
	{
		SDL_FreeSurface(_image->_pSurface); _image->_pSurface = nullptr;
		delete _image; _image = nullptr;
		return nullptr;
	}

	return _image;
}

inline bool _check_image_is_valid(ETHX_Image* image)
{
	// maybe assert something here

	return image;
}

void ETHX_SetImageColorKey(ETHX_Image* image, const ETHX_Color& color, bool flag)
{
	if (!_check_image_is_valid(image)) return;

	SDL_SetColorKey(image->_pSurface, flag, 
		SDL_MapRGBA(image->_pSurface->format, color.r, color.g, color.b, color.a));
	SDL_DestroyTexture(image->_pTexture); image->_pTexture = nullptr;
	image->_pTexture = SDL_CreateTextureFromSurface(_pWRenderer, image->_pSurface);
}

void ETHX_SetImageAplha(ETHX_Image* image, Uint8 alpha)
{
	if (!_check_image_is_valid(image)) return;

	SDL_SetTextureBlendMode(image->_pTexture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(image->_pTexture, alpha);
}

void ETHX_GetImageSize(ETHX_Image* image, int& width, int& height)
{
	if (!_check_image_is_valid(image)) return;

	width = image->_pSurface->w;
	height = image->_pSurface->h;
}

void ETHX_DrawImage(ETHX_Image* image, const ETHX_Point& pos)
{
	if (!_check_image_is_valid(image)) return;

	SDL_Rect _dst_rect = { pos.x, pos.y, image->_pSurface->w, image->_pSurface->h };
	SDL_RenderCopy(_pWRenderer, image->_pTexture, nullptr, &_dst_rect);
}

void ETHX_DrawImage(ETHX_Image* image, const ETHX_Rect& show_rect)
{
	if (!_check_image_is_valid(image)) return;

	SDL_Rect _dst_rect = { show_rect.x, show_rect.y, show_rect.w, show_rect.h };
	SDL_RenderCopy(_pWRenderer, image->_pTexture, nullptr, &_dst_rect);
}

void ETHX_DrawImage(ETHX_Image* image, const ETHX_Rect& show_rect, const ETHX_Rect& clip_rect)
{
	if (!_check_image_is_valid(image)) return;

	SDL_Rect _dst_rect = { show_rect.x, show_rect.y, show_rect.w, show_rect.h };
	SDL_Rect _src_rect = { clip_rect.x, clip_rect.y, clip_rect.w, clip_rect.h };
	SDL_RenderCopy(_pWRenderer, image->_pTexture, &_src_rect, &_dst_rect);
}

void ETHX_DrawImage(ETHX_Image* image, const ETHX_Rect& show_rect, 
	const ETHX_Rect& clip_rect, const ETHX_Point& center, double angle, ETHX_ImageStyle style)
{
	if (!_check_image_is_valid(image)) return;

	SDL_Rect _dst_rect = { show_rect.x, show_rect.y, show_rect.w, show_rect.h };
	SDL_Rect _src_rect = { clip_rect.x, clip_rect.y, clip_rect.w, clip_rect.h };
	SDL_Point _flip_center = { center.x, center.y };
	SDL_RenderCopyEx(_pWRenderer, image->_pTexture, &_src_rect, &_dst_rect, 
		angle, &_flip_center, (SDL_RendererFlip)style);
}

void ETHX_SetDrawColor(const ETHX_Color& color)
{
	SDL_SetRenderDrawBlendMode(_pWRenderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(_pWRenderer, color.r, color.g, color.b, color.a);
}

ETHX_Color ETHX_GetDrawColor()
{
	ETHX_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));
	return _color;
}

void ETHX_DrawPoint(const ETHX_Point& point)
{
	SDL_RenderDrawPoint(_pWRenderer, point.x, point.y);
}

void ETHX_DrawLine(const ETHX_Point& begin, const ETHX_Point& end)
{
	ETHX_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));
	aalineRGBA(_pWRenderer, begin.x, begin.y, end.x, end.y, _color.r, _color.g, _color.b, _color.a);
}

void ETHX_DrawLine(const ETHX_Point& begin, const ETHX_Point& end, Uint8 width)
{
	ETHX_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));
	thickLineRGBA(_pWRenderer, begin.x, begin.y, end.x, end.y, width, _color.r, _color.g, _color.b, _color.a);
}

void ETHX_DrawRectangle(const ETHX_Rect& rect, bool fill)
{
	SDL_Rect _rect = { rect.x, rect.y, rect.w, rect.h };
	fill ? SDL_RenderFillRect(_pWRenderer, &_rect) : SDL_RenderDrawRect(_pWRenderer, &_rect);
}

void ETHX_DrawRectangle(const ETHX_Rect& rect, int radius, bool fill)
{
	ETHX_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));
	fill ? roundedBoxRGBA(_pWRenderer, rect.x, rect.y, rect.x + rect.w, rect.y + rect.h, 
		radius, _color.r, _color.g, _color.b, _color.a)
		: roundedRectangleRGBA(_pWRenderer, rect.x, rect.y, rect.x + rect.w, rect.y + rect.h,
			radius, _color.r, _color.g, _color.b, _color.a);
}

void ETHX_DrawCircle(const ETHX_Point& center, int radius, bool fill)
{
	ETHX_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));
	fill ? filledCircleRGBA(_pWRenderer, center.x, center.y, 
		radius, _color.r, _color.g, _color.b, _color.a) 
		: aacircleRGBA(_pWRenderer, center.x, center.y, 
			radius, _color.r, _color.g, _color.b, _color.a);
}

void ETHX_DrawEllipse(const ETHX_Point& center, int radius_x, int radius_y, bool fill)
{
	ETHX_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));
	fill ? filledEllipseRGBA(_pWRenderer, center.x, center.y, 
		radius_x, radius_y, _color.r, _color.g, _color.b, _color.a)
		: aaellipseRGBA(_pWRenderer, center.x, center.y, 
			radius_x, radius_y, _color.r, _color.g, _color.b, _color.a);
}

void ETHX_DrawPie(const ETHX_Point& center, int radius, int start_angle, int end_angle, bool fill)
{
	ETHX_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));
	fill ? filledPieRGBA(_pWRenderer, center.x, center.y, radius, 
		start_angle, end_angle, _color.r, _color.g, _color.b, _color.a)
		: pieRGBA(_pWRenderer, center.x, center.y, radius,
			start_angle, end_angle, _color.r, _color.g, _color.b, _color.a);
}

void ETHX_DrawTriangle(const ETHX_Point& point_1, const ETHX_Point& point_2, const ETHX_Point& point_3, bool fill)
{
	ETHX_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));
	fill ? filledTrigonRGBA(_pWRenderer, point_1.x, point_1.y, point_2.x, point_2.y, 
		point_3.x, point_3.y, _color.r, _color.g, _color.b, _color.a)
		: aatrigonRGBA(_pWRenderer, point_1.x, point_1.y, point_2.x, point_2.y,
			point_3.x, point_3.y, _color.r, _color.g, _color.b, _color.a);
}

ETHX_Font* ETHX_LoadFont(const std::string& path, int ptsize)
{
	ETHX_Font* _font = new ETHX_Font();

	if (!(_font->_pFont = TTF_OpenFont(path.c_str(), ptsize)))
	{
		delete _font; _font = nullptr;
		return nullptr;
	}

	return _font;
}

ETHX_Font* ETHX_LoadFont(void* data, size_t size, int ptsize)
{
	ETHX_Font* _font = new ETHX_Font();

	if (!(_font->_pFont = TTF_OpenFontRW(SDL_RWFromMem(data, size), 1, ptsize)))
	{
		delete _font; _font = nullptr;
		return nullptr;
	}

	return _font;
}

inline bool _check_font_is_valid(ETHX_Font* font)
{
	// maybe assert something here

	return font;
}

void ETHX_SetFontStyle(ETHX_Font* font, ETHX_FontStyle style)
{
	if (!_check_font_is_valid(font)) return;

	TTF_SetFontStyle(font->_pFont, style);
}

int ETHX_GetFontStyle(ETHX_Font* font)
{
	if (!_check_font_is_valid(font)) return ETHX_FONT_NORMAL;

	return TTF_GetFontStyle(font->_pFont);
}

void ETHX_GetTextSize(ETHX_Font* font, const std::string& text, int& width, int& height)
{
	if (!_check_font_is_valid(font)) return;

	TTF_SizeUTF8(font->_pFont, text.c_str(), &width, &height);
}

void ETHX_DrawText(ETHX_Font* font, const std::string& text, const ETHX_Point& pos)
{
	if (!_check_font_is_valid(font)) return;

	ETHX_Image* _image = nullptr;

	if (!(_image = ETHX_CreateTextImage(font, text))) return;

	ETHX_Rect _rect = { pos.x, pos.y, _image->_pSurface->w, _image->_pSurface->h };
	ETHX_DrawImage(_image, _rect);

	delete _image; _image = nullptr;
}

void ETHX_DrawText(ETHX_Font* font, const std::string& text, const ETHX_Rect& show_rect)
{
	if (!_check_font_is_valid(font)) return;

	ETHX_Image* _image = nullptr;
	if (!(_image = ETHX_CreateTextImage(font, text))) return;

	ETHX_DrawImage(_image, show_rect);

	delete _image; _image = nullptr;
}

ETHX_Image* ETHX_CreateTextImage(ETHX_Font* font, const std::string& text)
{
	if (!_check_font_is_valid(font)) return nullptr;

	ETHX_Image* _image = new ETHX_Image();

	SDL_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));

	if (!(_image->_pSurface = TTF_RenderUTF8_Blended(font->_pFont, text.c_str(), _color)))
	{
		delete _image; _image = nullptr;
		return nullptr;
	}

	if (!(_image->_pTexture = SDL_CreateTextureFromSurface(_pWRenderer, _image->_pSurface)))
	{
		SDL_FreeSurface(_image->_pSurface); _image->_pSurface = nullptr;
		delete _image; _image = nullptr;
		return nullptr;
	}

	return _image;
}

/*
* *****************************************
*
* Media API Implementation
*
* *****************************************
*/

inline bool _check_music_is_valid(ETHX_Music* music);
inline bool _check_sound_is_valid(ETHX_Sound* sound);

ETHX_Music* ETHX_LoadMusic(const std::string& path)
{
	ETHX_Music* _music = new ETHX_Music();

	if (!(_music->_pMusic = Mix_LoadMUS(path.c_str())))
	{
		delete _music; _music = nullptr;
		return nullptr;
	}

	return _music;
}

inline bool _check_music_is_valid(ETHX_Music* music)
{
	// maybe assert something here

	return music;
}

void ETHX_PlayMusic(ETHX_Music* music, int loops, bool fade_in, int delay)
{
	if (!_check_music_is_valid(music)) return;

	fade_in ? Mix_FadeInMusic(music->_pMusic, loops, delay)
		: Mix_PlayMusic(music->_pMusic, loops);
}

void ETHX_StopMusic(bool fade_out, int delay)
{
	fade_out ? Mix_FadeOutMusic(delay) : Mix_HaltMusic();
}

bool ETHX_CheckMusicPlaying()
{
	return Mix_PlayingMusic();
}

void ETHX_PauseMusic()
{
	Mix_PauseMusic();
}

void ETHX_ResumeMusic()
{
	Mix_ResumeMusic();
}

void ETHX_RewindMusic()
{
	Mix_RewindMusic();
}

void ETHX_SetMusicVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

int ETHX_GetMusicVolume()
{
	return Mix_VolumeMusic(-1);
}

ETHX_Sound* ETHX_LoadSound(const std::string& path)
{
	ETHX_Sound* _sound = new ETHX_Sound();

	if (!(_sound->_pSound = Mix_LoadWAV(path.c_str())))
	{
		delete _sound; _sound = nullptr;
		return nullptr;
	}

	return _sound;
}

ETHX_Sound* ETHX_LoadSound(void* data, size_t size)
{
	ETHX_Sound* _sound = new ETHX_Sound();

	if (!(_sound->_pSound = Mix_LoadWAV_RW(SDL_RWFromMem(data, size), 1)))
	{
		delete _sound; _sound = nullptr;
		return nullptr;
	}

	return _sound;
}

inline bool _check_sound_is_valid(ETHX_Sound* sound)
{
	// maybe assert something here

	return sound;
}

void ETHX_PlaySound(ETHX_Sound* sound, int loops)
{
	if (!_check_sound_is_valid(sound)) return;

	Mix_PlayChannel(-1, sound->_pSound, loops);
}

void ETHX_SetSoundVolume(ETHX_Sound* sound, int volume)
{
	if (!_check_sound_is_valid(sound)) return;

	Mix_VolumeChunk(sound->_pSound, volume);
}

int ETHX_GetSoundVolume(ETHX_Sound* sound)
{
	if (!_check_sound_is_valid(sound)) return 0;

	return sound->_pSound->volume;
}

/*
* *****************************************
*
* Interactivity API Implementation
*
* *****************************************
*/

bool ETHX_UpdateEvent(ETHX_Event& event)
{
	SDL_Event _event;

	if (!SDL_PollEvent(&_event)) return false;

	switch (_event.type)
	{
	case SDL_QUIT:
		event.type = ETHX_ET_QUIT;
		break;
	case SDL_MOUSEMOTION:
		event.type = ETHX_ET_MOUSEMOTION;
		event.mouse_pos_x = _event.motion.x;
		event.mouse_pos_y = _event.motion.y;
		break;
	case SDL_MOUSEWHEEL:
		event.type = ETHX_ET_MOUSESCROLL;
		event.mouse_scroll_x = _event.wheel.x;
		event.mouse_scroll_y = _event.wheel.y;
		break;
	case SDL_TEXTINPUT:
		event.type = ETHX_ET_TEXTINPUT;
		event.text = _event.text.text;
		break;
	case SDL_KEYDOWN:
		event.type = ETHX_ET_KEYDOWN;
		event.key_code = (ETHX_KeyCode)_event.key.keysym.sym;
		break;
	case SDL_KEYUP:
		event.type = ETHX_ET_KEYUP;
		event.key_code = (ETHX_KeyCode)_event.key.keysym.sym;
		break;
	case SDL_WINDOWEVENT:
		event.type = (ETHX_EventType)_event.window.event;
		break;
	default:
		break;
	}

	return true;
}

/*
* *****************************************
*
* Time API Implementation
*
* *****************************************
*/

void ETHX_Sleep(Uint32 ms)
{
	SDL_Delay(ms);
}

Uint32 ETHX_GetInitTime()
{
	return SDL_GetTicks();
}

#endif	// ETHERX_IMPLEMENTATION

#endif // !_ETHERX_H_