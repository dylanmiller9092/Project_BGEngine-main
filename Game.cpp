#include <iostream>
#include "Game.h"
#include "Texture.h"
using namespace std;

// constructor
Game::Game()
{
	// set the SDL Window and Renderer to null in case it has memory
	SdlWindow = nullptr;
	SdlRenderer = nullptr;

	// Initialise the subsytem in the SDL2 Framework
	if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) != 0) {

		bIsGameOver = true;
		// if failed to initialise subsystem, tell us on the console
		cout << "Initialise SDL - failed" << endl;
	}
	else {
		// enable the game loop
		bIsGameOver = false;
		// if the subsytem succesfully initialises
		cout << "Initialise SDL - success" << endl;
	}
}

// deconstructor
Game::~Game()
{

}

bool Game::Start()
{
	// create the sdl renderer and define it
	SdlRenderer = SDL_CreateRenderer(SdlWindow, 0, -1);

	// get the start time of the clock in milliseconds
	LastUpdateTime = SDL_GetTicks();

	// make sure the renderer worked
	if (SdlRenderer != nullptr) {
		cout << "Create Renderer - success" << endl;

		//Initalise the player Texture
		PlayerTexture = new Texture();
		//load the player texture
		PlayerTexture->LoadImageFromFile("assets/spritesheet.png", SdlRenderer);

		//Construct the player
		Character* Player = new Character(PlayerTexture, 0, 0, 109);
		GameObjects.push_back(Player);

		//Initalise the enemy Texture
		EnemyTexture = new Texture();
		//load the enemy texture
		EnemyTexture->LoadImageFromFile("assets/goblin-spritesheet-65x35-28.png", SdlRenderer);

		//Construct the enemy
		Character* Enemy = new Character(EnemyTexture, 0, 35, 28);
		GameObjects.push_back(Enemy);
	}

	return true;
}

void Game::ProcessInput()
{
	// @ TODO: Process player inputs

	//cycle through all game objects and run their inputs
	for (unsigned int i = 0; i < GameObjects.size(); ++i) {
		GameObjects[i]->Input();
	}
}

void Game::Update()
{
	// @ TODO: Add and changes to the game each frame
	// howe long since the last frame was updated in milliseconds
	unsigned int tick = SDL_GetTicks() - LastUpdateTime;

	//change the tick to seconds
	float DeltaTime = tick / 1000.0f;

	//refresh the last update time
	LastUpdateTime = SDL_GetTicks();

	// @TODO: Add anything that needs DeltaTime below here


	//cycle through all game objects and run their update
	for (unsigned int i = 0; i < GameObjects.size(); ++i) {
		GameObjects[i]->Update(DeltaTime);
	}

	// get how many seconds it's been
	int Seconds = SDL_GetTicks() / 1000;

	// after 10 seconds kill the program
	if (Seconds > 9) {
		bIsGameOver = true;
	}
}

void Game::Draw()
{
	// set the draw colour
	SDL_SetRenderDrawColor(SdlRenderer, 15, 15, 15, 255);

	// clear the renderers
	SDL_RenderClear(SdlRenderer);

	// @ TODO: Draw stuff herea

	//Cycle through all game objects and run their draw
	for (unsigned int i = 0; i < GameObjects.size(); ++i) {
		GameObjects[i]->Draw(SdlRenderer);
	}

	SDL_RenderPresent(SdlRenderer);
}

void Game::Run(const char* title, int width, int height, bool fullscreen)
{
	// define the creation flag
	int CreationFlag = 0;

	// if fullscreen is set to false then set windowed mode
	if (!fullscreen) {
		CreationFlag = SDL_WINDOW_SHOWN;
	}
	else {
		CreationFlag = SDL_WINDOW_FULLSCREEN;
	}

	// create the SDL Window
	SdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, CreationFlag);

	// check if the SDL window worked
	// create the renderer and start the game loop
	if (SdlWindow != nullptr && Start()) {
		cout << "Create Window - success" << endl;

		// run the game loop
		while (!bIsGameOver) {
			// check for player input
			ProcessInput();

			// process any changes that were made either by input or game code
			Update();

			// draw everything to the screen
			Draw();
		}
	}

	// debug if we failed or exited
	cout << "Create Window - failed or was exited" << endl;

	Shutdown();
	Destroy();
}

void Game::Shutdown()
{
	// @ TODO: deallocate all of the stuff we add in start
}

void Game::Destroy()
{
	// deallocate the window
	SDL_DestroyWindow(SdlWindow);

	// deallocate the renderer
	SDL_DestroyRenderer(SdlRenderer);

	// shut down the SDL framework
	SDL_Quit();

}
