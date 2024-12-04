#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

void map();
std::pair<int, int> inputMovePlayer();
int inputFirePlayer();
std::pair<int, int> moveFire();
bool gameOver();

int mapX = 10, mapY = 10;
int playerX = 5, playerY = 5;
int fireX = playerX, fireY = playerY, fire = 0;
int enemyX, enemyY;
bool player = true;
bool enemy = true;

int main() {
	srand(time(NULL));
	enemyX = rand() % mapX; enemyY = rand() % mapY;
	do {
		map();
		std::pair<int, int> p = inputMovePlayer();
		playerX = p.first; playerY = p.second;
		fire = inputFirePlayer();
		std::pair<int, int> f = moveFire();
		fireX = f.first; fireY = f.second;
		player = gameOver();
		system("cls");
		//Sleep(100);
	} while (player);
	return 0;
}

void map() {
	for (int i = 0; i <= mapY + 2; i++)
		std::cout << "# ";
	std::cout << std::endl;
	for (int i = 0; i <= mapY; i++) {
		std::cout << "# ";
		for (int j = 0; j <= mapX; j++) {
			if (i == playerY && j == playerX)
				std::cout << "Z ";
			else if (i == enemyY && j == enemyX)
				std::cout << "V ";
			//else if (i == fireY && j == fireX)
			//	moveFire();
			else
				std::cout << "  ";
		}
		std::cout << "#";
		std::cout << std::endl;
	}
	for (int i = 0; i <= mapY + 2; i++)
		std::cout << "# ";
}

std::pair<int, int> inputMovePlayer() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			if (playerX > 0)
				playerX--;
			break;
		case 'd':
			if (playerX < mapY)
				playerX++;
			break;
		case 'w':
			if (playerY > 0)
				playerY--;
			break;
		case 's':
			if (playerY < mapX)
				playerY++;
			break;
		}
	}
	return std::make_pair(playerX, playerY);
}

int inputFirePlayer() {
	if (_kbhit()) {
		fireX = playerX; fireY = playerY;
		switch (_getch()) {
		case 'j':
			if (fireX > 0)
				fire = -2;
			break;
		case 'l':
			if (fireX < mapY)
				fire = 2;
			break;
		case 'i':
			if (fireY > 0)
				fire = -1;
			break;
		case 'k':
			if (fireY < mapX)
				fire = 1;
			break;
		}
	}
	return fire;
}

std::pair<int, int> moveFire() {
	switch (fire) {
	case -2: {
		std::cout << ".";
		fireX--;
	}
	case 2: {
		std::cout << ".";
		fireX++;
	}
	case -1: {
		std::cout << ".";
		fireY--;
	}
	case 1: {
		std::cout << ".";
		fireY++;
	}
	}
	return std::make_pair(fireX, fireY);
}

bool gameOver() {
	if (playerX == enemyX && playerY == enemyY) {
		system("cls");
		std::cout << "GAME OVER\n";
		system("pause");
		player = false;
	}
	return player;
}