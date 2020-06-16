//Differentiating polynomials
#include <iostream>

using namespace std;


int main()
{
	int N;
	cout << "Enter N:";
	cin >> N;
	int coefficients[1000];

	for (int i = 0; i <= N; i++) {
		cout << "Coefficient - " << i << ":";
		cin >> coefficients[i];
	}

	int derivative;
	cout << "Derivative:";
	cin >> derivative;

	

	int trackDegreeAfterDiff = N;

	while (derivative > 0) {
		for (int i = 0, j = trackDegreeAfterDiff; i <= N; i++, j--) {
			coefficients[i] *= j;
		}
		trackDegreeAfterDiff--;
		derivative--;
	}


	for (int i = 0, j = trackDegreeAfterDiff; i <= N; i++, j--) {

		if (coefficients[i] != 0 && j > 1) {
			cout << coefficients[i] << "*X^" << j;
			cout << " + ";
		}
		if (j == 0) {
			cout << coefficients[i];
		}
		if (j == 1) {
			cout << coefficients[i] << "*X";
			cout << " + ";
		}
		
	}

	cout << endl;




	system("pause");
	return 0;
}

