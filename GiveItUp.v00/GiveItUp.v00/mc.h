#pragma once
#include "GameObjectRender.h"
class mc:public GameObjectRender
{
	void Update(float dt) override;
public:
	mc();
	~mc();
};

