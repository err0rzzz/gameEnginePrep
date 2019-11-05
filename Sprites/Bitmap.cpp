#include "Bitmap.h"
#include "SDL.h"
#include "SDL_render.h"

using namespace std;

Bitmap::Bitmap(SDL_Renderer* renderer, string fileName, int xpos, int ypos, bool useTransparency)
{
	//store renderer for future use
	m_pRenderer = renderer;

	//create the bitmap surface
	m_pbitmapSurface = SDL_LoadBMP(fileName.c_str());
	if (!m_pbitmapSurface)
	{
		printf("SURFACE for bitmap '%s' is not loaded! \n", fileName.c_str());
		printf("%s \n", SDL_GetError());
	}
	else
	{
		// set up transparency assuming Magenta(r255,g0,b255) is key
		if(useTransparency)
		{
			Uint32 colourKey = SDL_MapRGB(m_pbitmapSurface->format, 255, 0, 255);
			SDL_SetColorKey(m_pbitmapSurface, SDL_TRUE, colourKey);
		}

		//create the texture
		m_pbitmapTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pbitmapSurface);
		if (!m_pbitmapTexture)
		{
			//texture not loaded?
			printf("TEXTURE for bitmap '%s' is not loaded! \n", fileName.c_str());
			printf("%s \n", SDL_GetError());
		}
	}

	//store the position
	m_x = xpos;
	m_y = ypos;
}

void Bitmap::UpdatePos(int transform, int t2)
{
	m_x += transform;
	m_y += t2;
}

void Bitmap::draw()
{
	//render the bitmap at the x/y coords
	if(m_pbitmapTexture)
	{
		SDL_Rect destRect = { m_x, m_y, m_pbitmapSurface->w, m_pbitmapSurface->h };
		SDL_RenderCopy(m_pRenderer, m_pbitmapTexture, NULL, &destRect);
	}
}
Bitmap::~Bitmap()
{
	if (m_pbitmapTexture)
		SDL_DestroyTexture(m_pbitmapTexture);
	
	if (m_pbitmapSurface)
		SDL_FreeSurface(m_pbitmapSurface);
}
