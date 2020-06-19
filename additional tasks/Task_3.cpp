#include <iostream>

int main()
{
	
	int N;
	int M;
	int S;
	std::cout << "N:";
	std::cin >> N;
	std::cout << "M:";
	std::cin >> M;

	while (N < 0 || N > M) {
		std::cout << "Enter number N in range:";
		std::cin >> N;
	}
	while (M < N || M >= 10000) 
	{
		std::cout << "Enter number M in range:";
		std::cin >> M;
	}
	std::cout << "S:";
	std::cin >> S;
	while (S < N || S > M) 
	{
		std::cout << "Enter number S in range:";
		std::cin >> S;
	}
	int arr[10000];
	int index = 0;
	for (int i = M; i >= N; i--) 
	{
		if (i % 2 == 0 && i % 3 == 0) 
		{
			if (i == S)
			{
				for (int i = M; i > S; i--)
				{
					if (i % 2 == 0 && i % 3 == 0)
					{
						break;
						std::cout << i << " ";
					}
				}
				break;
			}
			else 
			{
				std::cout << i << " ";
			}
			
		}
	
	}
	
	system("pause");
	return 0;
}

