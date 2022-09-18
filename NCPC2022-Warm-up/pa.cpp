#include <iostream>
#include <math.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	double d;
	for ( int c=0; c<t; c++ ) {
		cin >> d;
		d = ( d * 567 / 9 + 7492 ) * 235 / 47 - 498;
		d = abs(d);
		cout << ((int)floor(d)) / 10 % 10 << '\n';
	}
	return 0;
}
