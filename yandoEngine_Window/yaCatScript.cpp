#include "yaCatScript.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaGameObject.h"
#include "yaAnimator.h"
#include "time.h"
#include "yaObject.h"
namespace ya {
	CatScript::CatScript() : mState(CatScript::eState::SitDown), mAnimator(nullptr), mTime(0.0f), mDeathTime(0.0f), mDest(Vector2::Zero), mRadian(0.0f)
	{
	}
	CatScript::~CatScript() {}
	void CatScript::Initialize()
	{
	}
	void CatScript::Update()
	{
		mDeathTime += Time::DeltaTime();
		if (mDeathTime > 6.0f)
		{
			//object::Destroy(GetOwner());
		}
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}
		
		
		switch (mState)
		{
		case ya::CatScript::eState::SitDown:
			sitDown();
			break;
		case ya::CatScript::eState::Walk:
			move();
			break;
		case ya::CatScript::eState::Sleep:
			break;
		case ya::CatScript::eState::LayDown:
			break;
		case ya::CatScript::eState::Attack:
			break;
		default:
			break;
		}

	}
	void CatScript::LateUpdate() {}
	void CatScript::Render(HDC hdc) {}
	void CatScript::sitDown()
	{
		mTime += Time::DeltaTime();

		if (mTime > 2.0f)
		{
			object::Destroy(GetOwner());
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		//Vector2 mousePos = Input::GetMousePosition();
	
		// 마우스 위치 이동 (벡터의 뺄셈 활용)
		//Transform* plTr = mPlayer->GetComponent<Transform>();
		
		//Vector2 dest = mDest - plTr->GetPosition() + Vector(100.f, 0.0f));

		//pos += dest.normalize() * (100.0f * Time::DeltaTime());
		//pos += Vector2(50.0f, 0.0f)

		// 삼각함수를 통한 이동
		//mRadian += Time::DeltaTime();
		//pos += Vector2(1.0f, cosf(mRadian)) * (100.0f * Time::DeltaTime());

		tr->SetPosition(pos);

		/*if (mTime > 3.0f)
		{
			mState = CatScript::eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			PlayWalkPlayAnimationByDirection(mDirection);
			mTime = 0.0f;
		}*/
	}
	void CatScript::move()
	{
		mTime += Time::DeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
			

		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Translate(tr);

	}

	void CatScript::layDown()
	{

	}

	void CatScript::PlayWalkPlayAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case ya::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case ya::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case ya::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case ya::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void CatScript::Translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();

		switch (mDirection)
		{
		case ya::CatScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case ya::CatScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case ya::CatScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case ya::CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
} // namespace ya
