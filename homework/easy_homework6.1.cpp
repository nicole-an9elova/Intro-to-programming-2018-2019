//Matrix
#include <iostream>
using namespace std;
int main()
{
	int elements[100][100];
	int rows;//N
	cout << "Enter number of rows:";
	cin >> rows;
	while (rows < 0 || rows > 100) {
		cout << "Invalid number of rows!Try again!";
		cin >> rows;
	}
	int cols;//M
	cout << "Enter number of columns:";
	cin >> cols;
	while (cols < 0 || cols > 100) {
		cout << "Invalid number of columns!Try again!";
		cin >> cols;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "el[" << i << "][" << j << "]:";
			cin >> elements[i][j];
		}
	}
	cout << endl;
	int multiRows[100];
	int multiCols[100];
	int multiR = 1;
	int multiC = 1;
	int tempRow = 0;
	int tempCol = 0;
	while (tempRow < rows) {
		multiR = 1;
		for (int j = 0; j < cols; j++) {
			multiR *= elements[tempRow][j];

		}
		multiRows[tempRow] = multiR;
		tempRow++;
	}
	while (tempCol < cols) {
		multiC = 1;
		for (int i = 0; i < rows; i++) {
			multiC *= elements[i][tempCol];
		}
		multiCols[tempCol] = multiC;
		tempCol++;
	}
	for (int i = 0; i < tempRow; i++) {
		for (int j = 0; j < tempCol; j++) {
			if (multiRows[i] == multiCols[j]) {
				cout << "(" << i  << ", " << j << ")";
			}
		}
	}

	system("pause");
	return 0;
}

