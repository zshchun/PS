#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int w, n;
pa a[1001];
int dp[1001][1001];

int dfs(int car1, int car2) {
	int x1 = 1, y1 = 1, x2 = n, y2 = n, d1, d2, cur, next, ny, nx;

	cur = max(car1, car2);
	if (cur == w)
		return 0;
	if (dp[car1][car2] != -1)
		return dp[car1][car2];

	if (car1) tie(y1, x1) = a[car1];
	if (car2) tie(y2, x2) = a[car2];

	next = cur + 1;
	ny = a[next].first;
	nx = a[next].second;

	d1 = abs(ny - y1) + abs(nx - x1) + dfs(next, car2);
	d2 = abs(ny - y2) + abs(nx - x2) + dfs(car1, next);
	
	return dp[car1][car2] = min(d1, d2);
}

void trace(int car1, int car2) {
	int x1 = 1, y1 = 1, x2 = n, y2 = n, d1, d2, cur, next, ny, nx;

	cur = max(car1, car2);
	if (cur == w) return;

	if (car1) tie(y1, x1) = a[car1];
	if (car2) tie(y2, x2) = a[car2];

	next = cur + 1;
	ny = a[next].first;
	nx = a[next].second;

	d1 = abs(ny - y1) + abs(nx - x1) + dp[next][car2];
	d2 = abs(ny - y2) + abs(nx - x2) + dp[car1][next];
	if (d1 < d2) {
		cout << 1 << endl;
		trace(next, car2);
	} else {
		cout << 2 << endl;
		trace(car1, next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, x, y, ans;
	cin >> n >> w;
	fill_n(dp[0], 1001*1001, -1);

	for (i=1;i<=w;i++) {
		cin >> y >> x;
		a[i] = pa(y, x);
	}

	ans = dfs(0, 0);

	cout << ans << endl;
	trace(0, 0);

	return 0;
}
