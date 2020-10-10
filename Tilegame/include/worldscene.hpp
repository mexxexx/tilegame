#pragma once

#include <memory>

#include "engine.hpp"

namespace tilegame
{
    class WorldScene : public engine::Scene
    {
    private:
        std::unique_ptr<engine::Observer> cameraObserver;

        void updateCameras();

    public:
        virtual void initialize() override;
        virtual void loadContent() override;
        virtual void processInput() override;
        virtual void update(const double deltaTime) override;
        virtual void draw() override;
    };
} // namespace tilegame