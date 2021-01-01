project "Sandbox"
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

	defines
	{
	}

	includedirs
	{
		"%{wks.location}/EagleClaw/vendor/spdlog/include",
		"%{wks.location}/EagleClaw/src",
		"%{wks.location}/EagleClaw/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"EagleClaw"
	}

	filter "system:windows"
		systemversion "latest"
	
	filter "system:macosx"
		systemversion "latest"
