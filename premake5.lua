workspace "Resource"
 architecture "x64"

 configurations
 {
  "Debug",
  "Release",
  "Dist"
 }

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Resource/vendor/GLFW/include"
IncludeDir["Glad"] = "Resource/vendor/Glad/include"
IncludeDir["glm"] = "Resource/vendor/glm"

include "Resource/vendor/GLFW"
include "Resource/vendor/Glad"

 project "Resource"
 location "Resource"
 kind "SharedLib"
 language "C++"

 targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

 files
 {
  "%{prj.name}/src/**.h",
  "%{prj.name}/src/**.cpp",
  "%{prj.name}/vendor/glm/**.hpp",
  "%{prj.name}/vendor/glm/**.inl"
 }

 includedirs
 {
  "%{prj.name}/vendor/spdlog/include",
  "%{IncludeDir.GLFW}",
  "%{IncludeDir.Glad}",
  "%{IncludeDir.glm}"
 }

 links
 {
   "GLFW",
   "Glad",
   "opengl32.lib"
 }

 filter "system:windows"
  cppdialect "C++17"
  staticruntime "On"
  systemversion "latest"

  defines
  {
   "RS_PLATFORM_WINDOWS",
   "RS_BUILD_DLL"
  }

postbuildcommands
{
   ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
  }

 filter "configurations:Debug"
  defines "RS_DEBUG"
  symbols "On"

 filter "configurations:Release"
  defines "RS_RELEASE"
  optimize "On"

 filter "configurations:Dist"
  defines "RS_DIST"
  optimize "On"

project "Sandbox"
 location "Sandbox"
 kind "ConsoleApp"
 language "C++"

 targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

 files
 {
  "%{prj.name}/src/**.h",
  "%{prj.name}/src/**.cpp"
 }

 includedirs
 {
  "Resource/vendor/spdlog/include",
  "Resource/src",
  "%{IncludeDir.GLFW}",
  "%{IncludeDir.Glad}",
  "%{IncludeDir.glm}"
 }

 links
 {
  "Resource",
  "GLFW",
  "Glad",
  "opengl32.lib"
 }

 filter "system:windows"
  cppdialect "C++17"
  staticruntime "On"
  systemversion "latest"

  defines
  {
   "RS_PLATFORM_WINDOWS"
  }

 filter "configurations:Debug"
  defines "RS_DEBUG"
  symbols "On"

 filter "configurations:Release"
  defines "RS_RELEASE"
  optimize "On"

 filter "configurations:Dist"
  defines "RS_DIST"
  optimize "On"