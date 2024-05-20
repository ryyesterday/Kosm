#pragma once

#ifdef KOSM_PLATFORM_WINDOWS

extern Kosm::Application* Kosm::CreateApplication();

int main(int argc, char** argv)
{
	Kosm::Log::Init();
	KOSM_CORE_WARN("Initialized Log");
	int a = 5;
	KOSM_INFO("Hello! Var={0}", a);
	
	auto app = Kosm::CreateApplication();
	app->Run();
	delete app;
}

#endif
