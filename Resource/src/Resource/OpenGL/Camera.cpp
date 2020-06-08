#include "Camera.h"

void Resource::Camera::Translate(mat4& view, vec3& translation)
{
	view = glm::translate(view, translation);
}

void Resource::Camera::Rotate(mat4& view, f32 angle, vec3& axis)
{
	view = glm::rotate(view, angle, axis);
}
