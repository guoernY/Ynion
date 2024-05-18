#pragma once
#include "Ynion.h"
#include "GameMode.h"

#include "PlayerController.h"
#include "Goal.h"

#include "Box2D/include/box2d/b2_world.h"
#include "Box2D/include/box2d/b2_contact.h"
#include "Box2D/include/box2d/b2_world_callbacks.h"

class MyGameMode : public Ynion::GameMode
{
public:
	MyGameMode(Ynion::EditorLayer* editor);
	~MyGameMode();

	virtual void BeginGame() override;
	virtual void UpdateGame() override;
	virtual void EndGame() override;

	virtual void GameWin() override;
	virtual void GameLoss() override;
private:
	uint64_t getScriptEntityID(const std::string name);
	glm::vec3 getScriptEntityTranslation(const std::string name);
private:
	b2ContactListener* m_ContactListener = nullptr;
	bool m_isGame = true;
};

Ynion::GameMode* Ynion::CreateGameMode(Ynion::EditorLayer* editor)
{
	return new MyGameMode(editor);
}

class MyContactListener : public b2ContactListener
{
public:
	MyContactListener(uint64_t playerID, uint64_t goalID, MyGameMode* gameMode)
		:m_PlayerID(playerID), m_GoalID(goalID),m_Game(gameMode)
	{
	}

	virtual void BeginContact(b2Contact* contact) override
	{
		uint64_t a_ID = contact->GetFixtureA()->GetBody()->GetUserData().pointer;
		uint64_t b_ID = contact->GetFixtureB()->GetBody()->GetUserData().pointer;

		if (a_ID != m_PlayerID && b_ID != m_PlayerID)
		{
			return;
		}
		else if (a_ID != m_GoalID && b_ID != m_GoalID)
		{
			YN_INFO("Player Contact!");
			m_Game->setGameState(Ynion::GameMode::GameState::Loss);
		}
		else
		{
			YN_INFO("Reach Goal!");
			m_Game->setGameState(Ynion::GameMode::GameState::Win);
		}
	}
private:
	uint64_t m_PlayerID;
	uint64_t m_GoalID;
	MyGameMode* m_Game;
};
