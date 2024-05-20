#include "kmpch.h"
#include "Application.h"

#include "Kosm/Events/ApplicationEvent.h"

namespace Kosm {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	};
}
