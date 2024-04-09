#include "ynpch.h"
#include "Ynion/Core/Input.h"

#ifdef YN_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace Ynion {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
	#ifdef YN_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
	#else
		YN_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}