
#pragma once

class CSDL_Setup
{
    public:
        CSDL_Setup(bool* quit,int ScreenWidth,int ScreenHeight);
        //virtual
        ~CSDL_Setup();
        SDL_Renderer* GetRenderer();
        SDL_Event GetMainEvent();

        void Begin();
        void End();

  //  protected:
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event mainEvent;
};

//#endif
