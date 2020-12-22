include "./vendor/premake/premake_customization/solution_items.lua"

workspace "OpenGL"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/EagleClaw/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/EagleClaw/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/EagleClaw/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/EagleClaw/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/EagleClaw/vendor/stb_image"
IncludeDir["ImGuizmo"] = "%{wks.location}/EagleClaw/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "EagleClaw/vendor/GLFW"
	include "EagleClaw/vendor/Glad"
	include "EagleClaw/vendor/imgui"
group ""

include "EagleClaw"
include "Sandbox"