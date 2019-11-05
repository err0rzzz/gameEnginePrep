#pragma once

#include "SDL.h"
#include "Transform.h"

// global vars
enum KEYS_PRESSED_LIST
{
	KEY_ESCAPE, KEY_W, KEY_A, KEY_S, KEY_D, KEY_K, KEY_L, SIZE_OF_KEYS_PRESSED_ENUM
};

class Input
{
public:
	void Update(void);
	bool KeyIsPressed(KEYS_PRESSED_LIST key);
	
	//Transform GetAxis();

	Input();
	~Input();

private:
	//Transform m_axis = { 0,0 };
	SDL_Event m_event;
	bool m_keysPressed[SIZE_OF_KEYS_PRESSED_ENUM];
};

