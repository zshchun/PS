#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v, t;
	cin >> t;
	while (t--) {
		vector<int> a(10);
		for (i=0;i<10;i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		cout << a[7] << endl;
	}
	return 0;
}
