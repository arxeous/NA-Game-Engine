#pragma once

// Core serves to define some "macros" that will clean up code for us when we start using the dll file for our functions/classes.

#ifdef AGEZ_PLATFORM_WINDOWS									// First check that the platform is windows
	#ifdef AGEZ_BUILD_DLL										// If we are building the dll this macro will be defined. WE build in AGE lib so we export here
		#define AGEZ_API __declspec(dllexport)				
	#else
		#define AGEZ_API __declspec(dllimport)					// Otherwise we we import from our library to our application (i.e. the sandbox test project)
	#endif
#else
	#error Apollonian Currently only supports Windows
#endif

#ifdef AGEZ_ENABLE_ASSERTS
	#define AGEZ_ASSERT(x, ...) {if(!(x) {AGEZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AGEZ_CORE_ASSERT(x, ...) {if(!(x)){AGEZ_CORE_ASSERT("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AGEZ_ASSERT(x, ...)
	#define AGEZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)


