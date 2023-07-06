#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll g[201][201];
ll route[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, M, i, j, k, x, ans = true;
	ll cur, next;
	cin >> N >> M;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			cin >> g[i][j];
			if (g[i][j] || i == j)
				g[j][i] = 1;
		}
	}

	for (i=0;i<M;i++) {
		cin >> route[i];
	}

	// floyd-warshall
	for (k=1;k<=N;k++) {
		for (i=1;i<=N;i++) {
			for (j=1;j<=N;j++) {
				if (g[i][k] & g[k][j])
					g[i][j] = 1;
			}
		}
	}

	for (i=0;i<M-1;i++) {
		cur = route[i];
		next = route[i+1];
		if (!g[cur][next]) {
			ans = false;
			break;
		}
	}

	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";


	return 0;
}
