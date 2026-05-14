#include<iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

void displayBoard() {
	cout << "\n----- Tic Tac Toe Game -----\n" << endl;
	cout << "\t-------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "\t| ";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " | ";
		}
		cout << endl << "\t-------------" << endl;
	}
}

bool checkWin() {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return true;
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return true;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return true;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return true;
	}
	return false;
}

int main() {
	int player = 1;
	int choice;
	int moves = 0;
	char mark;
	while (true) {
		displayBoard();
		player = (player % 2) ? 1 : 2;
		cout << "\nPlayer " << player << ", enter a number (1-9): ";
		cin >> choice;
		mark = (player == 1) ? 'X' : 'O';
		if (choice >= 1 && choice <= 9) {
			int row = (choice - 1) / 3;
			int col = (choice - 1) % 3;
			if (board[row][col] != 'X' && board[row][col] != 'O') {
				board[row][col] = mark;
				if (checkWin()) {
					displayBoard();
					cout << "\nCONGRATULATIONS! Player " << player << " wins!" << endl;
					break;
				}
				moves++;
				if (moves == 9) {
					displayBoard();
					cout << "\nGAME OVER! It's a Draw." << endl;
					break;
				}
				player++;
			} else {
				cout << "\nCell already occupied! Try again." << endl;
			}
		} else {
			cout << "\nInvalid input! Please enter a number between 1 and 9." << endl;
		}
	}
	return 0;
}