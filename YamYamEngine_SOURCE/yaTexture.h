#pragma once
#include "yaResource.h"

namespace ya::graphics {
class Texture : public Resource {
public:
  enum class eTextureType {
    Bmp,
    Png,
    Jpg,
    None,
  };

  static Texture *Create(const std::wstring& name, UINT width, UINT height);

  Texture();
  ~Texture();

  virtual HRESULT Load(const std::wstring &path)
      override; // 순수 가상함수 실제메모리 할당이 불가능해지는 문법
  UINT GetWidth() { return mWidth; }
  void SetWidth(UINT width) { mWidth = width; }
  UINT GetHeight() { return mHeight; }
  void SetHeight(UINT height) { mHeight = height; }

  HDC GetHdc() { return mHdc; }
  eTextureType GetTextureType() { return mType; }
  Gdiplus::Image *GetImage() { return mImage; }
  bool IsAlpha() { return mbAlpha; }

private:
  bool mbAlpha; // 알파블렌드 여부
  eTextureType mType;
  Gdiplus::Image *mImage;
  HBITMAP mBitmap;
  HDC mHdc;
  UINT mWidth;
  UINT mHeight;
};
} // namespace ya::graphics
