workspace "Ynion"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ynion"
	location "Ynion"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines{
			"YN_PLATFORM_WINDOWS",
			"YN_BUILD_DLL"
		}
	
		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/Sandbox")
		}

	filter "configurations:Debug"
		defines "YN_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "YN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Ynion/vendor/spdlog/include",
		"Ynion/src"
	}

	links{
		"Ynion"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines{
			"YN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "YN_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "YN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YN_DIST"
		optimize "On"