#pragma once

#include "Kosm/Core.h"
#include "Kosm/Window.h"

namespace Kosm {

	class KOSM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in client
	Application* CreateApplication();
}
