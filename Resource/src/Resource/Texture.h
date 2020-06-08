#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include "Core.h"
#include "stb_image.h"

namespace Resource {
	class RESOURCE_API Texture {
	public:
		Texture(const char* path);
		void Bind();
	private:
		unsigned int texture;
		unsigned char* data;
		int width, height, nrChannels;
	};
}