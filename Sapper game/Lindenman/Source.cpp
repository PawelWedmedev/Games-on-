#include <iostream>
#include <windows.h>
#include <iomanip> 
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;
enum ConsoleColor {Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White};
void SetColor(int text, int background)
{HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));}
//******************************//



struct players
{
	char name[30];
	short score;
};

void sort(players *arrp, short sizep)
{
	int x, k;
	for (int i(0); i < sizep; i++)
	{
		k = i;
		x = arrp[i].score;
		for (int j(i + 1); j < sizep; j++)
		{
			if (arrp[j].score > x)
			{
				k = j;
				x = arrp[j].score;
			}
		}
		swap(arrp[i], arrp[k]);
	}
}

void print_plgame(players *arrp, short sizep,char *np)
{
	FILE *f3 = fopen("Score.txt", "w");
	if (!f3) cout << "Нет такого!!!";
	fprintf(f3, "%c\t%s\t %s\n", '№',"Имя","Кол очков");
	fclose(f3);
	cout << endl << endl;
	SetColor(10, 0);cout << "\t\t\t\t №\tИмя \t   Кол очков\n\n"; SetColor(15, 0);
	for (int i(0); i < sizep; i++)
	{
		if (strstr(arrp[i].name, np))
			continue;
		else arrp[i].score = rand() % 200;
	}
	f3 = fopen("Score.txt", "a");
	sort(arrp, sizep);
	for (int i(0); i < sizep; i++)
	{fprintf(f3,"%-5d %-15s %-100d\n", (i + 1), arrp[i].name, arrp[i].score);
		printf("\t\t\t\t %-5d %-15s %-100d\n", (i + 1), arrp[i].name, arrp[i].score);
	}
	cout << endl << endl;
	fclose(f3);
}

void creat_arr(float **arr,int coll,int row,short &qm)
{
	short k=0;
	short s;
	for (int i(0); i < row; i++)
	{
		*(arr + i) = new float[coll];
		if (!arr)exit(0);
		for (int j(0); j < coll; j++)
		{
			if(k != qm)
			*(*(arr + i) + j) = rand() % 2;
			else *(*(arr + i) + j) = 1;
			if (*(*(arr + i) + j) == 0)
				k++;
		}
	}
	if (k != qm)
		creat_arr(arr, coll, row, qm);

	for (int i(0); i < row; i++)
	{
		for (int j(0); j < coll; j++)
		{
			if ((i != row-1 && i!=0)&&(j != coll - 1&&j!=0))
			{
		     	s = rand() % 3-1;
				swap(*(*(arr + i+s) + j+s), *(*(arr + i - s) + j-s));
			}
		}
	}
}

void rec(float **arr, int coll, int row, FILE *&f,bool recs)
{
	if (recs == 1)
	{
		f = fopen("Playing_field.txt", "w");
		if (!f) cout << "Файл не открылся ...\n";
		fprintf(f, "Исходная расстановка игрового поля\n\n ");
	}
	if (recs == 0)
	{
		f = fopen("Playing_field.txt", "a");
		if (!f) cout << "Файл не открылся ...\n";
		fprintf(f, "Конечное поле \n\n ");
	}
	fprintf(f, " \t\t\t");
	for (int i(0); i < row; i++)
	{
		for (int j(0); j < coll; j++)
		{
			if (*(*(arr + i) + j) == 0)
				fprintf(f, "%s", "[x]");
			if (*(*(arr + i) + j) == 1|| *(*(arr + i) + j)==9|| *(*(arr + i) + j)==8|| *(*(arr + i) + j)==7|| *(*(arr + i) + j)==6|| *(*(arr + i) + j)==5|| *(*(arr + i) + j)==4|| * (*(arr + i) + j)==3|| * (*(arr + i) + j)==2|| *(*(arr + i) + j)==(float)0.1|| *(*(arr + i) + j)==(float)1.1)
				fprintf(f, "%s", "[ ]");
			if (j == coll - 1)
				fprintf(f, "\n");
		}
		fprintf(f, " \t\t\t");
	}
	fprintf(f, "\n");
	fclose(f);
}

