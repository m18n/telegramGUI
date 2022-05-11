#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>
#include <JavaScriptCore/JSRetainPtr.h>
#include <iostream>
#include<string>
#include"telegramCloud/header/tdclass.h"
using namespace ultralight;
JSValueRef CNz(JSContextRef ctx, JSObjectRef function,
               JSObjectRef thisObject, size_t argumentCount,
               const JSValueRef arguments[], JSValueRef *exception);

JSValueRef CVp(JSContextRef ctx, JSObjectRef function,
               JSObjectRef thisObject, size_t argumentCount,
               const JSValueRef arguments[], JSValueRef *exception);
class UltralightMain : public WindowListener, public LoadListener
{
  RefPtr<Overlay> overlay;
  JSContextRef ctx;

public:
  UltralightMain(){

  }
  UltralightMain(Ref<Window> win)
  {

   SetWindow(win);
    
  }
  void SetWindow(Ref<Window> win){
    overlay = Overlay::Create(win, win->width(), win->height(), 0, 0);

    // Load its content from file
    // All the files must be put into the assets folder, then you can create other subdirectories and all you need

    overlay->view()->LoadURL("file:///index.html");
    overlay->view()->set_load_listener(this);
    
  }
  virtual void OnResize(uint32_t width, uint32_t height) override
  {
    overlay->Resize(width, height);
  }

  void RegistrFunctionJs(std::string namefunction, JSObjectCallAsFunctionCallback fun)
  {
    JSStringRef name = JSStringCreateWithUTF8CString(namefunction.c_str());

    // Create a garbage-collected JavaScript function that is bound to our
    // native C callback 'OnButtonClick()'.'

    JSObjectRef func = JSObjectMakeFunctionWithCallback(ctx, name,
                                                        fun);

    // Get the global JavaScript object (aka 'window')
    JSObjectRef globalObj = JSContextGetGlobalObject(ctx);

    // Store our function in the page's global JavaScript object so that it
    // accessible from the page as 'OnButtonClick()'.
    JSObjectSetProperty(ctx, globalObj, name, func, 0, 0);

    // Release the JavaScript String we created earlier.
    JSStringRelease(name);
  }
  void CallFunctionJs(std::string namefunction, std::string val)
  {
    JSRetainPtr<JSStringRef> str = adopt(
        JSStringCreateWithUTF8CString(namefunction.c_str()));

    // Evaluate the string "ShowMessage"
    JSValueRef func = JSEvaluateScript(ctx, str.get(), 0, 0, 0, 0);

    // Check if 'func' is actually an Object and not null
    if (JSValueIsObject(ctx, func))
    {

      // Cast 'func' to an Object, will return null if typecast failed.
      JSObjectRef funcObj = JSValueToObject(ctx, func, 0);

      // Check if 'funcObj' is a Function and not null
      if (funcObj && JSObjectIsFunction(ctx, funcObj))
      {

        // Create a JS string from null-terminated UTF8 C-string, store it
        // in a smart pointer to release it when it goes out of scope.
        JSRetainPtr<JSStringRef> msg =
            adopt(JSStringCreateWithUTF8CString(val.c_str()));

        // Create our list of arguments (we only have one)
        const JSValueRef args[] = {JSValueMakeString(ctx, msg.get())};

        // Count the number of arguments in the array.
        size_t num_args = sizeof(args) / sizeof(JSValueRef *);

        // Create a place to store an exception, if any
        JSValueRef exception = 0;

        // Call the ShowMessage() function with our list of arguments.
        JSValueRef result = JSObjectCallAsFunction(ctx, funcObj, 0,
                                                   num_args, args,
                                                   &exception);

        if (exception)
        {
          // Handle any exceptions thrown from function here.
        }

        if (result)
        {
          // Handle result (if any) here.
        }
      }
    }
  }
  void CallFunctionJs(std::string namefunction, double val)
  {
    JSRetainPtr<JSStringRef> str = adopt(
        JSStringCreateWithUTF8CString(namefunction.c_str()));

    // Evaluate the string "ShowMessage"
    JSValueRef func = JSEvaluateScript(ctx, str.get(), 0, 0, 0, 0);

    // Check if 'func' is actually an Object and not null
    if (JSValueIsObject(ctx, func))
    {

      // Cast 'func' to an Object, will return null if typecast failed.
      JSObjectRef funcObj = JSValueToObject(ctx, func, 0);

      // Check if 'funcObj' is a Function and not null
      if (funcObj && JSObjectIsFunction(ctx, funcObj))
      {

        // Create a JS string from null-terminated UTF8 C-string, store it
        // in a smart pointer to release it when it goes out of scope.
       
        
        // Create our list of arguments (we only have one)
        const JSValueRef args[] = {JSValueMakeNumber(ctx,val)};

        // Count the number of arguments in the array.
        size_t num_args = sizeof(args) / sizeof(JSValueRef *);

        // Create a place to store an exception, if any
        JSValueRef exception = 0;

        // Call the ShowMessage() function with our list of arguments.
        JSValueRef result = JSObjectCallAsFunction(ctx, funcObj, 0,
                                                   num_args, args,
                                                   &exception);

        if (exception)
        {
          // Handle any exceptions thrown from function here.
        }

        if (result)
        {
          // Handle result (if any) here.
        }
      }
    }
  }
  void LoadMedia(int id,std::string path){
    CallFunctionJs("SetPath",std::to_string(id)+":"+path);
  }
  void OnDOMReady(View *caller,
                  uint64_t frame_id,
                  bool is_main_frame,
                  const String &url) override
  {

    // Acquire the JS execution context for the current page.
    //
    // This call will lock the execution context for the current
    // thread as long as the Ref<> is alive.
    //
    Ref<JSContext> context = caller->LockJSContext();

    // Get the underlying JSContextRef for use with the
    // JavaScriptCore C API.
    ctx = context.get();
    RegistrFunctionJs("CNz", CNz);
    RegistrFunctionJs("CVp", CVp);
    CallFunctionJs("CreateBlock",10);
    LoadMedia(0,"img/2.jpg");
  
    // Create a JavaScript String containing the name of our callback.
  }
  virtual void OnClose() override {
    
  }
  virtual ~UltralightMain() {
   
  
  }
};
UltralightMain sa;
JSValueRef CNz(JSContextRef ctx, JSObjectRef function,
               JSObjectRef thisObject, size_t argumentCount,
               const JSValueRef arguments[], JSValueRef *exception)
{

  std::cout << "NZ";
  
  
  return JSValueMakeNull(ctx);
}

JSValueRef CVp(JSContextRef ctx, JSObjectRef function,
               JSObjectRef thisObject, size_t argumentCount,
               const JSValueRef arguments[], JSValueRef *exception)
{

  std::cout << "NZ";

  return JSValueMakeNull(ctx);
}
TdCloud cloud;
int main()
{

  auto app = App::Create();

  // Create a 450 x 700 pixels window, with a title
  auto window = Window::Create(app->main_monitor(), 1000, 700, false,
                               kWindowFlags_Titled);

  window->SetTitle("TelegramGUI");

  app->set_window(window);
  sa.SetWindow(window);
  window->set_listener(&sa);
  cloud.Login();
  cloud.ChannelInit();
  cloud.hist.UpdateChatHistory();
  cloud.hist.WaitHistory();
  // example.DownloadManager(3,false);
  // cloud.DownloadBlock(0,30);
  // Start the main loop
  app->Run();

  return 0;
}