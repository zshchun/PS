#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll L, R, i, j, ans = 0;
	cin >> L >> R;
	vector<ll> a, b;

	while (L || R) {
		a.push_back(L % 10);
		b.push_back(R % 10);
		L /= 10;
		R /= 10;
	}
	while (!a.empty() && !b.empty()) {
		if (a.back() == b.back()) {
			if (a.back() == 8 && b.back() == 8)
				ans++;
			a.pop_back();
			b.pop_back();
			continue;
		} else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
