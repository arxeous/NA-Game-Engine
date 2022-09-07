#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "ApollonianGE/Events/ApplicationEvent.h"
#include "ApollonianGE/LayerStack.h"

namespace ApollonianGE {
	class AGEZ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT (SandboxApp,etc.)
	// Because this is defined in client there is no need to export it like the Application class .
	Application* CreateApplication();

}

