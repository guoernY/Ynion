#include "ynpch.h"
#include "Ynion/Core/Window.h"

#ifdef YN_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Ynion
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef YN_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		YN_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}