#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
ll n, m, ans;
vector<ll> prime;

ll solve(ll k, ll cnt, ll prod) {
	if (cnt == 0)
		return m / prod;
	ll ret = 0;
	for (ll i=k+1;i<n;i++)
		ret += solve(i, cnt-1, prod * prime[i]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k;
	cin >> n >> m;
	prime.resize(n);
	for (i=0;i<n;i++)
		cin >> prime[i];

	for (i=1;i<=n;i++) {
		if (i & 1)
			ans += solve(-1, i, 1);
		else
			ans -= solve(-1, i, 1);
	}
	cout << ans << endl;

	return 0;
}
