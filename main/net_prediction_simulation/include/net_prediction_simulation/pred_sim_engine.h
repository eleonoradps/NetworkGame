#pragma once


#include <engine/engine.h>
#include <engine/transform.h>
#include "sfml_engine/shape.h"
#include <random>
#include <sfml_engine/transform.h>
#include <sfml_engine/engine.h>

#include "net_prediction_simulation/pred_sim_server.h"
#include "net_prediction_simulation/pred_sim_client.h"

namespace neko::net
{

class VelocityManager : public neko::ComponentManager<neko::Vec2f, velocityMask>
{

};

struct Globals
{
    size_t shownActorNmb = 100;
    sf::Uint8 actorAlpha = 150;
    neko::Index clientTickPeriod = 2;
    int packetDelayMin = 2;
    int packetDelayMax = 20;
    std::uniform_real_distribution<float> distrNormal{0.0f, 1.0f};
    float dataLossProb = 0.0f;
    neko::Index serverDelayPeriod = 9;
    bool hideClient = false;
};


class PredSimEngine : public neko::sfml::SfmlBasicEngine
{
public:
    explicit PredSimEngine(neko::Configuration* config = nullptr);

    void Init() override;

    void Update(float dt) override;

    void Destroy() override;
    const Globals& GetGlobals(){ return globals_; }
private:
    friend class ServerSimSystem;

    friend class ClientSimSystem;

    ServerSimSystem server_;
    ClientSimSystem client_;
    Globals globals_;
    neko::EntityManager entityManager_;
    neko::sfml::SfmlGraphicsManager graphicsManager_;
    neko::sfml::SfmlTransform2dManager transformManager_;
    neko::sfml::ConvexShapeManager shapeManager_;
    VelocityManager velocitiesManager_;
};

}
