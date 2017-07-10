#include "SceneGraph.h"
#include "../Game.h"

SceneGraph::SceneGraph(Game* game)
{
	this->game = game;
	this->root = new GameObject();
	root->m_graph = this;
}

SceneGraph::~SceneGraph()
{
	delete root;
}

void SceneGraph::Update()
{
	root->TraverseGraph(&GameObject::Update);
}

void SceneGraph::FixedUpdate()
{
	root->TraverseGraph(&GameObject::Update);
}

void SceneGraph::ClearGraph()
{
	delete root;
	root = new GameObject();
	root->m_graph = this;
}

void SceneGraph::SetRoot(GameObject * newRoot)
{
	delete root;
	root = newRoot;
	root->m_graph = this;
}
