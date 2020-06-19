#include <iostream>

int main()
{
	int day;
	std::cout << "Day:";
	std::cin >> day;

	int month;
	std::cout << "Month:";
	std::cin >> month;
	std::cout << std::endl;

	int dayInAMonth;
	int new_day = day + 5;
	switch (month)
	{
	
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
		while (day < 0 || day > 31) 
		{
			std::cout << "Enter number in range:";
			std::cin >> day;
		}
		dayInAMonth = 31;
		if (dayInAMonth < (new_day))
		{
			if (month < 10) {
				std::cout << (new_day - dayInAMonth) << ".0" << ++month;
			}
			else {
				std::cout << (new_day - dayInAMonth) << "." << ++month;
			}
		}
		else {
			if (month < 10) {
				std::cout << new_day  << ".0" << month;
			}
			else {
				std::cout << new_day << "." << month;
			}
		}
		break;
	case 2:
		while (day < 0 || day > 28) 
		{
			std::cout << "Enter number in range:";
			std::cin >> day;
		}
		dayInAMonth = 28;
		if (dayInAMonth < (new_day))
		{
			if (month < 10) {
				std::cout << (new_day - dayInAMonth) << ".0" << ++month;
			}
			else {
				std::cout << (new_day - dayInAMonth) << "." << ++month;
			}
		}
		else {
			if (month < 10) {
				std::cout << new_day << ".0" << month;
			}
			else {
				std::cout << new_day << "." << month;
			}
		}
		break;
	case 4: case 6: case 9: case 11:
		while (day < 0 || day> 30) 
		{
			std::cout << "Enter number in range:";
			std::cin >> day;
		}
		dayInAMonth = 30;
		if (dayInAMonth < (new_day))
		{
			if (month < 10 ) {
				std::cout << (new_day - dayInAMonth) << ".0" << ++month;
			}
			else {
				std::cout << (new_day - dayInAMonth) << "." << ++month;
			}
		}
		else {
			if (month < 10) {
				std::cout << new_day << ".0" << month;
			}
			else {
				std::cout << new_day << "." << month;
			}
		}
		break;
	default:
		std::cout << "There is no such month" << std::endl;
		break;
	}
	
	system("pause");
	return 0;
}


