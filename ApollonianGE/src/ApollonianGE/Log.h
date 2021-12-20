#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"



namespace ApollonianGE {
	class AGEZ_API Log
	{
	public:
		static void Init();

		// Use shared_ptr to automate allocation deletion on heap
		// Fcn returns a ref(address) to our logger
		// obviously it will be static since we only need these two loggers across the board
		// and inline for overhead. 
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// ... is just a macro for variable number arguements. __VA_ARGS__ is just us
// forwarding this to our function

// one reason we want these as macros is the ability to strip out this code in distribution
// We would simply need to check #if dist build -> #define AGEZ_CORE_TRACE
// This would strip anyplace in our code from actually logging when we don't need it to
// making our lives that much easier.

// Core log macros
#define AGEZ_CORE_TRACE(...)  ::ApollonianGE::Log::GetCoreLogger()->trace(__VA_ARGS__ )
#define AGEZ_CORE_INFO(...)   ::ApollonianGE::Log::GetCoreLogger()->info(__VA_ARGS__ )
#define AGEZ_CORE_WARN(...)   ::ApollonianGE::Log::GetCoreLogger()->warn(__VA_ARGS__ )
#define AGEZ_CORE_ERROR(...)  ::ApollonianGE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AGEZ_CORE_FATAL(...)  ::ApollonianGE::Log::GetCoreLogger()->fatal(__VA_ARGS__ )

// Client log macros
#define AGEZ_TRACE(...)  ::ApollonianGE::Log::GetClientLogger()->trace(__VA_ARGS__ )
#define AGEZ_INFO(...)   ::ApollonianGE::Log::GetClientLogger()->info(__VA_ARGS__ )
#define AGEZ_WARN(...)   ::ApollonianGE::Log::GetClientLogger()->warn(__VA_ARGS__ )
#define AGEZ_ERROR(...)  ::ApollonianGE::Log::GetClientLogger()->error(__VA_ARGS__)
#define AGEZ_FATAL(...)  ::ApollonianGE::Log::GetClientLogger()->fatal(__VA_ARGS__ )