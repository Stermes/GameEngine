#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "../Utility/Transform.h"
#include <vector>

class Component;
class Game;

class GameObject
{
	friend class SceneGraph;
public:
	GameObject();
	~GameObject();

	Transform transform;
	
	virtual void Init();
	virtual void Update();
	virtual void FixedUpdate();

	// Child management
	void AddChild(GameObject* obj);
	void RemoveChild(GameObject* obj);

	// Component Management
	void AddComponent(Component* comp);
	void RemoveComponent(Component* comp);

	// Parent management
	void SetParent(GameObject* obj);
	void RemoveParent();
	GameObject* GetParent();

	Game* GetGame();
	SceneGraph* GetGraph();
private:

	void TraverseGraph(void(GameObject::*ptr)());
	std::vector<GameObject*> m_children;
	std::vector<Component*> m_components;
	GameObject* m_parent;
	SceneGraph* m_graph;
	void UpdateTransform();
	//Origin look and upvector of the sceneNode
	glm::vec3 m_lookAtOrigin;
	glm::vec3 m_upVectorOrigin;
};

#endif