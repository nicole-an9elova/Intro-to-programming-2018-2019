//Binary Search
#include <iostream>
#include <time.h>
using namespace std;

unsigned long const SIZE = 9223372036854775807;

unsigned long choosePassword() {
	return rand() * rand();
}

//Standard binary search
//AND
//Binary search, but instead of using the middle element, I must use a random one
void binarySearchStandardAndRandom(unsigned long password, int& count, bool random) {
	unsigned long tryPassword = choosePassword();
	unsigned long left = 0;
	unsigned long right = SIZE;

	bool flagForSearching = true;

	while (flagForSearching) {
		if (tryPassword == password) {
			flagForSearching = false;
		}
		else {
			if (tryPassword > password) {
				right = tryPassword;
			}
			else {
				left = tryPassword;
			}
			if (random) {
				tryPassword = choosePassword() % (right - left + 1) + left;
			}
			else {
				tryPassword = (left + right) / 2;
			}
			count++;
		}
	}
}

int main()
{
	srand(time(NULL));
	unsigned long password = choosePassword();
	cout << "Password: " << password << endl;

	int countNormal = 0;
	int countRandom = 0;
	bool isRandom = true;

	binarySearchStandardAndRandom(password, countNormal, !isRandom);
	binarySearchStandardAndRandom(password, countRandom, isRandom);

	cout << "Result from NORMAL binary search: " <<countNormal << endl;
	cout << "Result from RANDOM binary search: " << countRandom << endl;
	
	return 0;
}

