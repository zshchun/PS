#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
int n, m;
int dist[201][201];
int ans[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, u, v, d;

	cin >> n >> m;
	fill_n(&dist[0][0], 201*201, INF);

	for (i=0;i<m;i++) {
		cin >> u >> v >> d;
		dist[u][v] = dist[v][u] = d;
		ans[u][v] = v;
		ans[v][u] = u;
	}

	for (i=1;i<=n;i++)
		dist[i][i] = 0;

	// floyd-warshall
	for (k=1;k<=n;k++) {
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					ans[i][j] = ans[i][k];
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (i == j)
				cout << "- ";
			else
				cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
