#include "Application.h"

#include "Ynion/Events/ApplicationEvent.h"
#include "Ynion/Log.h"

namespace Ynion {

	Ynion::Application::Application()
	{
	}

	Ynion::Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			YN_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			YN_TRACE(e);
		}

		while (true);
	}

}


