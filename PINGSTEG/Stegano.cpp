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

//int main(array<String^>^ args) { // entrypoint�� WinMain�̾�� �ܼ� �ȶ�
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	//System::Windows::Forms::Application::Run(gcnew PINGSTEG::Stegano());
	//if (Environment::OSVersion->Version->Major >= 6);
	//dpi ������ ������Ʈ �Ӽ� - �Ŵ��佺Ʈ ���� - dpi �ν��� �����ϸ� �ȴ�.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PINGSTEG::Stegano form;
	Application::Run(%form);
	return 0;
}