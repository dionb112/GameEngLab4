#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include "Animation.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "InputComponent.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "AISystem.h"
#include "HealthSystem.h"

static const int SPRITE_SIZE = 32;
class Game
{
public:
	Game();
	~Game();
	bool Initialize(const char*, int, int, int, int, int);
	void LoadContent();
	void UnloadContent();
	void Render();
	void Update();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();
private:
	Entity player;
	Entity alien;
	Entity dog;
	Entity cat;
	HealthComponent healthComponent;
	PositionComponent positionComponent;
	InputComponent inputComponent;
	ControlSystem controlSystem;
	RenderSystem renderSystem;
	AISystem aISystem;
	HealthSystem healthSystem;

	int m_spriteX; 
	int m_spriteY;
	Animation fsm;
	int m_pressed;
	Uint32 m_ticks;
	int m_sprite;
	SDL_Rect m_srcrect;
	SDL_Rect m_dstrect;
	bool m_running;
	SDL_Window* m_p_Window;
	SDL_Renderer* m_p_Renderer;
	SDL_Texture* m_p_Texture;
	SDL_Rect m_Source;
	SDL_Rect m_Destination;
	SDL_Surface* m_p_Surface;
};
#endif
