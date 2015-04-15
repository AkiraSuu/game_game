
#include <SDL_image.h>
#include "../stdafx.h"
#include "../include/Sprite.h"
//file creat time 11-2:00
CSprite::CSprite(SDL_Renderer* passed_renderer,std::string FilePath,int x,int y,int w,int h)
{
    renderer = passed_renderer;

	image = IMG_LoadTexture(renderer,FilePath.c_str());
	if(image==NULL){
		std::cerr << SDL_GetError() << std::endl;
		std::cout<<"Couldn`t Load Image!"<< FilePath.c_str()<< std::endl;
	}
	rect.x=x;//0
	rect.y=y;//0
	rect.w=w;//640
	rect.h=h;//400

	SDL_QueryTexture(image,NULL,NULL,&img_width,&img_height);

	crop.x=0;
	crop.y=0;

	crop.w=img_width;
	crop.h=img_height;

	X_pos=x;
	Y_pos=y;

	Orgin_X=0;
	Orgin_Y=0;

	CurrentFrame =0;
	Amount_Frame_X=0;
	Amount_Frame_Y=0;
}

void CSprite::SetUpAnimation(int passed_Amount_X,int passed_Amount_Y)
{
	Amount_Frame_X =passed_Amount_X;
	Amount_Frame_Y= passed_Amount_Y;
}

void CSprite::PlayAnimation(int BeginFrame,int EndFrame,int Row,float Speed)
{
	if(animationDelay+Speed<SDL_GetTicks())
	{
	if(EndFrame <= CurrentFrame)

		CurrentFrame = BeginFrame;
	else
		CurrentFrame++;



	crop.x =CurrentFrame* (img_width/Amount_Frame_X);
	crop.y =Row* (img_height/Amount_Frame_Y);
	crop.w = img_width/Amount_Frame_X;
	crop.h = img_height/Amount_Frame_Y;

	animationDelay=SDL_GetTicks();
	}
}


CSprite::~CSprite()
{
    SDL_DestroyTexture(image);
}

void CSprite::Draw()
{
	SDL_RenderCopy(renderer,image,&crop,&rect);
}


void CSprite::SetX(float x)
{
	X_pos=x;

	rect.x=int(X_pos-Orgin_X) ;
}
void CSprite::SetY(float y)
{
	Y_pos=y;

	rect.y=int(Y_pos-Orgin_Y);
}
void CSprite::SetPosition(float x,float y)

{
	X_pos=x;
	Y_pos=y;

	rect.x=int(X_pos-Orgin_X);
	rect.y=int(Y_pos-Orgin_Y);
}
float CSprite::GetX()
{
	return X_pos;
}
float CSprite::GetY()
{
	return Y_pos;
}

void CSprite::SetOrgin(float X,float Y)
{
	Orgin_X=X;
	Orgin_Y=Y;

	SetPosition(GetX(),GetY()) ;
}
void CSprite::SetWidth(int W)
{
	rect.w=W;
}
void CSprite::SetHight(int H)
{
	rect.h=H;
}


int CSprite::GetWidth()
{
	return rect.w;
}
int CSprite::GetHight()
{
	return rect.h;

}

		int GetWidth();
		int GetHight();
