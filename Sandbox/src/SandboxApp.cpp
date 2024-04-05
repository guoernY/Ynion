#include <Ynion.h>
#include <Ynion/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public Ynion::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.f / 720.0f, true)
	{
		// The Triangle
		// ------------
		m_VertexArray = Ynion::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Ynion::Ref<Ynion::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Ynion::VertexBuffer::Create(vertices, sizeof(vertices)));
		Ynion::BufferLayout layout = {
			{ Ynion::ShaderDataType::Float3, "a_Position" },
			{ Ynion::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0,1,2 };
		Ynion::Ref<Ynion::IndexBuffer> indexBuffer;
		indexBuffer.reset(Ynion::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		// The Square
		// ----------
		m_SquareVA = Ynion::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Ynion::Ref<Ynion::VertexBuffer> squareVB;
		squareVB.reset(Ynion::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Ynion::ShaderDataType::Float3, "a_Position" },
			{ Ynion::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Ynion::Ref<Ynion::IndexBuffer> squareIB;
		squareIB.reset(Ynion::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		// Shader of the triangle
		// ----------------------
		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
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

		m_Shader = Ynion::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		// Shader of the square
		// --------------------
		std::string flatColorShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader = Ynion::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Ynion::Texture2D::Create("assets/textures/Checkerboard.png");
		m_LogoTexture = Ynion::Texture2D::Create("assets/textures/ChernoLogo.png");

		std::dynamic_pointer_cast<Ynion::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Ynion::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}

	virtual void OnUpdate(Ynion::Timestep ts) override
	{
		// Update
		m_CameraController.OnUpdate(ts);

		// Render
		Ynion::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Ynion::RenderCommand::Clear();

		Ynion::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Ynion::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Ynion::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f - 1.0f, y * 0.11f - 1.0f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Ynion::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		Ynion::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		m_LogoTexture->Bind();
		Ynion::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		// Triangle
		// Ynion::Renderer::Submit(m_Shader, m_VertexArray);

		Ynion::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	virtual void OnEvent(Ynion::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}
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

class Sandbox : public Ynion::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{                                                                           

	}

};

Ynion::Application* Ynion::CreateApplication()
{
	return new Sandbox();
}