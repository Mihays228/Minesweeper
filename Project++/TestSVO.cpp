#include <iostream>
#include <conio.h>
#include <windows.h>
#pragma comment (lib, "winmm.lib")
#include <fstream>

void menu();
void map();
void mapCompletion();
void number();
bool mine(int i, int j);
void open(int i, int j);
void inputMovePlayer();
void gameOver();
void timeRecord();

int lenght;
int mine_number;
bool first_open;
int** array_map;
bool** array_open;
int playerY, playerX;
int mine_mark;
int win_number;
bool player;
bool you_win;
bool exitb = false;
bool sound = false;
int start_time;
int current_time;
int finish_time;
int mode;
int cheat_code;
int best_time_easy = 99999;
int best_time_normal = 99999;
int best_time_hard = 99999;

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int main() {
	timeRecord();
	hideCursor();
	menu();
	if (exitb == false) {
		mapCompletion();
		number();
		system("cls");
		do {
			map();
			inputMovePlayer();
			gameOver();
		} while (player);
		main();
	}
	return 0;
}

void menu() {
	system("chcp 1251");
	lenght = 9;
	mine_number = 10;
	cheat_code = 0;
	int choice_menu = 1;
	bool play = false;
	mode = 1;
	do {
		bool choice_mode = false;
		system("cls");
		std::cout << "\t<<��Ϩ�>>\n";
		if (choice_menu == 1) std::cout << "[������]\n";
		else std::cout << "������\n";
		if (choice_menu == 2) {
			if (mode == 1) std::cout << "[�����: �����]\n";
			if (mode == 2) std::cout << "[�����: ����������]\n";
			if (mode == 3) std::cout << "[�����: �������]\n";
			if (mode == 4) std::cout << "[�����: ����������]\n";
		}
		else {
			if (mode == 1) std::cout << "�����: �����\n";
			if (mode == 2) std::cout << "�����: ����������\n";
			if (mode == 3) std::cout << "�����: �������\n";
			if (mode == 4) std::cout << "�����: ����������\n";
		}
		if (choice_menu == 3) {
			if (sound == false) std::cout << "[����: ����.]\n";
			else std::cout << "[����: ���.]\n";
		}
		else {
			if (sound == false) std::cout << "����: ����.\n";
			else std::cout << "����: ���.\n";
		}
		if (choice_menu == 4) std::cout << "[����������]\n";
		else std::cout << "����������\n";
		if (choice_menu == 5) std::cout << "[�������]\n";
		else std::cout << "�������\n";
		if (choice_menu == 6) std::cout << "[�������]\n";
		else std::cout << "�������\n";
		if (choice_menu == 7) std::cout << "[�����]\n";
		else std::cout << "�����\n";
		switch (_getch()) {
		case 72/*�����*/:
			if (choice_menu > 1) choice_menu--;
			break;
		case 80/*����*/:
			if (choice_menu < 7) choice_menu++;
			break;
		case 113/*Q*/:
			if (cheat_code < 5) {
				cheat_code++;
			}
			break;
		case 13/*Enter*/:
			if (choice_menu == 1) {
				play = true;
			}
			if (choice_menu == 2) {
				do {
					system("cls");
					std::cout << "\t<<�����>>\n";
					if (mode == 1) std::cout << "[˸����: ����� 9 �� 9 � 10 ���]\n";
					else std::cout << "˸����: ����� 9 �� 9 � 10 ���\n";
					if (mode == 2) std::cout << "[����������: ����� 16 �� 16 � 40 ���]\n";
					else std::cout << "����������: ����� 16 �� 16 � 40 ���\n";
					if (mode == 3) std::cout << "[�������: ����� 24 �� 24 � 99 ���]\n";
					else std::cout << "�������: ����� 24 �� 24 � 99 ���\n";
					if (mode == 4) std::cout << "[����������: �� ���� ������ ������ ����� � ���������� ���]\n";
					else std::cout << "����������: �� ���� ������ ������ ����� � ���������� ���\n";
					switch (_getch()) {
					case 72/*�����*/:
						if (mode > 1) mode--;
						break;
					case 80/*����*/:
						if (mode < 4) mode++;
						break;
					case 13/*Enter*/:
						if (mode == 1) {
							lenght = 9;
							mine_number = 10;
						}
						if (mode == 2) {
							lenght = 16;
							mine_number = 40;
						}
						if (mode == 3) {
							lenght = 24;
							mine_number = 99;
						}
						if (mode == 4) {
							std::cout << "������� ������ �����: "; std::cin >> lenght;
							std::cout << "������� ���������� ���: "; std::cin >> mine_number;
						}
						choice_mode = true;
						break;
					}
				} while (choice_mode == false);
			}
			if (choice_menu == 3 && sound == false) sound = true;
			else sound = false;
			if (choice_menu == 4) {
				system("cls");
				std::cout << "\t<<����������>>\n"
						<< "z - ������� ������\n"
						<< "x - �������� ������\n"
						<< "��������� - ����� ������\n";
				system("pause");
			}
			if (choice_menu == 5) {
				system("cls");
				std::cout << "\t<<�������>>\n"
					<< "���� ���� � ������� ������ ������, �� ������ ��� ���� �� �����, ���������� ����.\n"
					<< "����� � ������ - ���������� ������� ��� ������ ��.\n";
				system("pause");
			}
			if (choice_menu == 6) {
				system("cls");
				std::cout << "\t<<�������>>";
				if (best_time_easy == 99999) std::cout << "\n˸���� - �� �������"; else std::cout << "\n˸���� - " << best_time_easy;
				if (best_time_normal == 99999) std::cout << "\n���������� - �� �������"; else std::cout << "\n���������� - " << best_time_normal;
				if (best_time_hard == 99999) std::cout << "\n������� - �� �������" << std::endl; else std::cout << "\n������� - " << best_time_hard << std::endl;
				system("pause");
			}
			if (choice_menu == 7) {
				exitb = true;
				play = true;
			}
			break;
		}
	} while (play == false);
}

