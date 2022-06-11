#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N, M, R;
int item[101];
bool visited[101];
int d[101][101];
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, u, v, x;
	cin >> N >> M >> R;
	for (i=1;i<=N;i++)
		cin >> item[i];
	fill_n(&d[0][0], 101*101, INF);
	for (i=1;i<=R;i++) {
		cin >> u >> v >> x;
		d[u][v] = x;
		d[v][u] = x;
	}
	for (i=1;i<=N;i++) d[i][i] = 0;
	for (k=1;k<=N;k++) {
		for (i=1;i<=N;i++) {
			for (j=1;j<=N;j++) {
				if (d[i][j] > d[i][k]+d[k][j])
					d[i][j] = d[i][k]+d[k][j];
			}
		}
	}
	int ans = 0, score;
	for (i=1;i<=N;i++) {
		score = 0;
		for (j=1;j<=N;j++) {
			if (d[i][j] <= M) {
				score += item[j];
			}
		}
		if (score > ans)
			ans = score;
	}
	cout << ans << '\n';
	return 0;
}

