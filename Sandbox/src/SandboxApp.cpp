#include <ApollonianGE.h>

class Sandbox : public ApollonianGE::Application {
public: 
	Sandbox() {

	}
	~Sandbox() {

	}
};


ApollonianGE::Application* ApollonianGE::CreateApplication() {
	return new Sandbox();
} 