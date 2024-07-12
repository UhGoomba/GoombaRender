#ifndef GOOMBARENDER_INPUT_H
#define GOOMBARENDER_INPUT_H

#include <SDL3/SDL.h>

namespace GoombaEngine
{
    class Input
    {
    public:
        void ProcessEvent(SDL_Event &event);
        bool IsKeyPressed(SDL_Keycode keycode);
        bool IsKeyJustPressed(SDL_Keycode keycode);
        bool IsKeyJustReleased(SDL_Keycode keycode);
    private:
        std::unordered_set<SDL_Keycode> m_PressedKeys;
    };
    
} // GoombaEngine

#endif //GOOMBARENDER_INPUT_H
