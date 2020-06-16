#include <iostream>

using namespace std;

int main()
{
	int x1, y1, r1, x2, y2, r2;
	cout << "x1 = ";
	cin >> x1;
	cout << "y1 = ";
	cin >> y1;
	cout << "r1 = ";
	cin >> r1;
	cout << "x2 = ";
	cin >> x2;
	cout << "y2 = ";
	cin >> y2;
	cout << "r2 = ";
	cin >> r2;

	double sumOfRadii = r1 + r2;

	double xS = pow((x1 - x2), 2);
	double yS = pow((y1 - y2), 2);
	double distance = sqrt(xS + yS);

	if (distance > sumOfRadii) {
		cout << "The circles do NOT intersect!";
	}
	else if (distance < sumOfRadii) {
		cout << "The circles intersect!";
	}
	else {
		cout << "The circles touch!" <<endl;
	}





	system("pause");
	return 0;
}

