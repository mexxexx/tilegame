#ifndef __TILEGAME_TILEGAME_H__
#define __TILEGAME_TILEGAME_H__

#include "engine.h"

namespace tilegame
{
    class Tilegame : public engine::Game
    {
    protected:
        void initialize();
        void loadContent();
        void unloadContent();
        void update(const double timeStep);
        void draw();

    private:
        int frames = 0;
        int updates = 0;
        double timer = 0;
    };
} // namespace tilegame

#endif