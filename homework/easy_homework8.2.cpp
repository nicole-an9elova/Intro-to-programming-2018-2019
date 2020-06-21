#include <iostream>

int* dynamicArray(int size) {
	int* bedrooms = new(std::nothrow) int[size];
	if (bedrooms == nullptr) {
		return nullptr;
	}
	return bedrooms;
}

bool isTheRoomsSizePowOfTwo(int bedrSize) {
	if (bedrSize > 1 && bedrSize < 257)
	{
		while (bedrSize % 2 == 0)
		{
			bedrSize /= 2;
		}
		return (bedrSize == 1);
	}
	return false;
}

void readArray(int* bedrooms, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "Bedrooms " << i << "s size: ";
		std::cin >> bedrooms[i];
		if (!isTheRoomsSizePowOfTwo(bedrooms[i])) {
			i--;
		}
	}
}

void resize(int* &bedrooms, int &size, int people) {
	size += people;
	int* newBedrooms = new(std::nothrow) int[size];
	for (int i = 0; i < size - people; i++) {
		newBedrooms[i] = bedrooms[i];
	}
	delete[] bedrooms;
	bedrooms = newBedrooms;
}

int findTheBiggestRoom(int* bedrooms, int size) {
	int maxNum = 0;
	for (int i = 0; i < size; i++) {
		if (bedrooms[i] > maxNum) {
			maxNum = bedrooms[i];
		}
	}
	return maxNum;
}
int findThePosOfBiggestRoom(int* bedrooms, int size) {
	int maxInd = 0;
	int maxEl = findTheBiggestRoom(bedrooms, size);
	for (int i = 0; i < size; i++) {
		if (bedrooms[i] == maxEl) {
			maxInd = i;
			break;
		}
	}
	return maxInd;
}

//commands
void A(int* &bedrooms, int &size, int numberOfPeopleToAdd) {
	resize(bedrooms, size, numberOfPeopleToAdd);
	while (numberOfPeopleToAdd > 0) {
		int maxEl = findTheBiggestRoom(bedrooms, size);
		int maxPos = findThePosOfBiggestRoom(bedrooms, size);
		if (maxEl == 2) {
			std::cout << "Try again after Hoth." << std::endl;
			break;
		}
		for (int i = size - 1; i > maxPos; i--) {
			bedrooms[i] = bedrooms[i - 1];
		}
		bedrooms[maxPos] = maxEl / 2;
		bedrooms[maxPos + 1] = maxEl / 2;
		numberOfPeopleToAdd--;
	}
}
void P(int* bedrooms, int size) {
	std::cout << "[";
	for (int i = 0; i < size; i++) {
		if(bedrooms[i] > 0)
			std::cout << bedrooms[i];
		if (i != size - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
}
void E(int* bedrooms) {
	if (bedrooms != nullptr) {
		delete[] bedrooms;
	}
	bedrooms = nullptr;
}

int main()
{
	int size;
	do {
		std::cout << "Enter the number of bedrooms:";
		std::cin >> size;
	} while (size < 4 || size > 1024);

	int* bedrooms = nullptr;
	bedrooms = dynamicArray(size);

	readArray(bedrooms, size);
	char command;
	int numberOfPeople;
	

	do {
		std::cin >> command;
		if (command == 'A') {
			std::cin >> numberOfPeople;
			A(bedrooms, size, numberOfPeople);
		}
		if (command == 'P') {
			P(bedrooms, size);
		}
		if (command == 'E') {
			E(bedrooms);
		}
	} while (command != 'E');
	
	return 0;
}

