#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool try_jump(int d, vector<int>& stones, vector<int> isBig) {
	int cur = 0;
	int next = 1;
	while ( cur != stones.size()-1 ) {
		while ( next != stones.size()-1 &&
				isBig[next] == 0 &&
				stones[next+1]-stones[cur] <= d ) {
			next++;
		}
		if ( stones[next] - stones[cur] > d ) {
			return false;
		}
		if ( isBig[next] == 0 ) isBig[next] = -1;
		cur = next;
		next = cur+1;
	}
	int prev = 0;
	for ( int i=0; i<stones.size(); i++ ) {
		if ( isBig[i] == -1 ) continue;
		if ( stones[i] - stones[prev] > d ) {
			return false;
		}
		prev = i;
	}
	return true;
}

int main () {
	int T;
	cin >> T;
	for ( int c=1; c<=T; c++ ) {
		int N, D;
		cin >> N >> D;
		vector<int> stones(N+2);
		vector<int> isBig(N+2);
		stones[0] = 0;
		stones[N+1] = D;
		isBig[0] = isBig[N+1] = 1;
		string str;
		for ( int i=0; i<N; i++ ) {
			cin >> str;
			if ( str[0] == 'B' ) {
				isBig[i+1] = 1;
			} else {
				isBig[i+1] = 0;
			}
			stones[i+1] = stoi(str.substr(2));
		}

		int left = 1;
		int right = D;
		int mid;
		while ( left != right ) {
			mid = left + (right-left)/2;
			if ( try_jump(mid, stones, isBig) ) {
				right = mid;
			} else {
				left = mid+1;
			}
		}
		cout << "Case " << c << ": " << left << '\n';
	}
}