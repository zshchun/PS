#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, s, i, g = 0, v, d;
	cin >> n >> s;
	vector<int> a;
	for (i=0;i<n;i++) {
		cin >> v;
		d = abs(s-v);
		if (i) g = gcd(g, d);
		else g = d;
		a.push_back(d);
	}
	cout << g << endl;
	return 0;
}
