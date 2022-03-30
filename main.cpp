#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>
 
using namespace ultralight;
 
class UltralightMain:public WindowListener {
  RefPtr<Overlay> overlay;
public:
  UltralightMain(Ref<Window> win) {
    
 // Create a basic window
    overlay = Overlay::Create(win, win->width(), win->height(), 0, 0);
 
 // Load its content from file
 // All the files must be put into the assets folder, then you can create other subdirectories and all you need
    
    overlay->view()->LoadURL("file:///index.html");
  }
  virtual void OnResize(uint32_t width, uint32_t height) override {
    overlay->Resize(width,height);
  }
  virtual void OnClose() override {}
  virtual ~UltralightMain() {}
};
 
int main() {
  
  auto app = App::Create();
 
  // Create a 450 x 700 pixels window, with a title
  auto window = Window::Create(app->main_monitor(), 450, 700, false,
    kWindowFlags_Titled);
 
  window->SetTitle("Hi Ultralight here!");
 
  app->set_window(window);
    
  UltralightMain my_app(window);
  window->set_listener(&my_app);
  // Start the main loop
  app->Run();
 
  return 0;
}