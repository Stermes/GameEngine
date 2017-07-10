#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"

class Camera : public GameObject
{
public:
	Camera();
	~Camera();

	virtual void Update();
	void SetProjection(glm::mat4 proj);
	glm::mat4 GetProjection();
	glm::mat4 GetView();
	


private:
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;

};

#endif // #ifndef CAMERA_H