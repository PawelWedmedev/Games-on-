#include <iostream>
#include <windows.h>
#include <iomanip> 
#include <string> 
#include <conio.h>
#include <ctime>

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue,
	LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background = Black)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

using namespace std;
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7(); 
void f8();

void main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	//**** все переменные начало
	char name[10];
	char name2[10];
	short go, go2 = 0;// переменная ввода человека и компа
	short winner1 = 0, winner2 = 0, draw = 0;// переменные победитель 1 или 2 или ничья
	short sumwinner1 = 0, sumwinner2 = 0;// переменные суммы очков за всю игру
	const int row = 3;
	const int col = 3;
	char arr[row][col] = { 49,50,51,52,53,54,55,56,57 };
	//****  титульный лист
	SetColor(8, 0);
	cout << endl << endl;
	cout << "        $$__$$__$$$$$___$$$$$$___$$$$___$$$$$$__$$__$$__$$__$$__$$__$$ " << endl;
	cout << "	$$_$$___$$__$$__$$______$$__$$____$$____$$__$$__$$_$$___$$__$$ " << endl;
	cout << "	$$$$____$$$$$$__$$$$____$$________$$____$$_$$$__$$$$____$$_$$$ " << endl;
	cout << "	$$_$$___$$______$$______$$__$$____$$____$$$_$$__$$_$$___$$$_$$ " << endl;
	cout << "        $$__$$__$$______$$$$$$___$$$$_____$$____$$__$$__$$__$$__$$__$$ " << endl;
	cout << endl << endl;
	cout << "\t\t\t	    $$" << endl;
	cout << "\t\t\t	  $$$$$$" << endl;
	cout << "\t\t\t	    $$ "<< endl;
	cout << endl << endl;
	cout << "\t        $$__$$___$$$$______$$$__$$__$$__$$__$$__$$__$$ " << endl;
	cout << "\t	$$__$$__$$__$$____$_$$__$$__$$__$$_$$___$$__$$ " << endl;
	cout << "\t	$$$$$$__$$__$$___$__$$__$$_$$$__$$$$____$$_$$$ " << endl;
	cout << "\t        $$__$$__$$__$$__$$__$$__$$$_$$__$$_$$___$$$_$$ " << endl;
	cout << "\t        $$__$$___$$$$___$$__$$__$$__$$__$$__$$__$$__$$ " << endl;
	cout << endl << endl;
	SetColor(15, 0);
	cout << "\t\t  Для начала игры нажмите любую клавишу..." << endl;
	system("pause >> NUL");
	//*** ...поехали
	int key = 0, index = 0;
	const int size = 5;
	char * menu[size] = { "Играть","Играть с другом","Об игре","Статистика","Выход" };
	//********************************* цикл показывает основное меню + символ стрелка.
	for (; key != 27;)//*************** начало цикла если переменной key не присвоено значение esc(выход).Если присвоено то выходим из программы.
	{
		system("cls");
		cout << endl << endl << endl << endl;
		for (int i = 0; i < size; i++)
		{
			
			if (index == i)//  если index =i, печатаем символ + i индекс char * menu массива.
			{
				SetColor(14, 0);
				cout << endl;
				cout << "\t\t\t\t" << (char)3 << "  " << menu[i] << "\n";
				SetColor(13, 0);
			}
			else {
				cout << endl;
				cout << "\t\t\t\t" << "  " << menu[i] << "\n";//если нет, то  печатаем  просто i индекс char * menu массива.
			}
		}
			key = _getch(); //присваиваем key новое значение и после ентера(_getch();) заходим в диапозон.
		
		if (key == 224 || key == 0)
			key = _getch();

		switch (key) //****************************** выбираем key
		{
		case 72: // ***************** стрелка вверх
			if (index>0)
				index--;
			else
				index = size - 1;
			break;
		case 80:// ***************** стрелка вниз
			if (index<size - 1)
				index++;
			else
				index = 0;
			break;
		case 13:
			switch (index) // ***************** смотрим какое значение емеет переменная index
			{
			case 0: f1(); break;
			case 1: f2(); break;
			case 2: f3(); break;
			case 3: f4(); break;
			case 4: f5(); break;
			case 5: cout << "Выход\n";
				key = 27; break;
			}
			//system("pause");
		}//************************* конец switchа
	} system("pause >> NUL");//******************************************* конец бесконечного цикла если key=27
}// ********* конец основной функции void(main)

 
// 1я функция- делит меню "Играть" на подменю по уровням сложности
void f1() {
	int key = 0, index = 0;
	const int size = 3;
	char * menu[size] = { "Легкий","Средний","Тяжелый",};
	for (; key != 27;)
	{
		system("cls");
		SetColor(10, 0);
		cout << endl << endl << endl;
		cout << "\t\t\t" << " Выберите уровень сложности игы: " << endl;
		cout << endl << endl << endl;
		SetColor(13, 0);
		for (int i = 0; i < size; i++)
		{
			if (index == i)
			{
				SetColor(14, 0);
				cout << endl;
				cout << "\t\t\t\t" << (char)16 << "  " << menu[i] << "\n";
				SetColor(13, 0);
			}
			else {
				cout << endl;
				cout << "\t\t\t\t" << "  " << menu[i] << "\n";
			}
		}
		key = _getch(); 

		if (key == 224 || key == 0)
			key = _getch();

		switch (key) //****************************** выбираем key
		{
		case 72: // ***************** стрелка вверх
			if (index>0)
				index--;
			else
				index = size - 1;
			break;
		case 80:// ***************** стрелка вниз
			if (index<size - 1)
				index++;
			else
				index = 0;
			break;
		case 13:
			switch (index) // ***************** смотрим какое значение емеет переменная index
			{
			case 0: f6(); break;
			case 1: f7(); break;
			case 2: f8(); break;
			case 3: cout << "Выход\n";
				key = 27; break;
			}
			system("pause");
		}
	}
}
//****** игра поочередно друг с другом
void f2() {
	char name[10];
	char name2[10];
	short go, go2 = 0;// переменная ввода человека и компа
	short winner1 = 0, winner2 = 0, draw = 0;// переменные победитель 1 или 2 или ничья
	short sumwinner1 = 0, sumwinner2 = 0;// переменные суммы очков за всю игру
	const int row = 3;
	const int col = 3;
	char arr[row][col] = { 49,50,51,52,53,54,55,56,57 };
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t\t  Введите Ваше имя ";
	cin >> name;
	cout << endl;
	cout << "\t\t\t Введите имя второго игрока ";
	cin >> name2;
	system("cls");
	bool cheng = rand() % 2;

	if (cheng == 1)
	{
		SetColor(14, 0);
		// **********игровое поле со значениями начало игрок
		for (int i(0); i < 3; i++)
		{
			if (i == 1)
				cout << "\t\t  Первым ходит " << name;
			if (i == 2)
				cout << "\t\tон играет крестиками ";
			cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
			for (int j(0); j < 3; j++)
			{
				if (j > 0)
					cout << "|";
				cout << "\t" << arr[i][j] << "\t";
			}
			if (i < 2)
			{
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				cout << " ";
				for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
					cout << "-";
			}
			else cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
		}
		SetColor(15, 0);
		while (true)
		{
		M1:
			go = _getch();
			//******* игра крестиками человек
			switch (go)
			{
			case 49: if (arr[0][0] == 49) arr[0][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 50: if (arr[0][1] == 50) arr[0][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 51: if (arr[0][2] == 51) arr[0][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 52: if (arr[1][0] == 52) arr[1][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 53: if (arr[1][1] == 53) arr[1][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 54: if (arr[1][2] == 54) arr[1][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 55: if (arr[2][0] == 55) arr[2][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 56: if (arr[2][1] == 56) arr[2][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 57: if (arr[2][2] == 57) arr[2][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			default: cout << "Введите цифры от 1 до 9 "; goto M1;
			}
			// **** поле после первого игрока
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name2 << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}
			//****если ничья
			draw++;
			if (draw == 5)
			{
				SetColor(14, 0);
				cout << " Ничья !!!"; Sleep(4000); break;
				SetColor(14, 0);
			}

			//*** а может я победил?
			for (int i(0); i < 3; i++)
				for (int j(0); j < 3; j++)
					arr[i][j];
			if ((arr[0][0] == 88 && arr[0][1] == 88 && arr[0][2] == 88) ||
				(arr[1][0] == 88 && arr[1][1] == 88 && arr[1][2] == 88) ||
				(arr[2][0] == 88 && arr[2][1] == 88 && arr[2][2] == 88) ||
				(arr[0][0] == 88 && arr[1][0] == 88 && arr[2][0] == 88) ||
				(arr[0][1] == 88 && arr[1][1] == 88 && arr[2][1] == 88) ||
				(arr[0][2] == 88 && arr[1][2] == 88 && arr[2][2] == 88) ||
				(arr[0][2] == 88 && arr[1][1] == 88 && arr[2][0] == 88) ||
				(arr[0][0] == 88 && arr[1][1] == 88 && arr[2][2] == 88))
			{
				system("cls");
				winner1 += 10;
				sumwinner1 += winner1;
				for (int i(0); i < 3; i++)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					for (int j(0); j < 3; j++)
					{
						SetColor(14, 0);
						if (j > 0)
							cout << "|";
						SetColor(12, 0);
						cout << "\t" << arr[i][j] << "\t";
						SetColor(15, 0);
					}
					if (i < 2)
					{
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						cout << " ";
						for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
							cout << "-";
					}
					else {
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						SetColor(15, 0);
					}
				}
				SetColor(14, 0);
				cout << " Победитель " << name << " он зарабатывает " << winner1 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}

			Sleep(400);
			// ****** ход второго игрока	
			 go2 = _getch();
		 M2:// ****** ход комп
			 switch (go2)
			 {
			 case 49: if (arr[0][0] == 49) arr[0][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M2; } break;
			 case 50: if (arr[0][1] == 50) arr[0][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M2; } break;
			 case 51: if (arr[0][2] == 51) arr[0][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M2; } break;
			 case 52: if (arr[1][0] == 52) arr[1][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M2; } break;
			 case 53: if (arr[1][1] == 53) arr[1][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M2; } break;
			 case 54: if (arr[1][2] == 54) arr[1][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M2; } break;
			 case 55: if (arr[2][0] == 55) arr[2][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M2; } break;
			 case 56: if (arr[2][1] == 56) arr[2][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M2; } break;
			 case 57: if (arr[2][2] == 57) arr[2][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M2; } break;
			 default: cout << "Введите цифры от 1 до 9 "; goto M2;
			 }

			//***** игровое поле после хода второго игрока
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}
			//***** проверяем не победил ли 2 игрок ???

			if ((arr[0][0] == 48 && arr[0][1] == 48 && arr[0][2] == 48) ||
				(arr[1][0] == 48 && arr[1][1] == 48 && arr[1][2] == 48) ||
				(arr[2][0] == 48 && arr[2][1] == 48 && arr[2][2] == 48) ||
				(arr[0][0] == 48 && arr[1][0] == 48 && arr[2][0] == 48) ||
				(arr[0][1] == 48 && arr[1][1] == 48 && arr[2][1] == 48) ||
				(arr[0][2] == 48 && arr[1][2] == 48 && arr[2][2] == 48) ||
				(arr[0][2] == 48 && arr[1][1] == 48 && arr[2][0] == 48) ||
				(arr[0][0] == 48 && arr[1][1] == 48 && arr[2][2] == 48))
			{
				winner2 += 10;
				sumwinner2 += winner2;
				SetColor(14, 0);
				cout << " Победил "<< name2<< "Он зарабатывает " << winner2 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		}
	}
	//*************************если первый играет игрок 2 крестиками
	else
	{
		system("cls");
		SetColor(14, 0);
		//**** игровое поле общий вид игрок 2
		for (int i(0); i < 3; i++)
		{
			if (i == 1)
				cout << "\t\t  Первым ходит " << name2;
			if (i == 2)
				cout << "\t\tон играет крестиками ";
			cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
			for (int j(0); j < 3; j++)
			{
				if (j > 0)
					cout << "|";
				cout << "\t" << arr[i][j] << "\t";
			}
			if (i < 2)
			{
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				cout << " ";
				for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
					cout << "-";
			}
			else cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
		}
		SetColor(15, 0);
		while (true)
		{
			go2 = _getch();

		M4:// ****** ход игрок 2
			switch (go2)
			{
			case 49: if (arr[0][0] == 49) arr[0][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M4; } break;
			case 50: if (arr[0][1] == 50) arr[0][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M4; } break;
			case 51: if (arr[0][2] == 51) arr[0][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M4; } break;
			case 52: if (arr[1][0] == 52) arr[1][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M4; } break;
			case 53: if (arr[1][1] == 53) arr[1][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M4; } break;
			case 54: if (arr[1][2] == 54) arr[1][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M4; } break;
			case 55: if (arr[2][0] == 55) arr[2][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M4; } break;
			case 56: if (arr[2][1] == 56) arr[2][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M4; } break;
			case 57: if (arr[2][2] == 57) arr[2][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M4; } break;
			default: cout << "Введите цифры от 1 до 9 "; goto M4;
			}
			
			//***** игровое поле
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}

			//****если ничья
			draw++;
			SetColor(14, 0);
			if (draw == 5)
			{
				cout << " Ничья !!!"; Sleep(4000); break;
			}
			SetColor(15, 0);
			//***** проверяем не победил ли игрок 2 ???

			if ((arr[0][0] == 88 && arr[0][1] == 88 && arr[0][2] == 88) ||
				(arr[1][0] == 88 && arr[1][1] == 88 && arr[1][2] == 88) ||
				(arr[2][0] == 88 && arr[2][1] == 88 && arr[2][2] == 88) ||
				(arr[0][0] == 88 && arr[1][0] == 88 && arr[2][0] == 88) ||
				(arr[0][1] == 88 && arr[1][1] == 88 && arr[2][1] == 88) ||
				(arr[0][2] == 88 && arr[1][2] == 88 && arr[2][2] == 88) ||
				(arr[0][2] == 88 && arr[1][1] == 88 && arr[2][0] == 88) ||
				(arr[0][0] == 88 && arr[1][1] == 88 && arr[2][2] == 88))
			{
				winner2 += 10;
				sumwinner2 += winner2;
				SetColor(14, 0);
				cout << " Победил "<<name2 <<" Он зарабатывает " << winner2 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		M3:
			go = _getch();
			//******* игра ноликами человек
			switch (go)
			{
			case 49: if (arr[0][0] == 49) arr[0][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 50: if (arr[0][1] == 50) arr[0][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 51: if (arr[0][2] == 51) arr[0][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 52: if (arr[1][0] == 52) arr[1][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 53: if (arr[1][1] == 53) arr[1][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 54: if (arr[1][2] == 54) arr[1][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 55: if (arr[2][0] == 55) arr[2][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 56: if (arr[2][1] == 56) arr[2][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 57: if (arr[2][2] == 57) arr[2][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			default: cout << "Введите цифры от 1 до 9 "; goto M3;
			}

			//***** игровое поле
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name2 << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}
			
			//*** а может я победил?
			for (int i(0); i < 3; i++)
				for (int j(0); j < 3; j++)
					arr[i][j];
			if ((arr[0][0] == 48 && arr[0][1] == 48 && arr[0][2] == 48) ||
				(arr[1][0] == 48 && arr[1][1] == 48 && arr[1][2] == 48) ||
				(arr[2][0] == 48 && arr[2][1] == 48 && arr[2][2] == 48) ||
				(arr[0][0] == 48 && arr[1][0] == 48 && arr[2][0] == 48) ||
				(arr[0][1] == 48 && arr[1][1] == 48 && arr[2][1] == 48) ||
				(arr[0][2] == 48 && arr[1][2] == 48 && arr[2][2] == 48) ||
				(arr[0][2] == 48 && arr[1][1] == 48 && arr[2][0] == 48) ||
				(arr[0][0] == 48 && arr[1][1] == 48 && arr[2][2] == 48))
			{
				system("cls");
				winner1 += 10;
				sumwinner1 += winner1;
				for (int i(0); i < 3; i++)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					for (int j(0); j < 3; j++)
					{
						SetColor(14, 0);
						if (j > 0)
							cout << "|";
						SetColor(12, 0);
						cout << "\t" << arr[i][j] << "\t";
						SetColor(15, 0);
					}
					if (i < 2)
					{
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						cout << " ";
						for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
							cout << "-";
					}
					else {
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						SetColor(15, 0);
					}
				}
				SetColor(14, 0);
				cout << " Победитель " << name << " он зарабатывает " << winner1 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		}
	}

}
//***** об игре
void f3() {
	system("cls");
	cout << endl;
	cout << " \tЗдравствуйте, предлагаем Вам сыграть в игру крестики нолики." << endl;
	cout << endl;
	cout << " Cуть игры заключаеться в том, чтобы расположить свой значек 'X' или '0'  в один ряд " ;
	cout << " по диагонали, вертикали, или горизонтали. Тот кто первый это сделает, тот  и победитель!!!" ;
	cout << " Он зарабытывает 10 баллов!!! "<<endl;
	cout << endl;
	cout << " Играть можно как с другом, делая ходы поочереди, так и с компьютером." << endl;
	cout<<  " В игре с компьютером доступно 3 версии сложности игры : " << endl;
	cout << endl;
	cout << " Легкий уровень - компьютер не отслеживает Ваши ходы и ставит свои знаки произво льно. " << endl;
	cout << " Средний уровень - компютер отслеживает Ваши ходы по горизонтали и вертикали, и  блокирует Ваши возможные выигрышные комбинации. " << endl;
	cout << " Тяжелый уровень игры - компьютер отслеживает все возможные комбинации и блокиру ет их." << endl;
	cout << endl;
	cout << " Вам нужно придумать как его обмануть..." <<(char) 1 << endl;
	cout << " Право первого хода, и игра крестиками, определяеться случайным образом." << endl;
	cout << " Правила игры: на игровом поле состоящим из 9 ячеек расположены цыфры от 1 до 9." << endl;
	cout << " Нажимая определенную цифру,Вы ставите на ее место свое значение ('X' либо '0')" << endl;
	cout << endl;
	cout << " \t\t\t\tУдачи !!!!! " << endl;
	
	getchar();
}
//***** статистика
void f4() {
	system("cls");
	cout << "\t\t\t\t Статистика игроков : "<<endl;
	getchar();
   
}
// ******функция выхода
void f5() {
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t До свидания !!!" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl;
	exit(0);
}
// ****** легкий вариант игры
void f6() {
	char name[10];
	char name2[10];
	short go, go2 = 0;// переменная ввода человека и компа
	short winner1 = 0, winner2 = 0, draw = 0;// переменные победитель 1 или 2 или ничья
	short sumwinner1 = 0, sumwinner2 = 0;// переменные суммы очков за всю игру
	const int row = 3;
	const int col = 3;
	char arr[row][col] = { 49,50,51,52,53,54,55,56,57 };
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t Введите Ваше имя ";
	cin >> name;
	system("cls");
	bool cheng = rand() % 2;

	if (cheng == 1)
	{
		SetColor(14, 0);
		// **********игровое поле со значениями начало игрок
		for (int i(0); i < 3; i++)
		{
			if (i == 1)
				cout << "\t\t  Первым ходит " << name;
			if (i == 2)
				cout << "\t\tон играет крестиками ";
			cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
			for (int j(0); j < 3; j++)
			{
				if (j > 0)
					cout << "|";
				cout << "\t" << arr[i][j] << "\t";
			}
			if (i < 2)
			{
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				cout << " ";
				for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
					cout << "-";
			}
			else cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
		}
		SetColor(15, 0);
		while (true)
		{
		M1:
			go = _getch();
			//******* игра крестиками человек
			switch (go)
			{

			case 49: if (arr[0][0] == 49) arr[0][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 50: if (arr[0][1] == 50) arr[0][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 51: if (arr[0][2] == 51) arr[0][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 52: if (arr[1][0] == 52) arr[1][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 53: if (arr[1][1] == 53) arr[1][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 54: if (arr[1][2] == 54) arr[1][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 55: if (arr[2][0] == 55) arr[2][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 56: if (arr[2][1] == 56) arr[2][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 57: if (arr[2][2] == 57) arr[2][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			default: cout << "Введите цифры от 1 до 9 "; goto M1;
			}

			//****если ничья
			draw++;
			if (draw == 5)
			{
				SetColor(14, 0);
				cout << " Ничья !!!"; Sleep(4000); break;
				SetColor(14, 0);
			}

			//*** а может я победил?
			for (int i(0); i < 3; i++)
				for (int j(0); j < 3; j++)
					arr[i][j];
			if ((arr[0][0] == 88 && arr[0][1] == 88 && arr[0][2] == 88) ||
				(arr[1][0] == 88 && arr[1][1] == 88 && arr[1][2] == 88) ||
				(arr[2][0] == 88 && arr[2][1] == 88 && arr[2][2] == 88) ||
				(arr[0][0] == 88 && arr[1][0] == 88 && arr[2][0] == 88) ||
				(arr[0][1] == 88 && arr[1][1] == 88 && arr[2][1] == 88) ||
				(arr[0][2] == 88 && arr[1][2] == 88 && arr[2][2] == 88) ||
				(arr[0][2] == 88 && arr[1][1] == 88 && arr[2][0] == 88) ||
				(arr[0][0] == 88 && arr[1][1] == 88 && arr[2][2] == 88))
			{
				system("cls");
				winner1 += 10;
				sumwinner1 += winner1;
				for (int i(0); i < 3; i++)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					for (int j(0); j < 3; j++)
					{
						SetColor(14, 0);
						if (j > 0)
							cout << "|";
						SetColor(12, 0);
						cout << "\t" << arr[i][j] << "\t";
						SetColor(15, 0);
					}
					if (i < 2)
					{
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						cout << " ";
						for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
							cout << "-";
					}
					else {
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						SetColor(15, 0);
					}
				}
				SetColor(14, 0);
				cout << " Победитель " << name << " он зарабатывает " << winner1 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}

			Sleep(400);
			//****** логика комп начало

			if (arr[0][1] == arr[1][1])
				go2 = 56;
			else go2 = rand() % 9 + 49;

			//****** логике компа конец!!!

		M2:// ****** ход комп
			switch (go2)
			{
			case 49: { if (arr[0][0] == 49) arr[0][0] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 50: { if (arr[0][1] == 50) arr[0][1] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 51: { if (arr[0][2] == 51) arr[0][2] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 52: { if (arr[1][0] == 52) arr[1][0] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 53: { if (arr[1][1] == 53) arr[1][1] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 54: { if (arr[1][2] == 54) arr[1][2] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 55: { if (arr[2][0] == 55) arr[2][0] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 56: { if (arr[2][1] == 56) arr[2][1] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 57: { if (arr[2][2] == 57) arr[2][2] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			}

			//***** игровое поле
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}
			//***** проверяем не победил ли комп ???

			if ((arr[0][0] == 48 && arr[0][1] == 48 && arr[0][2] == 48) ||
				(arr[1][0] == 48 && arr[1][1] == 48 && arr[1][2] == 48) ||
				(arr[2][0] == 48 && arr[2][1] == 48 && arr[2][2] == 48) ||
				(arr[0][0] == 48 && arr[1][0] == 48 && arr[2][0] == 48) ||
				(arr[0][1] == 48 && arr[1][1] == 48 && arr[2][1] == 48) ||
				(arr[0][2] == 48 && arr[1][2] == 48 && arr[2][2] == 48) ||
				(arr[0][2] == 48 && arr[1][1] == 48 && arr[2][0] == 48) ||
				(arr[0][0] == 48 && arr[1][1] == 48 && arr[2][2] == 48))
			{
				winner2 += 10;
				sumwinner2 += winner2;
				SetColor(14, 0);
				cout << " Победил умный компьютер!!! Он зарабатывает " << winner2 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		}
	}
	//*************************если первый играет комп крестиками
	else
	{
		system("cls");
		SetColor(14, 0);
		//**** игровое поле общий вид комп
		for (int i(0); i < 3; i++)
		{
			if (i == 1)
				cout << "\t\t Первым ходит комп ";
			if (i == 2)
				cout << "\t\tон играет крестиками ";
			cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
			for (int j(0); j < 3; j++)
			{
				if (j > 0)
					cout << "|";
				cout << "\t" << arr[i][j] << "\t";
			}
			if (i < 2)
			{
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				cout << " ";
				for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
					cout << "-";
			}
			else cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
		}
		SetColor(15, 0);
		while (true)
		{
			Sleep(1500);
			//****** логика комп начало
			if (arr[0][1] == arr[1][1])
				go2 = 56;
			else go2 = rand() % 9 + 49;

			//****** логике компа конец!!!

		M4:// ****** ход комп
			switch (go2)
			{
			case 49: { if (arr[0][0] == 49) arr[0][0] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 50: { if (arr[0][1] == 50) arr[0][1] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 51: { if (arr[0][2] == 51) arr[0][2] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 52: { if (arr[1][0] == 52) arr[1][0] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 53: { if (arr[1][1] == 53) arr[1][1] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 54: { if (arr[1][2] == 54) arr[1][2] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 55: { if (arr[2][0] == 55) arr[2][0] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 56: { if (arr[2][1] == 56) arr[2][1] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 57: { if (arr[2][2] == 57) arr[2][2] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			}

			//***** игровое поле
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}

			//****если ничья
			draw++;
			SetColor(14, 0);
			if (draw == 5)
			{
				cout << " Ничья !!!"; Sleep(4000); break;
			}
			SetColor(15, 0);
			//***** проверяем не победил ли комп ???

			if ((arr[0][0] == 88 && arr[0][1] == 88 && arr[0][2] == 88) ||
				(arr[1][0] == 88 && arr[1][1] == 88 && arr[1][2] == 88) ||
				(arr[2][0] == 88 && arr[2][1] == 88 && arr[2][2] == 88) ||
				(arr[0][0] == 88 && arr[1][0] == 88 && arr[2][0] == 88) ||
				(arr[0][1] == 88 && arr[1][1] == 88 && arr[2][1] == 88) ||
				(arr[0][2] == 88 && arr[1][2] == 88 && arr[2][2] == 88) ||
				(arr[0][2] == 88 && arr[1][1] == 88 && arr[2][0] == 88) ||
				(arr[0][0] == 88 && arr[1][1] == 88 && arr[2][2] == 88))
			{
				winner2 += 10;
				sumwinner2 += winner2;
				SetColor(14, 0);
				cout << " Победил умный компьютер!!! Он зарабатывает " << winner2 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		M3:
			go = _getch();
			//******* игра ноликами человек
			switch (go)
			{
			case 49: if (arr[0][0] == 49) arr[0][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 50: if (arr[0][1] == 50) arr[0][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 51: if (arr[0][2] == 51) arr[0][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 52: if (arr[1][0] == 52) arr[1][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 53: if (arr[1][1] == 53) arr[1][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 54: if (arr[1][2] == 54) arr[1][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 55: if (arr[2][0] == 55) arr[2][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 56: if (arr[2][1] == 56) arr[2][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 57: if (arr[2][2] == 57) arr[2][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			default: cout << "Введите цифры от 1 до 9 "; goto M3;
			}

			//*** а может я победил?
			for (int i(0); i < 3; i++)
				for (int j(0); j < 3; j++)
					arr[i][j];
			if ((arr[0][0] == 48 && arr[0][1] == 48 && arr[0][2] == 48) ||
				(arr[1][0] == 48 && arr[1][1] == 48 && arr[1][2] == 48) ||
				(arr[2][0] == 48 && arr[2][1] == 48 && arr[2][2] == 48) ||
				(arr[0][0] == 48 && arr[1][0] == 48 && arr[2][0] == 48) ||
				(arr[0][1] == 48 && arr[1][1] == 48 && arr[2][1] == 48) ||
				(arr[0][2] == 48 && arr[1][2] == 48 && arr[2][2] == 48) ||
				(arr[0][2] == 48 && arr[1][1] == 48 && arr[2][0] == 48) ||
				(arr[0][0] == 48 && arr[1][1] == 48 && arr[2][2] == 48))
			{
				system("cls");
				winner1 += 10;
				sumwinner1 += winner1;
				for (int i(0); i < 3; i++)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					for (int j(0); j < 3; j++)
					{
						SetColor(14, 0);
						if (j > 0)
							cout << "|";
						SetColor(12, 0);
						cout << "\t" << arr[i][j] << "\t";
						SetColor(15, 0);
					}
					if (i < 2)
					{
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						cout << " ";
						for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
							cout << "-";
					}
					else {
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						SetColor(15, 0);
					}
				}
				SetColor(14, 0);
				cout << " Победитель " << name << " он зарабатывает " << winner1 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		}
	}
	
}
// ****** средний вариант игры
void f7() {
	char name[10];
	char name2[10];
	short go, go2 = 0;// переменная ввода человека и компа
	short winner1 = 0, winner2 = 0, draw = 0;// переменные победитель 1 или 2 или ничья
	short sumwinner1 = 0, sumwinner2 = 0;// переменные суммы очков за всю игру
	const int row = 3;
	const int col = 3;
	char arr[row][col] = { 49,50,51,52,53,54,55,56,57 };
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t Введите Ваше имя ";
	cin >> name;
	system("cls");
	bool cheng = rand() % 2;

	if (cheng == 1)
	{
		SetColor(14, 0);
		// **********игровое поле со значениями начало игрок
		for (int i(0); i < 3; i++)
		{
			if (i == 1)
				cout << "\t\t  Первым ходит " << name;
			if (i == 2)
				cout << "\t\tон играет крестиками ";
			cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
			for (int j(0); j < 3; j++)
			{
				if (j > 0)
					cout << "|";
				cout << "\t" << arr[i][j] << "\t";
			}
			if (i < 2)
			{
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				cout << " ";
				for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
					cout << "-";
			}
			else cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
		}
		SetColor(15, 0);
		while (true)
		{
		M1:
			go = _getch();
			//******* игра крестиками человек
			switch (go)
			{

			case 49: if (arr[0][0] == 49) arr[0][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 50: if (arr[0][1] == 50) arr[0][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 51: if (arr[0][2] == 51) arr[0][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 52: if (arr[1][0] == 52) arr[1][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 53: if (arr[1][1] == 53) arr[1][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 54: if (arr[1][2] == 54) arr[1][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 55: if (arr[2][0] == 55) arr[2][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 56: if (arr[2][1] == 56) arr[2][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 57: if (arr[2][2] == 57) arr[2][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			default: cout << "Введите цифры от 1 до 9 "; goto M1;
			}

			//****если ничья
			draw++;
			if (draw == 5)
			{
				SetColor(14, 0);
				cout << " Ничья !!!"; Sleep(4000); break;
				SetColor(14, 0);
			}

			//*** а может я победил?
			for (int i(0); i < 3; i++)
				for (int j(0); j < 3; j++)
					arr[i][j];
			if ((arr[0][0] == 88 && arr[0][1] == 88 && arr[0][2] == 88) ||
				(arr[1][0] == 88 && arr[1][1] == 88 && arr[1][2] == 88) ||
				(arr[2][0] == 88 && arr[2][1] == 88 && arr[2][2] == 88) ||
				(arr[0][0] == 88 && arr[1][0] == 88 && arr[2][0] == 88) ||
				(arr[0][1] == 88 && arr[1][1] == 88 && arr[2][1] == 88) ||
				(arr[0][2] == 88 && arr[1][2] == 88 && arr[2][2] == 88) ||
				(arr[0][2] == 88 && arr[1][1] == 88 && arr[2][0] == 88) ||
				(arr[0][0] == 88 && arr[1][1] == 88 && arr[2][2] == 88))
			{
				system("cls");
				winner1 += 10;
				sumwinner1 += winner1;
				for (int i(0); i < 3; i++)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					for (int j(0); j < 3; j++)
					{
						SetColor(14, 0);
						if (j > 0)
							cout << "|";
						SetColor(12, 0);
						cout << "\t" << arr[i][j] << "\t";
						SetColor(15, 0);
					}
					if (i < 2)
					{
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						cout << " ";
						for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
							cout << "-";
					}
					else {
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						SetColor(15, 0);
					}
				}
				SetColor(14, 0);
				cout << " Победитель " << name << " он зарабатывает " << winner1 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}

			Sleep(400);
			//****** логика комп начало
			
			 if (arr[0][1] == arr[1][1])
				go2 = 56;
			else if (arr[2][1] == arr[1][1])
				go2 = 50;
			else if (arr[1][2] == arr[1][1])
				go2 = 52;
			else if (arr[1][0] == arr[1][1])
				go2 = 54;
			else go2 = rand() % 9 + 49;

			//****** логике компа конец!!!

		M2:// ****** ход комп
			switch (go2)
			{
			case 49: { if (arr[0][0] == 49) arr[0][0] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 50: { if (arr[0][1] == 50) arr[0][1] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 51: { if (arr[0][2] == 51) arr[0][2] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 52: { if (arr[1][0] == 52) arr[1][0] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 53: { if (arr[1][1] == 53) arr[1][1] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 54: { if (arr[1][2] == 54) arr[1][2] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 55: { if (arr[2][0] == 55) arr[2][0] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 56: { if (arr[2][1] == 56) arr[2][1] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 57: { if (arr[2][2] == 57) arr[2][2] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			}

			//***** игровое поле
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}
			//***** проверяем не победил ли комп ???

			if ((arr[0][0] == 48 && arr[0][1] == 48 && arr[0][2] == 48) ||
				(arr[1][0] == 48 && arr[1][1] == 48 && arr[1][2] == 48) ||
				(arr[2][0] == 48 && arr[2][1] == 48 && arr[2][2] == 48) ||
				(arr[0][0] == 48 && arr[1][0] == 48 && arr[2][0] == 48) ||
				(arr[0][1] == 48 && arr[1][1] == 48 && arr[2][1] == 48) ||
				(arr[0][2] == 48 && arr[1][2] == 48 && arr[2][2] == 48) ||
				(arr[0][2] == 48 && arr[1][1] == 48 && arr[2][0] == 48) ||
				(arr[0][0] == 48 && arr[1][1] == 48 && arr[2][2] == 48))
			{
				winner2 += 10;
				sumwinner2 += winner2;
				SetColor(14, 0);
				cout << " Победил умный компьютер!!! Он зарабатывает " << winner2 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		}
	}
	//*************************если первый играет комп крестиками
	else
	{
		system("cls");
		SetColor(14, 0);
		//**** игровое поле общий вид комп
		for (int i(0); i < 3; i++)
		{
			if (i == 1)
				cout << "\t\t Первым ходит комп ";
			if (i == 2)
				cout << "\t\tон играет крестиками ";
			cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
			for (int j(0); j < 3; j++)
			{
				if (j > 0)
					cout << "|";
				cout << "\t" << arr[i][j] << "\t";
			}
			if (i < 2)
			{
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				cout << " ";
				for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
					cout << "-";
			}
			else cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
		}
		SetColor(15, 0);
		while (true)
		{
			Sleep(1500);
			//****** логика комп начало
			 if (arr[0][1] == arr[1][1])
				go2 = 56;
			else if (arr[2][1] == arr[1][1])
				go2 = 50;
			else if (arr[1][2] == arr[1][1])
				go2 = 52;
			else if (arr[1][0] == arr[1][1])
				go2 = 54;
			else go2 = rand() % 9 + 49;

			//****** логике компа конец!!!

		M4:// ****** ход комп
			switch (go2)
			{
			case 49: { if (arr[0][0] == 49) arr[0][0] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 50: { if (arr[0][1] == 50) arr[0][1] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 51: { if (arr[0][2] == 51) arr[0][2] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 52: { if (arr[1][0] == 52) arr[1][0] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 53: { if (arr[1][1] == 53) arr[1][1] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 54: { if (arr[1][2] == 54) arr[1][2] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 55: { if (arr[2][0] == 55) arr[2][0] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 56: { if (arr[2][1] == 56) arr[2][1] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 57: { if (arr[2][2] == 57) arr[2][2] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			}

			//***** игровое поле
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}

			//****если ничья
			draw++;
			SetColor(14, 0);
			if (draw == 5)
			{
				cout << " Ничья !!!"; Sleep(4000); break;
			}
			SetColor(15, 0);
			//***** проверяем не победил ли комп ???

			if ((arr[0][0] == 88 && arr[0][1] == 88 && arr[0][2] == 88) ||
				(arr[1][0] == 88 && arr[1][1] == 88 && arr[1][2] == 88) ||
				(arr[2][0] == 88 && arr[2][1] == 88 && arr[2][2] == 88) ||
				(arr[0][0] == 88 && arr[1][0] == 88 && arr[2][0] == 88) ||
				(arr[0][1] == 88 && arr[1][1] == 88 && arr[2][1] == 88) ||
				(arr[0][2] == 88 && arr[1][2] == 88 && arr[2][2] == 88) ||
				(arr[0][2] == 88 && arr[1][1] == 88 && arr[2][0] == 88) ||
				(arr[0][0] == 88 && arr[1][1] == 88 && arr[2][2] == 88))
			{
				winner2 += 10;
				sumwinner2 += winner2;
				SetColor(14, 0);
				cout << " Победил умный компьютер!!! Он зарабатывает " << winner2 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		M3:
			go = _getch();
			//******* игра ноликами человек
			switch (go)
			{
			case 49: if (arr[0][0] == 49) arr[0][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 50: if (arr[0][1] == 50) arr[0][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 51: if (arr[0][2] == 51) arr[0][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 52: if (arr[1][0] == 52) arr[1][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 53: if (arr[1][1] == 53) arr[1][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 54: if (arr[1][2] == 54) arr[1][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 55: if (arr[2][0] == 55) arr[2][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 56: if (arr[2][1] == 56) arr[2][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 57: if (arr[2][2] == 57) arr[2][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			default: cout << "Введите цифры от 1 до 9 "; goto M3;
			}

			//*** а может я победил?
			for (int i(0); i < 3; i++)
				for (int j(0); j < 3; j++)
					arr[i][j];
			if ((arr[0][0] == 48 && arr[0][1] == 48 && arr[0][2] == 48) ||
				(arr[1][0] == 48 && arr[1][1] == 48 && arr[1][2] == 48) ||
				(arr[2][0] == 48 && arr[2][1] == 48 && arr[2][2] == 48) ||
				(arr[0][0] == 48 && arr[1][0] == 48 && arr[2][0] == 48) ||
				(arr[0][1] == 48 && arr[1][1] == 48 && arr[2][1] == 48) ||
				(arr[0][2] == 48 && arr[1][2] == 48 && arr[2][2] == 48) ||
				(arr[0][2] == 48 && arr[1][1] == 48 && arr[2][0] == 48) ||
				(arr[0][0] == 48 && arr[1][1] == 48 && arr[2][2] == 48))
			{
				system("cls");
				winner1 += 10;
				sumwinner1 += winner1;
				for (int i(0); i < 3; i++)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					for (int j(0); j < 3; j++)
					{
						SetColor(14, 0);
						if (j > 0)
							cout << "|";
						SetColor(12, 0);
						cout << "\t" << arr[i][j] << "\t";
						SetColor(15, 0);
					}
					if (i < 2)
					{
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						cout << " ";
						for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
							cout << "-";
					}
					else {
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						SetColor(15, 0);
					}
				}
				SetColor(14, 0);
				cout << " Победитель " << name << " он зарабатывает " << winner1 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		}
	}
}	
// ****** сложный вариант игры
void f8() {
	char name[10];
	char name2[10];
	short go, go2 = 0;// переменная ввода человека и компа
	short winner1 = 0, winner2 = 0, draw = 0;// переменные победитель 1 или 2 или ничья
	short sumwinner1 = 0, sumwinner2 = 0;// переменные суммы очков за всю игру
	const int row = 3;
	const int col = 3;
	char arr[row][col] = { 49,50,51,52,53,54,55,56,57 };
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t Введите Ваше имя ";
	cin >> name;
	system("cls");
	bool cheng = rand() % 2;

	if (cheng == 1)
	{
		SetColor(14, 0);
		// **********игровое поле со значениями начало игрок
		for (int i(0); i < 3; i++)
		{
			if (i == 1)
				cout << "\t\t  Первым ходит " << name;
			if (i == 2)
				cout << "\t\tон играет крестиками ";
			cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
			for (int j(0); j < 3; j++)
			{
				if (j > 0)
					cout << "|";
				cout << "\t" << arr[i][j] << "\t";
			}
			if (i < 2)
			{
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				cout << " ";
				for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
					cout << "-";
			}
			else cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
		}
		SetColor(15, 0);
		while (true)
		{
		M1:
			go = _getch();
			//******* игра крестиками человек
			switch (go)
			{

			case 49: if (arr[0][0] == 49) arr[0][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 50: if (arr[0][1] == 50) arr[0][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 51: if (arr[0][2] == 51) arr[0][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 52: if (arr[1][0] == 52) arr[1][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 53: if (arr[1][1] == 53) arr[1][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 54: if (arr[1][2] == 54) arr[1][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 55: if (arr[2][0] == 55) arr[2][0] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 56: if (arr[2][1] == 56) arr[2][1] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			case 57: if (arr[2][2] == 57) arr[2][2] = 88; else { cout << " ... извините, но эта клетка уже занята "; goto M1; } break;
			default: cout << "Введите цифры от 1 до 9 "; goto M1;
			}

			//****если ничья
			draw++;
			if (draw == 5)
			{
				SetColor(14, 0);
				cout << " Ничья !!!"; Sleep(4000); break;
				SetColor(14, 0);
			}

			//*** а может я победил?
			for (int i(0); i < 3; i++)
				for (int j(0); j < 3; j++)
					arr[i][j];
			if ((arr[0][0] == 88 && arr[0][1] == 88 && arr[0][2] == 88) ||
				(arr[1][0] == 88 && arr[1][1] == 88 && arr[1][2] == 88) ||
				(arr[2][0] == 88 && arr[2][1] == 88 && arr[2][2] == 88) ||
				(arr[0][0] == 88 && arr[1][0] == 88 && arr[2][0] == 88) ||
				(arr[0][1] == 88 && arr[1][1] == 88 && arr[2][1] == 88) ||
				(arr[0][2] == 88 && arr[1][2] == 88 && arr[2][2] == 88) ||
				(arr[0][2] == 88 && arr[1][1] == 88 && arr[2][0] == 88) ||
				(arr[0][0] == 88 && arr[1][1] == 88 && arr[2][2] == 88))
			{
				system("cls");
				winner1 += 10;
				sumwinner1 += winner1;
				for (int i(0); i < 3; i++)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					for (int j(0); j < 3; j++)
					{
						SetColor(14, 0);
						if (j > 0)
							cout << "|";
						SetColor(12, 0);
						cout << "\t" << arr[i][j] << "\t";
						SetColor(15, 0);
					}
					if (i < 2)
					{
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						cout << " ";
						for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
							cout << "-";
					}
					else {
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						SetColor(15, 0);
					}
				}
				SetColor(14, 0);
				cout << " Победитель " << name << " он зарабатывает " << winner1 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}

			Sleep(400);
			//****** логика комп начало
			if ((arr[0][0] == arr[0][1]) || (arr[2][0] == arr[1][1]) || (arr[1][2] == arr[2][2]))
				go2 = 51;
			else  if ((arr[0][2] == arr[1][1]) || (arr[2][1] == arr[2][2]) || (arr[0][0] == arr[1][0]))
				go2 = 55;
			else  if ((arr[0][2] == arr[1][2]) || (arr[0][0] == arr[1][1]) || (arr[2][0] == arr[2][1]))
				go2 = 57;
			else  if ((arr[1][1] == arr[2][2]) || (arr[0][1] == arr[0][2]) || (arr[1][0] == arr[2][0]))
				go2 = 49;
			else if (arr[0][1] == arr[1][1])
				go2 = 56;
			else if (arr[2][1] == arr[1][1])
				go2 = 50;
			else if (arr[1][2] == arr[1][1])
				go2 = 52;
			else if (arr[1][0] == arr[1][1])
				go2 = 54;
			else go2 = rand() % 9 + 49;

			//****** логике компа конец!!!

		M2:// ****** ход комп
			switch (go2)
			{
			case 49: { if (arr[0][0] == 49) arr[0][0] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 50: { if (arr[0][1] == 50) arr[0][1] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 51: { if (arr[0][2] == 51) arr[0][2] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 52: { if (arr[1][0] == 52) arr[1][0] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 53: { if (arr[1][1] == 53) arr[1][1] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 54: { if (arr[1][2] == 54) arr[1][2] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 55: { if (arr[2][0] == 55) arr[2][0] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 56: { if (arr[2][1] == 56) arr[2][1] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			case 57: { if (arr[2][2] == 57) arr[2][2] = 48; else { go2 = rand() % 9 + 49; goto M2; }} break;
			}

			//***** игровое поле
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}
			//***** проверяем не победил ли комп ???

			if ((arr[0][0] == 48 && arr[0][1] == 48 && arr[0][2] == 48) ||
				(arr[1][0] == 48 && arr[1][1] == 48 && arr[1][2] == 48) ||
				(arr[2][0] == 48 && arr[2][1] == 48 && arr[2][2] == 48) ||
				(arr[0][0] == 48 && arr[1][0] == 48 && arr[2][0] == 48) ||
				(arr[0][1] == 48 && arr[1][1] == 48 && arr[2][1] == 48) ||
				(arr[0][2] == 48 && arr[1][2] == 48 && arr[2][2] == 48) ||
				(arr[0][2] == 48 && arr[1][1] == 48 && arr[2][0] == 48) ||
				(arr[0][0] == 48 && arr[1][1] == 48 && arr[2][2] == 48))
			{
				winner2 += 10;
				sumwinner2 += winner2;
				SetColor(14, 0);
				cout << " Победил умный компьютер!!! Он зарабатывает " << winner2 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		}
	}
	//*************************если первый играет комп крестиками
	else
	{
		system("cls");
		SetColor(14, 0);
		//**** игровое поле общий вид комп
		for (int i(0); i < 3; i++)
		{
			if (i == 1)
				cout << "\t\t Первым ходит комп ";
			if (i == 2)
				cout << "\t\tон играет крестиками ";
			cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
			for (int j(0); j < 3; j++)
			{
				if (j > 0)
					cout << "|";
				cout << "\t" << arr[i][j] << "\t";
			}
			if (i < 2)
			{
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				cout << " ";
				for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
					cout << "-";
			}
			else cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
		}
		SetColor(15, 0);
		while (true)
		{
			Sleep(1500);
			//****** логика комп начало
			if ((arr[0][0] == arr[0][1]) || (arr[2][0] == arr[1][1]) || (arr[1][2] == arr[2][2]))
				go2 = 51;
			else  if ((arr[0][2] == arr[1][1]) || (arr[2][1] == arr[2][2]) || (arr[0][0] == arr[1][0]))
				go2 = 55;
			else  if ((arr[0][2] == arr[1][2]) || (arr[0][0] == arr[1][1]) || (arr[2][0] == arr[2][1]))
				go2 = 57;
			else  if ((arr[1][1] == arr[2][2]) || (arr[0][1] == arr[0][2]) || (arr[1][0] == arr[2][0]))
				go2 = 49;
			else if (arr[0][1] == arr[1][1])
				go2 = 56;
			else if (arr[2][1] == arr[1][1])
				go2 = 50;
			else if (arr[1][2] == arr[1][1])
				go2 = 52;
			else if (arr[1][0] == arr[1][1])
				go2 = 54;
			else go2 = rand() % 9 + 49;

			//****** логике компа конец!!!

		M4:// ****** ход комп
			switch (go2)
			{
			case 49: { if (arr[0][0] == 49) arr[0][0] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 50: { if (arr[0][1] == 50) arr[0][1] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 51: { if (arr[0][2] == 51) arr[0][2] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 52: { if (arr[1][0] == 52) arr[1][0] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 53: { if (arr[1][1] == 53) arr[1][1] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 54: { if (arr[1][2] == 54) arr[1][2] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 55: { if (arr[2][0] == 55) arr[2][0] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 56: { if (arr[2][1] == 56) arr[2][1] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			case 57: { if (arr[2][2] == 57) arr[2][2] = 88; else { go2 = rand() % 9 + 49; goto M4; }} break;
			}

			//***** игровое поле
			system("cls");
			for (int i(0); i < 3; i++)
			{//*****
				SetColor(12, 0);
				if (i == 1)
					cout << "\t\t " << name << " ваш ход...  ";
				//*****
				SetColor(14, 0);
				cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
				for (int j(0); j < 3; j++)
				{
					SetColor(14, 0);
					if (j > 0)
						cout << "|";
					SetColor(12, 0);
					cout << "\t" << arr[i][j] << "\t";
					SetColor(15, 0);
				}
				if (i < 2)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					cout << " ";
					for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
						cout << "-";
				}
				else {
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					SetColor(15, 0);
				}
			}

			//****если ничья
			draw++;
			SetColor(14, 0);
			if (draw == 5)
			{
				cout << " Ничья !!!"; Sleep(4000); break;
			}
			SetColor(15, 0);
			//***** проверяем не победил ли комп ???

			if ((arr[0][0] == 88 && arr[0][1] == 88 && arr[0][2] == 88) ||
				(arr[1][0] == 88 && arr[1][1] == 88 && arr[1][2] == 88) ||
				(arr[2][0] == 88 && arr[2][1] == 88 && arr[2][2] == 88) ||
				(arr[0][0] == 88 && arr[1][0] == 88 && arr[2][0] == 88) ||
				(arr[0][1] == 88 && arr[1][1] == 88 && arr[2][1] == 88) ||
				(arr[0][2] == 88 && arr[1][2] == 88 && arr[2][2] == 88) ||
				(arr[0][2] == 88 && arr[1][1] == 88 && arr[2][0] == 88) ||
				(arr[0][0] == 88 && arr[1][1] == 88 && arr[2][2] == 88))
			{
				winner2 += 10;
				sumwinner2 += winner2;
				SetColor(14, 0);
				cout << " Победил умный компьютер!!! Он зарабатывает " << winner2 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		M3:
			go = _getch();
			//******* игра ноликами человек
			switch (go)
			{
			case 49: if (arr[0][0] == 49) arr[0][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 50: if (arr[0][1] == 50) arr[0][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 51: if (arr[0][2] == 51) arr[0][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 52: if (arr[1][0] == 52) arr[1][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 53: if (arr[1][1] == 53) arr[1][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 54: if (arr[1][2] == 54) arr[1][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 55: if (arr[2][0] == 55) arr[2][0] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 56: if (arr[2][1] == 56) arr[2][1] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			case 57: if (arr[2][2] == 57) arr[2][2] = 48; else { cout << " ... извините, но эта клетка уже занята "; goto M3; } break;
			default: cout << "Введите цифры от 1 до 9 "; goto M3;
			}

			//*** а может я победил?
			for (int i(0); i < 3; i++)
				for (int j(0); j < 3; j++)
					arr[i][j];
			if ((arr[0][0] == 48 && arr[0][1] == 48 && arr[0][2] == 48) ||
				(arr[1][0] == 48 && arr[1][1] == 48 && arr[1][2] == 48) ||
				(arr[2][0] == 48 && arr[2][1] == 48 && arr[2][2] == 48) ||
				(arr[0][0] == 48 && arr[1][0] == 48 && arr[2][0] == 48) ||
				(arr[0][1] == 48 && arr[1][1] == 48 && arr[2][1] == 48) ||
				(arr[0][2] == 48 && arr[1][2] == 48 && arr[2][2] == 48) ||
				(arr[0][2] == 48 && arr[1][1] == 48 && arr[2][0] == 48) ||
				(arr[0][0] == 48 && arr[1][1] == 48 && arr[2][2] == 48))
			{
				system("cls");
				winner1 += 10;
				sumwinner1 += winner1;
				for (int i(0); i < 3; i++)
				{
					SetColor(14, 0);
					cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
					for (int j(0); j < 3; j++)
					{
						SetColor(14, 0);
						if (j > 0)
							cout << "|";
						SetColor(12, 0);
						cout << "\t" << arr[i][j] << "\t";
						SetColor(15, 0);
					}
					if (i < 2)
					{
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						cout << " ";
						for (int k(0); k < 46; k++)// печатаем 2 горизонтальные полосы поля
							cout << "-";
					}
					else {
						SetColor(14, 0);
						cout << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl << "\t\t|" << "\t\t|" << endl;
						SetColor(15, 0);
					}
				}
				SetColor(14, 0);
				cout << " Победитель " << name << " он зарабатывает " << winner1 << " очков ";
				SetColor(15, 0);
				Sleep(4000); break;
			}
		}
	}
}