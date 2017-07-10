#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;

class Component
{
public:
	Component();
	
	GameObject* gameObject;
	bool isEnabled;

	virtual void Init();
	virtual void Update();
	virtual void FixedUpdate();

	virtual ~Component();
};

#endif