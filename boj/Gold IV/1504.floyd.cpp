#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;

#define INF 9999999
int m[801][801];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, E, i, j, k, u, v, w, v1, v2;
	cin >> N >> E;
	for (i=0;i<=N;i++) {
		for (j=0;j<=N;j++) {
			if (i == j)
				m[i][j] = 0;
			else
				m[i][j] = INF;
		}
	}
	for (i=0;i<E;i++) {
		cin >> u >> v >> w;
		m[u][v] = w;
		m[v][u] = w;
	}
	cin >> v1 >> v2;
	for (k=1;k<=N;k++) {
		for (i=1;i<=N;i++) {
			for (j=1;j<=N;j++) {
				if (m[i][j] > m[i][k]+m[k][j])
					m[i][j] = m[i][k]+m[k][j];
			}
		}
	}
	int ans = min(m[1][v1] + m[v1][v2] + m[v2][N], m[1][v2] + m[v2][v1] + m[v1][N]);
	if (ans < INF)
		cout << ans << '\n';
	else
		cout << "-1\n";
	return 0;
}

