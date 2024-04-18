#pragma once

#include "Ynion/Core/Base.h"

#include "Ynion/Core/Window.h"
#include "Ynion/Core/LayerStack.h"
#include "Ynion/Events/Event.h"
#include "Ynion/Events/ApplicationEvent.h"

#include "Ynion/Core/Timestep.h"

#include "Ynion/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Ynion {

	class Application
	{
	public:
		Application(const std::string& name = "Ynion App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		
		Window& GetWindow() { return *m_Window; }

		void Close();

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

