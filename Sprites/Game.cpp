#include "Game.h"
#include <iostream>
#include "Sprite.h"

Game::Game()
{
	m_window = nullptr;
	m_renderer = nullptr;

	//start up
	SDL_Init(SDL_INIT_VIDEO);

	//create the window
	m_window = SDL_CreateWindow(
		"Game_Engine_Proto_1",	// name
		250,				// initial x pos
		50,					// initial y pos
		640,				// width in pixels
		480,				// height in pixels
		0					// window behaviour flags
		);

	if (!m_window)
	{
		printf("WINDOW Init failed: %s\n", SDL_GetError());
		printf("press any key to continue \n");
		getchar();
		return;

	}

	// create the renderer
	m_renderer = SDL_CreateRenderer(
		m_window,				// link the renderer to window
		-1,					// index rendering driver
		0					// renderer behavior flags
		);

	if (!m_renderer)
	{
		printf("RENDERER init failed: %s \n", SDL_GetError());
		printf("Press any key to continue \n");
		getchar();

		return;
	}

	//create bitmaps
	m_monster = new Bitmap(m_renderer, "assets/monster.bmp", 100, 100);
	m_monsterTrans = new Bitmap(m_renderer, "assets/monsterTrans.bmp", 200, 100);
	m_monsterTransKeyed = new Bitmap(m_renderer, "assets/monsterTrans.bmp", 300, 100, true);

	// Transform player_trans = Transform(1,2);
	
	// Sprite player = new Sprite(m_monsterTransKeyed, player_trans);
}

Game::~Game()
{
	if (m_monsterTransKeyed) delete m_monsterTransKeyed;
	if (m_monsterTrans) delete m_monsterTrans;
	if (m_monster) delete m_monster;
	
	if (m_renderer) SDL_DestroyRenderer(m_renderer);
	if (m_window)	SDL_DestroyWindow(m_window);
}

void Game::Update()
{
	SDL_RenderClear(m_renderer);	// render colour to buffer

	m_monster->draw();
	m_monsterTrans->draw();
	m_monsterTransKeyed->draw();
	
	SDL_RenderPresent(m_renderer);	// show what has been drawn
	SDL_Delay(5);					// wait 
}

void Game::SetDisplayColour(colour inputColour)
{
	if (m_renderer)
	{
		// render in a colour
		int result = SDL_SetRenderDrawColor(
			m_renderer,
			inputColour.rgbR,
			inputColour.rgbB,
			inputColour.rgbG,
			inputColour.rgbA
		);


		//SDL_Delay(5000);				// wait 5 seconds
	}
}