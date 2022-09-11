#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int d[100001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, N, T;
	cin >> T;
	while (T--) {
		cin >> N;
		int ans = 0;
		for (i=0;i<N;i++) cin >> d[i][0];
		for (i=0;i<N;i++) cin >> d[i][1];
		ans = max(d[0][0], d[0][1]);
		if (N > 1) {
			d[1][0] += d[0][1];
			d[1][1] += d[0][0];
			ans = max({d[1][0], d[1][1], ans});
		}
		for (i=2;i<N;i++) {
			d[i][0] += max({d[i-1][1], d[i-2][1]});
			d[i][1] += max({d[i-1][0], d[i-2][0]});
			ans = max({d[i][0], d[i][1], ans});
		}
		cout << ans << '\n';
	}
	return 0;
}

