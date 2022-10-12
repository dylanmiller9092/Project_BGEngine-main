#pragma once
#include "SDL.h"
#include "Texture.h"

class GameObject
{
public: 
	GameObject();
	~GameObject();

	virtual void Draw(SDL_Renderer* Renderer);
	virtual void Update(float DeltaTime);
	virtual void Input();

protected: 
	//positions for the game object to display on the window
	int PositionX;
	int PositionY;
	//The objects texture
	Texture* ObjectTexture;
};