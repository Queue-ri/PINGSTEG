#pragma warning (disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <windows.h>
#include <msclr\marshal_cppstd.h>
#include "lodepng.h"
#include "Stegano.h" //

using namespace System; //
using namespace System::Windows::Forms; //
using namespace msclr::interop;
using namespace System::Threading;
using namespace System::IO;

[STAThreadAttribute]

//int main(array<String^>^ args) { // entrypoint가 WinMain이어야 콘솔 안뜸
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	//System::Windows::Forms::Application::Run(gcnew PINGSTEG::Stegano());
	//if (Environment::OSVersion->Version->Major >= 6);
	//dpi 문제는 프로젝트 속성 - 매니페스트 도구 - dpi 인식을 설정하면 된다.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PINGSTEG::Stegano form;
	Application::Run(%form);
	return 0;
}