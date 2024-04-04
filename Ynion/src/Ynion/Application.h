#pragma once

#include "Core.h"

#include "Window.h"
#include "Ynion/LayerStack.h"
#include "Ynion/Events/Event.h"
#include "Ynion/Events/ApplicationEvent.h"

#include "Ynion/Core/Timestep.h"

#include "Ynion/ImGui/ImGuiLayer.h"

namespace Ynion {

	class YNION_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		
		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
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
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}


