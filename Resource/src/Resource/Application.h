#pragma once
#include "Core.h"
namespace Resource {
	class RESOURCE_API Application {
	public:
		static void Run();
		static void Update();
		static void Render();
		static void Start();
	};
}