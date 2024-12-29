# PINGSTEG

[![Release Version](https://img.shields.io/github/release/Queue-ri/PINGSTEG.svg?style=flat-square)]()
![GitHub License](https://img.shields.io/github/license/Queue-ri/PINGSTEG?style=flat-square)
![PR Welcome](https://img.shields.io/badge/PR-Welcome-29ab47ff?style=flat-square)

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![.Net](https://img.shields.io/badge/.NET-5C2D91?style=for-the-badge&logo=.net&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

<p><b>Built with</b>&nbsp;
  <img src="https://upload.wikimedia.org/wikipedia/commons/2/2c/Visual_Studio_Icon_2022.svg" alt="msvc_2022" width="20px" height="auto" />
  <img src="https://img.shields.io/badge/Visual Studio-5C2D91?style=flat-square&logo=Visual Studio&logoColor=white"/>
</p>

<br />

# Do you see the *difference*?

![Comparison](https://github.com/user-attachments/assets/c82a98f0-ab23-48f2-a07c-7a4648f91387)

<br />

# But there *IS* the *difference*.

![Decode](https://github.com/user-attachments/assets/3605b4eb-715f-41d6-94fc-7c7982c2dd98)

> *Hide everything in a single PNG file.*

PINGSTEG는 컴팩트한 스테가노그래피 툴입니다.

PNG 이미지를 변조하여 나만의 비밀 데이터를 숨겨보아요~😋

<br />

# Features

## 🔒 Encoding

PNG 파일을 스테가노그래피로 인코딩합니다.

은폐할 데이터는 txt 외에도 mp3, excel, zip 등 다양한 포맷의 파일을 선택할 수 있습니다.

인코딩이 완료된 스테가노그래피는 `program_output.png`라는 파일명으로 프로젝트 경로에 생성됩니다.

<br />

## 🔑 Decoding

스테가노그래피로부터 데이터를 추출합니다.

PINGSTEG이 추출 전 인코딩 방식, 데이터 파일명, 데이터 크기를 보여줍니다.

사용자는 해당 정보 확인 후 추출 여부를 결정할 수 있습니다.

<br />

## ✨ Future Supports
```markdown
# 📢 Announcement
본 프로젝트는 대학교 1학년에 취미로 시작하여, 현재 리팩토링 진행 중에 있습니다.
그에 따라 신규 기능은 천천히 추가될 예정입니다.
```
- 2, 3채널 LSB 인코딩 옵션 제공
- 인코딩 메모리 부족 여부를 사전에 판단하도록 수정
- 자체 암호화 옵션 제공
- 인코딩 메모리가 부족해도 인코딩이 가능한 자체 알고리즘 추가

<br />

# Based Theory

## What is Steganography?
> [!NOTE]
> 스테가노그래피는 데이터 은폐 기술 중 하나로, 데이터를 다른 데이터에 삽입하는 기술입니다.<br />
> PINGSTEG는 PNG 포맷의 무손실 압축 특성을 이용하여 데이터를 은폐합니다.

<br />

## Differences with Cryptography
> [!NOTE]
> 암호화(cryptography)는 데이터를 식별하기 어려울 뿐, 기밀 정보라는 점이 인지되어 송수신 과정에서 주목을 받게 됩니다.<br />
> 하지만 스테가노그래피는 이러한 주목을 피하여 은밀하게 정보를 교환할 수 있도록 합니다.

<br />

# Project Environment
<img src="https://github.com/user-attachments/assets/3c130df4-0f09-4112-adb7-313afa4bcfb4" width="450px" height="auto" /><br />

본 프로젝트는 .NET Framework를 기반으로 하는 CLR 프로젝트입니다.

C++의 표준 확장인 C++/CLI를 채택하여 C#으로의 확장성을 열어두고 있습니다.

[공식 참고 문서](https://learn.microsoft.com/ko-kr/cpp/dotnet/dotnet-programming-with-cpp-cli-visual-cpp?view=msvc-170)

<br />

# Dependency
의존 라이브러리는 프로젝트에 포함되어 있습니다.
- [lodepng](https://github.com/lvandeve/lodepng)

<br />

# Disclaimer
> [!WARNING]
> 본 프로그램을 불법적으로 악용할 시 개발자는 이에 책임지지 않습니다.