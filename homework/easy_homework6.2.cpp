// SEA CHESS
#include <iostream>
using namespace std;

bool areThereAnyFreePositions(char board[][10], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 'X' && board[i][j] != 'O') {
				return true;
			}
		}
	}
	return false;
}
bool isThisPostitionFree(char board[][10], int N, int X, int Y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((X < N || X > 0) && (Y < N || Y > 0)) {
				if (board[i][j] != 'X' && board[i][j] != 'O' && i == X && j == Y) {
					return true;
				}
			}
		}
	}
	return false;
}
bool winningMainDiagonal(char board[][10], int N, char symbol) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				if (board[i][j] != symbol) {
					return false;
				}
			}
		}
	}
	
	return true;
}
bool winningSecondDiagonal(char board[][10], int N, char symbol) {
	for (int i = 0; i < N; i++) {
		if (board[i][N - 1 - i] != symbol) {
			return false;
		}		
	}
	return true;
}

bool winningRow(char board[][10], int N, char symbol) {
	int tempRow = 0;
	while(tempRow < N){
		bool win = true;
		for (int j = 0; j < N; j++) {
			if (board[tempRow][j] != symbol) {
				win = false;
				break;
			}
		}
		tempRow++;
		if (win) return true;
	}
	return false;
}

bool winningCol(char board[][10], int N, char symbol) {
	int tempCol = 0;
	while (tempCol < N) {
		bool win = true;
		for (int i = 0; i < N; i++) {
			if (board[i][tempCol] != symbol) {
				win = false;
				break;
			}
		}
		tempCol++;
		if (win) return true;
		
	}
	return false;
	
}

bool isWinner(char board[][10], int N, char symbol) {
	return winningMainDiagonal(board, N, symbol) ||
		winningSecondDiagonal(board, N, symbol) ||
		winningCol(board, N, symbol) ||
		winningRow(board, N, symbol);
}

void printBoard(char board[][10], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "[" << board[i][j] << "] " ;
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	cout << "***SEA CHESS***" << endl;
	int mode;
	cout << "Choose game mode(1 - PvP, 2 - PvC):";
	cin >> mode;
	int N;
	cout << "Enter grid size:";
	cin >> N;
	while (N < 3 || N > 9) {
		cout << "Enter grid size:";
		cin >> N;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "[  ]";
		}
		cout << endl;
	}
	int X;
	int Y; 
	char firstPlayer;
	char secondPlayer;
	int turn = 0;
	cout << "Player 1 choose a symbol: [X/O] ";
	cin >> firstPlayer;
	if (firstPlayer == 'X') {
		secondPlayer = 'O';
	}
	else { 
		secondPlayer = 'X';
	}
	char board[10][10] = {' '};
	char symbolInUse;

	if (mode == 1) {
		while (areThereAnyFreePositions(board, N)) {
			if (turn % 2 == 0) {
				symbolInUse = firstPlayer;
				cout << "It's Player 1's turn:";
			}
			else {
				symbolInUse = secondPlayer;
				cout << "It's Player 2's turn:";
			}
			turn++;
			cin >> X >> Y;
			if (X > N || X < 0 || Y > N || Y < 0) {
				return 1;
			}
			if (isThisPostitionFree(board, N, X, Y)) {
				board[X][Y] = symbolInUse;
				printBoard(board, N);
			}
			else {
				cout << "This position isn't free!";
				return 1;
			}
			if (isWinner(board, N, symbolInUse)) {
				if (symbolInUse == firstPlayer) {
					cout << "Player 1 wins!\n";
					break;
				}
				else {
					cout << "Player 2 wins!\n";
					break;
				}
			}
		}
		if (!areThereAnyFreePositions(board, N)) {
			cout << "No winner!\n";
		}
	}
	else {
		while (areThereAnyFreePositions(board, N)) {
			if (turn % 2 == 0) {
				cout << "Players's turn: " ;
				symbolInUse = firstPlayer;
				cin >> X >> Y;
			}
			else {
				cout << "Computer's turn: ";
				symbolInUse = secondPlayer;
				X = rand() % N;
				Y = rand() % N;

				cout << X << " " << Y << endl;

			}
			turn++;
			if (X > N || X < 0 || Y > N || Y < 0) {
				return 1;
			}
			if (isThisPostitionFree(board, N, X, Y)) {
				board[X][Y] = symbolInUse;
				printBoard(board, N);
			}
			else {
				turn--;
			}
			if (isWinner(board, N, symbolInUse)) {
				if (symbolInUse == firstPlayer) {
					cout << "The Player wins!" << endl;
					break;
				}
				else {
					cout << "The Computer wins!" << endl;
					break;
				}
			}	
		}
		if (!areThereAnyFreePositions(board, N)) {
			cout << "No winner!";
		}
	}
		
	

	system("pause");
	return 0;
}
