include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Ynion"
	architecture "x86_64"
	startproject "Ynion-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Ynion/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Ynion/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Ynion/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Ynion/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Ynion/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Ynion/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Ynion/vendor/yaml-cpp/include"
IncludeDir["Box2D"] = "%{wks.location}/Ynion/vendor/Box2D/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Ynion/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "Ynion/vendor/Box2D"
	include "Ynion/vendor/GLFW"
	include "Ynion/vendor/Glad"
	include "Ynion/vendor/imgui"
	include "Ynion/vendor/yaml-cpp"
group ""

include "Ynion"
include "Sandbox"
include "Ynion-Editor"