#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Main_Functions.h"
#include "User_interface.h"

using namespace std;

bool gameOver;
bool shutDown;
int headX, headY, fruitX, fruitY;
int tailX[100], tailY[100];
int snakeTail;
int snakeDirection;
int input;

void music_Start()
{
	Beep(220, 300);
	Beep(294, 300);
	Beep(294, 300);
	Beep(370, 300);
	Beep(494, 300);
	Beep(370, 300);
	Beep(440, 800);
}
void music_over()
{
	Beep(440, 300);
	Beep(494, 300);
	Beep(440, 300);
	Beep(370, 300);
	Beep(392, 300);
	Beep(370, 300);
	Beep(330, 800);
}

void SetUp()
{
	srand(time(NULL));
	snakeDirection = RIGHT;
	headX = WIDTH / 2;
	headY = HEIGHT / 2;

	fruitX = rand() % (WIDTH-1);										//Призначаємо фруктам рандомні значання розміщення в межах поля
	fruitY = rand() % (HEIGHT-1);

	input = snakeDirection; 
}

void Draw()
{
	system("cls");
	for (int i = 0; i < WIDTH + 1; i++)
	{
		cout << "-";													//Малюється верхня частина поля
	}
	cout << endl;

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0 || j == WIDTH - 1) {											// Малюється права і ліва сторони поля
				cout << "|";
			}

			if (i == headY && j == headX) {

				cout << "0";
			}
			else if (i == fruitY && j == fruitX) {									
				cout << (char)254;																			// Малюємо те що буде зїдати змія
			}
			else {
				bool print = false;
				for (int k = 0; k < snakeTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
						cout << "+";																	//Малюємо тіло змії
					}
				}
				if (!print)
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	for (int i = 0; i < WIDTH + 1; i++)
		cout << "-";										//Малюється нижня частина поля
	
	cout << endl;
	cout << "SCORE: " << score << endl;
}

int oppositeDirection(int input1, int input2)
{
	if (input1 == LEFT && input2 == RIGHT)
		return 1;
	if (input1 == RIGHT && input2 == LEFT)			//Функція перевіряє рух змійки. Томущо була проблма коли змія рухалась в один бік, а їй дається команда рухатись в протилежний тоді гра закінчувалась. Ця функція це виправляє.
		return 1;
	if (input1 == UP && input2 == DOWN)
		return 1;
	if (input1 == DOWN && input2 == UP)
		return 1;

	return 0;
}

bool fileScoreCreate(int score)
{
	ofstream outfile("score.txt");
	fstream fout;

	fout.open("score.txt", fstream::in | fstream::out);

	if (!fout.is_open())
		return 0;

	fout.seekg(0, ios::beg);
	char info[128];
	char buffInfo[128];

	cout << "\t\t\tEnter your name to save your score: ";
	cin >> info;

	if (strlen(info) < 5) {
		strcat_s(info, "\t\t");
		_itoa_s(score, buffInfo, 128, 10);
		strcat_s(info, buffInfo);
	}
	else {
		strcat_s(info, "\t");
		_itoa_s(score, buffInfo, 128, 10);
		strcat_s(info, buffInfo);
	}	

	fout << info;
	fout.close();
	return 1;
}

bool openScoreFile()
{
	fstream fout;
	fout.open("score.txt", fstream::in | fstream::out);

	if (!fout.is_open())
		return 0;

	fout.seekp(0, ios::beg);

	char info[128];
	fout.getline(info, 128);
	cout << info << endl;

	fout.close();
	return 1;	
}

void Input()											//Функція яка розприділяє дії кнопок, для руху
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			snakeDirection = UP;
			break;
		case'd':
			snakeDirection = RIGHT;
			break;
		case'a':
			snakeDirection = LEFT;
			break;
		case's':
			snakeDirection = DOWN;
			break;
		}
	}	
}

void Logic()											// Дана функція здійснює рух змії
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = headX;
	tailY[0] = headY;

	for (int i = 1; i < snakeTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	if (!oppositeDirection(snakeDirection, input))		//!
		input = snakeDirection;

	switch (input)
	{
	case LEFT:
		headX--;
		break;
	case RIGHT:
		headX++;
		break;
	case UP:
		headY--;
		break;
	case DOWN:
		headY++;
		break;
	}

	if (headX >= WIDTH - 1)
		headX = 0;
	else if (headX < 0)													//Дана перевірка робить можливість змійки проходити крізь стіну
		headX = WIDTH - 2;

	if (headY >= HEIGHT)
		headY = 0;
	else if (headY < 0)
		headY = HEIGHT - 1;

	for (int i = 0; i < snakeTail; i++)
	{
		if (tailX[i] == headX && tailY[i] == headY)			// Перевірка чи змія зїдає саму себе, ящо ТАК то повернення до головного меню
		{
			gameOver = true;
			game_Over();
			music_over();
			fileScoreCreate(score);
			menu_StartScreen(1);
		}
	}

	if (headX == fruitX && headY == fruitY)
	{		
		score += 10;
		fruitX = rand() % (WIDTH - 1);									
		fruitY = rand() % (HEIGHT - 1);			//Перевірка чи голова зїдає фрукт,якщо так то змія збільшується
		snakeTail++;
	}
}

void Play(int level)							// Функція вибирає рівень важкості гри
{
	if (level == 1) {
		SetUp();
		while (!gameOver)
		{
			Draw();
			Input();
			Logic();
			Sleep(120);
		}
	}
	else if (level == 2) {
		SetUp();
		while (!gameOver)
		{
			Draw();
			Input();
			Logic();
			Sleep(60);
		}
	}
	else if (level == 3) {
		SetUp();
		while (!gameOver)
		{
			Draw();
			Input();
			Logic();
			Sleep(10);
		}
	}
}

void switchStartScreen(int switcher)
{
	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == 72)
		if (switcher != 1)
			menu_StartScreen(switcher - 1);
		else
			menu_StartScreen(3);
	if (choice == 80)
		if (switcher != 3)
			menu_StartScreen(switcher + 1);
		else
			menu_StartScreen(1);
	if (choice == 13 || choice == 32)
	{
		if (switcher == 1)
			menu_level(1);

		if (switcher == 2)
			menu_Instructions();

		if (switcher == 3)
			shutDown = true;
	}
}


void switchLevelScreen(int switcher)
{
	int choice = _getch();

	if (choice == 224)
		choice = _getch();

	if (choice == 72)
		if (switcher != 1)
			menu_level(switcher - 1);
		else
			menu_level(3);
	if (choice == 80)
		if (switcher != 3)
			menu_level(switcher + 1);
		else
			menu_level(1);

	if (choice == 13 || choice == 32)
	{
		if (switcher == 1)
			Play(1);

		if (switcher == 2)
			Play(2);

		if (switcher == 3)
			Play(3);
	}
}