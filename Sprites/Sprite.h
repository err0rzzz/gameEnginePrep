#pragma once
#include "Bitmap.h"
#include "Transform.h"

class Sprite
{
public:
	Sprite(Bitmap* bitmap, Transform* transform);

	Bitmap* m_bitmap;
	Transform* m_transform;
	
	~Sprite();
};

