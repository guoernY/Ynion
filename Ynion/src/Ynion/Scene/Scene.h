#pragma once

#include "Ynion/Core/Timestep.h"
#include "Ynion/Core/UUID.h"
#include "Ynion/Renderer/EditorCamera.h"

#include "entt.hpp"

class b2World;

namespace Ynion {

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		static Ref<Scene> Copy(Ref<Scene> other);

		Entity CreateEntity(const std::string& name = std::string());
		Entity CreateEntityWithUUID(UUID uuid, const std::string& name = std::string());
		void DestroyEntity(Entity entity);

		void OnRuntimeStart();
		void OnRuntimeStop();

		void OnSimulationStart();
		void OnSimulationStop();

		void OnUpdateRuntime(Timestep ts);
		void OnUpdateSimulation(Timestep ts, EditorCamera& camera);
		void OnUpdateEditor(Timestep ts, EditorCamera& camera);
		void OnViewportResize(uint32_t width, uint32_t height);

		void DuplicateEntity(Entity entity);

		Entity GetPrimaryCameraEntity();

		bool IsPaused() const { return m_IsPaused; }
		bool IsGamePaused() const { return m_IsGamePaused; }

		void SetPaused(bool paused) { m_IsPaused = paused; }
		void SetGamePaused(bool paused) { m_IsGamePaused = paused; }

		void Step(int frames = 1);

		b2World* getPhysicsWorld() { return m_PhysicsWorld; }

		template<typename... Components>
		auto GetAllEntitiesWith()
		{
			return m_Registry.view<Components...>();
		}
	public:	// Temp
		entt::registry m_Registry;
	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);

		void OnPhysics2DStart();
		void OnPhysics2DStop();

		void RenderScene(EditorCamera& camera);
	private:
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;
		bool m_IsPaused = false;
		bool m_IsGamePaused = false;
		int m_StepFrames = 0;

		b2World* m_PhysicsWorld = nullptr;

		friend class Entity;
		friend class SceneSerializer;
		friend class SceneHierarchyPanel;
	};

}