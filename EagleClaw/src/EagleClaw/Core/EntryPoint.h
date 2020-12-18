#pragma once

#ifdef EGC_PLATFORM_WINDOWS

extern EagleClaw::Application* EagleClaw::CreateApplication();

int main()
{
	EagleClaw::Log::Init();
	EagleClaw::Log::GetCoreLog()->warn("Initalized Log!");
	EagleClaw::Log::GetAppLog()->info("Initalized Log!");
	auto app = EagleClaw::CreateApplication();
	app->Run();
	delete app;
}

#endif
