#pragma once
#ifndef updatableobject_h
#define updatableobject_h
#include"GameObject.h"

class UpdatableObject : virtual public GameObject
{
public:
	virtual void update()=0;
};

#endif // !updatableobject_h
