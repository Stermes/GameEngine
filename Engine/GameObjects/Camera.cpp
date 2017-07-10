#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Update()
{
	GameObject::Update();
	m_viewMatrix = glm::lookAt(transform.position, transform.position + transform.forward, transform.up);
}

void Camera::SetProjection(glm::mat4 proj)
{
	m_projectionMatrix = proj;
}

glm::mat4 Camera::GetProjection()
{
	return m_projectionMatrix;
}

glm::mat4 Camera::GetView()
{
	return m_viewMatrix;
}
