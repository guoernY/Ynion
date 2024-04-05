#pragma once

#include "Ynion/Core/Layer.h"

#include "Ynion/Events/ApplicationEvent.h"
#include "Ynion/Events/KeyEvent.h"
#include "Ynion/Events/MouseEvent.h"

namespace Ynion {

	class YNION_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}