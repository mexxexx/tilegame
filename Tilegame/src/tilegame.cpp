#include "tilegame.hpp"

#include <vector>
#include <memory>
#include <sstream>

#include "engine.hpp"

namespace tilegame
{
    std::unique_ptr<engine::Map> map1;
    std::unique_ptr<engine::MapRenderer> map1Renderer;

    std::unique_ptr<engine::FreeEntity> entity;
    std::unique_ptr<engine::Player> player;

    void Tilegame::initialize()
    {
        Game::initialize();

        map1 = std::unique_ptr<engine::Map>(new engine::Map());
        map1Renderer = std::unique_ptr<engine::MapRenderer>(new engine::MapRenderer(*map1));

        entity = std::unique_ptr<engine::FreeEntity>(new engine::FreeEntity());
        player = std::unique_ptr<engine::Player>(new engine::Player(entity.get(), this->graphicsDevice->getViewport()));

        //glfwSetInputMode(window.getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        window->setPosition(700, 400);
    }

    void Tilegame::loadContent()
    {
        map1->loadFromFile("content/world/", "map1.tmx");
        map1Renderer->initialize();

        Game::loadContent();
    }

    void Tilegame::unloadContent()
    {
        map1.reset();
        map1Renderer.reset();

        Game::unloadContent();
    }

    void Tilegame::update(const double deltaTime)
    {   
        player->moveLeft();
        player->update(deltaTime);

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

        map1Renderer->draw(*spriteBatch, player->getCamera());

        frames++;
    }
} // namespace tilegame
