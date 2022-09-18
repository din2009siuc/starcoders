#include <iostream>

using namespace std;

int main () {
	int T;
	cin >> T;
	for ( int c=0; c<T; c++ ) {
		int N;
		cin >> N;
		int trav = max(1, N-50);
		while ( true ) {
			if ( trav == N ) {
				cout << 0 << '\n';
				break;
			}
			int tmp = trav;
			int sum = tmp;
			while ( tmp > 0 ) {
				sum += tmp%10;
				tmp /= 10;
			}
			if ( sum == N ) {
				cout << trav << '\n';
				break;
			}
			trav++;
		}
	}
	return 0;
}
