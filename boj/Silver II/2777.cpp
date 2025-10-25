#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, i, r, x;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a;
		r = n;
		if (n == 1) a.push_back(1);
		for (i=9;i>=2;i--) {
			while (r % i == 0) {
				a.push_back(i);
				r /= i;
			}
		}
		if (r != 1) {
			cout << "-1\n";
			continue;
		}
		cout << a.size() << endl;
	}
	return 0;
}
