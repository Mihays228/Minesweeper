#include <iostream>
#include <windows.h>
#include <conio.h>

void coor();
std::pair<int, int> playerControls();
void Vilage();


int Y_coor = 10, X_coor = 10, playerY = 5, playerX = 5, live = 3, num = 0, vilageX = 1, vilageY = 1;
int Y = Y_coor - 1, X = X_coor - 1;
int main()
{
	do {
		coor();
		std::pair<int, int> p = playerControls();
		playerY = p.first; playerX = p.second;
	} while (live != 0);
}

void coor() {
	if (num == 1)
	{
		num--;
		system("cls");
		for (int i = 0; i < Y_coor; i++)
		{
			for (int j = 0; j < X_coor; j++)
			{
				if (vilageX == j && vilageY == i)
				{
					std::cout << "[>:(]" << "\t";
				}
				if (playerX == j && playerY == i)
				{
					std::cout << "[:)]" << "\t";
				}
				else
					std::cout << "[]" << "\t";
			}
			std::cout << "\n\n";
		}
	}
}

std::pair<int, int> playerControls()
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			if (playerX == -X)
			{
				break;
			}
			else if (playerX > 0)
			{
				playerX--;
				num++;
				Vilage();
			}
			break;
		case 'd':
			if (playerX == X)
			{
				break;
			}
			else if (playerX < X_coor)
			{
				playerX++;
				num++;
				Vilage();
			}
			break;
		case 'w':
			if (playerX == -X)
			{
				break;
			}
			else if (playerY > 0)
			{
				playerY--;
				num++;
				Vilage();
			}
			break;
		case 's':
			if (playerY == Y)
			{
				break;
			}
			else if (playerY < X_coor)
			{
				playerY++;
				num++;
				Vilage();
			}
			break;
		}
	}
	return std::make_pair(playerY, playerX);
}

void Vilage()
{
	int random, proverka = 0;
	if (vilageX < playerX && vilageY < playerY)
	{
		random = rand() % 2 + 1;
		if (random == 1)
		{
			vilageX += 1;
		}
		if (random == 2)
		{
			vilageY += 1;
		};
		std::cout << random;
		std::cout << "abobus1";
		proverka++;
	}
	if (vilageX < playerX && vilageY > playerY)
	{
		random = rand() % 2 + 1;
		if (random == 1)
		{
			vilageX += 1;
		}
		if (random == 2)
		{
			vilageY -= 1;
		}
		std::cout << "abobus2";
		proverka++;
	}
	if (vilageX > playerX && vilageY > playerY)
	{
		random = rand() % 2 + 1;
		if (random == 1)
		{
			vilageX -= 1;
		}
		if (random == 2)
		{
			vilageY -= 1;
		}
		std::cout << "abobus3";
		proverka++;
	}
	if (vilageX > playerX && vilageY < playerY)
	{
		random = rand() % 2 + 1;
		if (random == 1)
		{
			vilageX -= 1;
		}
		if (random == 2)
		{
			vilageY += 1;
		}
		std::cout << "abobus4";
		proverka++;
	}
	if (proverka != 1)
	{
		if (vilageX != playerX)
		{
			if (vilageX < playerX)
			{
				vilageX += 1;
			}
			if (vilageX > playerX)
			{
				vilageX -= 1;
			}
			std::cout << "abobus5";

		}
	}
	if (proverka != 1)
	{
		if (vilageY != playerY)
		{
			if (vilageY < playerY)
			{
				vilageY += 1;
			}
			if (vilageY > playerY)
			{
				vilageY -= 1;
			}
			std::cout << "abobus6";
		}
	}
	else
		live = 1;
	proverka = 0;

}