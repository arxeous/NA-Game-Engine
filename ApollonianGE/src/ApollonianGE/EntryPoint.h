#pragma once

#ifdef AGEZ_PLATFORM_WINDOWS 

// Extern function to be found somewhere else. In our case client will define what this application is, so it will be found
// in the clients implementation file.
extern ApollonianGE::Application* ApollonianGE::CreateApplication();


// By having Entrypoint.h we no longer place the burden of having an entry point on the client.
// Instead we simply take whatever function the client has created and run it in this main body,
// which will start the application for them. Obviously it deletes when its finished since this is on the heap. (Create app is of pointer type)
int main(int agrc, char** argv) {
	printf("Apollonian Engine");
	auto app = ApollonianGE::CreateApplication();
	app->Run();
	delete app;
}
#endif