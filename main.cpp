#include <iostream>
#include <conio.h>

using namespace std;

void Input();
void Process();
void Draw();

//1. 지도를 초기화 한다.
int Map[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int PlayerX = 1;
int PlayerY = 1;

bool bIsRunning = true;
char Key;


int main()
{	
	while (bIsRunning)
	{
		Input();
		Process();
		Draw();
	}

	return 0;
}

void Input()
{
	Key = _getch();
}

void Process()
{
	switch (Key)
	{
		//up
		case 'W':
		case 'w':
		{
			PlayerY--;
			break;
		}
		//down
		case 'S':
		case 's':
		{
			PlayerY++;
			break;
		}
		//left
		case 'A':
		case 'a':
		{
			PlayerX--;
			break;
		}
		//right
		case 'D':
		case 'd':
		{
			PlayerX++;
			break;
		}

		//quit
		case 'Q':
		case 'q':
		{
			bIsRunning = false;
			break;
		}
	}
}

void Draw()
{
	//화면을 지운다.
	system("cls");

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				cout << "P" << " ";
			}
			else if (Map[X][Y] == 0)
			{
				cout << " " << " ";
			}
			else if (Map[X][Y] == 1)
			{
				cout << "X" << " ";
			}
		}

		cout << endl;
	}
}
