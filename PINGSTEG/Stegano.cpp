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
									// wrapper[n] 으로 bit_depth 판단

	err = lodepng_load_file(&wrapper, &wrapper_size, wrapper_name);
	if (err) {
		printf("에러코드(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}

	unsigned char* rgb_wrapper; // 3채널 RGB
	uint32_t wrapper_width;
	uint32_t wrapper_height;

	UD_TEXT("PNG 정보를 가져오는 중입니다...");
	err = lodepng_decode24(&rgb_wrapper, &wrapper_width, &wrapper_height, wrapper, wrapper_size);
	if (err) {
		printf("에러코드(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}

	//////////////////// 작업 중단 체크 //////////////////////
	if (backgroundWorker1->CancellationPending) {
		UD_TEXT(Environment::NewLine);
		UD_TEXT("작업이 취소되었습니다.");
		return -1;
	}

	UD_PROG_VAL(5);
	prog_limit = 10;
	UD_TEXT(Environment::NewLine);
	UD_TEXT("성공적으로 PNG 정보를 가져왔습니다.");
	Sleep(300);

	// 숨길 파일 데이터
	FILE* data = fopen(data_name, "rb");
	if (!data) {
		puts("데이터 파일 열기 실패");
		abort();
	}

	if (fseek(data, 0, SEEK_END)) {
		puts("데이터 크기를 읽어들이는데 실패했습니다.");
		abort();
	}
	uint32_t file_size = ftell(data);

	unsigned char data_byte, copied_data_byte;
	uint32_t remain = 0, cnt = 0, fin = 0;

	// 헤더 정보 설정하기
	unsigned char header[39] = { 0, };
	// STEG (Steganography Signature - 4B)
	// 02 (File type - 1B) -> 이거 암호화 타입(bit_depth, LSB 방식)으로 바꿔라
	// 1A 34 FE 2C (File size - 4B)
	// HIDDEN_MP3_from_Queue (File Name - 30B)
	strncpy((char*)header, "STEG", 4);
	header[4] = 1; // 간단한 예시여서 일단 1(24bit 1채널 LSB)로 고정
							//uint32_t *size = &file_size;
	*(uint32_t*)&header[5] = file_size;
	for (int i = 0; i < 30; ++i)
		header[9 + i] = file_name[i];

	//////////////////// 작업 중단 체크 //////////////////////
	if (backgroundWorker1->CancellationPending) {
		UD_TEXT(Environment::NewLine);
		UD_TEXT("작업이 취소되었습니다.");
		return -1;
	}

	UD_PROG_VAL(10);
	UD_TEXT(Environment::NewLine);
	UD_TEXT(Environment::NewLine);
	UD_TEXT("데이터 헤더를 기록합니다.");
	Sleep(300);

	// 헤더 데이터 먼저 1비트씩 넣기
	unsigned int a, b, idx = 0;
	for (a = 0; a < wrapper_height; ++a) {
		for (b = 0; b < wrapper_width; ++b) {
			Sleep(5);
			//////////////////// 작업 중단 체크 //////////////////////
			if (backgroundWorker1->CancellationPending) {
				UD_TEXT(Environment::NewLine);
				UD_TEXT("작업이 취소되었습니다.");
				return -1;
			}

			if (!(cnt % 8)) {
				cnt = 0;
				if (idx == 39) {
					UD_TEXT(Environment::NewLine);
					UD_TEXT("성공적으로 헤더를 기록했습니다.");
					fin = 1;
					break;
				}
				data_byte = header[idx++];
				UD_TEXT(Environment::NewLine);
				UD_TEXT("헤더 정보 " + idx.ToString() + " / 39 Byte 기록 중. . .");
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
		puts("헤더를 기록하는 도중 오류가 발생했습니다.");
		abort();
	}
	UD_PROG_VAL(30);
	prog_limit = 30;
	Sleep(200);

	UD_TEXT(Environment::NewLine);
	UD_TEXT(Environment::NewLine);
	UD_TEXT("데이터를 기록합니다.");
	Sleep(500);

	// 픽셀 값에 마저 데이터 값 1비트씩 변조하기
	int takes = file_size * 8;

	fseek(data, 0, SEEK_SET);
	idx = 0, cnt = 0, fin = 0; // go back to default value
	for (unsigned int y = a; y < wrapper_height; ++y) {
		Sleep(10);
		//////////////////// 작업 중단 체크 //////////////////////
		if (backgroundWorker1->CancellationPending) {
			UD_TEXT(Environment::NewLine);
			UD_TEXT("작업이 취소되었습니다.");
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
		UD_TEXT(y.ToString() + " / " + wrapper_height.ToString() + " 기록 완료. . .");
		prog_limit = 30 + idx * 65 / takes;
		UD_TIMER_INIT();
		if (fin) {
			UD_TEXT(Environment::NewLine);
			UD_TEXT("성공적으로 데이터를 변조했습니다.");
			break;
		}
	}
	prog_limit = 95;
	if (fread(&data_byte, sizeof(unsigned char), 1, data)) {
		//fputs("데이터 크기가 wrapper 한도를 초과했습니다.", stderr);
		throw gcnew System::Exception("데이터 크기가 wrapper 한도를 초과했습니다.");
		abort();
	}
	UD_PROG_VAL(97);
	Sleep(200);
	UD_PROG_VAL(99);
	UD_BTN2_ENABLED();
	UD_TEXT(Environment::NewLine);
	UD_TEXT(Environment::NewLine);
	UD_TEXT("새 PNG 파일 작성하는중...잠시만 기다려주세요.");

	err = lodepng_encode24_file("program_output.png", rgb_wrapper, wrapper_width, wrapper_height);

	if (err) {
		printf("에러코드(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}
	UD_PROG_VAL(100);
	UD_TEXT(Environment::NewLine);
	UD_TEXT("데이터 암호화가 완료되었습니다.");

	return 7; // 에러 없음
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

	UD_TEXT_2("PNG 정보를 가져오는 중입니다...");
	err = lodepng_load_file(&stegano, &stegano_size, steg_file_name);
	if (err) {
		printf("에러코드(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}

	//////////////////// 작업 중단 체크 //////////////////////
	if (backgroundWorker2->CancellationPending) {
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("작업이 취소되었습니다.");
		return -1;
	}

	unsigned char* rgb_stegano;
	uint32_t stegano_width;
	uint32_t stegano_height;

	err = lodepng_decode24(&rgb_stegano, &stegano_width, &stegano_height, stegano, stegano_size);
	if (err) {
		printf("에러코드(%u): %s\n", err, lodepng_error_text(err));
		abort();
	}

	//////////////////// 작업 중단 체크 //////////////////////
	if (backgroundWorker2->CancellationPending) {
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("작업이 취소되었습니다.");
		return -1;
	}
	UD_PROG_VAL(5);
	prog_limit = 5;

	UD_TEXT_2(Environment::NewLine);
	UD_TEXT_2("스테가노그래피 헤더를 분석하는 중입니다..");
	Sleep(400);

	// STEG (Steganography Signature - 4B)
	// 01 (File type - 1B)
	// 1A 34 FE 2C (File size - 4B)
	// HIDDEN_MP3 (File Name - 30B)
	unsigned char header[39];

	// Steganography 헤더 정보 추출하기
	uint32_t a, b, cnt = 0, idx = 0, fin = 0;
	unsigned char stegano_byte, accumulated_byte = 0;
	for (a = 0; a < stegano_height; ++a) {
		for (b = 0; b < stegano_width; ++b) {

			if (!(cnt % 8) && cnt) {
				cnt = 0;
				if (idx == 38) {
					UD_TEXT_2(Environment::NewLine);
					UD_TEXT_2("성공적으로 헤더를 가져왔습니다.");
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

	// 헤더 RAW 데이터 중간 점검
	//for (int i = 0; i < 39; ++i) {
	//	printf("%d ", header[i]);
	//}
	//printf("\n\n");

	// 헤더 데이터를 저장할 변수
	char file_name[30] = { 0, };
	uint32_t n, file_size = *(uint32_t*)&header[5]; // test_stegano: 364757 B
	String^ png_bit_depth = "";
	String^ encode_type = "";

	if (strncmp((const char*)header, "STEG", 4)) {
		puts("스테가노그래피 정보가 없습니다.");
		abort();
	}
	else {
		for (n = 9; header[n]; ++n) { // 널문자 전까지
			file_name[n - 9] = header[n];
		}

		if (header[4] == 1) { // 1 for 24bit 1채널 LSB
			png_bit_depth = "24비트 PNG";
			encode_type = "1채널 LSB";
		}
		else {
			puts("해당 암호화 포맷은 지원 예정입니다.");
			abort();
		}
		String^ sys_file_name = gcnew String(file_name);
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("+--< Steganography Metadata >");
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("+--암호화 정보: " + png_bit_depth + " + " + encode_type);
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("+--파일 이름: " + sys_file_name);
		UD_TEXT_2(Environment::NewLine);
		UD_TEXT_2("+--파일 크기: " + file_size.ToString() + " Bytes");
	}

	UD_TEXT_2(Environment::NewLine);
	UD_TEXT_2(Environment::NewLine);
	UD_TEXT_2("추출하시려면 '추출' 버튼을 눌러주세요.");
	isDecodeBtn = false;
	UD_BTN1_TEXT("추출");

	// wait for the command
	for (;;) {
		Sleep(100);
		if (extract) {
			isDecodeBtn = true;
			extract = false;
			UD_BTN1_TEXT("취소");
			break;
		}
	}

	// 숨겨진 원본 데이터 추출하기
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
		UD_TEXT_2(y.ToString() + " / " + stegano_height.ToString() + " 분석 완료. . .");
		if (fin) {
			UD_PROG_VAL(100);
			UD_TEXT_2(Environment::NewLine);
			UD_TEXT_2("성공적으로 데이터를 추출했습니다.");
			break;
		}
	}

	fclose(hidden_data);
	return 7;
}