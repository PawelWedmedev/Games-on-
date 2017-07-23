#include <iostream>
#include <windows.h>
#include <iomanip> 
#include <conio.h>
//#include <ctime>
//#include <string> 

using namespace std;
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor (int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
inline void hello1()
{
	SetColor(12, 0);
	cout << "\t\t\t*********************************" << endl;
	SetColor(15, 0);
	cout << "\t\t\t������������ �������� �������!!!!" << endl;
	SetColor(12, 0);
	cout << "\t\t\t*********************************" << endl;
	SetColor(15, 0);


}
inline void hello2()
{
	cout << endl;
	cout << "\t\t     ������ �������� ������������� 1 �����a :" << endl;
	cout << endl;
	cout << endl;
	cout << " -������ 1 " << endl;
	SetColor(14, 0);
	cout << "\t��� �������� � ��������� �������� ������� 1..." << endl;
	SetColor(15, 0);
	cout << endl;
	/*cout << " - ������ 2 " << endl;
	SetColor(14, 0);
	cout << "\t��� �������� � ��������� �������� ������� 2..." << endl;
	SetColor(15, 0);
	cout << endl;
	cout << " - ������ 3" << endl;
	SetColor(14, 0);
	cout << "\t��� �������� � ��������� �������� ������� 3..." << endl;
	SetColor(15, 0);
	cout << endl;*/
	/*cout << " -������ 4 " << endl;
	SetColor(14, 0);
	cout << "\t��� �������� � ��������� �������� ������� 4..." << endl;
	SetColor(15, 0);
	cout << endl;
	cout << " ������ 5 " << endl;
	SetColor(14, 0);
	cout << "\t��� �������� � ��������� �������� ������� 5..." << endl;
	SetColor(15, 0);*/
}


// ������� �������� ����� ���������� �������
int ins(int n, bool x2)
{
	do {
		cin >> n;
		if (n < 3)
		{cout << "������� ������ ���� �� ����� 3 !!!" << endl; x2 = false;}
		else x2 =true;
			
	} while (x2 == false);

	return n;
}
// ������� �������� ����� ���������� ���
int ins1(int n, bool x2)
 {

	 do {
		 cin >> n;
		 if (n > 10)
		 { cout << "��� ������ ���� �� ������ 10 !!!" << endl; x2 = false;}
		 else x2 = true;
			 
	 } while (x2 == false);

	 return n;
 }
// ������� ������������� �������� ������� �� ������� � ���������
int rec(int n, int &pb5, int &pb3)
{
	if (n>=3 && n <=12 && n%3==0 ||n==0||n<0)
	   return 0;
	   pb5++;
		rec(n - 5, pb5, pb3);

		if ((n-5) % 3 == 0 && (n-5)>=3&&(n-5)<=12)
		{
			pb3 =n-5;
			pb3 /= 3;
		}		
}
// ������� ��� ����� ������� ������ 12 ��
inline void number_3_to_12(int n, int &pb5, int &pb3)
{
	switch (n)
	{
	case 3:pb5 = 0; pb3 = 1; break;
	case 4:pb5 = 0; pb3 = 1; cout << "���� ����� ������ " << endl; break;
	case 5:pb5 = 1; pb3 = 0; break;
	case 6:pb5 = 0; pb3 = 2; break;
	case 7:pb5 = 0; pb3 = 2; cout << "���� ����� ������ " << endl; break;
	case 8:pb5 = 1; pb3 = 1; break;
	case 9:pb5 = 0; pb3 = 3; break;
	case 10:pb5 = 2; pb3 = 0; break;
	case 11:pb5 = 1; pb3 = 2; break;
	case 12:pb5 = 0; pb3 = 4; break;

	}

}
// ������� ������������� �������� ������� �� ������� � ������
void troth(int n, int &pb5, int &pb3)
{
	for (int i(n); i > 0; i--)
	{
		if (n == 0)
			break;
		n -= 5;
		pb5++;
		if (n >= 3 && n <= 12 && n % 3 == 0)
			for (int j(n); j <= 12; j++)
			{
				n += 5;
				pb3++;
				if ((n - 5) % 3 == 0 && (n - 5) >= 3 && (n - 5) <= 12)
				{
					pb3 = n - 5;
					pb3 /= 3;
					n = 0;
					break;
				}
			}
	}
}
// ������� �������� ��� ������ ����� ������� ������ 12
void sum_year__less12(int n, int year, int sumyear, int &pb5, int &pb3,int *arr)
{
	int all_robots = n;
	int written_off = n;
	number_3_to_12(n, pb5, pb3);

		for (int i(0); i < year; i++)
		{
			sumyear = pb5 * 9 + pb3 * 5;
			*(arr + i) = sumyear;
			if (i == 0 || i == 1)
			{all_robots += sumyear; written_off =0;}
			else if (i == 2)
			{all_robots += sumyear - n; written_off = n;}
			else if (i >= 3)
			{all_robots += sumyear - *(arr + (i - 3));written_off = *(arr + (i - 3));}
			cout << endl;
			cout << "�� " << i + 1 << "� ��� ������� - " << sumyear << " ������� " << endl;
			cout << "\t  ������� - " << written_off << " ������� " << endl;
			cout<< "��������: " << pb5 << " ������  �� 5 ������� "<<endl <<"\t  "<< pb3 << " ������� �� 3 ������" << endl;
			
			cout << endl;
			pb5 = 0; pb3 = 0;
			if( all_robots<=12)
				number_3_to_12(all_robots, pb5, pb3);
			else if(all_robots> 12)
				troth(all_robots, pb5, pb3);
		}
	}
// ������� �������� ��� ������ ����� ������� ������ 12
void sum_year__more12(int n, int year, int sumyear, int &pb5, int &pb3, int *arr)
{
	int all_robots = n;
	int written_off = n;
	rec(n, pb5, pb3);

		for (int i(0); i < year; i++)
		{
			sumyear = pb5 * 9 + pb3 * 5;
			*(arr + i) = sumyear;
			if (i == 0 || i == 1)
			{all_robots += sumyear; written_off = 0;}
			else if (i == 2)
			{all_robots += sumyear - n; written_off = n;}
			else if (i >= 3)
			{all_robots += sumyear - *(arr + (i - 3)); written_off = *(arr + (i - 3));}
			cout << endl;
			cout << "�� " << i + 1 << "� ��� ������� - " << sumyear << " ������� " << endl;
			cout << "\t  ������� - " << written_off << " ������� " << endl;
			cout << "��������: " << pb5 << " ������  �� 5 ������� " << endl << "\t  " << pb3 << " ������� �� 3 ������" << endl;

			cout << endl;
			pb5 = 0; pb3 = 0;
			troth(all_robots, pb5, pb3);
		}
	}
	
	








 void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
    /*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	char key;
	hello1();
m1:
	hello2();
	cout << endl;
	do
	{
		cin >> key;
		switch (key)
		{
	//  ***********************************************************************
		case '1':
		system("cls");
		{ 
			char a;
			do {
				cout << endl;
				SetColor(5, 0);
				cout << "*****************************************************" << endl;
				SetColor(15, 0);
				cout << endl;
               // <<������ ������>>(��������� ����)
				char arr10000[1000] = { "������ � ��������� �������. �����������, ��� �� ������� ������� ������ ����������� ������� � N (������ 3) ������� ��� ������������. ������ ������ ������, ��� �������� ������� ������ ������ ��� �������� ����� ���� ��������, � ����� ��� ���� ������������ ����� ��������� �� ��������. ������ ��� ��� ������� ������ �� ������� ������������ � ������ �� 3 � �� 5 �������, ����� ������� �����. ��� ���� ������ �� 3 ������� �������� 5 �����, � �� 5 - 9 �����. �������� �� ������ ������������ � ������ ����, ��� ����� ������� ������������ ���������� ����� �������. ����� ��������, ������� ������� ������� ����� �� ������� ����� � (����� 10) ���? �������� ��������� ���������� �� ������� ����.) " };

				cout << arr10000 << endl;

				int n=0, sumyear=0;
				int year = 0;
				bool cheng_robots=true,cheng_year = true;
				int b5 = 0;
				int &pb5 = b5;
				int b3 = 0;
				int &pb3 = b3;
				const int size = 10;
				int arr[size] = { 0 };
				cout << endl;
				SetColor(2, 0);
				cout << "������� ��������� ������� ( �� ����� 3 ) _  ";
				n=ins(n, cheng_robots);
				cout << endl;
			    cout << "������� ���������� ��� ( �� ����� 10)  _ ";
				year = ins1(n, cheng_year);
				cout << endl;
				SetColor(15, 0);
				if (n <= 12)
					sum_year__less12(n, year, sumyear, b5, b3, arr);
				if (n>12)
				sum_year__more12(n, year, sumyear, b5, b3, arr);
				
				 cout << endl;
				//<<����� ������>> (����)
				SetColor(5, 0);
				cout << "*****************************************************" << endl;
				SetColor(15, 0);
				cout << endl;
				cout.fill('.');
				cout << "���� �� ������ ������ ������ �������� � ��� ������ �������" << setw(15) << " \"Y\" " << endl;
				cout << endl;
				cout << "��� ������ � ��������� �������" << setw(47) << "\"eny key\"" << endl;
				cout << endl;
				cout << "��� �������� � ������� ���� �������" << setw(37) << "\"0\"" << endl;
				cin >> a;
				system("cls");
			} while ((a == 'Y') || (a == 'y'));
			if (a == '0')
				goto m1;
			else if (a != 'Y' || a != 'y')
			{
				cout << "�� �������� !!!" << endl; goto m2;
			}
		}break;
	//	***********************************************************************
		case '2':
		 { system("cls");
		char a;
		do {
			cout << endl;
			SetColor(5, 0);
			cout << "*****************************************************" << endl;
			SetColor(15, 0);
            // <<������ ������>>(��������� ����)
			char arr1000[1000] = { "" };
			cout << arr1000 << endl;
			cout << endl;
			
			/*int n;
			int b5=0;
			int &pb5 = b5;
			int b3=0;
			int &pb3 = b3;
			cin >> n;
			if (n > 12)
			{
				troth(n, b5, b3);
				cout << b5 << " " << b3 << endl;
			}
			if (n <= 12)
			{
				number_3_to_12(n, b5, b3);
				cout << b5 << " " << b3 << endl;
			}*/
			
				

			cout << endl;
			//<<����� ������>> (����)
			SetColor(5, 0);
			cout << "*****************************************************" << endl;
			SetColor(15, 0);
			cout << endl;
			cout.fill('.');
			cout << "���� �� ������ ������ ������ �������� � ��� ������ �������" << setw(15) << " \"Y\" " << endl;
			cout << endl;
			cout << "��� ������ � ��������� �������" << setw(47) << "\"eny key\"" << endl;
			cout << endl;
			cout << "��� �������� � ������� ���� �������" << setw(37) << "\"0\"" << endl;
			cin >> a;
			system("cls");
		} while ((a == 'Y') || (a == 'y'));
		if (a == '0')
			goto m1;
		else if (a != 'Y' || a != 'y')
		{
			cout << "�� �������� !!!" << endl; goto m2;
		}
		}break;
		//**********************************************************************
		case '3':
		{system("cls");
			char a;
			do {
				cout << endl;
				SetColor(5, 0);
				cout << "*****************************************************" << endl;
				SetColor(15, 0);
				//<<������ ������>>(��������� ����)
				char arr100[1000] = { "" };
				cout << arr100 << endl;
				
				

				//<<����� ������>> (����)
				SetColor(5, 0);
				cout << "*****************************************************" << endl;
				SetColor(15, 0);
				cout << endl;
				cout.fill('.');
				cout << "���� �� ������ ������ ������ �������� � ��� ������ �������" << setw(15) << " \"Y\" " << endl;
				cout << endl;
				cout << "��� ������ � ��������� �������" << setw(47) << "\"eny key\"" << endl;
				cout << endl;
				cout << "��� �������� � ������� ���� �������" << setw(37) << "\"0\"" << endl;
				cin >> a;
				system("cls");
			} while ((a == 'Y') || (a == 'y'));
			if (a == '0')
			goto m1; 
			else if (a != 'Y' || a != 'y')
			{
				cout << "�� �������� !!!" << endl; goto m2;
			}
		}break;
	//	************************************************************************
		case '4':
		{ system("cls");
			char a;
			do {
				cout << endl;
				SetColor(5, 0);
				cout << "*****************************************************" << endl;
				SetColor(15, 0);
                //<<������ ������>>(��������� ����)
				char arr1[1000] = { " " };

				cout << arr1 << endl;
				
			
				cout << endl;
				//<<����� ������>> (����)
				SetColor(5, 0);
				cout << "*****************************************************" << endl;
				SetColor(15, 0);
				cout << endl;
				cout.fill('.');
				cout << "���� �� ������ ������ ������ �������� � ��� ������ �������" << setw(15) << " \"Y\" " << endl;
				cout << endl;
				cout << "��� ������ � ��������� �������" << setw(47) << "\"eny key\"" << endl;
				cout << endl;
				cout << "��� �������� � ������� ���� �������" << setw(37) << "\"0\"" << endl;
				cin >> a;
				system("cls");
			} while ((a == 'Y') || (a == 'y'));
			if (a == '0')
				goto m1;
			else if (a != 'Y' || a != 'y')
			{
				cout << "�� �������� !!!" << endl; goto m2;
			}
		}break;
	//  ************************************************************************
		case '5':
		{ system ("cls");
			char a;
			do {
				cout << endl;
				SetColor(5, 0);
				cout << "*****************************************************" << endl;
				SetColor(15, 0);
              //  <<������ ������>>(��������� ����)

				char arr1[1000] = { " " };

				cout << arr1 << endl;




				
		
				cout << endl << endl;
		
			//	<<����� ������>> (����)
				SetColor(5, 0);
				cout << "*****************************************************" << endl;
				SetColor(15, 0);
				cout << endl;
				cout.fill('.');
				cout << "���� �� ������ ������ ������ �������� � ��� ������ �������" << setw(15) << " \"Y\" " << endl;
				cout << endl;
				cout << "��� ������ � ��������� �������" << setw(47) << "\"eny key\"" << endl;
				cout << endl;
				cout << "��� �������� � ������� ���� �������" << setw(37) << "\"0\"" << endl;
				cin >> a;
				system("cls");
			} while ((a == 'Y') || (a == 'y'));
			if (a == '0')
				goto m1;
			else if (a != 'Y' || a != 'y')
			{
				cout << "�� �������� !!!" << endl; goto m2;
			}
		}break;
		default: cout << "\a" << "... � ���� ��� �� ���������� ������� ������������ ������� :)\n, �� ���-���� �������� ������� �� 1 �� 5 !!!" << endl; break;
		}
	} while (key != '1' || key != '2' || key != '3' || key != '4' || key != '5');

m2:
//***************************************************************************
getchar();
}
