#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <unistd.h>

const int BOARD_HEIGHT = 10;
const int BOARD_WIDTH  = 10;
char board[BOARD_HEIGHT][BOARD_WIDTH];

void clearScreen();
void createBoard();
void printBoard();
void move(int &, bool negative_direction);

int main() {

	createBoard();
	
	int x_pos = 4, y_pos = 4;
	int direction = 1;	
	char ch = '>'; // TODO: uncomment this
	// char ch = '_';
	
	board[x_pos][y_pos] = ch;


	system("cls");	
	
	while (true) {
		
		printBoard();
		
		board[y_pos][x_pos] = '_';
		
		switch (direction) {
			case 0:
				move(y_pos, true); // true: moving towards negative numbers
				break;
			case 1:
				move(x_pos, false); // false: moving towards positive numbers
				break;
			case 2:
				move(y_pos, false); 
				break;
			case 3:
				move(x_pos, true);
				break;
			default:
				std::cout << "Direction unknown..." << std::endl;
				exit(EXIT_FAILURE);
		}
		
		// board[y_pos][x_pos] = ch;
		
		if(GetAsyncKeyState(VK_UP) & 0x8000 && direction != 2) {
			direction = 0;
			ch = '^';
		} 
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && direction != 3) {
			direction = 1;
			ch = '>';
		} 
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && direction != 0) {
			direction = 2;
			ch = 'v';
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && direction != 1) {
			direction = 3;
			ch = '<';
		}
		
		if (GetAsyncKeyState('X') & 0x8000)
			break;
		
		board[y_pos][x_pos] = ch;
		
		// sleep(1);
		// system("cls");
		clearScreen();
	}
	
	
	/*
	while (true) {
		if(GetKeyState(VK_UP) & 0x8000) {
			std::cout << "Up Key pressed..." << std::endl;
		} 
		else if (GetKeyState(VK_RIGHT) & 0x8000) {
			std::cout << "Right Key pressed..." << std::endl;
		} 
		else if (GetKeyState(VK_DOWN) & 0x8000) {
		std::cout << "Down Key pressed..." << std::endl;	
		}
		else if (GetKeyState(VK_LEFT) & 0x8000) {
			std::cout << "Left Key pressed..." << std::endl;
		}
		
		if (GetKeyState('X') & 0x8000)
			break;
	}
	*/
	
	return 0;
}

void clearScreen() {	
	COORD cursorPosition;
	cursorPosition.X = 0;	
	cursorPosition.Y = 0;	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void createBoard() {
	for (int row = 0; row < BOARD_WIDTH; row++) {
		for (int col = 0; col < BOARD_HEIGHT; col++) {
			board[row][col] = '_';
		}
	}
}

void move(int &dir, bool negative_direction) {
	if (negative_direction) 
		 (dir == 0) ? dir = 9: dir--;
	else 
		(dir == 9) ? dir = 0: dir++;
}

void printBoard() {
	for (int row = 0; row < BOARD_WIDTH; row++) {
		// std::cout << std::setw(2) << (row + 1) << " ";
		for (int col = 0; col < BOARD_HEIGHT; col++) {
			std::cout << board[row][col] << " ";
		}
		std::cout << std::endl;
	}
	sleep(1);
}