void skan(float **arr, int coll, int row, FILE *&f)
{
	f = fopen("Playing_field.txt", "r");
	if (!f) cout << "Файл не открылся ...\n";
	FILE *f1 = fopen("Playing_field1.txt", "w");
	if (!f1) cout << "Файл не открылся ...\n";
	char *str;
	char text[300];
	do {
		str = fgets(text, sizeof(text), f);
		cout << text;
		fprintf(f1, "%s", text);
	} while (!feof(f));
	printf("%s\n", text);
	fclose(f);
	fclose(f1);
}

void print_mines(float **arr, int coll, int row,int &indexX,int &indexY)
{
	for (int i(0); i < row; i++)
	{
		cout << "\n ";
		cout << "\t\t\t\t ";
			for (int j(0); j < coll; j++)
			{
				SetColor(7, 9);
				cout << "|";
				SetColor(15, 0); 
				if (indexX == i&&indexY == j)
				{
					SetColor(6, 0); cout << *(*(arr + i) + j) << " "; SetColor(15, 0);
				}
				else cout << *(*(arr + i) + j) << " "; 
		    }
			SetColor(7, 9); cout << "|"; SetColor(15, 0);
		cout<< endl;
	}
}

short points(float **arr, int coll, int row, int indexX, int indexY,short &sumballs,short &k, short &balls,bool &bam)
{
	if(k<5) balls=5;
	if (k >= 5 && k < 10) balls = 10;
	if (k > 10) balls = 15;
	for (int i(0); i < row; i++)
	{
		for (int j(0); j < coll; j++)
		{
			if (indexX == i&&indexY == j) 
			{
				if ((*(*(arr + i) + j) == (float) 0.1 || *(*(arr + i) + j) == (float) 1.1 || *(*(arr + i) + j) == 2 || *(*(arr + i) + j) == 3 || *(*(arr + i) + j) == 4 || *(*(arr + i) + j) == 5 || *(*(arr + i) + j) == 6 || *(*(arr + i) + j) == 7 || *(*(arr + i) + j) == 8) && bam == false)
			   {
					k++;
				sumballs=balls;
				return sumballs;
			   }
			   
				if (*(*(arr + i) + j) == 9 && bam == false)
				{
					sumballs=-5;
					return sumballs;
				}
				if (bam == true)  return 0;
			}
		}
	}
}

short vin(float **arr, int row, int coll, short x)
{
	for (int i(0); i < row; i++)
	{
		for (int j(0); j < coll; j++)
		{
			if (*(*(arr + i) + j) != 1)
				x--;
		}
	}
	return x;	
}

void stat(float **arr, int X, int Y, bool &bam, short res,short &gm,int row,int coll,bool &nprint,short &balls,short x,FILE *&f)   
{
	if (*(*(arr + X) + Y) == 9 && bam == false)
	{
		gm--;
		if (gm >= 0)
		{
			cout << "\n";
			SetColor(2, 0);	cout << "\t\t\t\aБомба!!! Осторожно!!! у вас осталось " << gm; 
			switch (gm)
			{case 2:cout << " жизни!!!"; break; case 1: cout << " жизнь!!!"; break; case 0: cout << " жизней!!!"; break;}
			SetColor(15, 0);
		}
		
		if (gm < 0)
		{
			rec(arr, coll, row, f, 0);
			nprint = false;
			system("cls");
			if(gm<0)
		    SetColor(10, 0);cout << "\t\t\t\t\tGame over!!!\n\n"; SetColor(14, 0);
			skan(arr, coll, row, f);
			SetColor(15, 0);
		}
		bam = true; 
	}

	if( (*(*(arr + X) + Y) == (float) 0.1 || *(*(arr + X) + Y) == (float) 1.1 || *(*(arr + X) + Y) == 2 || *(*(arr + X) + Y) == 3 || *(*(arr + X) + Y) == 4 || *(*(arr + X) + Y) == 5 || *(*(arr + X) + Y) == 6 || *(*(arr + X) + Y) == 7 || *(*(arr + X) + Y) == 8) && bam == false)
	{
		SetColor(2, 0);
		cout << "\n";
		cout << "\t\t\t  Отлично!!! Вы зарабатываете " << balls << " балов";
		bam = true;
		SetColor(15, 0);
	}

	if (gm >= 0 && vin(arr, row, coll, x) == 0)
	{
		rec(arr, coll, row, f, 0);
		nprint = false;
		system("cls");
		SetColor(10,0);	cout << "\t\t\t\tПоздравляем, Вы выиграли!!!!\n\n"; SetColor(14, 0);
		skan(arr, coll, row, f);
	}   SetColor(15, 0);
}

