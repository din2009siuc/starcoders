#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int N;
vector<bool> isPrime;

int backtracking(vector<int>& digit_count, int cur_num) {
	int ans = 0;
	if ( isPrime[cur_num] ) ans++;
	for ( int i=0; i<10; i++ ) {
		if ( cur_num == 0 && i == 0 ) continue;
		if ( digit_count[i] > 0 ) {
			digit_count[i]--;
			ans += backtracking(digit_count, cur_num*10 + i);
			digit_count[i]++;
		}
	}
	return ans;
}

int main () {
	N = 10000000;
	isPrime = vector<bool>(N, true);
	isPrime[0] = isPrime[1] = false;
	for ( int num=2; num<N; num++ ) {
		if ( isPrime[num] ) {
			int tmp = num*2;
			while ( tmp < N ) {
				isPrime[tmp] = false;
				tmp += num;
			}
		}
	}

	int T;
	cin >> T;
	getc(stdin);
	for ( int c=0; c<T; c++ ) {
		vector<int> digit_count(10, 0);
		char ch;
		while ( (ch = getc(stdin)) != '\n' ) {
			digit_count[ch-'0']++;
		}
		cout << backtracking(digit_count, 0) << '\n';
	}

	return 0;
}
