

#include"stdafx.h"
#include"include/CMain.h"


int
main(int argc, char *argv[])
{
	CMain* cmain=new CMain(640,480);
	cmain->Gameloop();

	delete cmain;
	return 0;
}