void print_field(float **arr, int coll, int row, int indexX, int indexY, bool &bam, short res, short &gm, bool &nprint,short &balls,short&sr,short x,FILE *&f,short &lawel)
{
	cout << "\n";
	sr += res;
	SetColor(10, 0);	cout << "\t\t\t\t   Всего " << sr << " очков!!!"; SetColor(15, 0);
	if(sr==145)
	lawel =sr;
	cout << "\n";
		if(nprint==false)
		stat(arr, indexX, indexY, bam, res, gm, row, coll, nprint,balls,x,f);
		cout << "\n";
			for (int i(0); i < row; i++)
			{
				cout << "\n";
				cout << "\t\t\t\t ";
				for (int j(0); j < coll; j++)
				{
					SetColor(0, 9);
					cout << "|";
					SetColor(15, 0);
					if ((indexX == i&&indexY == j) && bam == true)
					{
						SetColor(12, 0); cout << (int) *(*(arr + i) + j) << "  "; SetColor(15, 0);
					}
					else {
						// если попадаем в пустоту
						if (*(*(arr + i) + j) == (float)0.1 || *(*(arr + i) + j) == (float)1.1 || *(*(arr + i) + j) == 2 || *(*(arr + i) + j) == 3 || *(*(arr + i) + j) == 4 || *(*(arr + i) + j) == 5 || *(*(arr + i) + j) == 6 || *(*(arr + i) + j) == 7 || *(*(arr + i) + j) == 8)
						{
							SetColor(15, 0); cout << "[" << (int)*(*(arr + i) + j) << "]"; SetColor(15, 0);
						}
						if (*(*(arr + i) + j) == (float) 0.1 || *(*(arr + i) + j) == (float)1.1 || *(*(arr + i) + j) == 2 || *(*(arr + i) + j) == 3 || *(*(arr + i) + j) == 4 || *(*(arr + i) + j) == 5 || *(*(arr + i) + j) == 6 || *(*(arr + i) + j) == 7 || *(*(arr + i) + j) == 8) continue;

						if (*(*(arr + i) + j) == 9)// если попадаем в бомбу
						{
							SetColor(15, 0); cout << "[!]"; SetColor(15, 0);
						}
						if (*(*(arr + i) + j) == 9) continue;
						SetColor(14, 14); cout << (int)*(*(arr + i) + j) << "  "; SetColor(15, 0);// цвет основного поля 	
					}
				}
				SetColor(7, 9); cout << "|"; SetColor(15, 0);
				cout << endl;
			}			
}

