#include <Ynion.h>

#include "imgui/imgui.h"

class ExampleLayer : public Ynion::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		// The Triangle
		// ------------
		m_VertexArray.reset(Ynion::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<Ynion::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Ynion::VertexBuffer::Create(vertices, sizeof(vertices)));
		Ynion::BufferLayout layout = {
			{ Ynion::ShaderDataType::Float3, "a_Position" },
			{ Ynion::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0,1,2 };
		std::shared_ptr<Ynion::IndexBuffer> indexBuffer;
		indexBuffer.reset(Ynion::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		// The Square
		// ----------
		m_SquareVA.reset(Ynion::VertexArray::Create());

		float squareVertices[3 * 4] = {
				-0.75f, -0.75f, 0.0f,
				 0.75f, -0.75f, 0.0f,
				 0.75f,  0.75f, 0.0f,
				-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<Ynion::VertexBuffer> squareVB;
		squareVB.reset(Ynion::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Ynion::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Ynion::IndexBuffer> squareIB;
		squareIB.reset(Ynion::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		// Shader of the triangle
		// ----------------------
		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(new Ynion::Shader(vertexSrc, fragmentSrc));

		// Shader of the square
		// --------------------
		std::string blueShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new Ynion::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	virtual void OnUpdate() override
	{
		if (Ynion::Input::IsKeyPressed(YN_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed;
		else if (Ynion::Input::IsKeyPressed(YN_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed;
		if (Ynion::Input::IsKeyPressed(YN_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed;
		else if (Ynion::Input::IsKeyPressed(YN_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed;

		if (Ynion::Input::IsKeyPressed(YN_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed;
		else if (Ynion::Input::IsKeyPressed(YN_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed;

		Ynion::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Ynion::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Ynion::Renderer::BeginScene(m_Camera);

		Ynion::Renderer::Submit(m_BlueShader, m_SquareVA);
		Ynion::Renderer::Submit(m_Shader, m_VertexArray);

		Ynion::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
	}

	virtual void OnEvent(Ynion::Event& event) override
	{
	}
private:
	std::shared_ptr<Ynion::Shader> m_Shader;
	std::shared_ptr<Ynion::VertexArray> m_VertexArray;

	std::shared_ptr<Ynion::Shader> m_BlueShader;
	std::shared_ptr<Ynion::VertexArray> m_SquareVA;

	Ynion::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 0.1f;
	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 1.0f;
};


class Sandbox : public Ynion::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{                                                                           

	}

};

Ynion::Application* Ynion::CreateApplication()
{
	return new Sandbox();
}