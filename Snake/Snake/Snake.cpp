#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

bool GameOver;
bool Win;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int TailX[100], TailY[100];
int nTail;
enum OOP{ STOP = 0,LEFT,RIGHT,UP,DOWN};
OOP dir;


	void Setup()
	{
		GameOver = false;
		Win = false;
		dir = STOP;
		x = width / 2 - 1;
		y = height / 2 - 1;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
	void Draw()
	{
		system("cls");
		for (int i = 0; i < width + 1; i++)
		{
			cout << "#";
		}
		cout << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
			{
				if (j == 0 || j == width - 1)
					cout << "#";
				if (i == y && j == x)
					cout << "O";
				else if (i == fruitY && j == fruitX)
					cout << "F";
				else {
					bool print = false;
					for (int k = 0; k < nTail; k++)
					{
						if (TailX[k] == j && TailY[k] == i)
						{
							print = true;
							cout << "o";
						}
					}
					if (!print)
						cout << " ";
				}
			}
			cout << endl;
		}

		for (int i = 0; i < width + 1; i++)
		{
			cout << "#";
		}
		cout << endl;
		cout << "Score: " << score << endl;
	}
	void Input()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				dir = LEFT;
				break;

			case 's':
				dir = DOWN;
				break;

			case 'd':
				dir = RIGHT;
				break;

			case 'w':
				dir = UP;
				break;
			case 'x':
				GameOver = true;
				break;
			}

		}
	}
	void Logic()
	{
		int prevX = TailX[0];
		int prevY = TailY[0];
		int prev2X, prev2Y;
		TailX[0] = x;
		TailY[0] = y;
		for (int i = 1; i < nTail; i++)
		{
			prev2X = TailX[i];
			prev2Y = TailY[i];
			TailX[i] = prevX;
			TailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
		switch (dir)
		{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		}

		if (x >= width - 1)
			x = 0;
		else if (x < 0)
			x = width - 2;
		if (y >= height)
			y = 0;
		else if (y < 0)
			y = height - 1;

		for (int i = 0; i < nTail; i++)
		{
			if (TailX[i] == x && TailY[i] == y)
			{
				GameOver = true;
			}
		}
		if (x == fruitX && y == fruitY) {
			score += 10;
			fruitX = rand() % width;
			fruitY = rand() % height;
			nTail++;
		}

		if (score == 500) {
			GameOver = true;
			Win = true;
			
		}
	}
	void Repit()
	{
		while (!GameOver)
		{
			Draw();
			Input();
			Logic();
		}
	}
	void win()
	{
		
		system("cls");
		cout << "Congratulations, you completed the game!" << endl;
		system("pause");

	}
class User
{
protected:
	string name, nickname;
public:
	User()
		{
			cout << "Enter your Name: ";
			cin >> name;
			cout << "Enter your Nickname: ";
			cin >> nickname;
		}


};
class Person :   User
{

public:
	Person() {
		system("cls");

		ofstream file("C:\\Users\\HP\\source\\repos\\Snake\\TotalBoard.txt", ios_base::app);
		if (!file.is_open())
		{
			cout << "file not open";
		}
		file << "Name: " << name << " Nickname: " << nickname << " Score: " << score << endl;
		file.close();
		}
};

int main()
{
	
	
	
	
	Setup();

	Repit();

	if(Win == true)
	{
		win();
		
	}
	Person B;
	return 0;
	
}