void chort (float **arr, int coll, int row, int indexX, int indexY,bool &bam)
{
	bool temp;
	short numbom = 0;
	for (int i(0); i < row; i++)
	{
		for (int j(0); j < coll; j++)
		{
			if (indexX == i&&indexY == j)
			{
				if (*(*(arr + i) + j) == 1)//мимо
				{
					if (i==0 && (j <= row-1||j==0))// ...........................верхний ряд
					{
						bam = false;
						if (*(*(arr + i + 1) + j) == 0)
							numbom++;
						if (*(*(arr + i) + j + 1) == 0)
							numbom++;
						if (*(*(arr + i) + j - 1) == 0)
							numbom++;
						if (*(*(arr + i + 1) + j - 1) == 0)
							numbom++;
						if (*(*(arr + i + 1) + j + 1) == 0)
							numbom++;

						if (numbom==1)
							*(*(arr + i) + j) = 1.1;
						else if (numbom == 0)
						{
							*(*(arr + i) + j) = 0.1;
							numbom = 1;
						}
						else
						*(*(arr + i) + j) = numbom;
						temp = false;
					}
					if (i >= row - 1 && j != coll - 1)//...................нижний ряд
					{
						bam = false;
						if (*(*(arr + i) + j + 1) == 0)
							numbom++;
						if (*(*(arr + i - 1) + j) == 0)//
							numbom++;
						if (*(*(arr + i) + j - 1) == 0)
							numbom++;
						if (*(*(arr + i - 1) + j + 1) == 0)//
							numbom++;
						if (*(*(arr + i - 1) + j - 1) == 0)//
							numbom++;

						if (numbom == 1)
							*(*(arr + i) + j) = 1.1;
						else if (numbom == 0)
						{
						*(*(arr + i) + j) = 0.1;
						numbom = 1;
				     	}
						else
						*(*(arr + i) + j) = numbom;
						temp = false;
					}
						if (numbom != 0 && temp == false) break;

						if (i == coll - 1 && j == row - 1) // ...............крайняя правая точка
						{
							bam = false;
							if (*(*(arr + i - 1) + j - 1) == 0)
								numbom++;
							if (*(*(arr + i - 1) + j) == 0)
								numbom++;
							if (*(*(arr + i) + j - 1) == 0)
								numbom++;

							if (numbom == 1)
								*(*(arr + i) + j) = 1.1;
							else if (numbom == 0)
							{
								*(*(arr + i) + j) = 0.1;
								numbom = 1;
							}
							else
								*(*(arr + i) + j) = numbom;
							temp = false;

						}
						if (numbom != 0 && temp == false) break;

						if ((i>0)||(j>=0&&j<row-1))// .............................. середина
						{
							bam = false;
							if (*(*(arr + i + 1) + j) == 0)
								numbom++;
							if (*(*(arr + i) + j + 1) == 0)
								numbom++;
							if (*(*(arr + i - 1) + j + 1) == 0)//
								numbom++;
							if (*(*(arr + i + 1) + j - 1) == 0)
								numbom++;
							if (*(*(arr + i + 1) + j + 1) == 0)
								numbom++;
							if (*(*(arr + i - 1) + j - 1) == 0)// +
								numbom++;
							if (*(*(arr + i - 1) + j) == 0)//+
								numbom++;
							if (*(*(arr + i) + j - 1) == 0)//+
								numbom++;

							if (numbom == 1)
								*(*(arr + i) + j) = 1.1;
							else if (numbom == 0)
							{
								*(*(arr + i) + j) = 0.1;
								numbom = 1;
							}
							else
							*(*(arr + i) + j) = numbom;
						}
				}
				if (*(*(arr + i) + j) == 0)//бомба
				{*(*(arr + i) + j) = 9; bam = false;}
			}
		}
	}	
}

void del_arr(float **arr, int row)
{
	for (int i(0); i <row; i++)
		delete[] * (arr + i);
	delete[]arr;
	arr = nullptr;
}
	
char inspection()
{
	char cheng;
	do {
		cin >> cheng;
		if ((cheng == '1') || (cheng == '2') || (cheng == '3') || (cheng == '4') || (cheng == '5')|| (cheng == '6'))
			break;
		else cout << "Сделайте правильный выбор !" << endl;
	} while ((cheng != '1') || (cheng != '2') || (cheng != '3') || (cheng != '4') || (cheng != '5')||(cheng == '6'));
	return cheng;
}

void skanrules( FILE *&f, bool scan)
{
	if (scan == true)
	{
		f = fopen("Obigre.txt", "r");
		if (!f) cout << "Файл не открылся ...\n";
	}
	else {
		f = fopen("Pravila.txt", "r");
		if (!f) cout << "Файл не открылся ...\n";
	}
	char *str;
	char text[1000];
	do {
		str = fgets(text, sizeof(text), f);
		cout << text;
	} while (!feof(f));
	fclose(f);
}


