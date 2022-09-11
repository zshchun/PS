#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool m[51][51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, L, i, j, k, x, ans=0;
	cin >> N >> M;
	cin >> L;
	for (i=0;i<L;i++) {
		cin >> x;
		m[x][0] = 1;
	}
	vector<int> c[M];
	for (i=0;i<M;i++) {
		cin >> L;
		c[i].resize(L);
		for (int &p : c[i])
			cin >> p;
		for (j=0;j<L-1;j++) {
			int u = c[i][j];
			for (k=j+1;k<L;k++) {
				int v = c[i][k];
				m[u][v] = 1;
				m[v][u] = 1;
			}
		}
	}
	for (k=0;k<=N;k++)
		for (i=0;i<=N;i++)
			for (j=0;j<=N;j++)
				if (m[i][k] && m[k][j])
					m[i][j] = 1;
	for (i=0;i<M;i++) {
		if (c[i].size() && !m[c[i][0]][0])
			ans++;
	}
	cout << ans << '\n';
	return 0;
}

