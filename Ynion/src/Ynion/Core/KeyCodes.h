#pragma once

namespace Ynion
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define YN_KEY_SPACE           ::Ynion::Key::Space
#define YN_KEY_APOSTROPHE      ::Ynion::Key::Apostrophe    /* ' */
#define YN_KEY_COMMA           ::Ynion::Key::Comma         /* , */
#define YN_KEY_MINUS           ::Ynion::Key::Minus         /* - */
#define YN_KEY_PERIOD          ::Ynion::Key::Period        /* . */
#define YN_KEY_SLASH           ::Ynion::Key::Slash         /* / */
#define YN_KEY_0               ::Ynion::Key::D0
#define YN_KEY_1               ::Ynion::Key::D1
#define YN_KEY_2               ::Ynion::Key::D2
#define YN_KEY_3               ::Ynion::Key::D3
#define YN_KEY_4               ::Ynion::Key::D4
#define YN_KEY_5               ::Ynion::Key::D5
#define YN_KEY_6               ::Ynion::Key::D6
#define YN_KEY_7               ::Ynion::Key::D7
#define YN_KEY_8               ::Ynion::Key::D8
#define YN_KEY_9               ::Ynion::Key::D9
#define YN_KEY_SEMICOLON       ::Ynion::Key::Semicolon     /* ; */
#define YN_KEY_EQUAL           ::Ynion::Key::Equal         /* = */
#define YN_KEY_A               ::Ynion::Key::A
#define YN_KEY_B               ::Ynion::Key::B
#define YN_KEY_C               ::Ynion::Key::C
#define YN_KEY_D               ::Ynion::Key::D
#define YN_KEY_E               ::Ynion::Key::E
#define YN_KEY_F               ::Ynion::Key::F
#define YN_KEY_G               ::Ynion::Key::G
#define YN_KEY_H               ::Ynion::Key::H
#define YN_KEY_I               ::Ynion::Key::I
#define YN_KEY_J               ::Ynion::Key::J
#define YN_KEY_K               ::Ynion::Key::K
#define YN_KEY_L               ::Ynion::Key::L
#define YN_KEY_M               ::Ynion::Key::M
#define YN_KEY_N               ::Ynion::Key::N
#define YN_KEY_O               ::Ynion::Key::O
#define YN_KEY_P               ::Ynion::Key::P
#define YN_KEY_Q               ::Ynion::Key::Q
#define YN_KEY_R               ::Ynion::Key::R
#define YN_KEY_S               ::Ynion::Key::S
#define YN_KEY_T               ::Ynion::Key::T
#define YN_KEY_U               ::Ynion::Key::U
#define YN_KEY_V               ::Ynion::Key::V
#define YN_KEY_W               ::Ynion::Key::W
#define YN_KEY_X               ::Ynion::Key::X
#define YN_KEY_Y               ::Ynion::Key::Y
#define YN_KEY_Z               ::Ynion::Key::Z
#define YN_KEY_LEFT_BRACKET    ::Ynion::Key::LeftBracket   /* [ */
#define YN_KEY_BACKSLASH       ::Ynion::Key::Backslash     /* \ */
#define YN_KEY_RIGHT_BRACKET   ::Ynion::Key::RightBracket  /* ] */
#define YN_KEY_GRAVE_ACCENT    ::Ynion::Key::GraveAccent   /* ` */
#define YN_KEY_WORLD_1         ::Ynion::Key::World1        /* non-US #1 */
#define YN_KEY_WORLD_2         ::Ynion::Key::World2        /* non-US #2 */

/* Function keys */
#define YN_KEY_F24             ::Ynion::Key::F24
#define YN_KEY_F25             ::Ynion::Key::F25

/* Keypad */
#define YN_KEY_KP_0            ::Ynion::Key::KP0
#define YN_KEY_KP_1            ::Ynion::Key::KP1
#define YN_KEY_KP_2            ::Ynion::Key::KP2
#define YN_KEY_KP_3            ::Ynion::Key::KP3
#define YN_KEY_KP_4            ::Ynion::Key::KP4
#define YN_KEY_KP_5            ::Ynion::Key::KP5
#define YN_KEY_KP_6            ::Ynion::Key::KP6
#define YN_KEY_KP_7            ::Ynion::Key::KP7
#define YN_KEY_KP_8            ::Ynion::Key::KP8
#define YN_KEY_KP_9            ::Ynion::Key::KP9
#define YN_KEY_KP_DECIMAL      ::Ynion::Key::KPDecimal
#define YN_KEY_KP_DIVIDE       ::Ynion::Key::KPDivide
#define YN_KEY_KP_MULTIPLY     ::Ynion::Key::KPMultiply
#define YN_KEY_KP_SUBTRACT     ::Ynion::Key::KPSubtract
#define YN_KEY_KP_ADD          ::Ynion::Key::KPAdd
#define YN_KEY_KP_ENTER        ::Ynion::Key::KPEnter
#define YN_KEY_KP_EQUAL        ::Ynion::Key::KPEqual

#define YN_KEY_LEFT_SHIFT      ::Ynion::Key::LeftShift
#define YN_KEY_LEFT_CONTROL    ::Ynion::Key::LeftControl
#define YN_KEY_LEFT_ALT        ::Ynion::Key::LeftAlt
#define YN_KEY_LEFT_SUPER      ::Ynion::Key::LeftSuper
#define YN_KEY_RIGHT_SHIFT     ::Ynion::Key::RightShift
#define YN_KEY_RIGHT_CONTROL   ::Ynion::Key::RightControl
#define YN_KEY_RIGHT_ALT       ::Ynion::Key::RightAlt
#define YN_KEY_RIGHT_SUPER     ::Ynion::Key::RightSuper
#define YN_KEY_MENU            ::Ynion::Key::Menu