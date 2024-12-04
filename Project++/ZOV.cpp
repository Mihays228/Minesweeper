#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

void map();
void inputMovePlayer();
void gameOver();
void newObstacle();
void pointRecord();

int mapY = 13, mapX = 13;
int playerY = mapY / 2, playerX = 1;
bool player = true;
int ObstacleX = mapX, ObstacleY;
int point = 0;
int speedObstacle = 300;
int bestPoint;

int main() {
	srand(time(NULL));
	ObstacleY = rand() % mapY / 2 + 2;
	do {
		pointRecord();
		map();
		newObstacle();
		inputMovePlayer();
		gameOver();
		system("cls");
	} while (player);
	return 0;
}

void map() {
	for (int i = 0; i < mapY; i++) {
		if (i == 0) {
			for (int i = 0; i < mapX + 2; i++) {
				std::cout << "# ";
			} std::cout << std::endl;
		}
		std::cout << "| ";
		for (int j = 0; j < mapX; j++) {
			if (playerY == i && playerX == j) {
				std::cout << "V ";
			}
			else if (ObstacleY - 3 >= i && ObstacleX == j || ObstacleY + 3 <= i && ObstacleX == j) {
				std::cout << "Z ";
			}
			else {
				std::cout << "  ";
			}
		} std::cout << "| " << std::endl;
		if (i == mapY - 1) {
			for (int i = 0; i < mapX + 2; i++) {
				std::cout << "# ";
			}
		}
	}
	std::cout << std::endl << "Point: " << point << " Best record: " << bestPoint << " Speed: " << speedObstacle << std::endl;
}

void inputMovePlayer() {
	if (_kbhit()) {
		switch (_getch()) {
		case ' ':
			playerY -= 2;
			break;
		}
	}
	else if (playerY < mapY) {
		playerY++;
	}
}

void gameOver() {
	if (playerY < 0 || playerY >= mapY || playerY <= ObstacleY - 3 && playerX == ObstacleX || playerY >= ObstacleY + 3 && playerX == ObstacleX) {
		player = false;
		std::cout << "GAME OVER\n";
		system("pause"); system("pause"); system("pause");
	}
	/*else if (playerY <= ObstacleY - 3 && playerX == ObstacleX || playerY >= ObstacleY + 3 && playerX == ObstacleX) {
		player = false;
		std::cout << "GAME OVER\n";
		system("pause"); system("pause"); system("pause");
	}*/
}
 
void newObstacle() {
	Sleep(speedObstacle);
	if (speedObstacle > 5) speedObstacle--;
	if (ObstacleX <= 0) {
		ObstacleX = mapX;
		ObstacleY = rand() % mapY / 2 + 2;
		point++;
	}
	else ObstacleX--;
}

void pointRecord() {
	std::ifstream inf("ZOV_Best_record.txt");    //открытие файлового потока считывания
	inf >> bestPoint;    //считывание инта из файла
	if (point > bestPoint) {
		bestPoint = point;
		std::ofstream outf("ZOV_Best_record.txt");    //открытие файлового потока записи
		outf << bestPoint;    //запись в файл
	}
}