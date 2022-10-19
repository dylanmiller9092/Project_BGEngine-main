#include "Input.h"

Input::Input() 
{
}

Input::~Input()
{
}

void Input::UpdateInput(bool& bIsGameOver)
{
	SDL_Event Event;
	if (SDL_PollEvent(&Event)) {
		//detect the type of input that was pressed
		switch(Event.type) {
		case SDL_KEYDOWN:
			KeyboardState = SDL_GetKeyboardState(NULL);
			break;
		case SDL_KEYUP:
			KeyboardState = SDL_GetKeyboardState(NULL);
			break;
		default:
			break;
		}


		// When you hit the cross button on the app, close the game
		if (Event.type == SDL_QUIT) {
			bIsGameOver = true;
		}
	}
}

bool Input::bIsKeyDown(SDL_Scancode Key)
{
	if (KeyboardState != nullptr && KeyboardState[Key] == true) {
		return true;
	}

	return false;
}

bool Input::bIsKeyUp(SDL_Scancode Key)
{
	if (KeyboardState != nullptr && KeyboardState[Key] == true) {
		return false;
	}

	return true;
}
