#pragma once
#include "GameObject.h"
#include "SDL.h"

using namespace std;

class Character : public GameObject
{
public:
	Character(Texture* CharacterTexture, int PosX, int PosY, int NumberOfFrames);
	~Character();

	void Draw(SDL_Renderer* Renderer) override;
	void Update(float DeltaTime) override;
	void Input() override;

private:
	unsigned int NumberOfFrames;
};

