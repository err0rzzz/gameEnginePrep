#include "Sprite.h"



Sprite::Sprite(Bitmap* bitmap, Transform* transform)
{
	m_bitmap = bitmap;
	m_transform = transform;
}


Sprite::~Sprite()
{
	delete m_transform;
	delete m_bitmap;
}
