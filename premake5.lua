workspace "PyxelFox"
    architecture "x64"
    startproject "PyxelFox"
    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}"

IncludeDir = {}
IncludeDir["GLFW"] = "ThirdParty/glfw/include"
IncludeDir["Glad"] =  "ThirdParty/glad/include"

group "Dependencies"
	include "ThirdParty/Glfw"
    include "ThirdParty/Glad"
group ""

group "PyxelFox"

group ""

project "PyxelFox"

    location "PyxelFox"
    kind "ConsoleApp"
    language "c++"
    cppdialect "C++20"
    staticruntime "on"

    files{
        "PyxelFox/src/**.h",
        "PyxelFox/src/**.hpp",
        "PyxelFox/src/**.cpp",
        "Foxigen/assets/**"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "Foxigen/assets/",
        "Foxigen/src/",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
	}

    links
    {
        "GLFW",
		"Glad"
    }

    targetdir( outputdir .. "/PyxelFox")
    objdir("bin-int/" .. outputdir .. "/PyxelFox")

    filter "system:windows"
    systemversion "latest"

    filter "configurations:Debug"
        defines "DRG_Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "DRG_Release"
        runtime "Release"
        optimize "on"

