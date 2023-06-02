#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll sum = 0;
	map<string, ll> m;
	string s;
	while (getline(cin, s)) {
		m[s]++;
		sum++;
	}

	cout.precision(4);
	for (auto &x: m) {
		double pop = x.second / (double)sum * 100.0;
		cout << x.first << " " << fixed << pop << endl;;

	}

	return 0;
}
