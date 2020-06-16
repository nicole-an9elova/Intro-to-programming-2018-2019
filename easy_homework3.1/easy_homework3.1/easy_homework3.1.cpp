// easy_homework3.1.cpp Hamming;s numbers

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter number:";
	cin >> n;
	int number = 1;
	
	while (n > 0)
	{
		int numbersCopy = number;
		while (numbersCopy % 2 == 0)
			numbersCopy /= 2;
		while (numbersCopy % 3 == 0)
			numbersCopy /= 3;
		while (numbersCopy % 5 == 0)
			numbersCopy /= 5;

		if (numbersCopy == 1) {
			n--;
			cout << number << " ";
		}
				
		number++;
	}

	system("pause");
	return 0;
}

