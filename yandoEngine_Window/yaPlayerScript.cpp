#include "yaPlayerScript.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaGameObject.h"
#include "yaAnimator.h"
#include "yaCat.h"
#include "yaCatScript.h"
#include "yaObject.h"
#include "yaResources.h"
namespace ya {
	PlayerScript::PlayerScript() : mState(PlayerScript::eState::Idle), mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript() {}
	void PlayerScript::Initialize() 
	{
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case ya::PlayerScript::eState::Idle:
			idle();
			break;
		case ya::PlayerScript::eState::Walk:
			move();
			break;
		case ya::PlayerScript::eState::Sleep:
			break;
		case ya::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case ya::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}

	}
	void PlayerScript::LateUpdate() {}
	void PlayerScript::Render(HDC hdc) {}
    void PlayerScript::AttackEffect()  
    {  
       Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);  
       CatScript* catSrc = cat->AddComponent<CatScript>();  
       catSrc->SetPlayer(GetOwner());  

       graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");  
       Animator* catAnimator = cat->AddComponent<Animator>();  
       catAnimator->CreateAnimation(L"DownWalk", catTex  
           , Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);  
       catAnimator->CreateAnimation(L"RightWalk", catTex  
           , Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);  
       catAnimator->CreateAnimation(L"UpWalk", catTex  
           , Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);  
       catAnimator->CreateAnimation(L"LeftWalk", catTex  
           , Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);  
       catAnimator->CreateAnimation(L"SitDown", catTex  
           , Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);  
       catAnimator->CreateAnimation(L"Grooming", catTex  
           , Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);  
       catAnimator->CreateAnimation(L"LayDown", catTex  
           , Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);  

       catAnimator->PlayAnimation(L"SitDown", false);  

       Transform* tr = GetOwner()->GetComponent<Transform>();  
       cat->GetComponent<Transform>()->SetPosition(tr->GetPosition() + Vector2(100.0f, 0.0f)); // Fix: Use GetPosition() instead of SetPosition()  
       cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));  

	   Vector2 mousePos = Input::GetMousePosition();
	   catSrc->mDest = mousePos;
    }
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);

			Vector2 mousePos = Input::GetMousePosition();
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();

		}
		tr->SetPosition(pos);
		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A) || Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);

		}
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
} // namespace ya
