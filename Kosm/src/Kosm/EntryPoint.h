#pragma once

#ifdef KM_PLATFORM_WINDOWS

extern Kosm::Application* Kosm::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome to the Kosm Engine!");
	auto app = Kosm::CreateApplication();
	app->Run();
	delete app;
}

#endif
