#pragma once

#include "Ynion/Core/Layer.h"

#include "Ynion/Events/ApplicationEvent.h"
#include "Ynion/Events/KeyEvent.h"
#include "Ynion/Events/MouseEvent.h"

namespace Ynion {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}