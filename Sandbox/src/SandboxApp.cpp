#include <Ynion.h>

class ExampleLayer : public Ynion::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		YN_INFO("ExampleLayer::Update");
	}
	void OnEvent(Ynion::Event& event) override
	{
		YN_TRACE("{0}", event);
	}
};


class Sandbox : public Ynion::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Ynion::ImGuiLayer());
	}

	~Sandbox()
	{                                                                           

	}

};

Ynion::Application* Ynion::CreateApplication()
{
	return new Sandbox();
}