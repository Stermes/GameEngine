#include "GameObject.h"
#include "../Components/Component.h"
#include "SceneGraph.h"
#include "../Game.h"


GameObject::GameObject()
{
	m_lookAtOrigin = transform.forward;
	m_upVectorOrigin = transform.up;
	m_parent = NULL;
}


GameObject::~GameObject()
{
}

void GameObject::Init()
{
	UpdateTransform();
	if (m_components.size() > 0)
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			(m_components[i]->Init());
		}
	}
}

void GameObject::Update()
{
	UpdateTransform();
	if (m_components.size() > 0)
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			(m_components[i]->Update());
		}
	}
}

void GameObject::FixedUpdate()
{
	UpdateTransform();
	if (m_components.size() > 0)
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			(m_components[i]->FixedUpdate());
		}
	}
}

void GameObject::AddChild(GameObject * obj)
{
	m_children.push_back(obj);
	if (obj->m_parent != NULL)
	{
		obj->RemoveParent();
	}
	obj->m_parent = this;
	obj->m_graph = GetGraph();
}

void GameObject::RemoveChild(GameObject * obj)
{
	for (int i = 0; i < m_children.size(); i++)
	{
		if (m_children[i] == obj)
		{
			m_children[i] = NULL;
			m_children.erase(m_children.begin() + i);
			obj->RemoveParent();
			break;
		}
	}
}

void GameObject::AddComponent(Component * comp)
{
	m_components.push_back(comp);
	comp->gameObject = this;
	comp->Init();
}

void GameObject::RemoveComponent(Component * comp)
{
	for (int i = 0; i < m_components.size(); i++)
	{
		if (m_components[i] == comp)
		{
			m_components[i] = NULL;
			m_components.erase(m_components.begin() + i);
			break;
		}
	}
}

void GameObject::SetParent(GameObject* obj)
{
	obj->AddChild(this);
	m_graph = obj->GetGraph();
}

void GameObject::RemoveParent()
{
	if (m_parent != NULL)
	{
		m_parent->RemoveChild(this);
		m_parent = NULL;
	}
}

GameObject * GameObject::GetParent()
{
	return m_parent;
}

Game * GameObject::GetGame()
{
	return m_graph->game;
}

SceneGraph * GameObject::GetGraph()
{
	return m_graph;
}

void GameObject::TraverseGraph(void(GameObject::*ptr)())
{
	(this->*ptr)();
	// use of function pointers so i dont have to rewrite the traverse logic
	if (m_children.size() > 0)
	{
		for (int i = 0; i < m_children.size(); i++)
		{
			(m_children[i]->TraverseGraph(ptr));
		}
	}
}

void GameObject::UpdateTransform()
{
	glm::mat4 identity;
	glm::mat4 currentTransform;

	glm::quat rot;

	float degreeToRadian = 3.14 / 180;

	rot *= glm::quat(cos(transform.euler.z * degreeToRadian / 2), 0, 0, sin(transform.euler.z * degreeToRadian / 2) * 1);
	rot *= glm::quat(cos(transform.euler.x * degreeToRadian / 2), sin(transform.euler.x * degreeToRadian / 2) * 1, 0, 0);
	rot *= glm::quat(cos(transform.euler.y * degreeToRadian / 2), 0, sin(transform.euler.y * degreeToRadian / 2) * 1, 0);

	transform.rotation = rot;

	transform.up = glm::rotate(transform.rotation, m_upVectorOrigin);
	transform.forward = glm::rotate(transform.rotation, m_lookAtOrigin);

	currentTransform = glm::scale(identity, transform.scale) * currentTransform;
	currentTransform = glm::toMat4(rot) * currentTransform;
	currentTransform = glm::translate(identity, transform.position) * currentTransform;

	transform.model = currentTransform;
}
