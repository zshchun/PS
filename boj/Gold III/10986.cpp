#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, M;
ll a[1000001];
ll m[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, ans;
	cin >> N >> M;
	for (i=1;i<=N;i++) {
		cin >> a[i];
		a[i] = (a[i-1] + a[i]) % M;
		m[a[i]]++;
	}

	ans = m[0];
	for (i=0;i<M;i++) {
		ans += (m[i] * (m[i] - 1)) / 2;
	}
	cout << ans << endl;
	return 0;
}
