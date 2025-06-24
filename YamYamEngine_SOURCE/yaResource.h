#pragma once
#include "yaEntity.h"
namespace ya
{
	class Resource : public Entity //�߻� Ŭ���� �޸� �Ҵ�x ��ӹ޾Ƽ��� ����ؾ��Ѵ�.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; //���� �����Լ� �����޸� �Ҵ��� �Ұ��������� ����

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


//���ӿ��� ���Ǵ� �����͵��� ����

//�̹���, ����, 3�������� Ŭ����

// ���� ���� �÷��� ������ HDD, Ŭ���� ������ �صд�.
// �̰͵� ���ҽ� �̴�.


