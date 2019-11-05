#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include "colour.h"
#include "Bitmap.h"

struct SDL_Window;
struct SDL_Renderer;
class Bitmap;

class Game
{
private:
	SDL_Window* m_window;
	SDL_Renderer *m_renderer;

	//bitmaps
	Bitmap*	m_monster;				//04-01
	Bitmap* m_monsterTrans;			//04-01

public:
	Bitmap* m_monsterTransKeyed;	//04-01
	Game();
	~Game();

	void SetDisplayColour(colour inputColour);
	void Update();

	
};

#endif