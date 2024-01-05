#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll a[301][21];
ll dp[301][21];
ll hist[301][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, N, M;
	cin >> N >> M;
	for (i=1;i<=N;i++) {
		cin >> k;
		for (j=1;j<=M;j++) {
			cin >> a[i][j];
		}
	}

	for (k=1;k<=M;k++) {
		for (i=1;i<=N;i++) {
			for (j=0;j<=i;j++) {
				int n = i - j;
				if (dp[i][k] < dp[n][k-1] + a[j][k]) {
					dp[i][k] = dp[n][k-1] + a[j][k];
					hist[i][k] = j;
				}
			}
		}
	}

	int n = N;
	int idx = M;
	deque<int> q;
	while (idx > 0) {
		int cost = hist[n][idx];
		q.push_front(cost);
		n -= cost;
		idx--;
	}
	cout << dp[N][M] << endl;
	for (int x : q)
		cout << x << ' ';
	cout << endl;

	return 0;
}
