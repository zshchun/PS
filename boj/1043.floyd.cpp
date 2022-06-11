#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[51][51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, H, i, j, k, v, u, x;
	cin >> N >> M;
	cin >> H;
	for (i=0;i<H;i++) {
		cin >> x;
		m[x][0] = 1;
	}
	vector<int> c[M];
	for (i=0;i<M;i++) {
		cin >> H;
		for (j=0;j<H;j++) {
			cin >> x;
			c[i].push_back(x);
		}
		for (j=1;j<(int)c[i].size();j++) {
			for (k=0;k<=j;k++) {
				u = c[i][j];
				v = c[i][k];
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
	int ans = 0;
	for (i=0;i<M;i++)
		if (c[i].size() && !m[c[i][0]][0])
			ans++;
	cout << ans << '\n';
	return 0;
}
