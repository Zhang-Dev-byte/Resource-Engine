#pragma once
#include "Application.h"
#include "Log.h"

int main() {
	Resource::Log::Init();
	RS_CORE_WARN("Initalized Log!");
	Resource::Application::Run();
	while (true);
}