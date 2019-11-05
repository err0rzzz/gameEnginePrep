#include "SDL.h"
#include "Game.h"
#include "input.h"
#include "Transform.h"

#undef main

int main(void)
{
	//start up
	SDL_Init(SDL_INIT_EVERYTHING);

	// define default colours
	//colour Red(255, 0, 0, 255);  
	//colour Blue(0, 0, 255, 255);
	colour Custom(127, 127, 127, 255);

	Game* game = new Game();
	Input* input = new Input();
	Transform axis{ 0,0 };
	
//	bool isIncreasing = true;

	
	bool running = true;
	if (game && input)
	{
	/// MAIN GAME LOOP ///
		while (running)
		{

			input->Update();
			//axis= input->GetAxis();
			
			//game->m_monsterTransKeyed->UpdatePos(axis);
			
			
			if (input->KeyIsPressed(KEY_W))
			{
				game->m_monsterTransKeyed->UpdatePos(0, -1);
			}

			if (input->KeyIsPressed(KEY_A))
			{
				game->m_monsterTransKeyed->UpdatePos(-1, 0);
			}

			if (input->KeyIsPressed(KEY_S))
			{
				game->m_monsterTransKeyed->UpdatePos(0, 1);
			}

			if (input->KeyIsPressed(KEY_D))
			{
				game->m_monsterTransKeyed->UpdatePos(1, 0);
			}

			if (input->KeyIsPressed(KEY_K))
			{
			//	action 1
			}

			if (input->KeyIsPressed(KEY_L))
			{
			// action 2
			}

			//close if esc pressed
			if (input->KeyIsPressed(KEY_ESCAPE))
			{
				running = false;
				printf("exit pressed");
			}


			game->SetDisplayColour(Custom);
			game->Update();
		}

	}

	//clean up
	delete input;
	input = nullptr;
	
	delete game;
	game = nullptr;

	SDL_Quit();
}