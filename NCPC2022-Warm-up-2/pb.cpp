#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void printMaze(vector<vector<char>>& maze) {
	for ( int i=0; i<maze.size(); i++ ) {
		for ( int j=0; j<maze[0].size(); j++ ) {
			cout << maze[i][j];
		}
		cout << '\n';
	}
}

bool DFS(vector<vector<char>>& maze, int i, int j, int dy, int dx ) {
	if ( i < 0 || i >= maze.size() ) return true;
	if ( j < 0 || j >= maze[0].size() ) return true;
	if ( maze[i][j] == '*' ) return false;
	if ( maze[i][j] == '.' ) return DFS(maze, i+dy, j+dx, dy, dx);
	if ( maze[i][j] == '/' || maze[i][j] == 'm' ) {
		char orgc = maze[i][j];
		int newdy = -dx;
		int newdx = -dy;
		maze[i][j] = '/';
		if ( DFS(maze, i+newdy, j+newdx, newdy, newdx) ) return true;
		maze[i][j] = orgc;
	}
	if ( maze[i][j] == '\\' || maze[i][j] == 'm' ) {
		char orgc = maze[i][j];
		int newdy = dx;
		int newdx = dy;
		maze[i][j] = '\\';
		if ( DFS(maze, i+newdy, j+newdx, newdy, newdx) ) return true;
		maze[i][j] = orgc;
	}
	return false;
}


int main () {
	int R, C;
	bool first = true;
	while ( true ) {
		cin >> C >> R;
		if ( C == -1 || R == -1 ) break;
		if ( !first ) cout << '\n';
		first = false;
		vector<vector<char>> maze(R, vector<char>(C));
		vector<vector<char>> cmaze(R, vector<char>(C));
		for ( int i=0; i<R; i++ ) {
			string str;
			cin >> str;
			for ( int j=0; j<C; j++ ) {
				maze[i][j] = str[j];
				cmaze[i][j] = str[j];
				if ( maze[i][j] == '/' || maze[i][j] == '\\') {
					maze[i][j] = 'm';
				}
			}
		}
		
		int entryi, entryj;
		int dy, dx;
		for ( int i=0; i<R; i++ ) {
			if ( maze[i][0] == '.') {
				entryi = i;
				entryj = 0;
				dy = 0;
				dx = 1;
			}
			if ( maze[i][C-1] == '.' ) {
				entryi = i;
				entryj = C-1;
				dy = 0;
				dx = -1;
			}
		}
		for ( int j=0; j<C; j++ ) {
			if ( maze[0][j] == '.') {
				entryi = 0;
				entryj = j;
				dy = 1;
				dx = 0;
			}
			if ( maze[R-1][j] == '.' ) {
				entryi = R-1;
				entryj = j;
				dy = -1;
				dx = 0;
			}
		}

		DFS(maze, entryi, entryj, dy, dx);
		for ( int i=0; i<R; i++ ) {
			for ( int j=0; j<C; j++ ) {
				if ( maze[i][j] == 'm' ) {
					maze[i][j] = cmaze[i][j];
				}
			}
		}
		printMaze(maze);
	}
	return 0;
}