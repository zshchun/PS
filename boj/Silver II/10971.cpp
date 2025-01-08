#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890123ULL

ll N, ans = INF;
ll a[10][10];

void dfs(ll s, ll p, ll visited, ll sum) {
	if (__builtin_popcount(visited) == N && p == s) {
		if (sum < ans)
			ans = sum;
		return;
	}

	if (visited & (1 << p)) {
		return;
	}


	for (ll i=0;i<N;i++) {
		if (a[p][i] == 0)
			continue;
		dfs(s, i, visited | (1 << p), sum + a[p][i]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> N;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			cin >> a[i][j];

	for (i=0;i<N;i++) {
		dfs(i, i, 0, 0);
	}

	cout << ans << endl;

	return 0;
}
