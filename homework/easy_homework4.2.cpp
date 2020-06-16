#include <iostream>

//1.finding the sum of the digits of a number transformed from decimal to a particular numeral system

int sumOfDigits(int number, int base) {
	int sum = 0;
	int result[32];
	
	int i = 0;
	while (number != 0) {
		result[i] = number % base;
		number /= base;
		i++;
	}

	for (int j = 0; j < i; j++) {
		sum += result[j];
	}
	return sum;
}

//2.Finding gcd
int findGCD(int a, int b) {
	if (b == 0)return a;
	return findGCD(b, a % b);
}

//3.Finding a^b - without math functions or pow

int powFunc(int a, int b) {
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

//4.Is the sum of the digits of third degree of a number, equal to the number in question?
//GREEN num - example = 153 = 1^3 + 5^3 + 3^3
bool isNumGreen(int number) {
	int sumOfDigits = 0;
	int numberCopy = number;
	while (numberCopy > 0) {
		int digit = numberCopy % 10;
		numberCopy /= 10;
		int digitOfThirdDegree = powFunc(digit, 3);
		sumOfDigits += digitOfThirdDegree;
	}
	if (sumOfDigits == number) {
		return true;
	}
	return false;
}

//5. Finding the sum of green numbers between [M, N] or [N, M];
int sumOfGreenNums(int M, int N) {
	int start, end;
	int sum = 0;
	if (M > N) {
		start = N;
		end = M;
	}
	else {
		start = M;
		end = N;
	}
	for (int i = start; i <= end; i++) {
		if (isNumGreen(i)) {
			sum += i;
		}
	}
	return sum;
}

//6.Finding if a particular number is RED - example: 12 = 4*(1 + 2)
bool isNumRed(int number) {
	int numberCopy = number;
	int sum = 0;
	while (numberCopy > 0) {
		int digit = numberCopy % 10;
		numberCopy /= 10;
		sum += digit;
	}
	double k = number / sum;
	if (k > sum) {
		return true;
	}
	return false;
}
//7.
int sumOfRedNums(int M, int N) {
	int start, end;
	int sum = 0;
	if (M > N) {
		start = N;
		end = M;
	}
	else {
		start = M;
		end = N;
	}
	for (int i = start; i <= end; i++) {
		if (isNumRed(i)) {
			sum += i;
		}
	}
	return sum;
}

int differenceSumRedAndSumGreen(int M, int N) {
	return sumOfGreenNums(M, N) - sumOfRedNums(M, N);
}

//8. 1 – x^2/2! + x^4/4! - x^6/6!....
double sumOfSeries(double x, int n) {
	double sum = 1, fact, jump = 2, term = 1, m;
	for (int i = 1; i < n; i++) {
		fact = 1;
		for (int j = 1; j <= jump; j++) {
			fact *= j;
		}
		term *= (-1);
		m = term * pow(x, jump) / fact;
		sum += m;
		jump += 2;
	}
	return sum;
}


int main()
{
	//testing
	//1.
	int bin = sumOfDigits(250, 16);
	std::cout << "First: " << bin << std::endl;
	//2.
	int gcd = findGCD(45, 10);
	std::cout << "Second: " << gcd << std::endl;
	//3.
	int pow = powFunc(25, 2);
	std::cout << "Third: " << pow << std::endl;
	//4.
	bool check = isNumGreen(153);
	std::cout << "Fourth: " << std::boolalpha << check << std::endl;
	//5.
	int sum = sumOfGreenNums(400, 5);
	std::cout << "Fifth: " << sum << std::endl;
	//6.
	bool check2 = isNumRed(22);
	std::cout << "Sixth: " << std::boolalpha << check2 << std::endl;
	//7.
	int sumR = sumOfRedNums(13, 5);
	std::cout << "Sum of Reds: " << sumR << std::endl;
	int diff = differenceSumRedAndSumGreen(200, 5);
	std::cout << "Seventh: " << diff << std::endl;
	//8.
	double aSum = sumOfSeries(0.81, 9);
	std::cout << "Eighth: " << aSum << std::endl;
	

	system("pause");
	return 0;
}

