#pragma once

#include "Ynion.h"

class Sandbox2D : public Ynion::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Ynion::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Ynion::Event& e) override;
private:
	Ynion::OrthographicCameraController m_CameraController;

	Ynion::Ref<Ynion::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};