#pragma once

namespace Ynion
{
	
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}

}

#define YN_MOUSE_BUTTON_0      ::Ynion::Mouse::Button0
#define YN_MOUSE_BUTTON_1      ::Ynion::Mouse::Button1
#define YN_MOUSE_BUTTON_2      ::Ynion::Mouse::Button2
#define YN_MOUSE_BUTTON_3      ::Ynion::Mouse::Button3
#define YN_MOUSE_BUTTON_4      ::Ynion::Mouse::Button4
#define YN_MOUSE_BUTTON_5      ::Ynion::Mouse::Button5
#define YN_MOUSE_BUTTON_6      ::Ynion::Mouse::Button6
#define YN_MOUSE_BUTTON_7      ::Ynion::Mouse::Button7
#define YN_MOUSE_BUTTON_LAST   ::Ynion::Mouse::ButtonLast
#define YN_MOUSE_BUTTON_LEFT   ::Ynion::Mouse::ButtonLeft
#define YN_MOUSE_BUTTON_RIGHT  ::Ynion::Mouse::ButtonRight
#define YN_MOUSE_BUTTON_MIDDLE ::Ynion::Mouse::ButtonMiddle