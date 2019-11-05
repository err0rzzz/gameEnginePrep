#include "input.h"

void Input::Update(void)
{
	//poll keys for up/down state
	while (SDL_PollEvent(&m_event) != NULL)
	{
		if (m_event.type == SDL_KEYDOWN)
		{
			SDL_Keycode keyPressed = m_event.key.keysym.sym;

			switch (keyPressed)
			{
			case SDLK_ESCAPE:
				m_keysPressed[KEY_ESCAPE] = true;
				break;

			case SDLK_w:
				m_keysPressed[KEY_W] = true;
				break;

			case SDLK_a:
				m_keysPressed[KEY_A] = true;
				break;

			case SDLK_s:
				m_keysPressed[KEY_S] = true;
				break;

			case SDLK_d:
				m_keysPressed[KEY_D] = true;
				break;

			case SDLK_k:
				m_keysPressed[KEY_K] = true;
				break;

			case SDLK_l:
				m_keysPressed[KEY_L] = true;
				break;
			}
		}

		else if (m_event.type == SDL_KEYUP)
		{
			SDL_Keycode keyPressed = m_event.key.keysym.sym;
			
			switch (keyPressed)
			{
			case SDLK_ESCAPE:
				m_keysPressed[KEY_ESCAPE] = false;
				break;

			case SDLK_w:
				m_keysPressed[KEY_W] = false;
				break;

			case SDLK_a:
				m_keysPressed[KEY_A] = false;
				break;

			case SDLK_s:
				m_keysPressed[KEY_S] = false;
				break;

			case SDLK_d:
				m_keysPressed[KEY_D] = false;
				break;

			case SDLK_k:
				m_keysPressed[KEY_K] = false;
				break;

			case SDLK_l:
				m_keysPressed[KEY_L] = false;
				break;
			}
		}
	}
	//m_axis.xPos = 0;
	//m_axis.yPos = 0;
}



bool Input::KeyIsPressed(KEYS_PRESSED_LIST key)
{
	return m_keysPressed[key];
	
}

//Transform Input::GetAxis()
//{
//		
//	if (m_keysPressed[KEY_W]) m_axis.yPos++;
//	if (m_keysPressed[KEY_S]) m_axis.yPos--;
//	if (m_keysPressed[KEY_D]) m_axis.xPos++;
//	if (m_keysPressed[KEY_A]) m_axis.xPos--;
//	
//	return m_axis;
//}

Input::Input()
{
	
}


Input::~Input()
{

}
