#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define VISIBLE   1
#define INVISIBLE 2
int a[1001][1001];
int ans[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int C, N, i, j, x, y;

	a[1][0] = VISIBLE;
	a[0][1] = VISIBLE;
	for (i=2;i<=1000;i++) {
		a[i][0] = INVISIBLE;
		a[0][i] = INVISIBLE;
	}
	ans[1] = 3;
	for (i=2;i<=1000;i++) {
		int cnt = 0;
		for (j=1;j<i;j++) {
			if (a[i][j]) continue;
			a[i][j] = VISIBLE;
			a[j][i] = VISIBLE;
			cnt += 2;
			y = i + i;
			x = j + j;
			while (x <= 1000 && y <= 1000) {
				a[y][x] = INVISIBLE;
				y += i;
				x += j;
			}
		}
		ans[i] = ans[i-1] + cnt;
	}

	cin >> C;
	while (C--) {
		cin >> N;
#if 0
		for (i=0;i<=N;i++) {
			for (j=0;j<=N;j++) {
				if (a[i][j] == VISIBLE)
					ans++;
			}
		}
#endif
		cout << ans[N] << endl;
	}

	return 0;
}
