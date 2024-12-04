#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

void map();
std::pair<int, int> inputMovePlayer();
int pointPlayer();
void pointRecord();
int lifePlayer();
void gameOver();

int mapY = 11, mapX = 11;
int playerY = mapY - 1, playerX = mapX / 2;
int fruitY = 0, fruitX;
int point = 0;
int bestPoint;
int life = 3;
bool player = true;

int main() {
	do {
		srand(time(NULL));
		if (fruitY == mapY) {
			fruitX = rand() % mapX;
			fruitY = 0;
		}
		point = pointPlayer();
		pointRecord();
		life = lifePlayer();
		map();
		fruitY++;
		Sleep(100);
		std::pair<int, int> p = inputMovePlayer();
		playerY = p.first; playerX = p.second;
		gameOver();
		system("cls");
	} while (player);
	return 0;
}

void map() {
	for (int i = 0; i <= mapY+2; i++) {
		std::cout << "_ ";
	}
	std::cout << std::endl;
	for (int i = 0; i < mapY; i++) {
		std::cout << "| ";
		for (int j = 0; j <= mapX; j++) {
			if (playerY == i && playerX == j)
				std::cout << "V ";
			else if (fruitY == i && fruitX == j) {
				std::cout << "Z ";
			}
			else
				std::cout << "  ";
		}
		std::cout << "| " << std::endl;
	}
	for (int i = 0; i <= mapY+2; i++) {
		std::cout << "# ";
	}
	std::cout << std::endl << "Point: " << point << " Life: " << life << " Best record: " << bestPoint << std::endl;
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
		}
	}
	return std::make_pair(playerY, playerX);
}

int pointPlayer() {
	if (fruitY == playerY && fruitX == playerX)
		point++;
	return point;
}

void pointRecord() {
	std::ifstream inf("ZZZ_Best_record.txt");    //открытие файлового потока считывания
	inf >> bestPoint;    //считывание инта из файла
	if (point > bestPoint) {
		bestPoint = point;
		std::ofstream outf("ZZZ_Best_record.txt");    //открытие файлового потока записи
		outf << bestPoint;    //запись в файл
	}
}

int lifePlayer() {
	if (fruitY == mapY - 1 && fruitX != playerX)
		life--;
	return life;
}

void gameOver() {
	if (life <= 0) {
		std::cout << "\nGAME OVER\n";
		player = false;
		system("pause");
	}
}