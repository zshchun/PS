#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll N, S, ans;
ll a[41];
map<ll,ll> m;
// meet in the middle

void dfs1(ll i,ll sum) {
	if (i == N/2) {
		m[sum]++;
		return;
	}

	dfs1(i+1, sum);
	dfs1(i+1, sum + a[i]);
}

void dfs2(ll i,ll sum) {
	if (i == N) {
		ans += m[S-sum];
		return;
	}

	dfs2(i+1, sum);
	dfs2(i+1, sum + a[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i;
	cin >> N >> S;

	for (i=0;i<N;i++)
		cin >> a[i];

	dfs1(0, 0);
	dfs2(N/2, 0);

	if (S == 0) ans--;
	cout << ans << endl;
	return 0;
}
