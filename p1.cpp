#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
void SetConsoleColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void check2(char board[][50], int size, int& count) {
	int score2 = 0;
	for (int i = 0; i < size; i++) {     //For Diagnal
		if (board[i][i] == '1')
			score2++;

		if (score2 == size) {
			count = score2;
			break;
		}
	}
	for (int i = 0; i < size; i++) {    //For rows
		score2 = 0;
		for (int j = 0; j < size; j++) {
			if (board[i][j] == '1')
				score2++;
		}
		if (score2 == size) {
			count = score2;
			break;
		}
	}
	for (int i = 0; i < size; i++) {    //For columns
		score2 = 0;
		for (int j = 0; j < size; j++) {
			if (board[j][i] == '1')
				score2++;
		}
		if (score2 == size) {
			count = score2;
			break;
		}
	}
	int point2 = 0;
	for (int i = 0; i < size; i++) {     //For Seconadary Diagnal
		for (int j = 0; j < size; j++) {
			if (i + j == size - 1) {
				if (board[i][j] == '1')
					point2++;
			}
		}
		if (point2 == size) {
			count = point2;
			break;
		}
	}
}
void check1(char board[][50], int size,int& count) {
	int score = 0;
	for (int i = 0; i < size; i++) {     //For Diagnal
     	if (board[i][i] == '0')
				score++;

		if (score == size) {
			count = score;
			break;
		}
	}
	for (int i = 0; i < size; i++) {    //For rows
		score = 0;
		for (int j = 0; j < size; j++) {
			if (board[i][j] == '0')
				score++;
		}
		if (score == size) {
			count = score;
			break;
		}
	}
	for (int i = 0; i < size; i++) {    //For columns
		score = 0;
		for (int j = 0; j < size; j++) {
			if (board[j][i] == '0')
				score++;
		}
		if (score == size) {
			count = score;
			break;
		}
	}
	int point = 0;
	for (int i = 0; i < size; i++) {     //For Seconadary Diagnal
		for (int j = 0; j < size; j++) {
			if (i + j == size - 1) {
				if (board[i][j] == '0')
					point++;
			}
		}
		if (point == size) {
			count = point;
			break;
		}
	}
}
void change(char board[][50], int size,int choice) {
	int a, b;
	cout << "Enter line no: ";
	cin >> a;
	cout << "Enter box no: ";
	cin >> b;
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "\t\t\t\t\t\t";
		for (int j = 0; j < size; j++) {
			if (a-1 == i && b-1 == j) {
				board[i][j] = choice;
				cout << "|" << board[i][j] << "|";
			}
			else {
				cout << "|" << board[i][j] << "|";
			}
		}
		cout << endl;
	}
	
}
void Board(char board[][50],int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = ' ';
		}
	}
	for (int i = 0; i < size; i++) {
		cout << "\t\t\t\t\t\t";
		for (int j = 0; j < size; j++) {
			cout << "|"<<board[i][j] << "|";
		}
		cout << endl;
	}
}
int main()
{
	int again;
	do {
		char board[50][50];
		int size, count1 = 0, count2 = 0;
		char choice1 = '0', choice2 = '1';
		string p1, p2;
		SetConsoleColor(6);
		std::cout << "\t\t\t___________.____________   ________________  _________   ___________________  ___________\n";
		std::cout << "\t\t\t\\__    ___/|   \\_   ___ \\  \\__    ___/  _  \\ \\_   ___ \\  \\__    ___/\\_____  \\ \\_   _____/\n";
		std::cout << "\t\t\t  |    |   |   /    \\  \\/    |    | /  /_\\  \\/    \\  \\/    |    |    /   |   \\ |    __)_\n";
		std::cout << "\t\t\t  |    |   |   \\     \\____   |    |/    |    \\     \\____   |    |   /    |    \\|        \\\n";
		std::cout << "\t\t\t  |____|   |___|\\______  /   |____|\\____|__  /\\______  /   |____|   \\_______  /_______  /\n";
		std::cout << "\t\t\t                       \\/                  \\/        \\/                     \\/        \\/\n";
		SetConsoleColor(13);
		cout << "Rules: " << endl;
		cout << "\tPlayer 1 sign ='0'\n";
		cout << "\tPlayer 2 sign ='1'\n\n";
		SetConsoleColor(14);
		cout << "Player1: ";
		cin >> p1;
		cout << "Player2: ";
		cin >> p2;
		cout << endl;
		cout << "Please enter the size of Game: ";
		cin >> size;
		cout << endl;
		srand(time(0));
		int toss = rand() % 2;
		SetConsoleColor(4);
		Board(board, size);
		cout << endl;
		while (true) {
			if (toss == 1) {
				SetConsoleColor(10);
				cout << p1 << " Turn: " << endl;
				change(board, size, choice1);
				cout << endl;
				check1(board, size, count1);
				if (count1 == size) {
					cout << "\t\t\t\t\t\t" << p1 << " Win!";
					break;
				}
				SetConsoleColor(9);
				cout << p2 << " Turn: " << endl;
				change(board, size, choice2);
				cout << endl;
				check2(board, size, count2);
				if (count2 == size) {
					cout << "\t\t\t\t\t\t" << p2 << " Win!";
					break;
				}

			}
			else {
				SetConsoleColor(9);
				cout << p2 << " Turn: " << endl;
				change(board, size, choice2);
				cout << endl;
				check2(board, size, count2);
				if (count2 == size) {
					cout << endl;
					cout << "\t\t\t\t\t\t" << p2 << " Win!";
					break;
				}
				SetConsoleColor(10);
				cout << p1 << " Turn: " << endl;
				change(board, size, choice1);
				cout << endl;
				check1(board, size, count1);
				if (count1 == size) {
					cout << "\t\t\t\t\t\t" << p1 << " Win!";
					break;
				}
			}
		}
		cout << endl;
		cout << "Press 1 if you want to play again else press anything ";
		cin >> again;
	} while (again == 1);
	system("pause");
	return 0;
}
