#pragma once

#ifdef AGEZ_PLATFORM_WINDOWS 

// Extern function to be found somewhere else. In our case client will define what this application is, so it will be found
// in the clients implementation file.
extern ApollonianGE::Application* ApollonianGE::CreateApplication();

// NOTE: If all we do is modify header files, we neednt bother with copying the dll
// If we modify .cpp files then we definitely need to copy the dll .

// By having Entrypoint.h we no longer place the burden of having an entry point on the client.
// Instead we simply take whatever function the client has created and run it in this main body,
// which will start the application for them. Obviously it deletes when its finished since this is on the heap. (Create app is of pointer type)
int main(int agrc, char** argv) {
	ApollonianGE::Log::Init();
	AGEZ_CORE_WARN("Initialized Log!");
	int a = 5;
	AGEZ_INFO("Hello! Variable test = {0}", a);


	auto app = ApollonianGE::CreateApplication();
	app->Run();
	delete app;
}
#endif