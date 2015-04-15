#pragma once
#include"CSDL_Setup.h"
#include"Sprite.h"
#include <math.h>
class CMain
{
    public:
        CMain(int passed_ScreenWidth,int passed_ScreenHeight);

        ~CMain(void);


        void Gameloop();
        double GetDistance(int X1, int Y1,int X2,int Y2);//16 路線


    private:
    int ScreenWidth;
    int ScreenHeight;
    bool quit ;


	CSprite* grass;
	CSprite* bob;

	CSDL_Setup* csdl_setup;

	int timeCheck;
	int MouseX;
	int MouseY;
	bool Follow;
	int Follow_Point_X;
	int Follow_Point_Y;

	float distance;
	bool stopAnimation;
};


