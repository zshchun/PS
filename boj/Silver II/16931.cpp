#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int a[101][101];
int N, M;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, x, y, d, ans;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> a[i][j];
		}
	}
	ans = 2 * N * M;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			for (k=0;k<4;k++) {
				y = i + dy[k];
				x = j + dx[k];
				if (x < 0 || y < 0 || y >= N || x >= M) {
					d = a[i][j];
				} else {
					d = a[i][j] - a[y][x];
				}
				if (d > 0)
					ans += d;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
