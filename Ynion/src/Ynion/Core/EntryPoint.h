#pragma once

#ifdef YN_PLATFORM_WINDOWS

extern Ynion::Application* Ynion::CreateApplication();

int main(int argc, char** argv)
{
	// 不用包含Log.h??? main函数的原因吗?
	Ynion::Log::Init();
	YN_CORE_WARN("Initialized Log!");
	YN_INFO("Hello!");

	auto app = Ynion::CreateApplication();
	app->Run();
	delete app;
}

#endif