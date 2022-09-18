#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtracking(int n, vector<int> &remain_chars, string cur_str) {
	if ( n == 0 ) {
		cout << cur_str << '\n';
	}
	for ( int i=0; i<26; i++ ) {
		if ( remain_chars[i] > 0 ) {
			remain_chars[i]--;
			backtracking(n-1, remain_chars, cur_str+(char)('a'+i));
			remain_chars[i]++;
		}
	}
}

int main () {
	int t;
	cin >> t;
	for ( int c=0; c<t; c++ ) {
		string str;
		cin >> str;
		vector<int> chars(26, 0);
		for ( int i=0; i<str.size(); i++ ) {
			chars[str[i]-'a']++;
		}
		backtracking(str.size(), chars, "");
		cout << '\n';
	}
	return 0;
}
