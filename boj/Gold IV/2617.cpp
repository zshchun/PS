#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
int N, M, ans;
bool d[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, u, v;
	cin >> N >> M;

	for (i=0;i<M;i++) {
		cin >> u >> v;
		d[u][v] = 1;
	}

	for (k=1;k<=N;k++) {
		for (i=1;i<=N;i++) {
			for (j=1;j<=N;j++) {
				if (d[i][k] && d[k][j])
					d[i][j] = 1;
			}
		}
	}

	for (i=1;i<=N;i++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (j=1;j<=N;j++) {
			if (i == j) continue;
			if (d[i][j]) cnt1++;
			if (d[j][i]) cnt2++;
		}
		if (cnt1 > (N-1) / 2 || cnt2 > (N-1) / 2)
			ans++;
	}
	cout << ans << endl;

	return 0;
}
