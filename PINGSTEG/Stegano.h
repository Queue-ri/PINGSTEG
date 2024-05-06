#pragma once


namespace PINGSTEG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;

	/// <summary>
	/// Stegano에 대한 요약입니다.
	/// </summary>
	public ref class Stegano : public System::Windows::Forms::Form
	{
	public:
		Stegano(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Stegano()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^ panel3;

	private: System::Windows::Forms::Button^  CLOSE_BUTTON;
	private: System::Windows::Forms::Button^  MINIMIZE_BUTTON;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  encodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  decodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  goToDevsBlogToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ whatIsPINGSTEGToolStripMenuItem;

	private: System::Windows::Forms::ProgressBar^  progressBar1;
	
	private: System::Windows::Forms::Timer^  timer1;

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stegano::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->MINIMIZE_BUTTON = (gcnew System::Windows::Forms::Button());
			this->CLOSE_BUTTON = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->whatIsPINGSTEGToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->goToDevsBlogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->encodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->decodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel1->Controls->Add(this->MINIMIZE_BUTTON);
			this->panel1->Controls->Add(this->CLOSE_BUTTON);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(460, 26);
			this->panel1->TabIndex = 0;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Stegano::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Stegano::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Stegano::panel1_MouseUp);
			// 
			// MINIMIZE_BUTTON
			// 
			this->MINIMIZE_BUTTON->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->MINIMIZE_BUTTON->BackColor = System::Drawing::Color::CornflowerBlue;
			this->MINIMIZE_BUTTON->Dock = System::Windows::Forms::DockStyle::Right;
			this->MINIMIZE_BUTTON->FlatAppearance->BorderSize = 0;
			this->MINIMIZE_BUTTON->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MINIMIZE_BUTTON->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->MINIMIZE_BUTTON->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->MINIMIZE_BUTTON->Location = System::Drawing::Point(408, 0);
			this->MINIMIZE_BUTTON->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MINIMIZE_BUTTON->Name = L"MINIMIZE_BUTTON";
			this->MINIMIZE_BUTTON->Size = System::Drawing::Size(26, 26);
			this->MINIMIZE_BUTTON->TabIndex = 1;
			this->MINIMIZE_BUTTON->TabStop = false;
			this->MINIMIZE_BUTTON->Text = L"_";
			this->MINIMIZE_BUTTON->UseVisualStyleBackColor = false;
			this->MINIMIZE_BUTTON->Click += gcnew System::EventHandler(this, &Stegano::button1_Click_3);
			// 
			// CLOSE_BUTTON
			// 
			this->CLOSE_BUTTON->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->CLOSE_BUTTON->BackColor = System::Drawing::Color::Tomato;
			this->CLOSE_BUTTON->Dock = System::Windows::Forms::DockStyle::Right;
			this->CLOSE_BUTTON->FlatAppearance->BorderSize = 0;
			this->CLOSE_BUTTON->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CLOSE_BUTTON->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->CLOSE_BUTTON->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->CLOSE_BUTTON->Location = System::Drawing::Point(434, 0);
			this->CLOSE_BUTTON->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CLOSE_BUTTON->Name = L"CLOSE_BUTTON";
			this->CLOSE_BUTTON->Size = System::Drawing::Size(26, 26);
			this->CLOSE_BUTTON->TabIndex = 0;
			this->CLOSE_BUTTON->TabStop = false;
			this->CLOSE_BUTTON->Text = L"x";
			this->CLOSE_BUTTON->UseVisualStyleBackColor = false;
			this->CLOSE_BUTTON->Click += gcnew System::EventHandler(this, &Stegano::CLOSE_BUTTON_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(183, 6);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 15);
			this->label4->TabIndex = 2;
			this->label4->Text = L"PINGSTEG v1.0.0";
			this->label4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Stegano::label4_MouseDown);
			this->label4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Stegano::label4_MouseMove);
			this->label4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Stegano::label4_MouseUp);
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::Color::DarkOrchid;
			this->progressBar1->Location = System::Drawing::Point(26, 218);
			this->progressBar1->Margin = System::Windows::Forms::Padding(0);
			this->progressBar1->MaximumSize = System::Drawing::Size(277, 8);
			this->progressBar1->MinimumSize = System::Drawing::Size(277, 8);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(277, 8);
			this->progressBar1->Step = 1;
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 3;
			this->progressBar1->Visible = false;
			this->progressBar1->Click += gcnew System::EventHandler(this, &Stegano::progressBar1_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 26);
			this->panel2->Margin = System::Windows::Forms::Padding(0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(133, 270);
			this->panel2->TabIndex = 1;
			// 
			// button8
			// 
			this->button8->AutoSize = true;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button8->Location = System::Drawing::Point(184, 237);
			this->button8->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(66, 26);
			this->button8->TabIndex = 15;
			this->button8->Text = L"설정";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &Stegano::button8_Click);
			// 
			// button6
			// 
			this->button6->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button6->Location = System::Drawing::Point(260, 72);
			this->button6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(42, 22);
			this->button6->TabIndex = 10;
			this->button6->Text = L"open";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &Stegano::button6_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Location = System::Drawing::Point(102, 74);
			this->textBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(158, 16);
			this->textBox3->TabIndex = 9;
			this->textBox3->TabStop = false;
			this->textBox3->Visible = false;
			// 
			// button5
			// 
			this->button5->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button5->Location = System::Drawing::Point(259, 36);
			this->button5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(43, 22);
			this->button5->TabIndex = 8;
			this->button5->Text = L"open";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &Stegano::button5_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(102, 38);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(158, 17);
			this->textBox2->TabIndex = 7;
			this->textBox2->TabStop = false;
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Stegano::textBox2_TextChanged);
			// 
			// button2
			// 
			this->button2->AutoSize = true;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Location = System::Drawing::Point(255, 237);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(61, 26);
			this->button2->TabIndex = 5;
			this->button2->Text = L"암호화";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Stegano::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(27, 74);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 17);
			this->label3->TabIndex = 1;
			this->label3->Text = L"DATA File";
			this->label3->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(34, 39);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 17);
			this->label2->TabIndex = 0;
			this->label2->Text = L"PNG File";
			this->label2->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Location = System::Drawing::Point(14, 46);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(312, 204);
			this->label6->TabIndex = 0;
			this->label6->Text = resources->GetString(L"label6.Text");
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->progressBar1);
			this->panel3->Controls->Add(this->button6);
			this->panel3->Controls->Add(this->button5);
			this->panel3->Controls->Add(this->button8);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->menuStrip1);
			this->panel3->Controls->Add(this->textBox3);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->textBox2);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->textBox4);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->textBox1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(133, 26);
			this->panel3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(327, 270);
			this->panel3->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Location = System::Drawing::Point(255, 237);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(61, 26);
			this->button1->TabIndex = 18;
			this->button1->Text = L"복호화";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &Stegano::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->aboutToolStripMenuItem,
					this->encodeToolStripMenuItem, this->decodeToolStripMenuItem
			});
			this->menuStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::HorizontalStackWithOverflow;
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->MaximumSize = System::Drawing::Size(331, 19);
			this->menuStrip1->MinimumSize = System::Drawing::Size(331, 20);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->menuStrip1->Size = System::Drawing::Size(331, 20);
			this->menuStrip1->Stretch = false;
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"MainMenu";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->whatIsPINGSTEGToolStripMenuItem,
					this->goToDevsBlogToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->aboutToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.999999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->ShowShortcutKeys = false;
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// whatIsPINGSTEGToolStripMenuItem
			// 
			this->whatIsPINGSTEGToolStripMenuItem->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->whatIsPINGSTEGToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->whatIsPINGSTEGToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.999999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->whatIsPINGSTEGToolStripMenuItem->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->whatIsPINGSTEGToolStripMenuItem->Margin = System::Windows::Forms::Padding(1);
			this->whatIsPINGSTEGToolStripMenuItem->Name = L"whatIsPINGSTEGToolStripMenuItem";
			this->whatIsPINGSTEGToolStripMenuItem->Padding = System::Windows::Forms::Padding(0);
			this->whatIsPINGSTEGToolStripMenuItem->Size = System::Drawing::Size(185, 20);
			this->whatIsPINGSTEGToolStripMenuItem->Text = L"What is PINGSTEG\?";
			this->whatIsPINGSTEGToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->whatIsPINGSTEGToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->whatIsPINGSTEGToolStripMenuItem->Click += gcnew System::EventHandler(this, &Stegano::whatIsPINGSTEGToolStripMenuItem_Click);
			// 
			// goToDevsBlogToolStripMenuItem
			// 
			this->goToDevsBlogToolStripMenuItem->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->goToDevsBlogToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->goToDevsBlogToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.999999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->goToDevsBlogToolStripMenuItem->Margin = System::Windows::Forms::Padding(1);
			this->goToDevsBlogToolStripMenuItem->Name = L"goToDevsBlogToolStripMenuItem";
			this->goToDevsBlogToolStripMenuItem->Padding = System::Windows::Forms::Padding(0);
			this->goToDevsBlogToolStripMenuItem->Size = System::Drawing::Size(185, 20);
			this->goToDevsBlogToolStripMenuItem->Text = L"Go to Dev\'s Blog";
			this->goToDevsBlogToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->goToDevsBlogToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->goToDevsBlogToolStripMenuItem->Click += gcnew System::EventHandler(this, &Stegano::goToDevsBlogToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->helpToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->helpToolStripMenuItem->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->helpToolStripMenuItem->Margin = System::Windows::Forms::Padding(1);
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Padding = System::Windows::Forms::Padding(0);
			this->helpToolStripMenuItem->Size = System::Drawing::Size(185, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Stegano::helpToolStripMenuItem_Click);
			// 
			// encodeToolStripMenuItem
			// 
			this->encodeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.999999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->encodeToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			this->encodeToolStripMenuItem->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->encodeToolStripMenuItem->Name = L"encodeToolStripMenuItem";
			this->encodeToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->encodeToolStripMenuItem->Text = L"Encode";
			this->encodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Stegano::encodeToolStripMenuItem_Click);
			// 
			// decodeToolStripMenuItem
			// 
			this->decodeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.999999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->decodeToolStripMenuItem->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->decodeToolStripMenuItem->Name = L"decodeToolStripMenuItem";
			this->decodeToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->decodeToolStripMenuItem->Text = L"Decode";
			this->decodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Stegano::decodeToolStripMenuItem_Click);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->textBox4->Location = System::Drawing::Point(26, 73);
			this->textBox4->Margin = System::Windows::Forms::Padding(0);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox4->ShortcutsEnabled = false;
			this->textBox4->Size = System::Drawing::Size(278, 147);
			this->textBox4->TabIndex = 17;
			this->textBox4->TabStop = false;
			this->textBox4->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->textBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->textBox1->Location = System::Drawing::Point(26, 107);
			this->textBox1->Margin = System::Windows::Forms::Padding(0);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->ShortcutsEnabled = false;
			this->textBox1->Size = System::Drawing::Size(278, 113);
			this->textBox1->TabIndex = 16;
			this->textBox1->TabStop = false;
			this->textBox1->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Stegano::timer1_Tick);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Stegano::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Stegano::backgroundWorker1_RunWorkerCompleted);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Stegano::backgroundWorker2_DoWork);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Stegano::backgroundWorker2_RunWorkerCompleted);
			// 
			// Stegano
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(460, 296);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->ImeMode = System::Windows::Forms::ImeMode::On;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(460, 296);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(460, 296);
			this->Name = L"Stegano";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PINGSTEG";
			this->Load += gcnew System::EventHandler(this, &Stegano::Stegano_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void Stegano_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void whatIsPINGSTEGToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void encodeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void decodeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void label4_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void label4_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void label4_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void button1_Click_3(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
}
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
}
System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {		
}
private: System::Void goToDevsBlogToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void progressBar1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void CLOSE_BUTTON_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
}
private: System::Void backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
}


#pragma region core functions

	private: int encode_png(Form^ form, String^ sys_wrapper_name, String^ sys_data_name);

#pragma endregion
};
}