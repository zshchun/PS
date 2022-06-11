#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, X, i, u, v, w, j, k;
	cin >> N >> M >> X;
	memset(m, 0x33, sizeof(m));
	for (i=0;i<M;i++) {
		cin >> u >> v >> w;
		m[u][v] = w;
	}
	for (i=1;i<=N;i++)
		m[i][i] = 0;
	for (k=1;k<=N;k++)
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
				if (m[i][j] > m[i][k]+m[k][j])
					m[i][j] = m[i][k]+m[k][j];
	int ans = 0;
	for (i=1;i<=N;i++) {
		ans = max(ans, m[X][i]+m[i][X]);
	}
	cout << ans << '\n';

	return 0;
}

