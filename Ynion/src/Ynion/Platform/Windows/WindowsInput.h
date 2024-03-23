#pragma once

#include "Ynion/Input.h"

namespace Ynion {

	class WindowsInput : public Input	// Ϊɶ���ﲻ�õ���Ϊdll
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}
