#pragma once
#ifdef RS_BUILD_DLL
#define RESOURCE_API __declspec(dllexport)
#else
#define RESOURCE_API __declspec(dllimport)
#endif // RS_BUILD_DLL
