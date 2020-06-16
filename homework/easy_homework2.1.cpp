#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "Enter number:";
	cin >> number;
	if (number < 0 || number > 3000) {
		cout << "Invalid number!";
		return 0;
	}
	int num[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	string romanNumeral;
	int i = 12;
	while (number > 0) {
		int d = number / num[i];
		number = number % num[i];
		while (d--) {
			switch (num[i])
			{
			case 1:
				romanNumeral = "I";
				break;
			case 4:
				romanNumeral = "IV";
				break;
			case 5:
				romanNumeral = "V";
				break;
			case 9:
				romanNumeral = "IX";
				break;
			case 10:
				romanNumeral = "X";
				break;
			case 40:
				romanNumeral = "XL";
				break;
			case 50:
				romanNumeral = "L";
				break;
			case 90:
				romanNumeral = "XC";
				break;
			case 100:
				romanNumeral = "C";
				break;
			case 400:
				romanNumeral = "CD";
				break;
			case 500:
				romanNumeral = "D";
				break;
			case 900:
				romanNumeral = "CM";
				break;
			case 1000:
				romanNumeral = "M";
				break;
			default:
				break;
			}
			cout << romanNumeral;
		}
		i--;
	}
	cout << endl;


	system("pause");
	return 0;
}

