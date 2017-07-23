#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <string.h>
using namespace std;
void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
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

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int count_s = 3;
	int k = 1;
	int kr = 1;
	char en = 0;
	int ex = 0;
	int b;
	int ar[5];
	int a;
	char name[] = { " " };
	char name2[] = { " " };
	short coursechoices, coursechoices1;
	//************************переменные человек
	short sum, sum1 = 0, sum2 = 0, sumS = 0;
	short number = 0, numbersum = 0;
	//************************переменные комп
	short sumk, sum1k = 0, sum2k = 0, sumSk = 0;
	short numberk = 0, numbersumk = 0;
	//************************переменные игрок № 1
	short sum3, sum13 = 0, sum23 = 0, sumS3 = 0;
	short number3 = 0, numbersum3 = 0;
	//************************переменные игрок № 2
	short sumk2, sum1k2 = 0, sum2k2 = 0, sumSk2 = 0;
	short numberk2 = 0, numbersumk2 = 0;

	cout << endl;
	SetColor(1, 0);
cout << "      $$  $$  $$  $$  $$$$$   $$  $$  $$  $$  $$  $$       $$  $$   $$$$" << endl;
cout << "      $$ $$    $$ $$  $$      $$  $$  $$ $$   $$  $$       $$  $$  $$  $$" << endl;
SetColor(14, 0);
cout << "      $$$$      $$$$  $$$$$   $$ $$$  $$$$    $$ $$$       $$  $$  $$$$$$" << endl;
cout << "      $$ $$       $$  $$ $$   $$$ $$  $$ $$   $$$ $$       $$  $$  $$  $$" << endl;
cout << "      $$  $$     $$$  $$$$$   $$  $$  $$  $$  $$  $$  $$    $$$$   $$  $$" << endl;
SetColor(14, 0);
cout << endl << endl << endl << endl;
	cout << "\t\t\t    Введите Ваше имя _";
	cin>> name;
	system("cls");
	do
	{
		cout << endl;
		if (en == 80)
		{
			k++;
			if (k == 6)
				k = 1;
		}
		if (en == 72)
		{
			k--;
			if (k == 0)
				k = 5;
		}
		if (en == 13)
		{   
			// ***************игра одному, меню №1
			if (k == 1)
			{
				
				//************* первое меню игра с компом
				SetColor(1, 0);
				gotoxy(22, 13);
				cout << " Выберите кто первый начинает игру" << endl;
				SetColor(14, 0);
				gotoxy(4, 16);
				cout << name << endl;
				gotoxy(2, 17);
				cout<<"нажмите " << endl;
				//*****************1
				SetColor(1, 0);
				gotoxy(2, 19);
				cout << "   $$" << endl;
				gotoxy(2, 20);
				cout << " $$$$" << endl;
				gotoxy(2, 21);
				cout << "   $$" << endl;
				gotoxy(2, 22);
			    cout << "   $$" << endl;
				gotoxy(2, 23);
				cout << "   $$" << endl;
				//****************2
				SetColor(14, 0);
				gotoxy(65,15);
				cout << " противник " << endl;
				gotoxy(66, 16);
				cout<<" нажмите" << endl;
				SetColor(1, 0);
				gotoxy(63, 18);
				cout << "      $$$$" << endl;
				gotoxy(63, 19);
				cout << "     $$  $$" << endl;
				gotoxy(63, 20);
				cout << "       $$" << endl;
				gotoxy(63 ,21);
				cout << "      $$" << endl;
				gotoxy(63, 22);
				cout << "     $$$$$$" << endl;
				SetColor(14, 0);
				gotoxy(39, 19);
				cin >> coursechoices;
				
				// выбираем очередность
				if (coursechoices == 1)
				{
				
					for (int i(0); i < 5; i++)
					{
						SetColor(14, 0);
						gotoxy(23, 20);
						cout<< name << ", для броска нажмите пробел..." << endl;
						system("pause>>NUL");
						system("cls");
						// бросок человека
						for (int i(0); i <= 10; i++)
						{
							sum = 0;
							int a = rand() % 6 + 1;
							switch (a)
							{
								
							case 1: GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*             *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*      O      *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*             *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1 = 1;
								break;

							case 2:  GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*          0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*             *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0          *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1 = 2;
								break;

							case 3:  GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*          0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*      0      *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0          *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1 = 3;
								break;

							case 4: GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*             *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1 = 4;
								break;

							case 5: GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*      0      *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1 = 5;
								break;

							case 6: GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1 = 6;
								break;
							}
							int b = rand() % 6 + 1;
							switch (b)
							{
							case 1: GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*             *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*      O      *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*             *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2 = 1;
								break;

							case 2:  GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*          0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*             *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0          *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2 = 2;
								break;

							case 3:  GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*          0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*      0      *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0          *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
                                sum2 = 3;
								break;

							case 4:  GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*             *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2 = 4;
								break;

							case 5:GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*      0      *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2 = 5;
								break;

							case 6: GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2 = 6;
								break;

							}
							sum = sum1 + sum2;
						}
						number++;
						numbersum += number;
						sumS += sum;
						SetColor(12, 0);
						GotoXY(20, 1);
						cout << "За " << number << " бросок " << name << " зарабатываете " << sum << " очков " << endl;
						GotoXY(25, 2);
						cout << "Всего очков за " << numbersum << " бросков = " << sumS << endl;
						numbersum = 0;
						SetColor(14, 0);
						if (numberk == 5)
							break;
						cout << endl;
						Sleep(1350);
m1:
						//********************************** бросок комп

					     for (int i(0); i <= 10; i++)
							{
								sumk = 0;
								int a = rand() % 6 + 1;
								switch (a)
								{
								case 1: GotoXY(20, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(20, 6);
									cout << "*             *" << endl;
									GotoXY(20, 7);
									cout << "*             *" << endl;
									GotoXY(20, 8);
									cout << "*      O      *" << endl;
									GotoXY(20, 9);
									cout << "*             *" << endl;
									GotoXY(20, 10);
									cout << "*             *" << endl;
									GotoXY(20, 11);
									cout << "***************" << endl;
									sum1k = 1;
									break;

								case 2:  GotoXY(20, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(20, 6);
									cout << "*          0  *" << endl;
									GotoXY(20, 7);
									cout << "*             *" << endl;
									GotoXY(20, 8);
									cout << "*             *" << endl;
									GotoXY(20, 9);
									cout << "*             *" << endl;
									GotoXY(20, 10);
									cout << "*  0          *" << endl;
									GotoXY(20, 11);
									cout << "***************" << endl;
									sum1k = 2;
									break;

								case 3:  GotoXY(20, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(20, 6);
									cout << "*          0  *" << endl;
									GotoXY(20, 7);
									cout << "*             *" << endl;
									GotoXY(20, 8);
									cout << "*      0      *" << endl;
									GotoXY(20, 9);
									cout << "*             *" << endl;
									GotoXY(20, 10);
									cout << "*  0          *" << endl;
									GotoXY(20, 11);
									cout << "***************" << endl;
									sum1k = 3;
									break;

								case 4: GotoXY(20, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(20, 6);
									cout << "*  0       0  *" << endl;
									GotoXY(20, 7);
									cout << "*             *" << endl;
									GotoXY(20, 8);
									cout << "*             *" << endl;
									GotoXY(20, 9);
									cout << "*             *" << endl;
									GotoXY(20, 10);
									cout << "*  0       0  *" << endl;
									GotoXY(20, 11);
									cout << "***************" << endl;
									sum1k = 4;
									break;

								case 5: GotoXY(20, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(20, 6);
									cout << "*  0       0  *" << endl;
									GotoXY(20, 7);
									cout << "*             *" << endl;
									GotoXY(20, 8);
									cout << "*      0      *" << endl;
									GotoXY(20, 9);
									cout << "*             *" << endl;
									GotoXY(20, 10);
									cout << "*  0       0  *" << endl;
									GotoXY(20, 11);
									cout << "***************" << endl;
									sum1k = 5;
									break;

								case 6: GotoXY(20, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(20, 6);
									cout << "*  0       0  *" << endl;
									GotoXY(20, 7);
									cout << "*             *" << endl;
									GotoXY(20, 8);
									cout << "*  0       0  *" << endl;
									GotoXY(20, 9);
									cout << "*             *" << endl;
									GotoXY(20, 10);
									cout << "*  0       0  *" << endl;
									GotoXY(20, 11);
									cout << "***************" << endl;
									sum1k = 6;
									break;
								}
								int b = rand() % 6 + 1;
								switch (b)
								{
								case 1: GotoXY(45, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(45, 6);
									cout << "*             *" << endl;
									GotoXY(45, 7);
									cout << "*             *" << endl;
									GotoXY(45, 8);
									cout << "*      O      *" << endl;
									GotoXY(45, 9);
									cout << "*             *" << endl;
									GotoXY(45, 10);
									cout << "*             *" << endl;
									GotoXY(45, 11);
									cout << "***************" << endl;
									sum2k = 1;
									break;

								case 2:  GotoXY(45, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(45, 6);
									cout << "*          0  *" << endl;
									GotoXY(45, 7);
									cout << "*             *" << endl;
									GotoXY(45, 8);
									cout << "*             *" << endl;
									GotoXY(45, 9);
									cout << "*             *" << endl;
									GotoXY(45, 10);
									cout << "*  0          *" << endl;
									GotoXY(45, 11);
									cout << "***************" << endl;
									sum2k = 2;
									break;

								case 3:  GotoXY(45, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(45, 6);
									cout << "*          0  *" << endl;
									GotoXY(45, 7);
									cout << "*             *" << endl;
									GotoXY(45, 8);
									cout << "*      0      *" << endl;
									GotoXY(45, 9);
									cout << "*             *" << endl;
									GotoXY(45, 10);
									cout << "*  0          *" << endl;
									GotoXY(45, 11);
									cout << "***************" << endl;
									sum2k = 3;
									break;

								case 4:  GotoXY(45, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(45, 6);
									cout << "*  0       0  *" << endl;
									GotoXY(45, 7);
									cout << "*             *" << endl;
									GotoXY(45, 8);
									cout << "*             *" << endl;
									GotoXY(45, 9);
									cout << "*             *" << endl;
									GotoXY(45, 10);
									cout << "*  0       0  *" << endl;
									GotoXY(45, 11);
									cout << "***************" << endl;
									sum2k = 4;
									break;

								case 5:GotoXY(45, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(45, 6);
									cout << "*  0       0  *" << endl;
									GotoXY(45, 7);
									cout << "*             *" << endl;
									GotoXY(45, 8);
									cout << "*      0      *" << endl;
									GotoXY(45, 9);
									cout << "*             *" << endl;
									GotoXY(45, 10);
									cout << "*  0       0  *" << endl;
									GotoXY(45, 11);
									cout << "***************" << endl;
									sum2k = 5;
									break;

								case 6: GotoXY(45, 5);
									SetColor(9, 0);
									cout << "***************" << endl;
									GotoXY(45, 6);
									cout << "*  0       0  *" << endl;
									GotoXY(45, 7);
									cout << "*             *" << endl;
									GotoXY(45, 8);
									cout << "*  0       0  *" << endl;
									GotoXY(45, 9);
									cout << "*             *" << endl;
									GotoXY(45, 10);
									cout << "*  0       0  *" << endl;
									GotoXY(45, 11);
									cout << "***************" << endl;
									sum2k = 6;
									break;
								}
								sumk = sum1k + sum2k;
							}
							numberk++;
							numbersumk += numberk;
							sumSk += sumk;
							GotoXY(20, 15);
							cout << "За " << numberk << " бросок компьютер зарабатывает " << sumk << " очков " << endl;
							GotoXY(25, 16);
							cout << "Всего очков за " << numbersumk << " бросков = " << sumSk << endl;
							numbersumk = 0;
							cout << endl;
							SetColor(1, 0);
							gotoxy(36, 19);
							cout << " Ваш ход " << endl;
							if (numberk == 6)
								break;
					}
			    }
			      else {system("cls");goto m1;}
				  Sleep(1350);
				  goto a1;
			}
			// ***************игра вдвоем, меню №2
			if (k == 2)
				
			{
				cout << "\t\t\t  Введите имя второго игрока  _";
				cin >> name2;
				SetColor(1, 0);
				gotoxy(22, 13);
				cout << " Выберите кто первый начинает игру" << endl;
				SetColor(14, 0);
				gotoxy(4, 16);
				cout << name << endl;
				gotoxy(2, 17);
				cout << "нажмите " << endl;
				//*****************1
				SetColor(1, 0);
				gotoxy(2, 19);
				cout << "   $$" << endl;
				gotoxy(2, 20);
				cout << " $$$$" << endl;
				gotoxy(2, 21);
				cout << "   $$" << endl;
				gotoxy(2, 22);
				cout << "   $$" << endl;
				gotoxy(2, 23);
				cout << "   $$" << endl;
				//****************2
				SetColor(14, 0);
				gotoxy(68, 15);
				cout << name2 << endl;
				gotoxy(66, 16);
				cout << " нажмите" << endl;
				SetColor(1, 0);
				gotoxy(63, 18);
				cout << "      $$$$" << endl;
				gotoxy(63, 19);
				cout << "     $$  $$" << endl;
				gotoxy(63, 20);
				cout << "       $$" << endl;
				gotoxy(63, 21);
				cout << "      $$" << endl;
				gotoxy(63, 22);
				cout << "     $$$$$$" << endl;
				SetColor(14, 0);
				gotoxy(39, 19);
				cin >> coursechoices1;

				// выбираем очередность
				if (coursechoices1 == 1)
					
				{
					for (int i(0); i < 5; i++)
					{
						SetColor(14, 0);
						gotoxy(23, 20);
						cout << name << ", для броска нажмите пробел..." << endl;
						system("pause>>NUL");
						system("cls");
						// бросок человека № 1
						for (int i(0); i <= 10; i++)
						{
							sum3 = 0;
							int a = rand() % 6 + 1;
							switch (a)
							{

							case 1: GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*             *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*      O      *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*             *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum13 = 1;
								break;

							case 2:  GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*          0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*             *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0          *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum13 = 2;
								break;

							case 3:  GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*          0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*      0      *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0          *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum13 = 3;
								break;

							case 4: GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*             *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum13 = 4;
								break;

							case 5: GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*      0      *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum13 = 5;
								break;

							case 6: GotoXY(20, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum13 = 6;
								break;
							}
							int b = rand() % 6 + 1;
							switch (b)
							{
							case 1: GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*             *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*      O      *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*             *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum23 = 1;
								break;

							case 2:  GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*          0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*             *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0          *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum23 = 2;
								break;

							case 3:  GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*          0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*      0      *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0          *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum23 = 3;
								break;

							case 4:  GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*             *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum23 = 4;
								break;

							case 5:GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*      0      *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum23 = 5;
								break;

							case 6: GotoXY(45, 5);
								SetColor(12, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum23 = 6;
								break;

							}
							sum3 = sum13 + sum23;
						}
						number3++;
						numbersum3 += number3;
						sumS3 += sum3;
						SetColor(12, 0);
						GotoXY(20, 1);
						cout << "За " << number3 << " бросок " << name << " зарабатываете " << sum3 << " очков " << endl;
						GotoXY(25, 2);
						cout << "Всего очков за " << numbersum3 << " бросков = " << sumS3 << endl;
						numbersum3 = 0;
						cout << endl;
						SetColor(1, 0);
						gotoxy(36, 19);
						cout << " Ваш ход " << endl;
						if (numberk2 == 5)
							break;
						cout << endl;

						Sleep(1050);

						//********************************** бросок игрок № 2
					m2:
						SetColor(14, 0);
						gotoxy(23, 20);
						cout << name2 << ", для броска нажмите пробел..." << endl;
						system("pause>>NUL");
						system("cls");
						for (int i(0); i <= 10; i++)
						{
							sumk2 = 0;
							int a = rand() % 6 + 1;
							switch (a)
							{
							case 1: GotoXY(20, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*             *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*      O      *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*             *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1k2 = 1;
								break;

							case 2:  GotoXY(20, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*          0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*             *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0          *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1k2 = 2;
								break;

							case 3:  GotoXY(20, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*          0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*      0      *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0          *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1k2 = 3;
								break;

							case 4: GotoXY(20, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*             *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1k2 = 4;
								break;

							case 5: GotoXY(20, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*      0      *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1k2 = 5;
								break;

							case 6: GotoXY(20, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(20, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 7);
								cout << "*             *" << endl;
								GotoXY(20, 8);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 9);
								cout << "*             *" << endl;
								GotoXY(20, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(20, 11);
								cout << "***************" << endl;
								sum1k2 = 6;
								break;
							}
							int b = rand() % 6 + 1;
							switch (b)
							{
							case 1: GotoXY(45, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*             *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*      O      *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*             *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2k2 = 1;
								break;

							case 2:  GotoXY(45, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*          0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*             *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0          *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2k2 = 2;
								break;

							case 3:  GotoXY(45, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*          0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*      0      *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0          *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2k2 = 3;
								break;

							case 4:  GotoXY(45, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*             *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2k2 = 4;
								break;

							case 5:GotoXY(45, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*      0      *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2k2 = 5;
								break;

							case 6: GotoXY(45, 5);
								SetColor(9, 0);
								cout << "***************" << endl;
								GotoXY(45, 6);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 7);
								cout << "*             *" << endl;
								GotoXY(45, 8);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 9);
								cout << "*             *" << endl;
								GotoXY(45, 10);
								cout << "*  0       0  *" << endl;
								GotoXY(45, 11);
								cout << "***************" << endl;
								sum2k2 = 6;
								break;
							}
							sumk2 = sum1k2 + sum2k2;
						}
						numberk2++;
						numbersumk2 += numberk2;
						sumSk2 += sumk2;
						GotoXY(20, 15);
						cout << "За " << numberk2 << " бросок " << name2 << " зарабатываете " << sumk2 << " очков " << endl;
						GotoXY(25, 16);
						cout << "Всего очков за " << numbersumk2 << " бросков = " << sumSk2 << endl;
						numbersumk2 = 0;
						cout << endl;
						SetColor(1, 0);
						gotoxy(36, 19);
						cout << " Ваш ход " << endl;
						if (numberk2 == 6)
							break;
						cout << endl;
					}
				}
				else goto m2;
				Sleep(1350);
				goto a1;
			}
			
			// *******************************правила
			if (k == 3)
				
			{
				   system("cls");
				    gotoxy(11, 10);
					cout << "Правила просты и понятны, попробуйте играть и следуйте указаниям," << endl;
					gotoxy(11, 11);
					cout << "и если вам понравится, то приятный и веселый вечер вам обеспечен." << endl;
					gotoxy(11,12);
					cout << "Удачных бросков Вам и послушных костей!" << endl;
			}
		    //*************************************результаты
			if (k == 4)
			{

				gotoxy(15, 11);
			a1:
				system("cls");
				SetColor(14, 0);
				//********************************* вывод результатов после игры с компом
				if (k == 1)
				{
					cout << "За игру " << name << " зарабатывает " << sumS << " очков " << endl;
					cout << endl;
					cout << "За игру компьютер зарабатывает " << sumSk << " очков " << endl;
					if (sumS > sumSk)
						cout << "Поздравляем " << name << ", он победитель !!!" << endl;
					else if (sumS == sumSk)
						cout << "Ничья..." << endl;
					else if (sumS < sumSk)
						cout << name << " проиграл." << endl;
				}
				//************************ вывод результатов после игры с другим человеком
				if (k == 2)
				{
					cout << "За игру " << name << " зарабатывает " << sumS3 << " очков " << endl;
					cout << endl;
					cout << "За игру " << name2 << " зарабатывает " << sumSk2 << " очков " << endl;
					if (sumS3 > sumSk2)
						cout << "Поздравляем " << name << ", он победитель !!!" << endl;
					else if (sumS3 == sumSk2)
						cout << "Ничья..." << endl;
					else if (sumS3 < sumSk2)
					{cout << name << " проиграл." << endl; cout << name2 << " победитель !!! " << endl;}
				}
				cout << endl;
				cout << "Для возврата в меню нажмите любую клавишу" << endl;
				system("pause>>NUL");
				system("cls");

			}

		}

		gotoxy(38,3);
		SetColor(14, 0);
		cout << "***";
		
		if (k == 1)
		SetColor(1, 0);
		gotoxy(28, 4);
		cout << "В игру играет один игрок " << endl;
		SetColor(14, 0);

		if (k == 2)
		SetColor(1, 0);
		gotoxy(28,5);
		cout << "В игру играет два игрока " << endl;
		SetColor(14, 0);

		if (k == 3)
		SetColor(1, 0);
		gotoxy(36, 6);
		cout << "Правила " << endl;
		SetColor(14, 0);

		if (k == 4)
		SetColor(1, 0);
		gotoxy(34.8, 7);
		cout << "Результаты " << endl;
		SetColor(14, 0);

		if (k == 5)
		SetColor(1, 0);
		gotoxy(37, 8);
		cout << "Выход " << endl;
		SetColor(14, 0);
	} while (en = _getch());

	//getchar();
}

