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

	Ynion::Ref<Ynion::Framebuffer> m_Framebuffer;

	Ynion::Ref<Ynion::Texture2D> m_CheckerboardTexture;

	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;

	glm::vec4 m_SquareColor;
};