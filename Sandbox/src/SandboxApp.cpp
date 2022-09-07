#include <ApollonianGE.h>

class ExampleLayer : public ApollonianGE::Layer {
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		AGEZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(ApollonianGE::Event& event) override
	{
		AGEZ_TRACE("{0}", event);
	}
};

class Sandbox : public ApollonianGE::Application {
public: 
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}

};


ApollonianGE::Application* ApollonianGE::CreateApplication() {
	return new Sandbox();
} 