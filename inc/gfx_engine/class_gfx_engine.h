class class_gfx_engine;

#pragma once

#include "class_engine.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include "defs.h"

class class_gfx_engine
    : public class_engine
{
	private:
		SDL_Window	*window;
		int 		screen_width;
		int 		screen_height;
		bool		fullscreen;

		void get_display_bounds(void);
		void set_window_fullscreen(void);
		void set_window_desktop(void);
		void switch_fullscreen_state(void);

	protected:
		void process_event(class_engine_event* e);

	public:
		class_gfx_engine(class_game *m_parent);
		~class_gfx_engine(void);

		void frame(void);
};