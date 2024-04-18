#include <Ynion.h>
#include <Ynion/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Ynion {

	class YnionEditor : public Application
	{
	public:
		YnionEditor()
			: Application("Ynion Editor")
		{
			PushLayer(new EditorLayer());
		}

		~YnionEditor()
		{

		}

	};

	Application* CreateApplication()
	{
		return new YnionEditor();
	}

}