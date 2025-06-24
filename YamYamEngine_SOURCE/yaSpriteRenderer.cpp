#include "yaSpriteRenderer.h"
#include "yaGameObject.h"
#include "yaTexture.h"
#include "yaTransform.h"
#include "yaRenderer.h"

namespace ya {
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer),
		mTexture(nullptr),
		mSize(Vector2::One)
	{

	}

	SpriteRenderer::~SpriteRenderer() {}

	void SpriteRenderer::Initialize() {}

	void SpriteRenderer::Update() {}

	void SpriteRenderer::LateUpdate() {}

	void SpriteRenderer::Render(HDC hdc) {
		if (mTexture == nullptr) // 텍스쳐 세팅 해주세요!
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalculatePosition(pos);
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x * scale.x
				, mTexture->GetHeight() * mSize.y * scale.y
				, mTexture->GetHdc()
				, 0, 0
				, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
				
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x
					, pos.y
					, mTexture->GetWidth()  * mSize.x  * scale.x
					, mTexture->GetHeight() *  mSize.y * scale.y
					, mTexture->GetHdc()
					, 0, 0
					, mTexture->GetWidth()
					, mTexture->GetHeight()
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x, pos.y
					, mTexture->GetWidth() * mSize.x * scale.x
					, mTexture->GetHeight() * mSize.y * scale.y
					, mTexture->GetHdc()
					, 0, 0
					, mTexture->GetWidth(), mTexture->GetHeight()
					, RGB(255, 0, 255));
			}
		}
		else if (mTexture->GetTextureType() ==
			graphics::Texture::eTextureType::Png)
		{
			//투명화 시킬 픽셀의 색 범위
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y
					, mTexture->GetWidth() * mSize.x * scale.x,
					mTexture->GetHeight() * mSize.y * scale.y)
				, 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, Gdiplus::UnitPixel
				, nullptr/*&imgAtt*/);

		}
	}
} // namespace ya
