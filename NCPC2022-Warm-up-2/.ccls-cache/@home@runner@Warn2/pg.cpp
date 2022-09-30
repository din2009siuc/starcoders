#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
    	int x, k, p, q;
    	cin >> x >> k;
    	q = x%k;
		p = k-q;
		cout << p << ' ' << q << '\n';
	}
	return 0;
}