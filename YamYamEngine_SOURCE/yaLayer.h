#pragma once
#include "yaEntity.h"
#include "CommonInclude.h"
#include "yaGameObject.h"
namespace ya
{
	class Layer : public Entity
	{
	public:
			Layer();
		~Layer();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject( GameObject *gameObject);

	private:
		//eLayerType mType;
          std::vector< GameObject *> mGameObjects;

	};
	typedef std::vector<GameObject*>::iterator GameObjectIter;
}