void map() {
	current_time = clock() / CLOCKS_PER_SEC - start_time;
	for (int i = 0; i < lenght + 2; i++) { SetColor(0, 7); std::cout << "# "; SetColor(7, 0); } std::cout << std::endl;
	for (int i = 0; i < lenght; i++) {
		SetColor(0, 7); std::cout << "# "; SetColor(7, 0);
		for (int j = 0; j < lenght; j++) {
			if (player && playerY == i && playerX == j) { SetColor(7, 8); std::cout << "Z "; SetColor(7, 0); }
			else if (array_map[i][j] >= lenght || array_map[i][j] == -lenght) { SetColor(0, 20); std::cout << "X "; SetColor(7, 0); }
			else if (!player && array_map[i][j] == -1 || cheat_code == 5 && array_map[i][j] == -1) { SetColor(0, 20); std::cout << "@ "; SetColor(7, 0); }
			else if (array_open[i][j] == true && array_map[i][j] == 0) { SetColor(0, 11); std::cout << "  "; SetColor(7, 0); }
			else if (array_open[i][j] == true && array_map[i][j] == 1) { SetColor(0, 3); std::cout << array_map[i][j] << " "; SetColor(7, 0); }
			else if (array_open[i][j] == true && array_map[i][j] == 2) { SetColor(0, 2); std::cout << array_map[i][j] << " "; SetColor(7, 0); }
			else if (array_open[i][j] == true && array_map[i][j] == 3) { SetColor(0, 6); std::cout << array_map[i][j] << " "; SetColor(7, 0); }
			else if (array_open[i][j] == true && array_map[i][j] != -1) { SetColor(0, 13); std::cout << array_map[i][j] << " "; SetColor(7, 0); }
			else std::cout << "  ";
		}
		SetColor(0, 7); std::cout << "# " << std::endl; SetColor(7, 0);
	}
	for (int i = 0; i < lenght + 2; i++) { SetColor(0, 7); std::cout << "# "; SetColor(7, 0); } std::cout << std::endl;
	if (mine_mark < 10) { std::cout << "X - " << mine_mark << " \tTime: " << current_time << std::endl; }
	else { std::cout << "X - " << mine_mark << "\tTime: " << current_time << std::endl; }
}

void mapCompletion() {
	srand(time(NULL));
	start_time = clock() / CLOCKS_PER_SEC;
	first_open = false;
	array_map = new int* [lenght];
	array_open = new bool* [lenght];
	playerY = lenght / 2; playerX = lenght / 2;
	mine_mark = mine_number;
	win_number = lenght * lenght - mine_number;
	player = true;
	you_win = false;
	for (int i = 0; i < lenght; i++) {
		array_map[i] = new int[lenght];
		array_open[i] = new bool[lenght];
	}
	for (int i = 0; i < lenght; i++) {
		for (int j = 0; j < lenght; j++) {
			array_map[i][j] = 0;
			array_open[i][j] = false;
		}
	}
	for (int i = 0; i < mine_number; i++) {
		bool placed = false;
		do {
			int rand1 = rand() % lenght, rand2 = rand() % lenght;
			if (array_map[rand1][rand2] != -1) {
				array_map[rand1][rand2] = -1;
				placed = true;
			}
		} while (!placed);
	}
}

void number() {
	for (int i = 0; i < lenght; i++) {
		for (int j = 0; j < lenght; j++) {
			if (array_map[i][j] != -1) {
				int num = 0;
				if (mine(i - 1, j - 1)) num++;
				if (mine(i - 1, j)) num++;
				if (mine(i - 1, j + 1)) num++;
				if (mine(i, j - 1)) num++;
				if (mine(i, j + 1)) num++;
				if (mine(i + 1, j - 1)) num++;
				if (mine(i + 1, j)) num++;
				if (mine(i + 1, j + 1)) num++;
				array_map[i][j] = num;
			}
		}
	}
}

