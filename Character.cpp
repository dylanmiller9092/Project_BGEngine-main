#include "Character.h"
#include "SDL.h"
#include <iostream>
using namespace std;

Character::Character(Texture* CharacterTexture, int PosX, int PosY, int NumberOfFrames)
{
	//cout << "Pos X: " << PositionX << endl;
	//cout << "Pos Y: " << PositionY << endl;
	PositionX = PosX;
	PositionY = PosY;
	ObjectTexture = CharacterTexture;
	this->NumberOfFrames = NumberOfFrames;
}

Character::~Character()
{
}

void Character::Draw(SDL_Renderer* Renderer)
{
	SDL_Rect Clip;
	Clip.x = 0;
	Clip.y = 0;
	Clip.h = ObjectTexture->GetImageHeight();
	Clip.w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);

	ObjectTexture->Draw(Renderer, PositionX, PositionY, &Clip);
}

void Character::Update(float DeltaTime)
{
}

void Character::Input()
{
}
