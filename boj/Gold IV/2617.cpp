#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
int N, M, ans;
int d[100][100];
int dr[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, u, v;
	cin >> N >> M;
	fill_n(d[0], 100*100, INF);
	fill_n(dr[0], 100*100, INF);

	for (i=0;i<M;i++) {
		cin >> u >> v;
		d[u][v] = 1;
		dr[v][u] = 1;
	}
	for (i=1;i<=N;i++) {
		d[i][i] = 0;
		dr[i][i] = 0;
	}

	for (k=1;k<=N;k++) {
		for (i=1;i<=N;i++) {
			for (j=1;j<=N;j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
				if (dr[i][j] > dr[i][k] + dr[k][j])
					dr[i][j] = dr[i][k] + dr[k][j];
			}
		}
	}

	for (i=1;i<=N;i++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (j=1;j<=N;j++) {
			if (i == j) continue;
			if (d[i][j] != INF) cnt1++;
			if (dr[i][j] != INF) cnt2++;
		}
		if (cnt1 > (N-1) / 2 || cnt2 > (N-1) / 2)
			ans++;
	}
	cout << ans << endl;

	return 0;
}
