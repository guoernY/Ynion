#include "MyGameMode.h"

#include<iostream>

MyGameMode::MyGameMode(b2World* world)
	:m_PhysicsWorld(world)
{
}

MyGameMode::~MyGameMode()
{
	delete m_ContactListener;
}

void MyGameMode::BeginGame()
{
}

void MyGameMode::UpdateGame()
{
	if (!isSetID)
	{
		m_PlayerID = PlayerController::getPlayerID();
		m_GoalID = Goal::getID();
		m_ContactListener = new MyContactListener(m_PlayerID, m_GoalID, this);
		m_PhysicsWorld->SetContactListener(m_ContactListener);

		isSetID = true;
	}
}

void MyGameMode::EndGame()
{
	delete m_ContactListener;
	m_ContactListener = nullptr;
	m_PhysicsWorld = nullptr;
}