bool mine(int i, int j)
{
	if ((i >= 0) && (i < lenght))
	{
		if ((j >= 0) && (j < lenght))
		{
			if (array_map[i][j] == -1) return true;
		}
	}
	return false;
}

void open(int i, int j) {
	first_open = true;
	if ((i >= 0) && (i < lenght)) {
		if ((j >= 0) && (j < lenght)) {
			if (!array_open[i][j]) {
				array_open[i][j] = true;
				win_number--;
				if (array_map[i][j] == 0) {
					open(i - 1, j - 1);
					open(i - 1, j);
					open(i - 1, j + 1);
					open(i, j - 1);
					open(i, j + 1);
					open(i + 1, j - 1);
					open(i + 1, j);
					open(i + 1, j + 1);
				}
			}
		}
	}
}

void inputMovePlayer() {
	if (_kbhit()) {
		//mciSendString(L"play SoundMove.mp3", NULL, 0, 0);
		switch (_getch()) {
		case 75/*�����*/:
			if (playerX > 0) {
				playerX--;
			}
			break;
		case 77/*������*/:
			if (playerX < lenght - 1) playerX++;
			break;
		case 72/*�����*/:
			if (playerY > 0) playerY--;
			break;
		case 80/*����*/:
			if (playerY < lenght - 1) playerY++;
			break;
		case 'z':
			if (first_open == false && array_map[playerY][playerX] == -1) {
				array_map[playerY][playerX] = 0;
				array_map[rand() % lenght][rand() % lenght] = -1;
				number();
				first_open = true;
			}
			if (array_map[playerY][playerX] == -1) player = false;
			else if (array_map[playerY][playerX] != -lenght && array_map[playerY][playerX] < lenght) open(playerY, playerX);
			break;
		case 'x':
			if (array_open[playerY][playerX] == false) {
				if (array_map[playerY][playerX] > -lenght && array_map[playerY][playerX] < lenght && mine_mark != 0 && array_map[playerY][playerX] != 0) {
					//mciSendString(L"play SoundMark.mp3", NULL, 0, 0);
					array_map[playerY][playerX] *= lenght;
					mine_mark--;
				}
				else if (array_map[playerY][playerX] > -lenght && array_map[playerY][playerX] < lenght && mine_mark != 0 && array_map[playerY][playerX] == 0) {
					//mciSendString(L"play SoundMark.mp3", NULL, 0, 0);
					array_map[playerY][playerX] = 99;
					mine_mark--;
				}
				else if (array_map[playerY][playerX] == 99) {
					array_map[playerY][playerX] = 0;
					mine_mark++;
				}
				else if (array_map[playerY][playerX] >= lenght || array_map[playerY][playerX] == -lenght) {
					array_map[playerY][playerX] /= lenght;
					mine_mark++;
				}
			}
			break;
		}
	}
}

void gameOver() {
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cd;
	cd.X = 0;
	cd.Y = 0;
	SetConsoleCursorPosition(hd, cd);
	if (player == false) {
		mciSendString(L"play SoundDeath.mp3", NULL, 0, 0);
		system("cls");
		map();
		std::cout << "GAME OVER\n";
		Sleep(3000);
		system("pause");
	}
	if (win_number <= 0 && first_open == true) {
		mciSendString(L"play SoundWin.mp3", NULL, 0, 0);
		system("cls");
		player = false;
		you_win = true;
		finish_time = clock() / CLOCKS_PER_SEC - start_time;
		map();
		std::cout << "YOU WIN\n";
		Sleep(3000);
		system("pause");
	}
}

void timeRecord() {
	std::ifstream inf1("SVO_Best_record_easy.txt");    //�������� ��������� ������ ����������
	inf1 >> best_time_easy;    //���������� ���� �� �����
	if (mode == 1 && finish_time < best_time_easy && you_win == true) {
		best_time_easy = finish_time;
		std::ofstream outf1("SVO_Best_record_easy.txt");    //�������� ��������� ������ ������
		outf1 << best_time_easy;    //������ � ����
	}
	std::ifstream inf2("SVO_Best_record_normal.txt");    //�������� ��������� ������ ����������
	inf2 >> best_time_normal;    //���������� ���� �� �����
	if (mode == 2 && finish_time < best_time_normal && you_win == true) {
		best_time_normal = finish_time;
		std::ofstream outf2("SVO_Best_record_normal.txt");    //�������� ��������� ������ ������
		outf2 << best_time_normal;    //������ � ����
	}
	std::ifstream inf3("SVO_Best_record_hard.txt");    //�������� ��������� ������ ����������
	inf3 >> best_time_hard;    //���������� ���� �� �����
	if (mode == 3 && finish_time < best_time_hard && you_win == true) {
		best_time_hard = finish_time;
		std::ofstream outf3("SVO_Best_record_hard.txt");    //�������� ��������� ������ ������
		outf3 << best_time_hard;    //������ � ����
	}
}