#include "tilegame.hpp"

#include <vector>
#include <time.h>

#include <sstream>

#include "engine.hpp"

namespace tilegame
{
    engine::Tileset tileset;

    void Tilegame::initialize()
    {
        Game::initialize();

        //glfwSetInputMode(window.getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        window->setPosition(700, 400);
    }

    void Tilegame::loadContent()
    {
        tileset.loadFromFile("content/world/tileset1.tsx", "content/textures/");
    }

    void Tilegame::unloadContent()
    {
    }

    void Tilegame::update(const double deltaTime)
    {
        timer += deltaTime;
        updates++;

        // - Reset after one second
        if (timer > 1)
        {
            timer--;
            std::stringstream ss;
            ss << "FPS: " << frames << " - UPS: " << updates;
            window->setTitle(ss.str());
            updates = 0, frames = 0;
        }
    }

    void Tilegame::draw()
    {
        graphicsDevice->clear(engine::Color::CornflowerBlue);

        spriteBatch->begin();
        spriteBatch->draw(tileset.getTexture(), engine::Rectangle(100, 100, 400, 400), engine::Color::White);
        spriteBatch->end();

        frames++;
    }
} // namespace tilegame
