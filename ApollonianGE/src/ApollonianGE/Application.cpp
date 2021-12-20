#include "agezpch.h"
#include "Application.h"
#include "ApollonianGE/Events/ApplicationEvent.h"
#include "ApollonianGE/Log.h"
// The application class definitions are pretty barebones for now, but the run function is what gets the window up and running.
// Obviously we have a creator and destructor 
namespace ApollonianGE {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application() {

	}

	void Application::Run() {

		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}