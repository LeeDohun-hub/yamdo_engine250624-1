#pragma once
#include "CommonInclude.h"
#include "yaComponent.h"
#include "yaObject.h"
namespace ya
{
	// 게임 오브젝트의 기본 클래스
	// 모든 게임 오브젝트는 이 클래스를 상속받아야 한다.
	// 이 클래스는 게임 오브젝트의 기본적인 속성과 기능을 정의한다.
	// Actor

	class GameObject
	{
	public:
		//friend void object::Destroy(GameObject* obj);
		//friend Component; friend 클래스 선언
		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};
		GameObject();
		~GameObject();
		
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;
			//mComponents.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}
		eState GetActive() {return mState;}
		void SetActive(bool power)
		{
			if (power == true)
				mState = eState::Active;
			if (power == false)
				mState = eState::Paused;
		}
		void Death() { mState = eState::Dead; }

	private:
		void initializeTransform();

	private:
		eState mState;
		std::vector<Component*> mComponents;
	};

}

