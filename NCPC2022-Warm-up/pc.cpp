#include <iostream>
#include <vector>

using namespace std;

int main () {
	int num;
	vector<int> nums;
	while ( cin >> num ) {
		nums.push_back(num);
	}
	vector<vector<pair<int,int> > > lis; // <num, idx>
	for ( int i=0; i<nums.size(); i++ ) {
		int left = 0;
		int right = lis.size();
		int mid;
		while ( left < right ) {
			mid = left + (right-left)/2;
			if ( nums[i] > lis[mid].back().first ) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		if ( left == lis.size() ) {
			lis.push_back(vector<pair<int,int> >(1, make_pair(nums[i], i)) );
		} else {
			lis[left].push_back(make_pair(nums[i], i));
		}
	}

	for ( int i=lis.size()-2; i>=0; i-- ) {
		while ( lis[i].back().second > lis[i+1].back().second ) lis[i].pop_back();
	}

	cout << lis.size() << "\n-\n";
	for ( int i=0; i<lis.size(); i++ ) {
		cout << lis[i].back().first << '\n';
	}
	return 0;
}
