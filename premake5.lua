workspace "Ynion"
	architecture "x86_64"
	startproject "Sandbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Ynion/vendor/GLFW/include"
IncludeDir["Glad"] = "Ynion/vendor/Glad/include"
IncludeDir["ImGui"] = "Ynion/vendor/imgui"
IncludeDir["glm"] = "Ynion/vendor/glm"
IncludeDir["stb_image"] = "Ynion/vendor/stb_image"

group "Dependencies"
	include "Ynion/vendor/GLFW"
	include "Ynion/vendor/Glad"
	include "Ynion/vendor/imgui"

group ""

project "Ynion"
	location "Ynion"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ynpch.h"
	pchsource "Ynion/src/ynpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"YN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "YN_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "YN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "YN_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Ynion/vendor/spdlog/include",
		"Ynion/src",
		"Ynion/vendor",
		"%{IncludeDir.glm}"
	}

	links{
		"Ynion"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"YN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "YN_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "YN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "YN_DIST"
		runtime "Release"
		optimize "on"