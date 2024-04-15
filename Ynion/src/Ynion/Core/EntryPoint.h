#pragma once
#include "Ynion/Core/Base.h"

#ifdef YN_PLATFORM_WINDOWS

extern Ynion::Application* Ynion::CreateApplication();

int main(int argc, char** argv)
{
	Ynion::Log::Init();
	YN_CORE_INFO("Initialized Log!");
	YN_INFO("Hello!");

	auto app = Ynion::CreateApplication();
	app->Run();
	delete app;
}

#endif