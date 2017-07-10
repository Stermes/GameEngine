#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include "GameObject.h"

class Game;

class SceneGraph
{
public:
	SceneGraph(Game* game);
	virtual ~SceneGraph();

	GameObject* root;
	Game* game;

	void Update();
	void FixedUpdate();
	void ClearGraph();
	
	void SetRoot(GameObject* newRoot);

};

#endif // 
