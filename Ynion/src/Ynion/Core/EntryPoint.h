#pragma once

#ifdef YN_PLATFORM_WINDOWS

extern Ynion::Application* Ynion::CreateApplication();

int main(int argc, char** argv)
{
	// ���ð���Log.h??? main������ԭ����?
	Ynion::Log::Init();
	YN_CORE_WARN("Initialized Log!");
	YN_INFO("Hello!");

	auto app = Ynion::CreateApplication();
	app->Run();
	delete app;
}

#endif