void main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	FILE *f; FILE *f4; FILE *f5;
	int key = 0, indexX = 0, indexY = 0;
	bool bam = true;//переменная печати(не печати) поля бомб после попадания
	bool nprint = true;// переменная не печати поля при game ower
	short sumballs = 0;// переменная общего количества баллов
	short gm = 2;//переменная количества попаданий на бомбу
	short balls = 0;// переменная начисления баллов в зависмости от открытых ячеек
	short res = 0;// переменная результата очков
	short sumres = 0;//переменная суммы очков
	short k = 0; // счетчик ходов
	bool recs = true;// переменная записи\дозаписи игрового поля
	short lawel = 0;// переменная второго уровня игры с настройками ==145!
	bool scan = true;//переменная для вставки текста из файла правила игры\об игре
	players n1, n2, n3, n4, n5, n6, n7;
	const short sizep = 7;
	n1 = { "Винни Пух",0 };
	n2 = { "Ослик Иа",0 };
	n3 = { "Пятачок",0 };
	n4 = { "Сова",0 };
	n5 = { "Кролик",0 };
	n6 = { "Тигра",0 };
	n7 = { "",0 };
	char np[30];
	cout << "\n\n\n\n\n\n\t\t\t\t\t Введите ваше имя_ ";
	cin.getline(np, 30);
	strcpy(n7.name, np);
	cout << endl;
	int keyses = 0, index = 0;
	const int sizees = 5;
	char * menu[sizees] = { "Правила","Играть","Рекорды","Об игре","Выход" };
