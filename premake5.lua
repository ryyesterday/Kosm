workspace "Kosm"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Kosm/vendor/GLFW/include"

include "Kosm/vendor/GLFW"

project "Kosm"
	location "Kosm"
	kind "SharedLib"
	language "C++"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kmpch.h"
	pchsource "Kosm/src/kmpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

		defines
		{
			"KOSM_PLATFORM_WINDOWS",
			"KOSM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "Configurations:Debug"
		defines 
		{
			"KOSM_DEBUG",
			"KOSM_ENABLE_ASSERTS"
		}
		symbols "On"
		runtime "Debug"

	filter "Configurations:Release"
		defines "KOSM_RELEASE"
		optimize "On"
		runtime "Release"

	filter "Configurations:Dist"
		defines "KOSM_DIST"
		optimize "On"
		runtime "Release"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Kosm/vendor/spdlog/include",
		"Kosm/src"
	}

	links
	{
		"Kosm"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

		defines
		{
			"KOSM_PLATFORM_WINDOWS"
		}

	filter "Configurations:Debug"
		defines "KOSM_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "Configurations:Release"
		defines "KOSM_RELEASE"
		optimize "On"
		runtime "Release"

	filter "Configurations:Dist"
		defines "KOSM_DIST"
		optimize "On"
		runtime "Release"
