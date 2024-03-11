#include <Ynion.h>

class Sandbox : public Ynion::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{                                                                           

	}

};

Ynion::Application* Ynion::CreateApplication()
{
	return new Sandbox();
}