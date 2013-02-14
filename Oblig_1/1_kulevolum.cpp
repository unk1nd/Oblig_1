#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main()
{
	// V= 4/3*PI*R^3
	cout << "Skriv inn radius for å beregne kulevolum:" << endl;
	double radius;
	cin >> radius;

	if (radius > 0)
	{
		int volum = 4/3 * 3.14 * M_PI * pow(radius,3);
		return volum;
	}
}