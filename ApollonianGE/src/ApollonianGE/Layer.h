#pragma once
#include "Core.h"
#include "ApollonianGE/Events/Event.h"

namespace ApollonianGE {
	class AGEZ_API Layer 
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetatch() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& e) {};

		inline const std::string& GetName() { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}
