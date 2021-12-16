#pragma once

// Core serves to define some "macros" that will clean up code for us when we start using the dll file for our functions/classes.

#ifdef AGEZ_PLATFORM_WINDOWS									// First check that the platform is windows
	#ifdef AGEZ_BUILD_DLL										// If we are building the dll this macro will be defined. WE build in AGE lib so we export here
		#define AGEZ_API __declspec(dllexport)				
	#else
		#define AGEZ_API __declspec(dllimport)					// Otherwise we we import from our library to our application (i.e. the sandbox test project)
	#endif
#else
	#error Apollonian Curren tly only supports Windows
#endif



