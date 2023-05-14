#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll N, K, cnt;
ll ans[11];

void backtrack(ll n, ll len) {
	ll i;
	if (n == N) {
		cnt++;
		if (cnt == K) {
			for (i=0;i<len;i++) {
				if (i > 0) cout << "+";
				cout << ans[i];
			}
			cout << endl;
		}
	}
	if (cnt >= K) return;
	for (i=1;i<=3;i++) {
		if (n + i <= N) {
			ans[len] = i;
			backtrack(n+i, len+1);
		}
	}
}

ll num[4];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	backtrack(0, 0);
	if (cnt < K)
		cout << "-1\n";
	return 0;
}
