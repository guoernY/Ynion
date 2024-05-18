#pragma once
#include "EditorLayer.h"

class b2World;

namespace Ynion {

	class EditorLayer;

	class GameMode {
	public:
		virtual ~GameMode() = default;

		virtual void BeginGame() = 0;
		virtual void UpdateGame() = 0;
		virtual void EndGame() = 0;

		virtual void GameWin() = 0;
		virtual void GameLoss() = 0;

		void setPhysicsWorld(b2World* world) { m_PhysicsWorld = world; }

		enum class GameState
		{
			Run = 0, Win = 1, Loss = 2
		};
		void setGameState(GameState state) { m_State = state; }
		GameState getGameState() { return m_State; }
	protected:
		EditorLayer* m_editor;
		b2World* m_PhysicsWorld;
		GameState m_State;
	};

	// To be defined in CLIENT
	GameMode* CreateGameMode(EditorLayer* editor);

}