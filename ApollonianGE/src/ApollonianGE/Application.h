#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace ApollonianGE {
	class AGEZ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT (SandboxApp,etc.)
	// Because this is defined in client there is no need to export it like the Application class .
	Application* CreateApplication();

}

