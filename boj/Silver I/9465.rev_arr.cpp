#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int d[2][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, N, T;
	cin >> T;
	while (T--) {
		cin >> N;
		int ans = 0;
		for (i=0;i<N;i++) cin >> d[0][i];
		for (i=0;i<N;i++) cin >> d[1][i];
		ans = max(d[0][0], d[1][0]);
		if (N > 1) {
			d[0][1] += d[1][0];
			d[1][1] += d[0][0];
			ans = max({d[0][1], d[1][1], ans});
		}
		for (i=2;i<N;i++) {
			d[0][i] += max({d[1][i-1], d[0][i-2], d[1][i-2]});
			d[1][i] += max({d[0][i-1], d[0][i-2], d[1][i-2]});
			ans = max({d[0][i], d[1][i], ans});
		}
		cout << ans << '\n';
	}
	return 0;
}

