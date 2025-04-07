#pragma once

namespace PINGSTEG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class Header : public System::Windows::Forms::Form
	{
	public:
		Header(System::Windows::Forms::Form^ form)
		{
			mother_form = form;
			form->Enabled = false;
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Header()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Form^ mother_form;


	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox2;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  CLOSE_HEADER_BUTTON;

			 /// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->CLOSE_HEADER_BUTTON = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel1->Controls->Add(this->CLOSE_HEADER_BUTTON);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(428, 32);
			this->panel1->TabIndex = 1;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Header::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Header::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Header::panel1_MouseUp);
			// 
			// CLOSE_HEADER_BUTTON
			// 
			this->CLOSE_HEADER_BUTTON->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->CLOSE_HEADER_BUTTON->BackColor = System::Drawing::Color::Tomato;
			this->CLOSE_HEADER_BUTTON->Dock = System::Windows::Forms::DockStyle::Right;
			this->CLOSE_HEADER_BUTTON->FlatAppearance->BorderSize = 0;
			this->CLOSE_HEADER_BUTTON->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CLOSE_HEADER_BUTTON->Font = (gcnew System::Drawing::Font(L"08서울남산체 B", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->CLOSE_HEADER_BUTTON->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->CLOSE_HEADER_BUTTON->Location = System::Drawing::Point(396, 0);
			this->CLOSE_HEADER_BUTTON->Name = L"CLOSE_HEADER_BUTTON";
			this->CLOSE_HEADER_BUTTON->Size = System::Drawing::Size(32, 32);
			this->CLOSE_HEADER_BUTTON->TabIndex = 3;
			this->CLOSE_HEADER_BUTTON->TabStop = false;
			this->CLOSE_HEADER_BUTTON->Text = L"x";
			this->CLOSE_HEADER_BUTTON->UseVisualStyleBackColor = false;
			this->CLOSE_HEADER_BUTTON->Click += gcnew System::EventHandler(this, &Header::CLOSE_HEADER_BUTTON_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"AppleSDGothicNeoM00", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(151, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(117, 17);
			this->label4->TabIndex = 2;
			this->label4->Text = L"PINGSTEG Option";
			this->label4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Header::panel1_MouseDown);
			this->label4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Header::panel1_MouseMove);
			this->label4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Header::panel1_MouseUp);
			// 
			// button8
			// 
			this->button8->AutoSize = true;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button8->Location = System::Drawing::Point(244, 406);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(83, 30);
			this->button8->TabIndex = 16;
			this->button8->Text = L"적용";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Header::button8_Click);
			// 
			// button2
			// 
			this->button2->AutoSize = true;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Location = System::Drawing::Point(333, 406);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 30);
			this->button2->TabIndex = 17;
			this->button2->Text = L"취소";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Header::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(12, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 20);
			this->label1->TabIndex = 18;
			this->label1->Text = L"::Encoding Option";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(23, 80);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(97, 24);
			this->checkBox1->TabIndex = 19;
			this->checkBox1->Text = L"1채널 LSB";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Enabled = false;
			this->checkBox2->Location = System::Drawing::Point(157, 80);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(100, 24);
			this->checkBox2->TabIndex = 20;
			this->checkBox2->Text = L"2채널 LSB";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Enabled = false;
			this->checkBox3->Location = System::Drawing::Point(299, 80);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(100, 24);
			this->checkBox3->TabIndex = 21;
			this->checkBox3->Text = L"3채널 LSB";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(12, 124);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 20);
			this->label2->TabIndex = 22;
			this->label2->Text = L"::Header Information";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label3->Location = System::Drawing::Point(52, 160);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 20);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Signature";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Enabled = false;
			this->maskedTextBox1->Location = System::Drawing::Point(154, 155);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->ReadOnly = true;
			this->maskedTextBox1->Size = System::Drawing::Size(213, 30);
			this->maskedTextBox1->TabIndex = 24;
			this->maskedTextBox1->Text = L"STEG";
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->maskedTextBox2->Location = System::Drawing::Point(154, 200);
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->ReadOnly = true;
			this->maskedTextBox2->Size = System::Drawing::Size(213, 30);
			this->maskedTextBox2->TabIndex = 26;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label5->Location = System::Drawing::Point(52, 205);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 20);
			this->label5->TabIndex = 25;
			this->label5->Text = L"File Type";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label6->Location = System::Drawing::Point(52, 250);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 20);
			this->label6->TabIndex = 27;
			this->label6->Text = L"File Size";
			// 
			// maskedTextBox4
			// 
			this->maskedTextBox4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->maskedTextBox4->Location = System::Drawing::Point(154, 292);
			this->maskedTextBox4->Name = L"maskedTextBox4";
			this->maskedTextBox4->Size = System::Drawing::Size(213, 30);
			this->maskedTextBox4->TabIndex = 30;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label7->Location = System::Drawing::Point(52, 297);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(79, 20);
			this->label7->TabIndex = 29;
			this->label7->Text = L"File Name";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(153, 250);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 20);
			this->label8->TabIndex = 31;
			this->label8->Text = L"No Data";
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->maskedTextBox3->Location = System::Drawing::Point(154, 337);
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->ReadOnly = true;
			this->maskedTextBox3->Size = System::Drawing::Size(162, 30);
			this->maskedTextBox3->TabIndex = 33;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label9->Location = System::Drawing::Point(52, 342);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(77, 20);
			this->label9->TabIndex = 32;
			this->label9->Text = L"Save Path";
			// 
			// button5
			// 
			this->button5->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button5->Location = System::Drawing::Point(315, 335);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(53, 34);
			this->button5->TabIndex = 34;
			this->button5->Text = L"open";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Header::button5_Click);
			// 
			// Header
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(428, 448);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->maskedTextBox3);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->maskedTextBox4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->maskedTextBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"AppleSDGothicNeoM00", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(428, 448);
			this->MinimumSize = System::Drawing::Size(428, 448);
			this->Name = L"Header";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Header Setting";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// 취소 버튼
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		mother_form->Enabled = true;
		this->Hide();
	}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	mother_form->Enabled = true;
	this->Hide();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

	// 파일 경로 저장용
	String^ File_Path;


}

// Make the Borderless Form Draggable
private: bool dragging = false;
private: Point offset;

private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->dragging = true;
	this->offset = Point(e->X, e->Y);
}

private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->dragging = false;
}
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (this->dragging) {
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
	}
}

private: System::Void CLOSE_HEADER_BUTTON_Click(System::Object^  sender, System::EventArgs^  e) {
	mother_form->Enabled = true;
	this->Close();
}
};
}
