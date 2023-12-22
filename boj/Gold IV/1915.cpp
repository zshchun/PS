#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[1001][1001];
#define VERT 0
#define HORI 1

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, i, j, k, x, y, ans = 0;
	char c;
	cin >> N >> M;
	for (i=1;i<=N;i++) {
		for (j=1;j<=M;j++) {
			cin >> c;
			a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + (c-'0');
		}
	}
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			for (k=1;k<1000;k++) {
				y = i + k;
				x = j + k;
				if (y > N || x > M) break;
				int sum = a[y][x] - a[y][j] - a[i][x] + a[i][j];
				if (sum != k * k) break;
				ans = max(ans, sum);
			}
		}
	}

	cout << ans << endl;
	return 0;
}
