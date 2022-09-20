#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void fire_BFS(queue<pair<int, int> >& que, vector<vector<int> >& fire_dst) {
	vector<vector<bool> > visited(fire_dst.size(), vector<bool>(fire_dst[0].size(), false));
	int dst = 0;
	while ( !que.empty() ) {
		int size = que.size();
		for ( int _=0; _<size; _++ ) {
			int cur_i = que.front().first;
			int cur_j = que.front().second;
			que.pop();
			if ( cur_i < 0 || cur_j < 0 || cur_i >= fire_dst.size() || cur_j >= fire_dst[0].size() ) continue;
			if ( visited[cur_i][cur_j] ) continue;
			visited[cur_i][cur_j] = true;
			if ( fire_dst[cur_i][cur_j] == -1 ) continue;
			fire_dst[cur_i][cur_j] = dst;
			que.push(make_pair(cur_i-1, cur_j));
			que.push(make_pair(cur_i+1, cur_j));
			que.push(make_pair(cur_i, cur_j-1));
			que.push(make_pair(cur_i, cur_j+1));
		}
		dst++;
	}
	return;
}

int joe_BFS(int s_i, int s_j, vector<vector<int> >& fire_dst) {
	vector<vector<bool> > visited(fire_dst.size(), vector<bool>(fire_dst[0].size(), false));
	queue<pair<int, int> > que;
	que.push(make_pair(s_i, s_j));
	int dst = 0;
	while ( !que.empty() ) {
		int size = que.size();
		for ( int _=0; _<size; _++ ) {
			int cur_i = que.front().first;
			int cur_j = que.front().second;
			que.pop();
			if ( cur_i < 0 || cur_j < 0 || cur_i >= fire_dst.size() || cur_j >= fire_dst[0].size() ) return dst;
			if ( visited[cur_i][cur_j] ) continue;
			visited[cur_i][cur_j] = true;
			if ( fire_dst[cur_i][cur_j] <= dst ) continue;
			que.push(make_pair(cur_i-1, cur_j));
			que.push(make_pair(cur_i+1, cur_j));
			que.push(make_pair(cur_i, cur_j-1));
			que.push(make_pair(cur_i, cur_j+1));
		}
		dst++;
	}
	return -1;
}

int main () {
	int T;
	cin >> T;
	for ( int c=1; c<=T; c++ ) {
		int R, C;
		cin >> R >> C;
		vector<vector<char> > maze(R, vector<char>(C));
		queue<pair<int,int> > fire_que;
		int joe_i, joe_j;
		vector<vector<int> > fire_dst(R, vector<int>(C));
		for ( int i=0; i<R; i++ ) {
			for ( int j=0; j<C; j++ ) {
				cin >> maze[i][j];
				if ( maze[i][j] == '#' ) {
					fire_dst[i][j] = -1;
				} else {
					fire_dst[i][j] = INT_MAX;
				}
				if ( maze[i][j] == 'F' ) {
					fire_que.push(make_pair(i, j));
				} else if ( maze[i][j] == 'J' ) {
					joe_i = i;
					joe_j = j;
				}
			}
		}
		fire_BFS(fire_que, fire_dst);
		int res = joe_BFS(joe_i, joe_j, fire_dst);
		if ( res == -1 ) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << res << '\n';
		}
	}
	return  0;
}