m1:
	n7.score = sumres;
	players arrp[sizep] = { n1,n2,n3,n4,n5,n6,n7 };
	if (nprint == true)
	sumres = 0;
	for (; keyses != 27;)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n";
		for (int i = 0; i < sizees; i++)
		{
			if (index == i)
			{SetColor(2, 0);cout << "\t\t\t\t\t  " << menu[i] << "\n"; SetColor(15, 0);}
			else
			{SetColor(7, 0);cout << "\t\t\t\t\t  " << menu[i] << "\n"; SetColor(15, 0);}
		}
		keyses = _getch();
		if (keyses == 224 || keyses == 0)
			keyses = _getch();
		switch (keyses)
		{
		case 72:
		    if (index > 0) index--;
			else index = sizees - 1;
			break;
		case 80:
			if (index < sizees - 1) index++;
			else index = 0;
			break;
		case 13:
			switch (index)
			{
			case 0: system("cls"); skanrules(f4, 0); system("pause >> NUL"); break;//**************  Правила
			case 1: // ****************************************************************************  Игра
			{
		    int keyses = 0, index = 0;
			const int sizees = 2;
			char * menu[sizees] = { "Фиксированное поле 5Х5 и 10 мин ","Выбрать размеры поля и количество мин" };
			for (; keyses != 27;)
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n";
				for (int i = 0; i < sizees; i++)
				{
					if (index == i)
					{SetColor(2, 0);	cout << "\t\t\t\t " << menu[i] << "\n"; SetColor(15, 0);}
					else{SetColor(7, 0);	cout << "\t\t\t\t " << menu[i] << "\n"; SetColor(15, 0);}
				}
				keyses = _getch();
				if (keyses == 224 || keyses == 0)
					keyses = _getch();
				switch (keyses)
				{
				case 72:
					if (index > 0) index--;
					else index = sizees - 1;
					break;
				case 80:
					if (index < sizees - 1) index++;
					else index = 0;
					break;
				case 13:
					switch (index)
					{
					case 0: //*********************игра*************5Х5
					{
						int coll = 5;
						int row = 5;
						short qm = 10;// количество бомб в функции расстановки для фиксированного варианта
						short x = row*coll;// переменная победы при открытии всех пустых клеточек
						float **arr = new float*[row];
						if (!arr)exit(0);
						creat_arr(arr, coll, row, qm);
						rec(arr, coll, row, f, 1);
						for (; key != 27;)
						{
							system("cls");
							if (nprint == true)
								print_field(arr, coll, row, indexX, indexY, bam, res, gm, nprint, balls, sumres, x, f, lawel);
							else { nprint = true; gm = 2; sumballs = 0; k = 0; indexX = 0, indexY = 0; del_arr(arr, row); goto m1; }
							res = 0;
							cout << endl;
							stat(arr, indexX, indexY, bam, res, gm, row, coll, nprint, balls, x, f);
							//*******
							cout << endl;
							//	print_mines(arr, coll, row, indexX, indexY);
							if (nprint == true)
							{
								cout << "Координаты курсора\n";
								cout << " X=" << indexX << endl;
								cout << " Y=" << indexY << endl;
							}
							//*******
							key = _getch();
							if (key == 224 || key == 0)
								key = _getch();
							switch (key)
							{
							case 72: if (indexX > 0) // **********************вверх
								indexX--;
									 else indexX = row - 1;
									 break;
							case 80: if (indexX < row - 1) // ****************вниз
								indexX++;
									 else indexX = 0;
									 break;
							case 75: if (indexY > 0) // *********************влево
								indexY--;
									 else indexY = coll - 1;
									 break;
							case 77: if (indexY < coll - 1) // **************вправо
								indexY++;
									 else indexY = 0;
									 break;
							case 13:
								chort(arr, coll, row, indexX, indexY, bam);
								res = points(arr, coll, row, indexX, indexY, sumballs, k, balls, bam);
								break;
							}
						}
					}
					break;
					//keyses = 27; break;
					case 1://*******************************castom настройки
					{
						system("cls");
						if (lawel == 145)
						{
							int coll;
							int row;
							short qm; // количество бомб
							SetColor(2, 0);
							cout << "\n\n\n\n\n";
							cout << "\t\t\t\tПоле 7Х8   и  20 бомб  - нажмите _  1\n";
							cout << "\t\t\t\tПоле 9Х7   и  35 бомб  - нажмите _  2\n";
							cout << "\t\t\t\tПоле 10Х9  и  50 бомб  - нажмите _  3\n";
							cout << "\t\t\t\tПоле 12Х12 и  80 бомб  - нажмите _  4\n";
							cout << "\t\t\t\tПоле 13Х13 и  100 бомб - нажмите _  5\n";
							cout << "\t\t\t\tПоле 13Х2  и  13 бомб  - нажмите _  6\n";
							SetColor(15, 0);
							switch (inspection())
							{
							case '1': row = 7; coll = 8; qm = 20; break;
							case '2': row = 9; coll = 7; qm = 35; break;
							case '3': row = 10; coll = 9; qm = 50; break;
							case '4': row = 12; coll = 12; qm = 80; break;
							case '5': row = 13; coll = 13; qm = 100; break;
							case '6': row = 13; coll = 2; qm = 13; break;
							}
							short x = row*coll; // переменная победы при открытии всех пустых клеточек
							float **arr = new float*[row];
							if (!arr)exit(0);
							creat_arr(arr, coll, row, qm);
							rec(arr, coll, row, f, 1);
							for (; key != 27;)
							{
								system("cls");
								if (nprint == true)
									print_field(arr, coll, row, indexX, indexY, bam, res, gm, nprint, balls, sumres, x, f, lawel);
								else { nprint = true; gm = 2; sumballs = 0; k = 0; indexX = 0, indexY = 0; del_arr(arr, row); goto m1; }
								res = 0;

								cout << endl;
								stat(arr, indexX, indexY, bam, res, gm, row, coll, nprint, balls, x, f);
								//*******
								cout << endl;
								//	print_mines(arr, coll, row, indexX, indexY);
								if (nprint == true)
								{
									cout << "Координаты курсора\n";
									cout << " X=" << indexX << endl;
									cout << " Y=" << indexY << endl;
								}
								//*******
								key = _getch();
								if (key == 224 || key == 0)
									key = _getch();
								switch (key)
								{
								case 72: if (indexX > 0) // **********************вверх
									indexX--;
										 else indexX = row - 1;
										 break;
								case 80: if (indexX < row - 1) // ****************вниз
									indexX++;
										 else indexX = 0;
										 break;
								case 75: if (indexY > 0) // *********************влево
									indexY--;
										 else indexY = coll - 1;
										 break;
								case 77: if (indexY < coll - 1) // **************вправо
									indexY++;
										 else indexY = 0;
										 break;
								case 13:
									chort(arr, coll, row, indexX, indexY, bam);
									res = points(arr, coll, row, indexX, indexY, sumballs, k, balls, bam);
									break;
								}
							}
						}/////////////////////////////
						else cout << "\a\n\n\n\n\n\t К сожалению этот уровень закрыт.Для разблокировки наберите 145 баллов в игре 5Х5 :)"; system("pause >> NUL");
						} 
					break;
					}
					//keyses = 27; break;
					}
				}
			}
			case 2:system("cls"); print_plgame(arrp, sizep, np);system("pause >> NUL"); break;//***  Рейтинг
			case 3:system("cls"); skanrules(f4,1); system("pause >> NUL"); break; //**************** Об игре
			case 4: exit(0); break;
			keyses = 27; break;
		 }
	  }
   }
}	