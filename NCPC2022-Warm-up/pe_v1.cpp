#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int t;
	cin >> t;
	for ( int c=0; c<t; c++ ) {
		string str;
		cin >> str;
		do {
			cout << str << '\n';
		} while ( next_permutation(str.begin(), str.end()) );
		cout << '\n';
	}
	return 0;
}
