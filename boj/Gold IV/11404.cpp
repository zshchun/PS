#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int d[101][101];

#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, i, j, k, u, v, x;

	cin >> n >> m;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
	for (i=0;i<m;i++) {
		cin >> u >> v >> x;
		if (x < d[u][v])
			d[u][v] = x;
	}
	for (k=1;k<=n;k++) {
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (d[i][j] > d[i][k]+d[k][j]) {
					d[i][j] = d[i][k]+d[k][j];
				}
			}
		}
	}
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (j > 1) cout << ' ';
			if (d[i][j] == INF)
				cout << '0';
			else
				cout << d[i][j];
		}
		cout << '\n';
	}

	return 0;
}

