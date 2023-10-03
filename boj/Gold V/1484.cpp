#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, G;
	cin >> G;
	vector<pa> a;
	unordered_set<ll> s;
	for (i=1;i<=100000;i++) {
		a.push_back(pa(i, i * i));
		s.insert(i * i);
	}
	bool found = false;
	for (pa &p : a) {
		if (p.second <= G) continue;
		if (s.count(p.second - G)) {
			cout << p.first << endl;
			found = true;
		}
	}
	if (!found)
		cout << "-1\n";

	return 0;
}
