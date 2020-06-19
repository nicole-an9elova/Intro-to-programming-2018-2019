#include <iostream>
#include <iomanip>

int main()
{
	int countChrysanthemum;
	std::cout << "The count of chrysanthemums:";
	std::cin >> countChrysanthemum;
	while (countChrysanthemum < 0 || countChrysanthemum > 200) 
	{
		std::cout << "Enter the count of chrysanthemums in range:";
		std::cin >> countChrysanthemum;
	}
	int countRoses;
	std::cout << "The count of roses:";
	std::cin >> countRoses;
	while (countRoses < 0 || countRoses > 200)
	{
		std::cout << "Enter the count of roses in range:";
		std::cin >> countRoses;
	}
	int countTulips;
	std::cout << "The count of tulips:";
	std::cin >> countTulips;
	while (countTulips < 0 || countTulips > 200)
	{
		std::cout << "Enter the count of tulips in range:";
		std::cin >> countTulips;
	}
	char season;
	std::cout << "Enter a season: (P,L,E or Z)";
	std::cin >> season;
	char holiday;
	std::cout << "Is it a holiday or not? (Y or N)";
	std::cin >> holiday;
	double priceChr = 0.0;
	double priceRoses = 0.0;
	double priceTulips = 0.0;
	double priceAll = 0;
	int countAll = countChrysanthemum + countRoses + countTulips;
	switch (season)
	{
	case 'P': 
		priceChr = 2.0*countChrysanthemum;
		priceRoses = 4.10*countRoses;
		priceTulips = 2.5*countTulips;
		priceAll = priceChr + priceRoses + priceTulips;
		if (holiday == 'Y') 
		{
			priceAll = priceChr + priceRoses + priceTulips;
			priceAll = (0.15 * priceAll) + priceAll;
		}
		if (countTulips > 7) {
			priceAll = priceAll - (0.05 * priceAll);
		}
		break;
	case 'L':
		priceChr = 2.0 * countChrysanthemum;
		priceRoses = 4.10 * countRoses;
		priceTulips = 2.5 * countTulips;
		priceAll = priceChr + priceRoses + priceTulips;
		if (holiday == 'Y')
		{
			priceAll = priceChr + priceRoses + priceTulips;
			priceAll = (0.15 * priceAll) + priceAll;
		}
		break;
	case 'E':
		priceChr = 3.75 * countChrysanthemum;
		priceRoses = 4.5 * countRoses;
		priceTulips = 4.15 * countTulips;
		priceAll = priceChr + priceRoses + priceTulips;
		if (holiday == 'Y')
		{
			priceAll = priceChr + priceRoses + priceTulips;
			priceAll = (0.15 * priceAll) + priceAll;
		}
		break;
	case 'Z':
		priceChr = 3.75 * countChrysanthemum;
		priceRoses = 4.5 * countRoses;
		priceTulips = 4.15 * countTulips;
		priceAll = priceChr + priceRoses + priceTulips;
		if (holiday == 'Y')
		{
			priceAll = priceChr + priceRoses + priceTulips;
			priceAll = (0.15 * priceAll) + priceAll;
		}
		if (countRoses >= 10) 
		{
			priceAll = priceAll - (0.1 * priceAll);
		}
		break;
	default:
		std::cout << "There is no such season" << std::endl;
		break;
	}
	if (countAll > 20) {
		priceAll = priceAll - (0.2 * priceAll);
	}
	const int arange = 2;
	std::cout << std::setprecision(2) << std::fixed << "Price:" <<priceAll + arange << std::endl;

	system("pause");
	return 0;
}

