#pragma once

#include "Ynion/Core/KeyCodes.h"
#include "Ynion/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace Ynion {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}