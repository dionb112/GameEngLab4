#include "Game.h"
#include <iostream>
#include <thread>
using namespace std;
Game::Game() : 
	m_running(false),
	m_spriteY{ 0 },
	m_spriteX{ 32 },
	m_pressed{ 4 }
{
}
Game::~Game()
{
}
bool Game::Initialize(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	player.addComponent(healthComponent);
	player.addComponent(positionComponent);
	player.addComponent(inputComponent);
	alien.addComponent(healthComponent);
	alien.addComponent(positionComponent);
	dog.addComponent(healthComponent);
	dog.addComponent(positionComponent);
	cat.addComponent(positionComponent);
	controlSystem.addEntity(player);
	renderSystem.addEntity(player);
	healthSystem.addEntity(player);
	renderSystem.addEntity(alien);
	healthSystem.addEntity(alien);
	aISystem.addEntity(alien);
	renderSystem.addEntity(dog);
	healthSystem.addEntity(dog);
	aISystem.addEntity(dog);
	renderSystem.addEntity(cat);
	aISystem.addEntity(cat); // cat has no health component

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		DEBUG_MSG("SDL Init success");
		m_p_Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if(m_p_Window != 0)
		{
			DEBUG_MSG("Window creation success");
			m_p_Renderer = SDL_CreateRenderer(m_p_Window, -1, 0);
			if(m_p_Renderer != 0)
			{
				DEBUG_MSG("Renderer creation success");
				SDL_SetRenderDrawColor(m_p_Renderer, 0, 255, 255, 255);
			}
			else
			{
				DEBUG_MSG("Renderer init fail");
				return false;
			}
		}
		else
		{
			DEBUG_MSG("Window init fail");
			return false;
		}
	}
	else
	{
		DEBUG_MSG("SDL init fail");
		return false;
	}
	m_running = true;

	return true;
}
void Game::LoadContent()
{
	DEBUG_MSG("Loading Content");
	m_p_Surface = SDL_LoadBMP("assets/sprite.bmp");
	m_p_Texture = SDL_CreateTextureFromSurface(m_p_Renderer, m_p_Surface);
	SDL_FreeSurface(m_p_Surface);

	if(SDL_QueryTexture(m_p_Texture, NULL, NULL, &m_Source.w, &m_Destination.h)==0)
	{
		m_Destination.x = m_Source.x = 0;
		m_Destination.y = m_Source.y = 0;
		m_Destination.w = m_Source.w;
		m_Destination.h = m_Source.h;
	}
	else
	{
		DEBUG_MSG("Texture Query Failed");
		m_running = false;
	}
}
void Game::Render()
{
	SDL_RenderClear(m_p_Renderer);
	DEBUG_MSG("Width Source" + m_Destination.w);
	DEBUG_MSG("Width Destination" + m_Destination.w);

	if(m_p_Renderer != nullptr && m_p_Texture != nullptr)
		SDL_RenderCopy(m_p_Renderer, m_p_Texture, &m_srcrect, &m_dstrect);
	SDL_RenderPresent(m_p_Renderer);
}
void Game::Update()
{
	controlSystem.update();
	renderSystem.update();

	m_ticks = SDL_GetTicks();
	m_sprite = (m_ticks / 100) % 3;

	m_srcrect = { m_sprite * m_spriteX, m_spriteY, SPRITE_SIZE, SPRITE_SIZE };
	m_dstrect = { SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE };
	switch (m_pressed)
	{
	case 0:
		fsm.walking();
		m_spriteY = SPRITE_SIZE;
		m_spriteX = SPRITE_SIZE;
		break;
	case 1:
		fsm.climbing();
		m_spriteY = SPRITE_SIZE * 2;
		m_spriteX = SPRITE_SIZE;
		break;
	case 2:
		fsm.jumping();
		m_spriteY = SPRITE_SIZE * 3;
		m_spriteX = SPRITE_SIZE;
		break;
	case 3:
		fsm.falling();
		m_spriteY = 0;
		m_spriteX = SPRITE_SIZE;
		break;
	case 4:
		fsm.idle();
		m_spriteX = 0;
		break;
	default:
		break;
	}
}
void Game::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_running = false;
				break;
			case SDLK_UP:
				SDL_SetRenderDrawColor(m_p_Renderer, 255, 0, 0, 255);
				m_pressed = 2; // jump
				break;
			case SDLK_DOWN:
				SDL_SetRenderDrawColor(m_p_Renderer, 0, 255, 0, 255);
				m_pressed = 3; // falling
				break;
			case SDLK_LEFT:
				SDL_SetRenderDrawColor(m_p_Renderer, 0, 0, 255, 255);
				m_pressed = 0; // walking
				break;
			case SDLK_RIGHT:
				SDL_SetRenderDrawColor(m_p_Renderer, 255, 255, 255, 255);
				m_pressed = 1; // climbing
				break;
			case SDLK_SPACE:
				SDL_SetRenderDrawColor(m_p_Renderer, 0, 255, 255, 255);
				m_pressed = 4; // idle
				break;
			default:
				SDL_SetRenderDrawColor(m_p_Renderer, 0, 0, 0, 255);
				break;
			}
		}
	}
}

bool Game::IsRunning()
{
	return m_running;
}

void Game::UnloadContent()
{
	DEBUG_MSG("Unloading Content");
	// delete(m_p_Texture);
	// m_p_Texture = NULL;
}

void Game::CleanUp()
{
	DEBUG_MSG("Cleaning Up");
	SDL_DestroyWindow(m_p_Window);
	SDL_DestroyRenderer(m_p_Renderer);
	SDL_Quit();
}
