workspace "ApollonianGE"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root foder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "ApollonianGE/vendor/GLFW/include"
IncludeDir["glad"] = "ApollonianGE/vendor/glad/include"

-- This include will include the premake in the GLFW 
-- Sorta like c++ where we just copy and paste that file into this one
include "ApollonianGE/vendor/GLFW"
include "ApollonianGE/vendor/glad"

project "ApollonianGE"
	location "ApollonianGE"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "agezpch.h"
	pchsource "ApollonianGE/src/agezpch.cpp"

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}"
	}

	links {
		"GLFW",
		"opengl32.lib",
		"glad"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"AGEZ_PLATFORM_WINDOWS", 
			"AGEZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AGEZ_DEBUG"
		symbols "On"
		buildoptions "/MDd"

	filter "configurations:Release"
		defines "AGEZ_RELEASE"
		optimize "On"
		buildoptions "/MD"

	filter "configurations:Dist"
		defines "AGEZ_DIST"
		optimize "On"
		buildoptions "/MD"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"ApollonianGE/vendor/spdlog/include",
		"ApollonianGE/src"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"AGEZ_PLATFORM_WINDOWS"
		}

	links {
		"ApollonianGE"
	}
	filter "configurations:Debug"
		defines "AGEZ_DEBUG"
		symbols "On"
		buildoptions "/MDd"

	filter "configurations:Release"
		defines "AGEZ_RELEASE"
		optimize "On"
		buildoptions "/MD"

	filter "configurations:Dist"
		defines "AGEZ_DIST"
		optimize "On"
		buildoptions "/MD"
	
	