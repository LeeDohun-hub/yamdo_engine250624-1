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
      override; // ���� �����Լ� �����޸� �Ҵ��� �Ұ��������� ����
  UINT GetWidth() { return mWidth; }
  void SetWidth(UINT width) { mWidth = width; }
  UINT GetHeight() { return mHeight; }
  void SetHeight(UINT height) { mHeight = height; }

  HDC GetHdc() { return mHdc; }
  eTextureType GetTextureType() { return mType; }
  Gdiplus::Image *GetImage() { return mImage; }
  bool IsAlpha() { return mbAlpha; }

private:
  bool mbAlpha; // ���ĺ��� ����
  eTextureType mType;
  Gdiplus::Image *mImage;
  HBITMAP mBitmap;
  HDC mHdc;
  UINT mWidth;
  UINT mHeight;
};
} // namespace ya::graphics
