#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void BFS(int i, int j, vector<vector<int> > &distances) {
	queue<pair<int, int> > que;
	que.push(make_pair(i, j));
	int count = 0;
	while ( !que.empty() ) {
		int size = que.size();
		for ( int _=0; _<size; _++ ) {
			int cur_i = que.front().first;
			int cur_j = que.front().second;
			que.pop();
			distances[cur_i][cur_j] = count;
			if ( cur_i < distances.size()-1 && distances[cur_i+1][cur_j] == INT_MAX ) {
				que.push(make_pair(cur_i+1, cur_j));
				distances[cur_i+1][cur_j]--;
			}
			if ( cur_i > 0 && distances[cur_i-1][cur_j] == INT_MAX ) {
				que.push(make_pair(cur_i-1, cur_j));
				distances[cur_i-1][cur_j]--;
			}
			if ( cur_j < distances[0].size()-1 && distances[cur_i][cur_j+1] == INT_MAX ) {
				que.push(make_pair(cur_i, cur_j+1));
				distances[cur_i][cur_j+1]--;
			}
			if ( cur_j > 0 && distances[cur_i][cur_j-1] == INT_MAX ) {
				que.push(make_pair(cur_i, cur_j-1));
				distances[cur_i][cur_j-1]--;
			}
		}
		count++;
	}
	return;
}

int escape(int i, int j, vector<vector<int> >& fire_dst) {
	queue<pair<int, int> > que;
	que.push(make_pair(i, j));
	vector<vector<bool> > visited(fire_dst.size(), vector<bool>(fire_dst[0].size(), false));
	int time = 0;
	while ( !que.empty() ) {
		int size = que.size();
		for ( int _=0; _<size; _++ ) {
			int cur_i = que.front().first;
			int cur_j = que.front().second;
			que.pop();
			if ( fire_dst[cur_i][cur_j] == -1 ) continue;
			if ( time >= fire_dst[cur_i][cur_j] ) continue;
			if ( cur_i == 0 || cur_i == fire_dst.size()-1 || cur_j == 0 || cur_j == fire_dst[0].size()-1 ) return time+1;
			if ( !visited[cur_i-1][cur_j] ) que.push(make_pair(cur_i-1, cur_j));
			visited[cur_i-1][cur_j] = true;
			if ( !visited[cur_i+1][cur_j] ) que.push(make_pair(cur_i+1, cur_j));
			visited[cur_i+1][cur_j] = true;
			if ( !visited[cur_i][cur_j-1] ) que.push(make_pair(cur_i, cur_j-1));
			visited[cur_i][cur_j-1] = true;
			if ( !visited[cur_i][cur_j+1] ) que.push(make_pair(cur_i, cur_j+1));
			visited[cur_i][cur_j+1] = true;
		}
		time++;
	}
	return -1;
}

int main () {
	int T;
	cin >> T;
	for ( int c=0; c<T; c++ ) {
		int R,C;
		cin >> R >> C;
		vector<vector<char> > maze(R, vector<char>(C));
		vector<vector<int> > distances(R, vector<int>(C));
		int fire_i, fire_j;
		int joe_i, joe_j;
		for ( int i=0; i<R; i++ ) {
			for ( int j=0; j<C; j++ ) {
				cin >> maze[i][j];
				distances[i][j] = maze[i][j] == '#'? -1: INT_MAX;
				if ( maze[i][j] == 'F' ) {
					fire_i = i;
					fire_j = j;
				} else if ( maze[i][j] == 'J' ) {
					joe_i = i;
					joe_j = j;
				}
			}
		}
		// count distance from fire
		BFS(fire_i, fire_j, distances);
		/*
		for ( int i=0; i<R; i++ ) {
			for ( int j=0; j< C; j++ ) {
				cout << distances[i][j] << ' ';
			}
			cout << '\n';
		}*/
		int res = escape(joe_i, joe_j, distances);
		if ( res == -1 ) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << res << '\n';
		}
	}
	return 0;
}
