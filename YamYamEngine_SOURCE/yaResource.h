#pragma once
#include "yaEntity.h"
namespace ya
{
	class Resource : public Entity //추상 클래스 메모리 할당x 상속받아서만 사용해야한다.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; //순수 가상함수 실제메모리 할당이 불가능해지는 문법

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
	//Resource test;
	//class Texture : public Resource;
	//class AudipClip : public Resource;

}

class Resource
{
};


//게임에서 사용되는 데이터들의 종류

//이미지, 사운드, 3스테이지 클리어

// 저장 게임 플레이 데이터 HDD, 클라우드 저장을 해둔다.
// 이것도 리소스 이다.


