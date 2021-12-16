#pragma once
#include "Core.h"

namespace ApollonianGE {
	class AGEZ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT (SandboxApp,etc.)
	// Because this is defined in client there is no need to export it like the Application class .
	Application* CreateApplication();

}

