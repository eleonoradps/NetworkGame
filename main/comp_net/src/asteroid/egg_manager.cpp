#include "asteroid/egg_manager.h"
#include "asteroid/game.h"

namespace neko::asteroid
{
	EggManager::EggManager(EntityManager& entityManager, GameManager& gameManager) :
		ComponentManager(entityManager), gameManager_(gameManager)
	{

	}

	void EggManager::FixedUpdate(seconds dt)
	{
		for (Entity entity = 0; entity < entityManager_.get().GetEntitiesSize(); entity++)
		{
			if (entityManager_.get().HasComponent(entity, EntityMask(ComponentType::EGG)))
			{

			}
		}
	}
}