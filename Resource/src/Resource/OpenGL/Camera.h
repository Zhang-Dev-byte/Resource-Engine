#pragma once
#include "../Core.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;


namespace Resource {
	class RESOURCE_API Camera {
	public:
		static void Translate(mat4& view, vec3& translation);
		static void Rotate(mat4& view, f32 angle, vec3& axis);
	};
}