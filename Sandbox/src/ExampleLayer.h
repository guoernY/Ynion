#pragma once

#include "Ynion.h"

class ExampleLayer : public Ynion::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Ynion::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Ynion::Event& e) override;
private:
	Ynion::ShaderLibrary m_ShaderLibrary;
	Ynion::Ref<Ynion::Shader> m_Shader;
	Ynion::Ref<Ynion::VertexArray> m_VertexArray;

	Ynion::Ref<Ynion::Shader> m_FlatColorShader;
	Ynion::Ref<Ynion::VertexArray> m_SquareVA;

	Ynion::Ref<Ynion::Texture2D> m_Texture, m_LogoTexture;

	Ynion::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};