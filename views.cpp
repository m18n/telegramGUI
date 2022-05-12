#include"include/views.h"
VServClient::VServClient() {
	details::cloud.SetCallBack(this);
	
	
}

VServClient::~VServClient() {

}
void VServClient::CallBackLogin() {
	
	//test->get().LoadURL("file:///index.html");

	//ov->view()->LoadURL("file:///index.html");
	views->LoadURL("file:///index.html");
}

void VServClient::InitTg() {
	details::cloud.Login();
	CallBackLogin();
	details::cloud.ChannelInit();
	details::cloud.hist.UpdateChatHistory();
}
void VServClient::SetWin(RefPtr<Window> win) {
	this->win = win;
	win->SetTitle(title.c_str());
	ov = Overlay::Create(*win, win->width(), win->height(), 0, 0);
	ov->view()->LoadURL("file:///load.html");
	ov->view()->set_view_listener(this);
	ov->view()->set_load_listener(this);
	win->set_listener(this);
	views = &ov->view().get();
	thread th(&VServClient::InitTg, this);
	th.detach();
}
void VServClient::OnDOMReady(View* caller,
	uint64_t frame_id,
	bool is_main_frame,
	const String& url)
{

	// Acquire the JS execution context for the current page.
	//
	// This call will lock the execution context for the current
	// thread as long as the Ref<> is alive.
	//
	Ref<JSContext> context = caller->LockJSContext();

	// Get the underlying JSContextRef for use with the
	// JavaScriptCore C API.
	SetCtx(context.get());
	
	
	while (true) {

	}
	/*RegistrFunctionJs("ConnectCpp", funjs::ConnectJs);
	RegistrFunctionJs("ServerStartCpp", funjs::ServerStartJs);
	RegistrFunctionJs("ServerStopCpp", funjs::ServerStopJs);
	RegistrFunctionJs("ServSendMessageCpp", funjs::ServerSendMessageJs);
	RegistrFunctionJs("ClientSendMessageCpp", funjs::ClientSendMessageJs);
	RegistrFunctionJs("DisconnectCpp", funjs::DisconnectJs);*/

	// Create a JavaScript String containing the name of our callback.
}
void VServClient::OnClose() {}
void VServClient::OnResize(uint32_t width, uint32_t height) {
	ov->Resize(width, height);
}

void VServClient::OnChangeCursor(ultralight::View* caller,
	Cursor cursor) {
	win->SetCursor(cursor);
}