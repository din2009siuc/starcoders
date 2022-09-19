#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool try_jump(const vector<int>& stones, const vector<bool>& isBig, int max_dst) {
	// cout << "try: " << max_dst << '\n';
	vector<int> used(stones.size(), false);
	int cur = 0;
	int next = 1;
	while ( cur < stones.size()-1 ) {
		while ( next < stones.size()-1 && !isBig[next] && stones[next+1]-stones[cur] <= max_dst ) {
			next++;
		}
		if ( stones[next]-stones[cur] > max_dst ) return false;
		if ( !isBig[next] ) used[next] = true;
		cur = next;
		next++;
	}
	int prev = 0;
	for ( int i=1; i<stones.size(); i++ ) {
		if ( used[i] ) continue;
		if ( stones[i]-stones[prev] > max_dst ) return false;
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
		vector<bool> isBig(N+2);
		vector<int> stones(N+2);
		isBig[0] = isBig[N+1] = true;
		stones[0] = 0;
		stones[N+1] = D;
		string str;
		for ( int i=1; i<=N; i++ ) {
			cin >> str;
			isBig[i] = str[0]=='B';
			stones[i] = stoi(str.substr(2));
		}
		// Find maximum distance
		int right = D;
		int left = 1;
		int mid;
		while ( left < right ) {
			mid = left + (right-left)/2;
			if ( try_jump(stones, isBig, mid) ) {
				right = mid;
			} else {
				left = mid+1;
			}
		}
		cout << "Case " << c << ": " << left << '\n';
	}
	return 0;
}
