#pragma once

class b2World;

namespace Ynion {

	class GameMode {
	public:
		virtual ~GameMode() = default;

		virtual void BeginGame() = 0;
		virtual void UpdateGame() = 0;
		virtual void EndGame() = 0;

		enum class GameState
		{
			Run = 0, Win = 1, Loss = 2
		};
		void setGameState(GameState state) { m_State = state; }
		GameState getGameState() { return m_State; }
	protected:
		GameState m_State;
	};

	// To be defined in CLIENT
	GameMode* CreateGameMode(b2World* world);

}