//the matrix should be sorted in such a way that the first row should have the smallest sum...
#include <iostream>
#include <cstdlib>

const int MAX_SIZE = 100;

void cleanUpMatrix(int** matrix, size_t N) {
	for (size_t i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
int** dynamicArray(size_t N, size_t M) {
	int** matrix = new(std::nothrow) int*[N];
	if (matrix == nullptr) {
		return nullptr;
	}
	for (size_t i = 0; i < N; i++) {
		matrix[i] = new(std::nothrow) int[M];
		if (matrix[i] == nullptr) {
			cleanUpMatrix(matrix, i);
			return nullptr;
		}
	}
	return matrix;
}
void readMatrix(int** matrix, size_t N, size_t M) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			std::cout << "matr[" << i << "][" << j << "] -- ";
			std::cin >> matrix[i][j];
		}
	}
}
void printMatrix(int** matrix, size_t N, size_t M) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int sumOfRow(int** matrix, size_t row, size_t M) {
	int sum = 0;
	for (size_t i = 0; i < M; i++) {
		sum += matrix[row][i];
	}
	return sum;
}
void swapRows(int** matrix, size_t row1, size_t row2, size_t columns)
{
	for (size_t i = 0; i < columns; i++) {
		int temp = matrix[row1][i];
		matrix[row1][i] = matrix[row2][i];
		matrix[row2][i] = temp;
	}
}
void bubbleSort(int** matrix, size_t N, size_t M) {
	bool changed = false;
	size_t sorted = 0;

	size_t sumOfRow1 = 0;
	size_t sumOfRow2 = 0;
	do {
		changed = false;
		for (size_t i = N - 1; i > sorted; i--) {
			sumOfRow1 = sumOfRow(matrix, i, M);
			sumOfRow2 = sumOfRow(matrix, i - 1, M);
			if (sumOfRow1 < sumOfRow2) {
				swapRows(matrix, i, i - 1, M);
				changed = true;
			}
		}
		sorted++;
	} while (changed);
}

int main()
{
	size_t N;
	std::cout << "Enter number of rows: ";
	std::cin >> N;
	size_t M;
	std::cout << "Enter number of columns: ";
	std::cin >> M;

	int** matr = nullptr;
	matr = dynamicArray(N, M);

	readMatrix(matr, N, M);
	bubbleSort(matr, N, M);
	std::cout << "**MATRIX**" << std::endl;
	printMatrix(matr, N, M);
	
	return 0;
}

