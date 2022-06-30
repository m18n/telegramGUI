#include<iostream>
#include"telegramCloud/header/tdclass.h"
using namespace std;
TdCloud tde;
void Phone() {
	std::cout << "GET PHONE\n";
	std::string phone;
	std::cin >> phone;
	tde.SetPhone(phone);
}
void Code() {
	std::cout << "GET Code\n";
	std::string code;
	std::cin >> code;
	tde.SetCode(code);
}
void GetPhone() {
	thread tv(Phone);
	tv.detach();
	
}
void GetCode() {
	thread tv(Code);
	tv.detach();
}
void DownloadHistory() {
	std::cout << "DOWNLOAD HISTORY\n";
	TdMedia* med = tde.DownloadManager(0, false);
	std::cout << "PATH: " << med->media.GetPath() << " PROC DOWN: " << med->procDown() << "\n";
	_sleep(10000);
	std::cout << "PATH: " << med->media.GetPath() << " PROC DOWN: " << med->procDown() << "\n";
}
int main() {
	std::cout << "START\n";
	CallBackTdCloudC tg;
	tg.CallBackAuthPhone = GetPhone;
	tg.CallBackAuthCode = GetCode;
	tg.CallBackDownloadHistory = DownloadHistory;
	tde.SetCallBack(tg);
	tde.Login();
	tde.ChannelInit();
	tde.hist.UpdateChatHistory();
	/*tde.ChannelInit();
	tde.hist.UpdateChatHistory();
	tde.hist.WaitHistory();
	int index=0;
	std::cout << "INPUT DOWNLOAD IMG: \n";
	std::cin >> index;
	TdMedia* med= tde.DownloadManager(index, false);
	std::cout << "PATH: " << med->media.GetPath()<<" PROC DOWN: "<<med->procDown() << "\n";
	_sleep(2000);
	std::cout << "PATH: " << med->media.GetPath() << " PROC DOWN: " << med->procDown() << "\n";*/
	cin.get();
	cin.get();
	return 0;
}