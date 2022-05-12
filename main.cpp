#include <iostream>
#include<string>

#include"include/funjs.h"

#define WINDOW_WIDTH    900
#define WINDOW_HEIGHT   600
int main()
{

    auto app = App::Create();
  auto window = Window::Create(app->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT, false,
      kWindowFlags_Titled | kWindowFlags_Resizable);
  app->set_window(window);
  VServClient vs;
  vs.SetWin(window);
  funjs::RegistrFunVServClient(&vs);
  vs.SetTitle("TG CLOUD\n");
  
   //cloud.hist.WaitHistory();
  app->Run();

  return 0;
}