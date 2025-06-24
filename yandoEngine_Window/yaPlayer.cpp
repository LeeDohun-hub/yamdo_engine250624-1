#include "yaPlayer.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaTime.h"
void ya::Player::Initialize()
{
	GameObject::Initialize();
}

void ya::Player::Update()
{
	GameObject::Update();
}

void ya::Player::LateUpdate()
{
	GameObject::LateUpdate();

}

void ya::Player::Render(HDC hdc)
{
	GameObject::Render(hdc);
}
