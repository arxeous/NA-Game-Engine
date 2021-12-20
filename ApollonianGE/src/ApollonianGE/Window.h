#pragma once

#include "agezpch.h"

#include "ApollonianGE/Core.h"
#include "ApollonianGE/Events/Event.h"

namespace ApollonianGE {
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;


		WindowProps(const std::string& title = "Apollonian Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}

	};

	// Interface that represents a desktop system based Window
	// This is an interface since thers no data nor functions in this class
	// Its all virtual, and has to be implemented per platform.
	class AGEZ_API Window {
	public: 
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}