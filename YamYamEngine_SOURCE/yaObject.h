#pragma once
#include "yaComponent.h"
#include "yaLayer.h"
#include "yaGameObject.h"
#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
namespace ya::object
{
	template <typename T>
	static T* Instantiate(ya::enums::eLayerType type )
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(ya::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
	static void Destroy(GameObject* obj)
	{
		obj->Death();
	}
}
