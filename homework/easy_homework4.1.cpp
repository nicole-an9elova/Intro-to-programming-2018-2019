//Всяко положително четно число, може
//да се изрази, чрез сумата на две прости числа.
#include <iostream>

using namespace std;

bool isPrime(int number) {
	if (number < 2) return false;
	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0) return false;
	}
	return true;
}

int main()
{
	int number;
	cout << "Enter number:";
	cin >> number;
	if (number % 2 == 1) {
		cout << "Are you joking with me, Euler? This number is not even!";
		return 0;
	}
	
	int primeNumbers[1000];

	int index = 0;

	for (int i = 0; i < number; i++) {
		if (isPrime(i)) {
			primeNumbers[index] = i;
			index++;
		}
	}
	
	for (int i = 0; i < index; i++) {
		for (int k = 0; k < i; k++) {
			if ((primeNumbers[i] + primeNumbers[k]) == number) {
				cout << "(" << primeNumbers[i] << ", " << primeNumbers[k] << ")";
			}
		}
	}

	cout << endl;

	system("pause");
	return 0;
}

