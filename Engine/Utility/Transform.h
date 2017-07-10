#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include "glm/glm/gtx/quaternion.hpp"

class Transform
{
public:
	Transform();

	static void QuaternionToEuler(const glm::quat &q1, glm::vec3 &TEuler);

	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 euler;

	glm::vec3 forward;
	glm::vec3 up;

	glm::mat4 model;
	glm::quat rotation;
};

#endif 