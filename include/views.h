#pragma once
#include"coreviews.h" 
class VServClient :public WindowListener, public ViewListener, public LoadListener, public IFunctionJS,public CallBackTdCloud {
public:

	VServClient();
	void SetWin(RefPtr<Window> win);
	void OnDOMReady(View* caller,
		uint64_t frame_id,
		bool is_main_frame,
		const String& url) override;
	virtual void OnClose() override;
	virtual void OnResize(uint32_t width, uint32_t height) override;
	virtual void OnChangeCursor(ultralight::View* caller,
		Cursor cursor);
	void SetTitle(std::string title) {
		this->title = title;
		win->SetTitle(title.c_str());
	}
	void InitTg();
	void CallBackLogin() override;
	~VServClient();
private:
	std::string title;
	ultralight::View* views ;
	RefPtr<Window> win;
	RefPtr<Overlay> ov;
};