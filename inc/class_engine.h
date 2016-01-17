#pragma once

#include <queue>
#include "class_game.h"
#include "class_game_engine.h"
#include "class_gfx_engine.h"
#include "class_sfx_engine.h"

class class_engine
{
    
    protected:

         class_game* parent;

         std::queue<engine_event> q_events;

         virtual void process_event(engine_event &e) = 0;

         void send_to_game(class_engine_event& e);
         void send_to_gfx(class_engine_event& e);
         void send_to_sfx(class_engine_event& e);

         class_game_engine* game_engine;
         class_gfx_engine* gfx_engine;
         class_sfx_engine* sfx_engine;

    public:

        class_engine(class_game* m_parent);
        virtual ~class_engine();

        void push_event(engine_event &e);

        void procces_events();

        virtual void frame() = 0;

        void attach_game_engine(class_game_engine* e) { game_engine = e; };
        void attach_gfx_engine(class_gfx_engine* e) { gfx_engine = e; };
        void attach_sfx_engine(class_sfx_engine* e) { sfx_engine = e };

};

