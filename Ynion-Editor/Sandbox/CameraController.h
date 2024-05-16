#pragma once
#include "Ynion.h"
#include "PlayerController.h"

#include "Box2D/include/box2d/b2_body.h"

glm::vec3 PlayerController::m_Translation = glm::vec3(0.0f, 0.0f, 0.0f);

class CameraController : public Ynion::ScriptableEntity
{
public:
	virtual void OnCreate() override
	{
	}

	virtual void OnDestroy() override
	{
	}

	virtual void OnUpdate(Ynion::Timestep ts) override
	{
		m_Translation = &GetComponent<Ynion::TransformComponent>().Translation;

		m_PlayerPos = PlayerController::getPlayerPos();
		m_Translation->x = m_PlayerPos.x;
		m_Translation->y = m_PlayerPos.y;

		//{
		//	float speed = 20.0f;

		//	if (Ynion::Input::IsKeyPressed(Ynion::Key::A))
		//		m_Translation->x -= speed * ts;
		//	else if (Ynion::Input::IsKeyPressed(Ynion::Key::D))
		//		m_Translation->x += speed * ts;
		//	if (Ynion::Input::IsKeyPressed(Ynion::Key::W))
		//		m_Translation->y += speed * ts;
		//	else if (Ynion::Input::IsKeyPressed(Ynion::Key::S))
		//		m_Translation->y -= speed * ts;
		//}
	}
private:
	glm::vec3 m_PlayerPos;
	glm::vec3* m_Translation;
};