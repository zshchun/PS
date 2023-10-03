#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll G, l, r, g;
	cin >> G;
	l = 1, r = 1;
	vector<ll> ans;

	do {
		g = r * r - l * l;
		if (g == G) ans.push_back(r);
		if (g > G)
			l++;
		else
			r++;
	} while (g <= G || l < r);

	for (ll x : ans)
		cout << x << endl;
	
	if (ans.empty())
		cout << "-1\n";

	return 0;
}
