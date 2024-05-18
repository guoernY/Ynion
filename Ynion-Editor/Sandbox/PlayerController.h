#pragma once
#include "Ynion.h"

#include "box2d/b2_body.h"

class PlayerController : public Ynion::ScriptableEntity
{
public:
	virtual void OnCreate() override
	{
		m_Rigidbody = GetComponent<Ynion::Rigidbody2DComponent>();
	}

	virtual void OnDestroy() override
	{
	}

	virtual void OnUpdate(Ynion::Timestep ts) override
	{
		float speed = 0.000001f;

		Ynion::Math::Vector3 velocity = Ynion::Math::Vector3::zero();

		if (Ynion::Input::IsKeyPressed(Ynion::Key::Up))
			velocity.Y = 1.0f;
		else if (Ynion::Input::IsKeyPressed(Ynion::Key::Down))
			velocity.Y = -1.0f;

		if (Ynion::Input::IsKeyPressed(Ynion::Key::Left))
			velocity.X = -1.0f;
		else if (Ynion::Input::IsKeyPressed(Ynion::Key::Right))
			velocity.X = 1.0f;

		velocity *= speed;

		ApplyLinearImpulseToCenter(glm::vec2(velocity.X, velocity.Y), true);
	}
private:
	void ApplyLinearImpulseToCenter(glm::vec2 impulse, bool wake)
	{
		b2Body* body = (b2Body*)m_Rigidbody.RuntimeBody;
		body->ApplyLinearImpulseToCenter(b2Vec2(impulse.x, impulse.y), wake);
	}
private:
	Ynion::Rigidbody2DComponent m_Rigidbody;
};
