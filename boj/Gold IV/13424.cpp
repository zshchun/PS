#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define INF 1234567890
ll T, N, M, K;
ll n[101];
ll m[101][101];

int main() {
	ll i, j, k, a, b, c, ans, s, room, mins;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		fill_n(&m[0][0], 101*101, INF);
		vector<ll> v;
		cin >> N >> M;
		for (i=0;i<M;i++) {
			cin >> a >> b >> c;
			m[a][b] = c;
			m[b][a] = c;
		}
		for (i=1;i<=N;i++)
			m[i][i] = 0;
		// floyd-warshall
		for (k=1;k<=N;k++) {
			for (i=1;i<=N;i++) {
				for (j=1;j<=N;j++) {
					if (m[i][j] > m[i][k] + m[k][j]) {
						m[i][j] = m[i][k] + m[k][j];
					}
				}
			}
		}
		cin >> K;
		v.resize(K);
		for (i=0;i<K;i++) {
			cin >> v[i];
		}
		mins = INF;
		ans = 0;
		for (i=1;i<=N;i++) {
			s = 0;
			for (ll x : v) {
				s += m[x][i];
			}
			if (s < mins) {
				mins = s;
				ans = i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

