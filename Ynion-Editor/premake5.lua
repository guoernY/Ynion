project "Ynion-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Ynion/vendor/spdlog/include",
		"%{wks.location}/Ynion/src",
		"%{wks.location}/Ynion/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"Ynion"
	}

	filter "system:windows"
		systemversion "latest"

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