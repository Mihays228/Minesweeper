#include <iostream>

void mapPlayer1();
void movePlayer1();
void mapPlayer2();
void movePlayer2();
int mapY = 10, mapX = 10;
char arrayY[10] = {'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', 'Æ', 'Ç', 'È', 'Ê'};
int arrayX[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
	system("chcp 1251");
	do {
		mapPlayer1();
		system("pause");
		system("cls");
		system("pause");
		mapPlayer2();
		system("pause");
		system("cls");
		system("pause");
	} while (true);
	return 0;
}

void mapPlayer1() {
	std::cout << "    ";
	for (int i = 0; i < mapY; i++) std::cout << arrayY[i] << " ";
	std::cout << std::endl << "  ";
	for (int i = 0; i < mapY + 2; i++) std::cout << "~ ";
	std::cout << std::endl;
	for (int i = 0; i < mapY; i++) {
		if (i < 9) std::cout << arrayX[i] << " ";
		if (i == 9) std::cout << arrayX[i];
		std::cout << "~ ";
		for (int j = 0; j < mapX; j++) {
			std::cout << "  ";
		}
		std::cout << "~ " << std::endl;
	}
	std::cout << "  ";
	for (int i = 0; i < mapY + 2; i++) std::cout << "~ ";
	std::cout << std::endl;
}

void movePlayer1() {

}

void mapPlayer2() {
	std::cout << "    ";
	for (int i = 0; i < mapY; i++) std::cout << arrayY[i] << " ";
	std::cout << std::endl << "  ";
	for (int i = 0; i < mapY + 2; i++) std::cout << "~ ";
	std::cout << std::endl;
	for (int i = 0; i < mapY; i++) {
		if (i < 9) std::cout << arrayX[i] << " ";
		if (i == 9) std::cout << arrayX[i];
		std::cout << "~ ";
		for (int j = 0; j < mapX; j++) {
			std::cout << "  ";
		}
		std::cout << "~ " << std::endl;
	}
	std::cout << "  ";
	for (int i = 0; i < mapY + 2; i++) std::cout << "~ ";
	std::cout << std::endl;
}

void movePlayer2() {

}