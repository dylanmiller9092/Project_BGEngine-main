#include "GameObject.h"

GameObject::GameObject()
{
	PositionX = 0;
	PositionY = 0;
	ObjectTexture = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::Draw(SDL_Renderer* Renderer)
{
}

void GameObject::Update(float DeltaTime)
{
}

void GameObject::Input()
{
}
