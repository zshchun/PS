#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x, y, n1, n2, ans;
	cin >> N >> M;
	vector<pa> a(M);
	for (i=0;i<M;i++)
		cin >> a[i].first >> a[i].second;

	for (i=0;i<(1<<N);i++) {
		ans = 1;
		for (auto [x, y] : a) {
			int result = 0;
			n1 = x < 0 ? 1 : 0;
			n2 = y < 0 ? 1 : 0;

			if (x < 0) result = !(i & (1 << (-x-1)));
			else result = !!(i & (1 << (x-1)));

			if (y < 0) result |= !(i & (1 << (-y-1)));
			else result |= !!(i & (1 << (y-1)));
			ans &= result;
		}
		if (ans) break;
	}
	if (ans) cout << "1\n";
	else cout << "0\n";
	return 0;
}
