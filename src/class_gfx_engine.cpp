#include "class_gfx_engine.h"

class_gfx_engine::class_gfx_engine(class_engine *m_parent): parent(m_parent)
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_INIT_VIDEO failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if ((window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0)) == NULL)
	{
		printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

class_gfx_engine::~class_gfx_engine(void)
{
	SDL_DestroyWindow(window);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void class_gfx_engine::frame(void)
{
	this->process_events();
}

void class_gfx_engine::process_event(class_engine_event &e)
{
	
}