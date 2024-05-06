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

int PINGSTEG::Stegano::encode_png(Form ^form, String ^sys_wrapper_name, String ^sys_data_name) {
	// file metadata
	const char *wrapper_name;
	const char *data_name;
	char file_name[30] = { 0, };

	// marshal variables (managed --> unmanaged)
	marshal_context^ conversion = gcnew marshal_context();
	wrapper_name = conversion->marshal_as<const char*>(sys_wrapper_name);
	data_name = conversion->marshal_as<const char*>(sys_data_name);
	String^ sys_file_name = Path::GetFileName(sys_data_name);
	std::string str_file_name = conversion->marshal_as<std::string>(sys_file_name);
	for (int i = 0; i < str_file_name.length(); ++i)
		file_name[i] = str_file_name[i];
}