#pragma once

#include "Ynion/Core/Base.h"
#include "Ynion/Core/KeyCodes.h"
#include "Ynion/Core/MouseCodes.h"

namespace Ynion {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}