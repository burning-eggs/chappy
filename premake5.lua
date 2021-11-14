workspace "chappy"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outdir = "%{cfg.buildcfg}-%{cfg.system}-${cfg.architecture}"

project "chappy"
    location "chappy"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/include/Chappy.h"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        staticruntime "On"
        
        defines {
            "CP_WINDOWS",
            "CHAPPY"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outdir .. "/Tests")
        }
    
    filter "configurations:Debug"
        defines "CP_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "CP_DEBUG"
        optimize "On"
    
    filter "configurations:Dist"
        defines "CP_DIST"
        optimize "On"

project "Tests"
    location "tests"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "chappy/include"
    }

    links {
        "chappy"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        staticruntime "On"

        defines {
            "CP_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "CP_DEBUG"
        symbols "On"
    
    filter "configurations:Debug"
        defines "CP_DEBUG"
        symbols "On"
    
    filter "configurations:Dist"
        defines "CP_DIST"
        symbols "On"