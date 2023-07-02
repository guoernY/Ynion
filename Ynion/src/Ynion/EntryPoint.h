#pragma once

#ifdef YN_PLATFORM_WINDOWS

extern Ynion::Application* Ynion::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ynion::CreateApplication();
	app->Run();
	delete app;
}

#endif