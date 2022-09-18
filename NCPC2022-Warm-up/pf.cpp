#include <iostream>
#include <vector>

using namespace std;

int N = 20000001;
long long table[20000001+1] = {0};

int main () {
	for ( int num=2; num<=N; num++ ) {
		table[num]++;
		int tmp = num;
		while ( tmp <= N ) {
			table[tmp] += num;
			tmp += num;
		}
	}
	for ( int num=2+1; num<=N; num++ ) {
		table[num] += table[num-1];
	}

	int n;
	while ( cin >> n && n ) {
		cout << table[n] << '\n';
	}

	return 0;
}
