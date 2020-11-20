#pragma once
#include "game.h"
#include "engine/component.h"
#include "comp_net/type.h"

namespace neko::asteroid
{
    struct Egg
    {
        float remainingTime = 0.0f;
        net::PlayerNumber playerNumber = net::INVALID_PLAYER;
    };
    class GameManager;
    class EggManager : public ComponentManager<Egg, static_cast<EntityMask>(ComponentType::EGG)>
    {
    public:
        explicit EggManager(EntityManager& entityManager, GameManager& gameManager);
        void FixedUpdate(seconds dt);
    private:
        std::reference_wrapper<GameManager> gameManager_;
    };
}