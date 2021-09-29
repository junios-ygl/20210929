#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void Input();
void Process();
void Draw();
void MovePlayer(int XDirection, int YDirection);

bool IsGoal();

void ChangeColor(int Color);

//1. ������ �ʱ�ȭ �Ѵ�.
int Map[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,0,1,0,1},
	{1,0,0,0,1,0,0,1,0,1},
	{1,0,0,0,1,0,0,1,9,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int PlayerX = 1;
int PlayerY = 1;

bool bIsRunning = true;
int Key;


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
	if (Key == 0x00 || Key == 0xE0)
	{
		// Ȯ��Ű�� ��� Ű�� �ϳ��� �Է� �޴´�.
		Key = _getch();
	}
}

void Process()
{
	switch (Key)
	{
		//up
		case 'W':
		case 'w':
		{
			MovePlayer(0, -1);
			break;
		}
		//down
		case 'S':
		case 's':
		{
			MovePlayer(0, 1);
			break;
		}
		//left
		case 'A':
		case 'a':
		{
			MovePlayer(-1, 0);
			break;
		}
		//right
		case 'D':
		case 'd':
		{
			MovePlayer(1, 0);
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

	if (IsGoal())
	{
		bIsRunning = false;
	}

}

void Draw()
{
	//ȭ���� �����.
	system("cls");

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				ChangeColor(171);
				cout << "P";
				ChangeColor(7);
				cout << " ";
			}
			else if (Map[Y][X] == 0)
			{
				cout << " " << " ";
			}
			else if (Map[Y][X] == 1)
			{
				cout << "X" << " ";
			}
			else if (Map[Y][X] == 9)
			{
				ChangeColor(14);
				cout << "G";
				ChangeColor(7);
				cout << " ";
			}
		}

		cout << endl;
	}
}

void MovePlayer(int XDirection, int YDirection)
{
	//���� ������ ���
	int NewPlayerX = PlayerX + XDirection;
	int NewPlayerY = PlayerY + YDirection;

	//�̸� ����
	if (Map[NewPlayerY][NewPlayerX] == 0 ||
		Map[NewPlayerY][NewPlayerX] == 9)
	{
		//�̵�
		PlayerX = NewPlayerX;
		PlayerY = NewPlayerY;
	}
}

bool IsGoal()
{
	return Map[PlayerY][PlayerX] == 9 ? true : false;

	//if (Map[PlayerY][PlayerX] == 9)
	//{
	//	return true;
	//}


	//return false;
}

void ChangeColor(int Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}
