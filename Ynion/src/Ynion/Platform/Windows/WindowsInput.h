#pragma once

#include "Ynion/Input.h"

namespace Ynion {

	class WindowsInput : public Input	// 为啥这里不用导出为dll
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}
