#include <iostream>
#include <string>

using namespace std;

int main()
{
	//easy_homework1 Checking whether FMIvalut card is valid 
	int n;
	cout << "Enter your card number:";
	cin >> n;
	while (n < 100000000 || n > 999999999) {
		cout << "Number must be 9 digits!" << endl;
		cin >> n;
	}
	int cardVersion = n / 100000000;
	int major = n / 1000000 % 10;
	string majorText = "";
	switch (major)
	{
	case 0:
		majorText = "Informatics";
		break;
	case 1:
		majorText = "Computer Science";
		break;
	case 2:
		majorText = "Information Systems";
		break;
	case 3:
		majorText = "Software Engineering";
		break;
	case 4:
		majorText = "Applied Mathematics";
		break;
	case 5:
		majorText = "Mathematics";
		break;
	case 6:
		majorText = "Statistics";
		break;
	case 8:
		majorText = "Mathematics and Informatics";
		break;
	default:
		majorText = "No major!";
		break;
	}
	int id = (n % 1000000) / 10;
	int digit;
	int countZeros = 0;
	int countDigits = 0;
	int idCopy = id;
	while (idCopy > 0) {
		digit = idCopy % 10;
		idCopy /= 10;
		countDigits++;
		if (digit == 0) {
			countZeros++;
		}
	}
	if (countZeros > 1 || countDigits < 5) {
		cout << "Invalid card number!" << endl;
	}
	else {
		cout << "{ card_version: " << cardVersion << ", owner_spec:" << majorText << ", owner_id: " << id << " }" << endl;
	}

	//easy_homework2 Checking whether card is original or fake 

	int secondDigitToBinary = n / 10000000 % 10;

	int binaryDigit[50];
	int i = 0;
	while (secondDigitToBinary > 0) {
		binaryDigit[i] = secondDigitToBinary % 2;
		secondDigitToBinary /= 2;
		i++;
	}
	string gender = binaryDigit[0] == 1 ? "male" : "female";
	string hairColor = binaryDigit[1] == 1 ? "dark hair" : "light hair";
	string eyeColor = binaryDigit[2] == 1 ? "dark eyes" : "light eyes";

	int checkDigit = n % 10;

	int nCopy = n;
	int digitsArr[9];
	int j = 0;
	while (nCopy > 0)
	{
		digitsArr[j] = n % 10;
		n /= 10;
		j++;
	}
	int sumOfEvenPos = 0;
	int sumOfOddPos = 0;
	for (int k = 8; k >= 0; k--) {

		if (k % 2 == 0) {
			sumOfEvenPos += digitsArr[k];
		}
		if (k % 2 == 1) {
			sumOfOddPos += digitsArr[k];
		}

	}
	int stepOne = sumOfEvenPos * sumOfOddPos;
	int stepTwo;

	if (hairColor == "dark hair" && eyeColor == "dark eyes") {
		stepTwo = stepOne | 0xCAFE;
	}
	else if (hairColor == "light hair" && eyeColor == "light eyes") {
		stepTwo = stepOne | 0xBABE;
	}
	else {
		stepTwo = stepOne | 0xC001;
	}

	int stepThree;

	if (gender == "female") {
		stepThree = stepTwo xor 0xFACE;
	}
	else {
		stepThree = stepTwo xor 0xC0DE;
	}

	int stepFour;

	int stepThreeCopyWithoutLastDigit = stepThree / 10;
	int sumOfFistFourBits = 0;

	while (stepThreeCopyWithoutLastDigit > 0) {
		int digits = stepThreeCopyWithoutLastDigit % 10;
		stepThreeCopyWithoutLastDigit /= 10;
		sumOfFistFourBits += digits;
	}

	sumOfFistFourBits > 10 ? stepFour = sumOfFistFourBits % 10 : stepFour = sumOfFistFourBits;

	stepFour == checkDigit ? cout << "Authentic card!\n" : cout << "Imitative card!\n";


	//easy_homework3 Rewarding the customers of FMIvalut
	int in;
	cout << "Enter number:";
	cin >> in;
	while (in < 1 || in > 31) {
		cout << "Enter number between 1 and 31!\n";
		cin >> in;
	}

	int arrIds[31];
	int arrStatistics[31];
	int numToBeRead;
	for (int i = 0; i < in; i++) {
		cout << "id(" << i << ") --- ";
		cin >> arrIds[i];
	}


	arrStatistics[0] = 1;

	for (int j = 0; j < in; j++) {
		if (arrIds[j + 1] >= arrIds[j]) {
			arrStatistics[j + 1] = 1;
		}
		else {
			arrStatistics[j + 1] = 0;
		}

	}



	int countOnes = 0;
	for (int k = 0; k < in; k++) {
		if (arrStatistics[k] == 1)
			countOnes++;
	}

	int middleOne = countOnes % 2 == 0 ? (countOnes / 2) - 1 : countOnes / 2;

	int helpCounter = 0;
	int median;


	for (int s = 0; s < in; s++) {
		if (arrStatistics[s] == 1) {
			helpCounter++;
			if (helpCounter == middleOne + 1) {
				median = s;
			}
		}
	}

	int countZerosLeftSide = 0;
	int countZerosRightSide = 0;

	for (int left = 0; left < median; left++) {
		if (arrStatistics[left] == 0)
			countZerosLeftSide++;
	}
	for (int right = median + 1; right < in; right++) {
		if (arrStatistics[right] == 0)
			countZerosRightSide++;
	}

	for (int b = 0; b < in; b++) {
		cout << arrStatistics[b];
	}

	cout << endl;

	if (countZerosLeftSide > countZerosRightSide) {
		cout << "Left side: " << countZerosLeftSide;
	}
	else if (countZerosRightSide > countZerosLeftSide) {
		cout << "Right side: " << countZerosRightSide;
	}
	else {
		cout << "Both sides: " << countZerosLeftSide;
	}

	cout << endl;


	system("pause");
	return 0;
}
