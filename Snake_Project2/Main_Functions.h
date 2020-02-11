#pragma once
#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3
#define HEIGHT 20
#define WIDTH 20

extern bool gameOver;
extern bool shutDown;
extern int headX, headY, fruitX, fruitY;
extern int tailX[100], tailY[100];
extern int snakeTail;
extern int snakeDirection;
extern int input;


void music_Start();
void music_over();
void SetUp();
void Draw();
void Input();
void Logic();
void Play(int level);
int oppositeDirection(int input1, int input2);
bool fileScoreCreate(int score);
void switchStartScreen(int switcher);
void switchLevelScreen(int switcher);
bool openScoreFile();
