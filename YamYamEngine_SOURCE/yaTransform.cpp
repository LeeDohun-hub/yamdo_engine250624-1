#include "yaTransform.h"

ya::Transform::Transform() : Component(enums::eComponentType::Transform), mScale(Vector2::One), mRotation(0.0f)
{
	
}

ya::Transform::~Transform()
{
}

void ya::Transform::Initialize()
{
}

void ya::Transform::Update()
{
}

void ya::Transform::LateUpdate()
{
}

void ya::Transform::Render(HDC hdc)
{
}
