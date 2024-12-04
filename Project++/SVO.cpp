#include <iostream>
#include <conio.h>

void map();
void mapMine();
void inputMovePlayer();
void mine();
void notMine();
void gameOver();

int lenght = 13, lenght = 13;
int playerY = lenght / 2, playerX = lenght / 2;
int mineY, mineX;
int* arrayMineY = new int[lenght];
int* arrayMineX = new int[lenght];
int* arrayNotMineY = new int[lenght*lenght];
int* arrayNotMineX = new int[lenght*lenght];
int* arrayMineNumber = new int[lenght*lenght];
int mineNumber = 0;
int lenght = 0;
bool player = true;

int main() {
	mine();
	do {
		map();
		mapMine();
		inputMovePlayer();
		gameOver();
		system("cls");
	} while (player);
	return 0;
}

void map() {
	for (int i = 0; i < lenght + 2; i++) std::cout << "# "; std::cout << std::endl;
	for (int i = 0, j2 = 0; i < lenght; i++, j2 = 0) {
		std::cout << "| ";
		for (int j = 0; j < lenght; j++, j2++) {
			if (playerY == i && playerX == j) std::cout << "Z ";
			else if (!player && arrayMineX[i] == j2) std::cout << "@ ";
			else if (arrayNotMineY[i] == i && arrayNotMineX[j] == j) std::cout << arrayMineNumber[i] << " ";
			else std::cout << "  ";
		}
		std::cout << "| " << std::endl;
	}
	for (int i = 0; i < lenght + 2; i++) std::cout << "# "; std::cout << std::endl;
}

void mapMine() {
	for (int i = 0; i < lenght + 2; i++) std::cout << "# "; std::cout << std::endl;
	for (int i = 0, j2 = 0; i < lenght; i++, j2 = 0) {
		std::cout << "| ";
		for (int j = 0; j < lenght; j++, j2++) {
			if (playerY == i && playerX == j) std::cout << "Z ";
			else if (arrayMineY[i] == i && arrayMineX[i] == j2) std::cout << "@ ";
			else if (arrayNotMineX[j] == j) std::cout << arrayMineNumber[i] << " ";
			else std::cout << "  ";
		}
		std::cout << "| " << std::endl;
	}
	for (int i = 0; i < lenght + 2; i++) std::cout << "# "; std::cout << std::endl;
	for (int i = 0; i < lenght; i++) std::cout << arrayMineY[i] << ":" << arrayMineX[i] << " "; std::cout << std::endl;
}

void inputMovePlayer() {
	switch (_getch()) {
	case 'a': {
		if (playerX > 0) playerX--;
		break;
	}
	case 'd': {
		if (playerX < lenght - 1) playerX++;
		break;
	}
	case 'w': {
		if (playerY > 0) playerY--;
		break;
	}
	case 's': {
		if (playerY < lenght - 1) playerY++;
		break;
	}
	case ' ': {
		for (int i = 0; i < lenght; i++) {
			if (playerY == arrayMineY[i] && playerX == arrayMineX[i]) player = false;
			else notMine();
		}
		break;
	}
	}
}

void mine() {
	srand(time(NULL));
	for (int i = 0; i < lenght; i++) {
		arrayMineY[i] = i;
		arrayMineX[i] = rand() % lenght;
	}
}

void notMine() {
	mineNumber = 0;
	for (int i = 0; i < lenght; i++) {
		if (playerY - 1 == arrayMineY[i] && playerX - 1 == arrayMineX[i]) mineNumber++;
		if (playerY - 1 == arrayMineY[i] && playerX == arrayMineX[i]) mineNumber++;
		if (playerY - 1 == arrayMineY[i] && playerX + 1 == arrayMineX[i]) mineNumber++;
		if (playerY == arrayMineY[i] && playerX - 1 == arrayMineX[i]) mineNumber++;
		if (playerY == arrayMineY[i] && playerX + 1 == arrayMineX[i]) mineNumber++;
		if (playerY + 1 == arrayMineY[i] && playerX - 1 == arrayMineX[i]) mineNumber++;
		if (playerY + 1 == arrayMineY[i] && playerX == arrayMineX[i]) mineNumber++;
		if (playerY + 1 == arrayMineY[i] && playerX + 1 == arrayMineX[i]) mineNumber++;
	}
	arrayMineNumber[lenght] = mineNumber;
	arrayNotMineY[lenght] = playerY;
	arrayNotMineX[lenght] = playerX;
	lenght++;
}

void gameOver() {
	if (player == false) {
		system("cls");
		map();
		std::cout << "GAME OVER\n";
		system("pause");
	}
}