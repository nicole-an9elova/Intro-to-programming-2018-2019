#include <iostream>
#include <iomanip>

int main()
{
	int age;
	std::cout << "Enter Traycho's age:";
	std::cin >> age;
	while (age < 1 || age > 77) 
	{
		std::cout << "Enter age in range:";
		std::cin >> age;
	}
	double pricePhone;
	std::cout << "Enter the price of the phone:";
	std::cin >> pricePhone;
	while (pricePhone < 1.0 || pricePhone > 10000.0) 
	{
		std::cout << "Enter price in range";
		std::cin >> pricePhone;
	}
	int priceToy;
	std::cout << "Enter the price of the toy:";
	std::cin >> priceToy;
	while (priceToy < 0 || priceToy > 40) 
	{
		std::cout << "Enter price in range";
		std::cin >> priceToy;
	}
	int countToys = 0;
	int countBro = 0;
	int sum = 0;
	int sumOfToys = 0;
	
	for (int i = 1; i <= age; i++) 
	{
		if (i == 1 || i % 2 == 1) 
		{
			countToys++;
		}
		else if (i % 2 == 0) 
		{
			countBro++;
			sum = sum + 10;
			sumOfToys = sumOfToys + sum;
		}

	}
	int moneyFromToySell = countToys * priceToy;
	int moneyTakenFromBrother = countBro;
	int savings = sumOfToys + moneyFromToySell - moneyTakenFromBrother;
	double print1 = savings - pricePhone;
	double print2 = pricePhone - savings;
	if (pricePhone <= savings) 
	{
		std::cout << "Yes!" << std::endl << std::setprecision(2) << std::fixed << print1 << std::endl;
	}
	else 
	{
		std::cout << "No!" << std::endl << std::setprecision(2) << std::fixed << print2 << std::endl;
	}


	system("pause");
	return 0;
}

