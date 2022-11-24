#pragma once
#ifndef updatableobject_h
#define updatableobject_h
#include"GameObject.h"

class UpdatableObject : virtual public GameObject
{
public:
	void update();
};

#endif // !updatableobject_h
