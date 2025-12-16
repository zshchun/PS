#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define X first
#define Y second
int N, M, T, K, ans, ans_x, ans_y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, cnt;
	cin >> N >> M >> T >> K;
	vector<int> xs(T), ys(T);
	vector<pa> a(T);
	
	for (i=0;i<T;i++) {
		cin >> xs[i] >> ys[i];
		a[i].X = xs[i];
		a[i].Y = ys[i];
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	for (int sx : xs) {
		int ex = sx + K;
		for (int sy : ys) {
			int ey = sy + K;
			cnt = 0;
			for (auto &[x, y] : a) {
				if (sx <= x && x <= ex && sy <= y && y <= ey)
					cnt++;
			}
			if (cnt > ans) {
				ans = cnt;
				ans_x = min(N-K, sx);
				ans_y = min(M, ey);
			}
		}
	}
	cout << ans_x << ' ' << ans_y << endl;
	cout << ans << endl;
	return 0;
}
