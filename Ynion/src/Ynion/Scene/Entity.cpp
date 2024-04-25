#include "ynpch.h"
#include "Entity.h"

namespace Ynion {

	Entity::Entity(entt::entity handle, Scene* scene)
		:m_EntityHandle(handle), m_Scene(scene)
	{
	}

}