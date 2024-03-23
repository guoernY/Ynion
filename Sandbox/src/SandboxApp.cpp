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
		if (Ynion::Input::IsKeyPressed(YN_KEY_TAB))
			YN_TRACE("Tab key is pressed (poll)!");
	}
	void OnEvent(Ynion::Event& event) override
	{
		//YN_TRACE("{0}", event);
		if (event.GetEventType() == Ynion::EventType::KeyPressed)
		{
			Ynion::KeyPressedEvent& e = (Ynion::KeyPressedEvent&)event;
			if (e.GetKeyCode() == YN_KEY_TAB)
				YN_TRACE("Tab key is pressed (event)!");
			YN_TRACE("{0}", (char)e.GetKeyCode());
		}
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