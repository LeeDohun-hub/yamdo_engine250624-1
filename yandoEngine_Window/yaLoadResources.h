#pragma once
#include "..\\YamYamEngine_SOURCE\\yaResources.h"

#include "..\\YamYamEngine_SOURCE\\yaTexture.h"
namespace ya {

void LoadResources() {
      //Resources::Load<graphics::Texture>(
      //L"BG",
      //// L"C:\\Users\\WORK\\Desktop\\Coding\\yamdo_engine\\Resources\\aooni.jpg");
      //// L"C:\\Users\\WORK\\Desktop\\Gamecoding\\yamdo_engine\\Resources\\aooni.jpg");
      ////L"C:\\Users\\WORK\\Desktop\\Gamecoding\\yamdo_engine\\Resources\\aooni."
      ////L"png");
      //L"C:\\Users\\WORK\\Desktop\\Gamecoding\\yamdo_engine\\Resources\\superboardstart."
      //L"png");
  //Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\superboardstart.png");
    Resources::Load<graphics::Texture>(L"WPlayer", L"..\\Resources\\chara02.png");
  //Resources::Load<graphics::Texture>(L"Chicken", L"..\\Resources\\chicken.bmp");
    Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
    //Resources::Load<graphics::Texture>(L"Bubble", L"..\\Resources\\Bubble.png");
    //Resources::Load<graphics::Texture>(L"MapleEffect", L"..\\Resources\\ezgif.com-gif-maker.png");
    Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");

}
} // namespace ya

//카메라

//크기 조정하는거

//스크립트