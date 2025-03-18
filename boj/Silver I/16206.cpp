#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, v, i, j, ans = 0;
	cin >> N >> M;
	vector<int> a;
	for (i=0;i<N;i++) {
		cin >> v;
		if (v < 10) continue;
		if (v == 10) ans++;
		else
			a.push_back(v);

	}

	sort(a.begin(), a.end(), [&](int lhs, int rhs) {
		if (lhs % 10 == 0 && rhs % 10 == 0)
			return lhs < rhs;
		else
			return lhs % 10 == 0;
	});
	for (i=0;i<a.size() && M;i++) {
		j = a[i] / 10;
		if (a[i] % 10 == 0) {
			if (j-1 <= M) {
				ans += j;
				M -= j - 1;
			} else {
				ans += M;
				break;
			}
		} else {
			if (j <= M) {
				ans += j;
				M -= j;
			} else {
				ans += M;
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
