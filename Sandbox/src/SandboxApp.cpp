
#include "Kosm.h"

class Sandbox : public Kosm::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Kosm::Application* Kosm::CreateApplication()
{
	return new Sandbox();
}
