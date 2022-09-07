#pragma once
#include "Core.h"
#include "Layer.h"
#include <vector>

namespace ApollonianGE {
	class AGEZ_API LayerStack 
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_LayerStack.begin(); }
		std::vector<Layer*>::iterator end() { return m_LayerStack.end(); }

	private:
		std::vector<Layer*> m_LayerStack;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}
