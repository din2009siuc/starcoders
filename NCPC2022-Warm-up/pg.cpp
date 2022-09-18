#include <iostream>
#include <vector>

using namespace std;

int recur(vector<int>& stones, int cur_stone, vector<bool>& isBig, vector<bool>& used, int cur_max, vector<int>& memorize) {
	if ( memorize[cur_stone] != -1 ) return memorize[cur_stone];
	if ( cur_stone == stones.size()-1 ) {
		int last = 0;
		for ( int i=1; i<stones.size(); i++ ) {
			if ( used[i] ) continue;
			if ( stones[i]-last > cur_max ) cur_max = stones[i]-last;
			last = stones[i];
		}
		return cur_max;
	}
	if ( isBig[cur_stone+1] || cur_stone == stones.size()-2 ) {
		cur_max = max(cur_max, stones[cur_stone+1]-stones[cur_stone]);
		return recur(stones, cur_stone+1, isBig, used, cur_max, memorize);
	}
	if ( !isBig[cur_stone+1] ) used[cur_stone+1] = true;
	int jump1 = recur(stones, cur_stone+1, isBig, used, max(cur_max, stones[cur_stone+1]-stones[cur_stone]), memorize );
	used[cur_stone+1] = false;
	if ( !isBig[cur_stone+2] ) used[cur_stone+2] = true;
	int jump2 = recur(stones, cur_stone+2, isBig, used, max(cur_max, stones[cur_stone+2]-stones[cur_stone]), memorize );
	used[cur_stone+2] = false;
	memorize[cur_stone] = min(jump1, jump2);
	return min(jump1, jump2);
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
		vector<bool> used(N+2, false);
		vector<int> memorize(N+2, -1);
		cout << "Case " << c << ": " << recur(stones, 0, isBig, used, 0, memorize) << '\n';
	}
	return 0;
}
