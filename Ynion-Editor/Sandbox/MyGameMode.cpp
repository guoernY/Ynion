#include "MyGameMode.h"

#include<iostream>

MyGameMode::MyGameMode(Ynion::EditorLayer* editor)
{
	m_editor = editor;
}

MyGameMode::~MyGameMode()
{
	if(m_ContactListener)
		delete m_ContactListener;
}

void MyGameMode::BeginGame()
{
	uint64_t m_PlayerID = getScriptEntityID("PlayerController");
	uint64_t m_GoalID = getScriptEntityID("Goal");

	m_isGame = m_PlayerID;

	if (m_isGame)
	{
		m_ContactListener = new MyContactListener(m_PlayerID, m_GoalID, this);
		m_PhysicsWorld->SetContactListener(m_ContactListener);
	}
}

void MyGameMode::UpdateGame()
{
	if (m_isGame)
	{
		if (m_State == GameState::Win)
		{
			GameWin();
			return;
		}
		else if (m_State == GameState::Loss)
		{
			GameLoss();
			return;
		}

		glm::vec3 PlayerPos = getScriptEntityTranslation("PlayerController");
		m_editor->SetMainCamerePos(glm::vec3(PlayerPos.x, PlayerPos.y, 60.0f));
	}
}

void MyGameMode::EndGame()
{
	if (m_isGame)
	{
		delete m_ContactListener;
		m_ContactListener = nullptr;
		m_PhysicsWorld = nullptr;
	}
}

void MyGameMode::GameWin()
{
	m_editor->SetGamePause(true);

	m_editor->DrawString("You Win!", glm::vec3(30.0f, 5.0f, 1.0f), glm::vec2(20.0f, 20.0f), glm::vec4(0.7f, 0.7f, 1.0f, 1.0f));

	if (Ynion::Input::IsKeyPressed(Ynion::Key::Enter))
		m_editor->RestartGame();
}

void MyGameMode::GameLoss()
{
	m_editor->RestartGame();
}

uint64_t MyGameMode::getScriptEntityID(const std::string scriptName)
{
	auto view = m_editor->getActiveScene()->GetAllEntitiesWith<Ynion::NativeScriptComponent>();
	for (auto entity : view)
	{
		std::string name = view.get<Ynion::NativeScriptComponent>(entity).name;
		if (!name.compare(scriptName))
			return m_editor->getActiveScene()->m_Registry.get<Ynion::IDComponent>(entity).ID;
	}
	return 0;
}

glm::vec3 MyGameMode::getScriptEntityTranslation(const std::string scriptName)
{
	bool isFind = false;
	auto view = m_editor->getActiveScene()->GetAllEntitiesWith<Ynion::NativeScriptComponent>();
	for (auto entity : view)
	{
		std::string name = view.get<Ynion::NativeScriptComponent>(entity).name;
		if (!name.compare(scriptName))
		{
			return m_editor->getActiveScene()->m_Registry.get<Ynion::TransformComponent>(entity).Translation;
		}
	}

	YN_ASSERT(isFind, "No entity is been found!");
}

