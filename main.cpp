#include <iostream>
#include <conio.h>
using namespace std;

int Key = 0;

int PlayerX = 1;
int PlayerY = 1;

int GoalX = 8;
int GoalY = 8;

int MonsterX = 5;
int MonsterY = 5;

char GoalShape = 'G';
char FloorShape = ' ';
char WallShape = '*';
char PlayerShape = 'P';
char MonsterShape = 'E';

int World[10][10] =
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

bool IsRunning = true;

void Input();
void Tick();
void MoveMonster();
void Render();

int main()
{

	while (IsRunning)
	{
		Input();
		MoveMonster();
		Tick();
		Render();
	}
	return 0;
}

void Input()
{
	Key = _getch();
}

void Tick()
{
	if (Key == 'w')
	{
		PlayerY--;
	}
	if (Key == 'a')
	{
		PlayerX--;
	}
	if (Key == 's')
	{
		PlayerY++;
	}
	if (Key == 'd')
	{
		PlayerX++;
	}
	if (Key == 27) 
	{
		IsRunning = false;
	}
}

void MoveMonster()
{
	int direction = rand() % 4;
	switch (direction)
	{
	case 0:
		MonsterY--;
		break;
	case 1: 
		MonsterX--;
		break;
	case 2: 
		MonsterY++;
		break;
	case 3:
		MonsterX++;
		break;
	default:
		break;
	}
}

void Render()
{
	system("cls");
	for (int Y = 0; Y < 10; Y++) 
	{
		for (int X = 0; X < 10; X++)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				cout << PlayerShape;
			}
			else if (GoalX == X && GoalY == Y)
			{
				cout << GoalShape;
			}
			else if (MonsterX == X && MonsterY == Y)
			{
				cout << MonsterShape;
			}
			else if (World[X][Y] == 1)
			{
				cout << WallShape;
			}
			else if (World[X][Y] == 0)
			{
				cout << FloorShape;
			}
		}
		cout << endl;
	}
}
