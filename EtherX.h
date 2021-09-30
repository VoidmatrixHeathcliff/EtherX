#ifndef _ETHERX_H_
#define _ETHERX_H_

#define ETHERX_IMPLEMENTATION

#ifndef __cplusplus
#error ETHERX IS ONLY FOR C++
#endif

#define ETHX_API __declspec(dllexport)

#include <string>

typedef uint8_t Uint8;

typedef struct ETHX_Spirit ETHX_Spirit;
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
	ETHX_WINDOW_FULLSCREEN = 0x00001000,
	ETHX_WINDOW_BORDERLESS = 0x00000010,
	ETHX_WINDOW_RESIZABLE = 0x00000020,
	ETHX_WINDOW_MAXIMIZED = 0x00000080,
	ETHX_WINDOW_MINIMIZED = 0x00000040,
};

enum ETHX_SpiritStyle
{
	ETHX_SPIRIT_FLIP_NONE = 0x00000000,
	ETHX_SPIRIT_FLIP_H = 0x00000001,
	ETHX_SPIRIT_FLIP_V = 0x00000002,
};

enum ETHX_FontStyle
{
	ETHX_FONT_NORMAL = 0x00,
	ETHX_FONT_BOLD = 0x01,
	ETHX_FONT_ITALIC = 0x02,
	ETHX_FONT_UNDERLINE = 0x04,
	ETHX_FONT_STRIKETHROUGH = 0x08
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

// Window API
ETHX_API void ETHX_InitWindow(const std::string& title, int width, int height, ETHX_WindowStyle style);
ETHX_API void ETHX_QuitWindow();
ETHX_API void ETHX_ShowMessageBox(const std::string& title, const std::string& msg, ETHX_MessageBoxStyle style);
ETHX_API void ETHX_SetWindowTitle(std::string title);
ETHX_API std::string ETHX_GetWindowTitle();
ETHX_API void ETHX_SetWindowFullscreen(bool flag);
ETHX_API void ETHX_SetWindowSize(int width, int height);
ETHX_API void ETHX_GetWindowSize(int& width, int& height);
ETHX_API void ETHX_GetWindowSize_HDPI(int& width, int& height);
ETHX_API void ETHX_SetWindowIcon(ETHX_Spirit* spirit);
ETHX_API void ETHX_ClearWindow();
ETHX_API void ETHX_UpdateWindow();

// Graphic API
ETHX_API ETHX_Spirit* ETHX_LoadSpirit(const std::string& path);
ETHX_API ETHX_Spirit* ETHX_LoadSpirit(void* data, size_t size);
ETHX_API void ETHX_SetSpiritColorKey(ETHX_Spirit* spirit, const ETHX_Color& color, bool flag);
ETHX_API void ETHX_SetSpiritAplha(ETHX_Spirit* spirit, Uint8 alpha);
ETHX_API void ETHX_GetSpiritSize(ETHX_Spirit* spirit, int& width, int& height);
ETHX_API void ETHX_DrawSpirit(ETHX_Spirit* spirit, const ETHX_Point& pos);
ETHX_API void ETHX_DrawSpirit(ETHX_Spirit* spirit, const ETHX_Rect& show_rect);
ETHX_API void ETHX_DrawSpirit(ETHX_Spirit* spirit, const ETHX_Rect& show_rect, const ETHX_Rect& clip_rect);
ETHX_API void ETHX_DrawSpirit(ETHX_Spirit* spirit, const ETHX_Rect& show_rect, 
	const ETHX_Rect& clip_rect, const ETHX_Point& center, double angle, ETHX_SpiritStyle style = ETHX_SPIRIT_FLIP_NONE);
ETHX_API void ETHX_SetDrawColor(const ETHX_Color& color);
ETHX_API ETHX_Color ETHX_GetDrawColor();
ETHX_API void ETHX_DrawPoint(const ETHX_Point& point);
ETHX_API void ETHX_DrawLine(const ETHX_Point& begin, const ETHX_Point& end);
ETHX_API void ETHX_DrawLine(const ETHX_Point& begin, const ETHX_Point& end, Uint8 width);
ETHX_API void ETHX_DrawRectangle(const ETHX_Rect& rect, bool fill = false);
ETHX_API void ETHX_DrawRectangle(const ETHX_Rect& rect, int radius, bool fill = false);
ETHX_API void ETHX_DrawCircle(const ETHX_Point& center, int radius, bool fill = false);
ETHX_API void ETHX_DrawCircle(const ETHX_Point& center, int radius_x, int radius_y, bool fill = false);
ETHX_API void ETHX_DrawCircle(const ETHX_Point& center, int radius, int start_angle, int end_angle, bool fill = false);
ETHX_API void ETHX_DrawTriangle(const ETHX_Point& point_1, const ETHX_Point& point_2, const ETHX_Point& point_3, bool fill = false);
ETHX_API ETHX_Font* ETHX_LoadFont(const std::string& path, int ptsize);
ETHX_API ETHX_Font* ETHX_LoadFont(void* data, size_t size, int ptsize);
ETHX_API void ETHX_SetFontStyle(ETHX_Font* font, ETHX_FontStyle style);
ETHX_API int ETHX_GetFontStyle(ETHX_Font* font);
ETHX_API void ETHX_GetTextSize(ETHX_Font* font, const std::string& text, int& width, int& height);
ETHX_API void ETHX_DrawText(ETHX_Font* font, const std::string& text, const ETHX_Point& pos);
ETHX_API ETHX_Spirit* ETHX_CreateTextSpirit(ETHX_Font* font, const std::string& text);

// Media API
ETHX_API ETHX_Music* ETHX_LoadMusic(const std::string& path);
ETHX_API void ETHX_PlayMusic(ETHX_Music* music, int loops, bool fade_in = false, int delay = 0);
ETHX_API void ETHX_StopMusic(bool fade_out = false, int delay = 0);
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

#ifdef ETHERX_IMPLEMENTATION

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL2_gfxPrimitives.h>

// Win32 API
#pragma comment(lib, "Setupapi.lib")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "Imm32.lib")
#pragma comment(lib, "Version.lib")

// SDL2
#pragma comment(lib, "lib/SDL2/SDL2.lib")
#pragma comment(lib, "lib/SDL2/SDL2main.lib")

// SDL2_image
#pragma comment(lib, "lib/SDL2_image/SDL2_image.lib")
#pragma comment(lib, "lib/SDL2_image/jpeg.lib")
#pragma comment(lib, "lib/SDL2_image/libpng16.lib")
#pragma comment(lib, "lib/SDL2_image/libwebpmux.lib")
#pragma comment(lib, "lib/SDL2_image/tiff.lib")
#pragma comment(lib, "lib/SDL2_image/tiffxx.lib")
#pragma comment(lib, "lib/SDL2_image/turbojpeg.lib")
#pragma comment(lib, "lib/SDL2_image/webp.lib")
#pragma comment(lib, "lib/SDL2_image/webpdecoder.lib")
#pragma comment(lib, "lib/SDL2_image/webpdemux.lib")
#pragma comment(lib, "lib/SDL2_image/zlib.lib")
#pragma comment(lib, "lib/SDL2_image/lzma.lib")

// SDL2_mixer
#pragma comment(lib, "lib/SDL2_mixer/SDL2_mixer.lib")
#pragma comment(lib, "lib/SDL2_mixer/FLAC.lib")
#pragma comment(lib, "lib/SDL2_mixer/FLAC++.lib")
#pragma comment(lib, "lib/SDL2_mixer/libmpg123.lib")
#pragma comment(lib, "lib/SDL2_mixer/ogg.lib")
#pragma comment(lib, "lib/SDL2_mixer/opus.lib")
#pragma comment(lib, "lib/SDL2_mixer/opusfile.lib")
#pragma comment(lib, "lib/SDL2_mixer/vorbis.lib")
#pragma comment(lib, "lib/SDL2_mixer/vorbisenc.lib")
#pragma comment(lib, "lib/SDL2_mixer/vorbisfile.lib")

// SDL2_ttf
#pragma comment(lib, "lib/SDL2_ttf/SDL2_ttf.lib")
#pragma comment(lib, "lib/SDL2_ttf/brotlicommon-static.lib")
#pragma comment(lib, "lib/SDL2_ttf/brotlidec-static.lib")
#pragma comment(lib, "lib/SDL2_ttf/brotlienc-static.lib")
#pragma comment(lib, "lib/SDL2_ttf/bz2.lib")
#pragma comment(lib, "lib/SDL2_ttf/freetype.lib")
#pragma comment(lib, "lib/SDL2_ttf/zlib.lib")

// SDL2_gfx
#pragma comment(lib, "lib/SDL2_gfx/SDL2_gfx.lib")

struct ETHX_Spirit
{
	SDL_Surface* _pSurface;
	SDL_Texture* _pTexture;
	~ETHX_Spirit()
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

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");
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

void ETHX_SetWindowIcon(ETHX_Spirit* spirit)
{
	SDL_SetWindowIcon(_pWindow, spirit->_pSurface);
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

inline bool _check_spirit_is_valid(ETHX_Spirit* spirit);
inline bool _check_font_is_valid(ETHX_Font* font);

ETHX_Spirit* ETHX_LoadSpirit(const std::string& path)
{
	ETHX_Spirit* _spirit = new ETHX_Spirit();

	if (!(_spirit->_pSurface = IMG_Load(path.c_str())))
	{
		delete _spirit; _spirit = nullptr;
		return nullptr;
	}

	if (!(_spirit->_pTexture = SDL_CreateTextureFromSurface(_pWRenderer, _spirit->_pSurface)))
	{
		SDL_FreeSurface(_spirit->_pSurface); _spirit->_pSurface = nullptr;
		delete _spirit; _spirit = nullptr;
		return nullptr;
	}

	return _spirit;
}

ETHX_Spirit* ETHX_LoadSpirit(void* data, size_t size)
{
	ETHX_Spirit* _spirit = new ETHX_Spirit();

	if (!(_spirit->_pSurface = IMG_Load_RW(SDL_RWFromMem(data, size), 1)))
	{
		delete _spirit; _spirit = nullptr;
		return nullptr;
	}

	if (!(_spirit->_pTexture = SDL_CreateTextureFromSurface(_pWRenderer, _spirit->_pSurface)))
	{
		SDL_FreeSurface(_spirit->_pSurface); _spirit->_pSurface = nullptr;
		delete _spirit; _spirit = nullptr;
		return nullptr;
	}

	return _spirit;
}

inline bool _check_spirit_is_valid(ETHX_Spirit* spirit)
{
	return spirit;
}

void ETHX_SetSpiritColorKey(ETHX_Spirit* spirit, const ETHX_Color& color, bool flag)
{
	if (!_check_spirit_is_valid(spirit)) return;

	SDL_SetColorKey(spirit->_pSurface, flag, 
		SDL_MapRGBA(spirit->_pSurface->format, color.r, color.g, color.b, color.a));
	SDL_DestroyTexture(spirit->_pTexture); spirit->_pTexture = nullptr;
	spirit->_pTexture = SDL_CreateTextureFromSurface(_pWRenderer, spirit->_pSurface);
}

void ETHX_SetSpiritAplha(ETHX_Spirit* spirit, Uint8 alpha)
{
	if (!_check_spirit_is_valid(spirit)) return;

	SDL_SetTextureBlendMode(spirit->_pTexture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(spirit->_pTexture, alpha);
}

void ETHX_GetSpiritSize(ETHX_Spirit* spirit, int& width, int& height)
{
	if (!_check_spirit_is_valid(spirit)) return;

	width = spirit->_pSurface->w;
	height = spirit->_pSurface->h;
}

void ETHX_DrawSpirit(ETHX_Spirit* spirit, const ETHX_Point& pos)
{
	if (!_check_spirit_is_valid(spirit)) return;

	SDL_Rect _dst_rect = { pos.x, pos.y, spirit->_pSurface->w, spirit->_pSurface->h };
	SDL_RenderCopy(_pWRenderer, spirit->_pTexture, nullptr, &_dst_rect);
}

void ETHX_DrawSpirit(ETHX_Spirit* spirit, const ETHX_Rect& show_rect)
{
	if (!_check_spirit_is_valid(spirit)) return;

	SDL_Rect _dst_rect = { show_rect.x, show_rect.y, show_rect.w, show_rect.h };
	SDL_RenderCopy(_pWRenderer, spirit->_pTexture, nullptr, &_dst_rect);
}

void ETHX_DrawSpirit(ETHX_Spirit* spirit, const ETHX_Rect& show_rect, const ETHX_Rect& clip_rect)
{
	if (!_check_spirit_is_valid(spirit)) return;

	SDL_Rect _dst_rect = { show_rect.x, show_rect.y, show_rect.w, show_rect.h };
	SDL_Rect _src_rect = { clip_rect.x, clip_rect.y, clip_rect.w, clip_rect.h };
	SDL_RenderCopy(_pWRenderer, spirit->_pTexture, &_src_rect, &_dst_rect);
}

void ETHX_DrawSpirit(ETHX_Spirit* spirit, const ETHX_Rect& show_rect, 
	const ETHX_Rect& clip_rect, const ETHX_Point& center, double angle, ETHX_SpiritStyle style)
{
	if (!_check_spirit_is_valid(spirit)) return;

	SDL_Rect _dst_rect = { show_rect.x, show_rect.y, show_rect.w, show_rect.h };
	SDL_Rect _src_rect = { clip_rect.x, clip_rect.y, clip_rect.w, clip_rect.h };
	SDL_Point _flip_center = { center.x, center.y };
	SDL_RenderCopyEx(_pWRenderer, spirit->_pTexture, &_src_rect, &_dst_rect, 
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

void ETHX_DrawCircle(const ETHX_Point& center, int radius_x, int radius_y, bool fill)
{
	ETHX_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));
	fill ? filledEllipseRGBA(_pWRenderer, center.x, center.y, 
		radius_x, radius_y, _color.r, _color.g, _color.b, _color.a)
		: aaellipseRGBA(_pWRenderer, center.x, center.y, 
			radius_x, radius_y, _color.r, _color.g, _color.b, _color.a);
}

void ETHX_DrawCircle(const ETHX_Point& center, int radius, int start_angle, int end_angle, bool fill)
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

	ETHX_Spirit* _spirit = nullptr;

	if (!(_spirit = ETHX_CreateTextSpirit(font, text))) return;

	ETHX_Rect _rect = { pos.x, pos.y, _spirit->_pSurface->w, _spirit->_pSurface->h };
	ETHX_DrawSpirit(_spirit, _rect);

	delete _spirit; _spirit = nullptr;
}

void ETHX_DrawText(ETHX_Font* font, const std::string& text, const ETHX_Rect& show_rect)
{
	if (!_check_font_is_valid(font)) return;

	ETHX_Spirit* _spirit = nullptr;
	if (!(_spirit = ETHX_CreateTextSpirit(font, text))) return;

	ETHX_DrawSpirit(_spirit, show_rect);

	delete _spirit; _spirit = nullptr;
}

ETHX_Spirit* ETHX_CreateTextSpirit(ETHX_Font* font, const std::string& text)
{
	if (!_check_font_is_valid(font)) return nullptr;

	ETHX_Spirit* _spirit = new ETHX_Spirit();

	SDL_Color _color;
	SDL_GetRenderDrawColor(_pWRenderer, &(_color.r), &(_color.g), &(_color.b), &(_color.a));

	if (!(_spirit->_pSurface = TTF_RenderUTF8_Blended(font->_pFont, text.c_str(), _color)))
	{
		delete _spirit; _spirit = nullptr;
		return nullptr;
	}

	if (!(_spirit->_pTexture = SDL_CreateTextureFromSurface(_pWRenderer, _spirit->_pSurface)))
	{
		SDL_FreeSurface(_spirit->_pSurface); _spirit->_pSurface = nullptr;
		delete _spirit; _spirit = nullptr;
		return nullptr;
	}

	return _spirit;
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

#endif	// ETHERX_IMPLEMENTATION

#endif // !_ETHERX_H_