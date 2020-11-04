#pragma once

//Алгоритм имитации отжига
//для поиска минимума функции

namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic; //Для List
	using namespace System::IO; //Для StreamWriter

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart;
	private: System::Windows::Forms::TextBox^  textBoxA;
	private: System::Windows::Forms::TextBox^  textBoxB;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labelMinF0;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  labelMinF;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelMinF0 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelMinF = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// chart
			// 
			this->chart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(2, 70);
			this->chart->Name = L"chart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->LegendText = L"Немодулированная";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->LegendText = L"Модулированная";
			series2->Name = L"Series2";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(784, 362);
			this->chart->TabIndex = 0;
			this->chart->Text = L"chart1";
			// 
			// textBoxA
			// 
			this->textBoxA->Location = System::Drawing::Point(6, 33);
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(100, 20);
			this->textBoxA->TabIndex = 1;
			this->textBoxA->Text = L"9";
			this->textBoxA->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBoxB
			// 
			this->textBoxB->Location = System::Drawing::Point(127, 34);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(100, 20);
			this->textBoxB->TabIndex = 2;
			this->textBoxB->Text = L"12";
			this->textBoxB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"A";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(129, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"B";
			// 
			// button
			// 
			this->button->Location = System::Drawing::Point(242, 32);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(75, 23);
			this->button->TabIndex = 5;
			this->button->Text = L"Расчет";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(342, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Min(F0)";
			// 
			// labelMinF0
			// 
			this->labelMinF0->AutoSize = true;
			this->labelMinF0->Location = System::Drawing::Point(342, 38);
			this->labelMinF0->Name = L"labelMinF0";
			this->labelMinF0->Size = System::Drawing::Size(13, 13);
			this->labelMinF0->TabIndex = 7;
			this->labelMinF0->Text = L"\?";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(461, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Min(F)";
			// 
			// labelMinF
			// 
			this->labelMinF->AutoSize = true;
			this->labelMinF->Location = System::Drawing::Point(461, 38);
			this->labelMinF->Name = L"labelMinF";
			this->labelMinF->Size = System::Drawing::Size(13, 13);
			this->labelMinF->TabIndex = 9;
			this->labelMinF->Text = L"\?";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(788, 432);
			this->Controls->Add(this->labelMinF);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->labelMinF0);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxB);
			this->Controls->Add(this->textBoxA);
			this->Controls->Add(this->chart);
			this->Name = L"MyForm";
			this->Text = L"Алгоритм имитации отжига";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Делегат для передачи функции
		delegate double function(double  x);
		//Не модулированная функция
		double F0(double x)
		{
			return x*x*Math::Sin(x);
		}
		//Модулированная
		double F(double x)
		{
			return F0(x) * Math::Sin(5*x);
		}

		double A, B; //Интервал
		ref struct Log //Единичная запись в журнале
		{
			double T; //Температура
			double X; //Аргумент
			double F; //Функция
		};
		List<Log^>^ list; //Журнал операций


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		list = gcnew List<Log^>();
		button_Click(sender, e); //Вызвать расчет для данных по умолчанию
	}


	private: System::Void button_Click(System::Object^  sender, System::EventArgs^  e) {
		//Прочитать данные
		if (!ReadData()) return; //В данных - ошибки
		//Заполнить график
		ShowInChart();
		//Выполнить расчет
		//function^ f = gcnew function(this,&MyForm::F0);
		double X = FindExtremum(gcnew function(this, &MyForm::F0));
		labelMinF0->Text = X.ToString("0.000");
		SaveToFile("F0.txt");
		X = FindExtremum(gcnew function(this, &MyForm::F));
		labelMinF->Text = X.ToString("0.000");
		//Вывести результат в файл
		SaveToFile("F.txt");
	}

			 //Прочитать одно значение
			 // ^ = ссылка на экземпляр класса
			 // % = передача параметра по ссылке (может быть изменен в функции)
			 bool ReadTextBox(TextBox^ textbox, double %value)
			 {
				 textbox->BackColor = Color::Red;
				 if (!double::TryParse(textbox->Text, value)) return false;
				 textbox->BackColor = Color::White;
				 return true;
			 }
			 //Прочитать исходные данные
			 bool ReadData()
			 {
				 bool result = true;
				 result &= ReadTextBox(textBoxA, A);
				 result &= ReadTextBox(textBoxB, B);
				 if (A > B)
				 {
					 MessageBox::Show("A>B");
					 return false;
				 }
				 return result;
			 }

			 void ShowInChart()
			 {
				 int N = 1000; //Точек на графике
				 double h = (B - A) / (N - 1);
				 chart->Series[0]->Points->Clear();
				 chart->Series[1]->Points->Clear();
				 chart->ChartAreas[0]->AxisX->Minimum = A;
				 chart->ChartAreas[0]->AxisX->Maximum = B;

				 for (int i = 0; i <= N; i++)
				 {
					 double x = A + h*i;
					 chart->Series[0]->Points->AddXY(x, F0(x));
					 chart->Series[1]->Points->AddXY(x, F(x));
				 }
			 }

			 double TMax = 10; //Начальная "температура"
			 double TMin = 1E-6; //Конечная температура
			 Random^ random = gcnew Random(); //Датчик случайных чисел

			 double FindExtremum(function^ F)
			 {
				 double T = TMax; //Номер итерации
				 double Alpha = 0.975; //Коэффициент уменьшения 
				 double X = (B + A) / 2; //Начальное значение приближения
				 double f1 = F(X); //Начальное значение функции
				 bool NeedToLog = true;
				 while (T > TMin)
				 {
					 if (NeedToLog)
					 {
						 //Записывается в журнал
						 Log^ log = gcnew Log();
						 log->T = T;
						 log->X = X;
						 log->F = f1;
						 list->Add(log);
						 NeedToLog = false;
					 }
					//Выбирается пробная точка
					 double xs = random->NextDouble()*(B - A) + A;

					 //Улучшение алгоритма - уменьшение величины шага с понижением температуры
					 //double xs = X + (2*random->NextDouble()-1) * (B - A)*(T / TMax);
					 //if (xs<A || xs>B) continue;

					 T = T * Alpha;//Следующая итерация
					 double f = f1; //Значение функции на предыдущем шаге

					 f1 = F(xs);
					 //Разница
					 double df = f1 - f; 
					 if (df <= 0)  //Если разница отрицательная - безусловный переход в новую точку
					 {
						 X = xs;
						 NeedToLog = true;
						 continue; //и продолжить выполнение цикла
					 }
					 //Если разница положительная
					 double P = Math::Exp(-df / T); //Вероятность перехода
					 if (random->NextDouble() <= P)
					 {
						 X = xs; //Переход
						 NeedToLog = true;
					 }
					 else 
						 f1 = f; //Иначе - остаемся на месте
				 }
				 return X;
			 }

			 //Сохранить журнал в файл, очистить
			 void SaveToFile(String^ filename)
			 {
				 StreamWriter^ writer = gcnew StreamWriter(filename);
				 writer->WriteLine("N\tT\tx\tf(x)\t"); //Заголовок
				 for (int k = 0; k < list->Count; k++)
				 {
					 Log^ log = list[k];
					 writer->WriteLine(
						 (k+1).ToString()+"\t"+
						 log->T.ToString("0.00")+ "\t" +
						 log->X.ToString("0.00000") + "\t" +
						 log->F.ToString("0.00000") + "\t"
						 );
				 }

				 writer->Close();
				 list->Clear();
			 }

};
}
