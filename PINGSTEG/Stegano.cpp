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

int PINGSTEG::Stegano::Encode_PNG(Form^ form, String^ w_name, String^ d_name) {
	///////////////////////////////////////////////////////////////////////////////
	const char* wrapper_name;
	const char* data_name;
	char file_name[30] = { 0, };
	//char *output_name;
	///////////////////////////////////////////////////////////////////////////////
	marshal_context^ conversion = gcnew marshal_context();
	wrapper_name = conversion->marshal_as<const char*>(w_name);
	data_name = conversion->marshal_as<const char*>(d_name);
	String^ sys_file_name = Path::GetFileName(d_name);
	std::string str_file_name = conversion->marshal_as<std::string>(sys_file_name);
	for (int i = 0; i < str_file_name.length(); ++i)
		file_name[i] = str_file_name[i];
	///////////////////////////////////////////////////////////////////////////////
	uint32_t err;
	unsigned char* wrapper;
	size_t wrapper_size; // wrapper size in bytes
									// wrapper[n] ���� bit_depth �Ǵ�

	err = lodepng_load_file(&wrapper, &wrapper_size, wrapper_name);
	if (err) {
		printf("�����ڵ�(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}

	unsigned char* rgb_wrapper; // 3ä�� RGB
	uint32_t wrapper_width;
	uint32_t wrapper_height;

	UD_TEXT("PNG ������ �������� ���Դϴ�...");
	err = lodepng_decode24(&rgb_wrapper, &wrapper_width, &wrapper_height, wrapper, wrapper_size);
	if (err) {
		printf("�����ڵ�(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}

	//////////////////// �۾� �ߴ� üũ //////////////////////
	if (backgroundWorker1->CancellationPending) {
		UD_TEXT(Environment::NewLine);
		UD_TEXT("�۾��� ��ҵǾ����ϴ�.");
		return -1;
	}

	UD_PROG_VAL(5);
	prog_limit = 10;
	UD_TEXT(Environment::NewLine);
	UD_TEXT("���������� PNG ������ �����Խ��ϴ�.");
	Sleep(300);

	// ���� ���� ������
	FILE* data = fopen(data_name, "rb");
	if (!data) {
		puts("������ ���� ���� ����");
		abort();
	}

	if (fseek(data, 0, SEEK_END)) {
		puts("������ ũ�⸦ �о���̴µ� �����߽��ϴ�.");
		abort();
	}
	uint32_t file_size = ftell(data);

	unsigned char data_byte, copied_data_byte;
	uint32_t remain = 0, cnt = 0, fin = 0;

	// ��� ���� �����ϱ�
	unsigned char header[39] = { 0, };
	// STEG (Steganography Signature - 4B)
	// 02 (File type - 1B) -> �̰� ��ȣȭ Ÿ��(bit_depth, LSB ���)���� �ٲ��
	// 1A 34 FE 2C (File size - 4B)
	// HIDDEN_MP3_from_Queue (File Name - 30B)
	strncpy((char*)header, "STEG", 4);
	header[4] = 1; // ������ ���ÿ��� �ϴ� 1(24bit 1ä�� LSB)�� ����
							//uint32_t *size = &file_size;
	*(uint32_t*)&header[5] = file_size;
	for (int i = 0; i < 30; ++i)
		header[9 + i] = file_name[i];

	//////////////////// �۾� �ߴ� üũ //////////////////////
	if (backgroundWorker1->CancellationPending) {
		UD_TEXT(Environment::NewLine);
		UD_TEXT("�۾��� ��ҵǾ����ϴ�.");
		return -1;
	}

	UD_PROG_VAL(10);
	UD_TEXT(Environment::NewLine);
	UD_TEXT(Environment::NewLine);
	UD_TEXT("������ ����� ����մϴ�.");
	Sleep(300);

	// ��� ������ ���� 1��Ʈ�� �ֱ�
	unsigned int a, b, idx = 0;
	for (a = 0; a < wrapper_height; ++a) {
		for (b = 0; b < wrapper_width; ++b) {
			Sleep(5);
			//////////////////// �۾� �ߴ� üũ //////////////////////
			if (backgroundWorker1->CancellationPending) {
				UD_TEXT(Environment::NewLine);
				UD_TEXT("�۾��� ��ҵǾ����ϴ�.");
				return -1;
			}

			if (!(cnt % 8)) {
				cnt = 0;
				if (idx == 39) {
					UD_TEXT(Environment::NewLine);
					UD_TEXT("���������� ����� ����߽��ϴ�.");
					fin = 1;
					break;
				}
				data_byte = header[idx++];
				UD_TEXT(Environment::NewLine);
				UD_TEXT("��� ���� " + idx.ToString() + " / 39 Byte ��� ��. . .");
			}

			copied_data_byte = data_byte;
			copied_data_byte <<= cnt;
			copied_data_byte >>= 7;

			rgb_wrapper[(a * wrapper_width + b) * 3 + 2] >>= 1;
			rgb_wrapper[(a * wrapper_width + b) * 3 + 2] <<= 1;
			if (copied_data_byte) rgb_wrapper[(a * wrapper_width + b) * 3 + 2] += copied_data_byte;
			printf("%d", copied_data_byte);

			++cnt;
			UD_PROG_VAL(10 + idx / 2);
		}
		if (fin) break;
	}
	if (idx != 39) {
		puts("����� ����ϴ� ���� ������ �߻��߽��ϴ�.");
		abort();
	}
	UD_PROG_VAL(30);
	prog_limit = 30;
	Sleep(200);

	UD_TEXT(Environment::NewLine);
	UD_TEXT(Environment::NewLine);
	UD_TEXT("�����͸� ����մϴ�.");
	Sleep(500);

	// �ȼ� ���� ���� ������ �� 1��Ʈ�� �����ϱ�
	int takes = file_size * 8;

	fseek(data, 0, SEEK_SET);
	idx = 0, cnt = 0, fin = 0; // go back to default value
	for (unsigned int y = a; y < wrapper_height; ++y) {
		Sleep(10);
		//////////////////// �۾� �ߴ� üũ //////////////////////
		if (backgroundWorker1->CancellationPending) {
			UD_TEXT(Environment::NewLine);
			UD_TEXT("�۾��� ��ҵǾ����ϴ�.");
			return -1;
		}

		for (unsigned int x = b; x < wrapper_width; ++x) {
			++idx;
			if (!(cnt % 8)) {
				cnt = 0;
				remain = fread(&data_byte, sizeof(unsigned char), 1, data);
				if (!remain) {
					fin = 1;
					break;
				}
			}
			copied_data_byte = data_byte;
			copied_data_byte <<= cnt;
			copied_data_byte >>= 7;
			/*
			printf("%d ", (int)rgb_wrapper[(y * wrapper_width + x) * 3 + 0]);
			printf("%d ", (int)rgb_wrapper[(y * wrapper_width + x) * 3 + 1]);
			printf("%d\n", (int)rgb_wrapper[(y * wrapper_width + x) * 3 + 2]);
			*/
			rgb_wrapper[(y * wrapper_width + x) * 3 + 2] >>= 1;
			rgb_wrapper[(y * wrapper_width + x) * 3 + 2] <<= 1;
			if (copied_data_byte) rgb_wrapper[(y * wrapper_width + x) * 3 + 2] += copied_data_byte;

			++cnt;
		}
		UD_TEXT(Environment::NewLine);
		UD_TEXT(y.ToString() + " / " + wrapper_height.ToString() + " ��� �Ϸ�. . .");
		prog_limit = 30 + idx * 65 / takes;
		UD_TIMER_INIT();
		if (fin) {
			UD_TEXT(Environment::NewLine);
			UD_TEXT("���������� �����͸� �����߽��ϴ�.");
			break;
		}
	}
	prog_limit = 95;
	if (fread(&data_byte, sizeof(unsigned char), 1, data)) {
		//fputs("������ ũ�Ⱑ wrapper �ѵ��� �ʰ��߽��ϴ�.", stderr);
		throw gcnew System::Exception("������ ũ�Ⱑ wrapper �ѵ��� �ʰ��߽��ϴ�.");
		abort();
	}
	UD_PROG_VAL(97);
	Sleep(200);
	UD_PROG_VAL(99);
	UD_BTN2_ENABLED();
	UD_TEXT(Environment::NewLine);
	UD_TEXT(Environment::NewLine);
	UD_TEXT("�� PNG ���� �ۼ��ϴ���...��ø� ��ٷ��ּ���.");

	err = lodepng_encode24_file("program_output.png", rgb_wrapper, wrapper_width, wrapper_height);

	if (err) {
		printf("�����ڵ�(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}
	UD_PROG_VAL(100);
	UD_TEXT(Environment::NewLine);
	UD_TEXT("������ ��ȣȭ�� �Ϸ�Ǿ����ϴ�.");

	return 7; // ���� ����
}


int PINGSTEG::Stegano::Decode_PNG(String^ f_name) {
	uint32_t err;
	unsigned char* stegano;
	size_t stegano_size;
	///////////////////////////////////////////////////////////////////////////////
	const char* steg_file_name;
	///////////////////////////////////////////////////////////////////////////////
	marshal_context^ conversion = gcnew marshal_context();
	steg_file_name = conversion->marshal_as<const char*>(f_name);
	///////////////////////////////////////////////////////////////////////////////

	UD_TEXT_2("PNG ������ �������� ���Դϴ�...");
	err = lodepng_load_file(&stegano, &stegano_size, steg_file_name);
	if (err) {
		printf("�����ڵ�(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}

	//////////////////// �۾� �ߴ� üũ //////////////////////
	if (backgroundWorker2->CancellationPending) {
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("�۾��� ��ҵǾ����ϴ�.");
		return -1;
	}

	unsigned char* rgb_stegano;
	uint32_t stegano_width;
	uint32_t stegano_height;

	err = lodepng_decode24(&rgb_stegano, &stegano_width, &stegano_height, stegano, stegano_size);
	if (err) {
		printf("�����ڵ�(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}

	//////////////////// �۾� �ߴ� üũ //////////////////////
	if (backgroundWorker2->CancellationPending) {
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("�۾��� ��ҵǾ����ϴ�.");
		return -1;
	}
	UD_PROG_VAL(5);
	prog_limit = 5;

	UD_TEXT_2(Environment::NewLine);
	UD_TEXT_2("���װ���׷��� ����� �м��ϴ� ���Դϴ�..");
	Sleep(400);

	// STEG (Steganography Signature - 4B)
	// 01 (File type - 1B)
	// 1A 34 FE 2C (File size - 4B)
	// HIDDEN_MP3 (File Name - 30B)
	unsigned char header[39];

	// Steganography ��� ���� �����ϱ�
	uint32_t a, b, cnt = 0, idx = 0, fin = 0;
	unsigned char stegano_byte, accumulated_byte = 0;
	for (a = 0; a < stegano_height; ++a) {
		for (b = 0; b < stegano_width; ++b) {

			if (!(cnt % 8) && cnt) {
				cnt = 0;
				if (idx == 38) {
					UD_TEXT_2(Environment::NewLine);
					UD_TEXT_2("���������� ����� �����Խ��ϴ�.");
					fin = 1;
					break;
				}
				//printf("\n");
				header[idx++] = accumulated_byte;
				accumulated_byte = 0;
			}

			stegano_byte = rgb_stegano[(a * stegano_width + b) * 3 + 2] & 1;

			//printf("%d", stegano_byte);
			accumulated_byte <<= 1;
			if (stegano_byte) accumulated_byte += stegano_byte;

			//printf("idx: %d  cnt: %d\n", idx, cnt);
			++cnt;
		}
		UD_PROG_VAL(5 + idx / 39 * 5);
		if (fin) break;
	}
	UD_PROG_VAL(10);
	prog_limit = 10;

	// ��� RAW ������ �߰� ����
	//for (int i = 0; i < 39; ++i) {
	//	printf("%d ", header[i]);
	//}
	//printf("\n\n");

	// ��� �����͸� ������ ����
	char file_name[30] = { 0, };
	uint32_t n, file_size = *(uint32_t*)&header[5]; // test_stegano: 364757 B
	String^ png_bit_depth = "";
	String^ encode_type = "";

	if (strncmp((const char*)header, "STEG", 4)) {
		puts("���װ���׷��� ������ �����ϴ�.");
		abort();
	}
	else {
		for (n = 9; header[n]; ++n) { // �ι��� ������
			file_name[n - 9] = header[n];
		}

		if (header[4] == 1) { // 1 for 24bit 1ä�� LSB
			png_bit_depth = "24��Ʈ PNG";
			encode_type = "1ä�� LSB";
		}
		else {
			puts("�ش� ��ȣȭ ������ ���� �����Դϴ�.");
			abort();
		}
		String^ sys_file_name = gcnew String(file_name);
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("+--< Steganography Metadata >");
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("+--��ȣȭ ����: " + png_bit_depth + " + " + encode_type);
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("+--���� �̸�: " + sys_file_name);
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("+--���� ũ��: " + file_size.ToString() + " Bytes");
	}

	UD_TEXT_2(Environment::NewLine);
	UD_TEXT_2(Environment::NewLine);
	UD_TEXT_2("�����Ͻ÷��� '����' ��ư�� �����ּ���.");
	isDecodeBtn = false;
	UD_BTN1_TEXT("����");

	// wait for the command
	for (;;) {
		Sleep(100);
		if (extract) {
			isDecodeBtn = true;
			extract = false;
			UD_BTN1_TEXT("���");
			break;
		}
	}

	// ������ ���� ������ �����ϱ�
	int takes = file_size * 8;
	FILE* hidden_data = fopen(file_name, "wb");

	idx = 0, cnt = 0, fin = 0;
	uint32_t y = a, x = b;
	for (y = a; y < stegano_height; ++y) {
		Sleep(7);
		for (x = b; x < stegano_width; ++x) {
			++idx;
			if (!(cnt % 8) && cnt) {
				cnt = 0;
				if (!(file_size--)) {
					fin = 1;
					break;
				}
				fwrite(&accumulated_byte, sizeof(unsigned char), 1, hidden_data);
				//printf("%02x ", accumulated_byte);
				accumulated_byte = 0;
			}

			stegano_byte = rgb_stegano[(y * stegano_width + x) * 3 + 2] & 1;
			accumulated_byte <<= 1;
			if (stegano_byte) accumulated_byte += stegano_byte;

			++cnt;
		}
		prog_limit = 10 + idx * 89 / takes;
		UD_TIMER_INIT();
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2(y.ToString() + " / " + stegano_height.ToString() + " �м� �Ϸ�. . .");
		if (fin) {
			UD_PROG_VAL(100);
			UD_TEXT_2(Environment::NewLine);
			UD_TEXT_2("���������� �����͸� �����߽��ϴ�.");
			break;
		}
	}

	fclose(hidden_data);
	return 7;
}